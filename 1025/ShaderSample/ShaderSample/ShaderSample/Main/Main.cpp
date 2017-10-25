#include <windows.h>
#include <mmsystem.h>
#include <d3dx9.h>
#include <d3dx9math.h>

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dxguid.lib")

#define D3D_FVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

/*** ���_�\���� */
struct CUSTOMVERTEX
{
	float     x, y, z;	//!< �ʒu���.
	float     rhw;		//!< ���_�ϊ��l.
	D3DCOLOR  color;	//!< ���_�J���[.
	float     tu, tv;	//!< �e�N�X�`�����W.
};

// DirectX�I�u�W�F�N�g.
LPDIRECT3D9			g_pDirect3D = NULL;
LPDIRECT3DDEVICE9	g_pD3DDevice = NULL;

// �V�F�[�_�[�֘A�I�u�W�F�N�g.
LPD3DXEFFECT	g_pEffect;		//!< �V�F�[�_�[�I�u�W�F�N�g.
D3DXHANDLE		g_Technique;	//!< �e�N�j�b�N�n���h��.
D3DXHANDLE		g_Alpha;		//!< �A���t�@�n���h��.

// �e�N�X�`��.
LPDIRECT3DTEXTURE9 g_pTexture = NULL;
LPDIRECT3DTEXTURE9 g_pTexture2 = NULL;

LPDIRECT3DTEXTURE9 g_pBackBufferTexture = NULL;
LPDIRECT3DTEXTURE9 g_pBackBufferTexture2 = NULL;
LPDIRECT3DSURFACE9 g_pTextureSurface = NULL;
LPDIRECT3DSURFACE9 g_pTextureSurface2 = NULL;

// ���_�f�[�^.
static CUSTOMVERTEX Background[] =
{
	{ 0.0f,		0.0f,	0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 0.0f },
	{ 1024.0f,	0.0f,	0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 0.0f },
	{ 1024.0f,	768.0f, 0.5f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
	{ 0.0f,		768.0f, 0.5f, 1.0f, 0xFFFFFFFF, 0.0f, 1.0f },
};

// DirectX������ ����֐�.
bool InitDirectX(HWND hWnd);
void ReleaseDirectX();

// �V�F�[�_�[������ ����֐�.
bool InitShader();
void ReleaseShader();

// �`��֐�.
void Draw();


LRESULT CALLBACK WndProc(HWND _hWnd, UINT _msg, WPARAM _wParam, LPARAM _lParam)
{
	switch (_msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		switch ((CHAR)_wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	}

	return DefWindowProc(_hWnd, _msg, _wParam, _lParam);
}


int WINAPI WinMain(HINSTANCE _instance, HINSTANCE _hPrevInst, LPSTR _szStr, INT _cmdShow)
{
	HWND		hWnd = NULL;
	WNDCLASSEX  Wndclass;
	static char AppName[] = "ShaderSample";

	Wndclass.cbSize			= sizeof(Wndclass);
	Wndclass.style			= CS_HREDRAW | CS_VREDRAW;
	Wndclass.lpfnWndProc	= WndProc;
	Wndclass.cbClsExtra		= 0;
	Wndclass.cbWndExtra		= 0;
	Wndclass.hInstance		= _instance;
	Wndclass.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	Wndclass.hCursor		= LoadCursor(NULL, IDC_ARROW);
	Wndclass.hbrBackground	= (HBRUSH)GetStockObject(BLACK_BRUSH);
	Wndclass.lpszMenuName	= NULL;
	Wndclass.lpszClassName	= AppName;
	Wndclass.hIconSm		= LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&Wndclass);

	hWnd = CreateWindow(
		AppName,
		AppName,
		WS_OVERLAPPEDWINDOW,
		0,
		0, 
		1024,
		768,
		NULL,
		NULL,
		_instance,
		NULL);

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	// DirectX�I�u�W�F�N�g�ƃV�F�[�_�̏�����.
	if (!InitDirectX(hWnd)) return -1;
	if (!InitShader())		return -1;


	// �e�N�X�`���̓ǂݍ���.
	D3DXCreateTextureFromFile(g_pD3DDevice, "Resource\\Texture\\Test.png", &g_pTexture);
	D3DXCreateTextureFromFile(g_pD3DDevice, "Resource\\Texture\\Test2.png", &g_pTexture2);

	// ��e�N�X�`���̍쐬.
	D3DXCreateTexture(
		g_pD3DDevice,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		1,
		D3DUSAGE_RENDERTARGET,
		D3DFMT_A8R8G8B8,
		D3DPOOL_DEFAULT,
		&g_pBackBufferTexture);
	g_pBackBufferTexture->GetSurfaceLevel(0, &g_pTextureSurface);

	D3DXCreateTexture(
		g_pD3DDevice,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		1,
		D3DUSAGE_RENDERTARGET,
		D3DFMT_A8R8G8B8,
		D3DPOOL_DEFAULT,
		&g_pBackBufferTexture2);
	g_pBackBufferTexture2->GetSurfaceLevel(0, &g_pTextureSurface2);



	DWORD SyncOld = timeGetTime();
	DWORD SyncNow;

	MSG	Msg;
	ZeroMemory(&Msg, sizeof(Msg));

	timeBeginPeriod(1);
	while (Msg.message != WM_QUIT)
	{
		Sleep(1);
		if (PeekMessage(&Msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
		else
		{
			SyncNow = timeGetTime();
			if (SyncNow - SyncOld >= 1000 / 60) 
			{
				Draw();
				SyncOld = SyncNow;
			}
		}
	}
	timeEndPeriod(1);

	// �������.
	g_pTextureSurface2->Release();
	g_pBackBufferTexture2->Release();
	g_pTextureSurface->Release();
	g_pBackBufferTexture->Release();
	g_pTexture2->Release();
	g_pTexture->Release();

	ReleaseShader();
	ReleaseDirectX();

	return 0;
}


bool InitDirectX(HWND hWnd)
{
	// Direct3D�I�u�W�F�N�g�̐���.
	g_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (g_pDirect3D == NULL)
		return false;

	D3DDISPLAYMODE D3ddm;
	g_pDirect3D->GetAdapterDisplayMode(
		D3DADAPTER_DEFAULT,
		&D3ddm);

	// Direct3D�f�o�C�X�̐���.
	D3DPRESENT_PARAMETERS D3dpp;
	ZeroMemory(&D3dpp, sizeof(D3dpp));
	D3dpp.BackBufferFormat			= D3ddm.Format;
	D3dpp.BackBufferCount			= 1;
	D3dpp.SwapEffect				= D3DSWAPEFFECT_DISCARD;
	D3dpp.Windowed					= TRUE;

	g_pDirect3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_MIXED_VERTEXPROCESSING,
		&D3dpp,
		&g_pD3DDevice);

	// �ݒ���s��.
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);

	return true;
}

void ReleaseDirectX()
{
	g_pD3DDevice->Release();
	g_pDirect3D->Release();
}

bool InitShader()
{
	LPD3DXBUFFER pError = NULL;
	if (FAILED(D3DXCreateEffectFromFile(
		g_pD3DDevice,
		"Resource\\Effect\\TestShader.fx",
		NULL,
		NULL,
		0, 
		NULL,
		&g_pEffect,
		&pError)))
	{
		return false;
	}

	g_Technique = g_pEffect->GetTechniqueByName("TShader");
	g_Alpha		= g_pEffect->GetParameterByName(NULL, "g_Alpha");

	g_pEffect->SetTechnique(g_Technique);

	return true;
}

void ReleaseShader()
{
	g_pEffect->Release();
}

void Draw()
{
	static bool IsReverse = true;	//!< �A���t�@�l�𑝉������邩�̃t���O.
	static float Alpha = 0;			//!< �A���t�@�l.

	if (IsReverse)
	{
		Alpha += 0.003f;
		if (Alpha > 1.0f)
		{
			IsReverse = false;
		}
	}
	else
	{
		Alpha -= 0.003f;
		if (Alpha < 0.f)
		{
			IsReverse = true;
		}
	}

	// �`��O����.
	g_pD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	g_pD3DDevice->BeginScene();
	g_pD3DDevice->SetFVF(D3D_FVF);

	// �o�b�N�o�b�t�@�T�[�t�F�[�X���擾.
	LPDIRECT3DSURFACE9 pBackBuffer;
	g_pD3DDevice->GetRenderTarget(0, &pBackBuffer);

	// �萔�̐ݒ�.
	g_pEffect->SetFloat(g_Alpha, Alpha);

	// �V�F�[�_�[�p�X�̊J�n.
	g_pEffect->Begin(NULL, 0);
	g_pEffect->BeginPass(1);

	// �e�N�X�`����`���Ƃ��ĕ`��.
	g_pD3DDevice->SetRenderTarget(0, g_pTextureSurface);
	g_pD3DDevice->SetTexture(0, g_pTexture);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Background, sizeof(CUSTOMVERTEX));

	g_pD3DDevice->SetRenderTarget(0, g_pTextureSurface2);
	g_pD3DDevice->SetTexture(0, g_pTexture2);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Background, sizeof(CUSTOMVERTEX));

	// �V�F�[�_�[�p�X�̏I��.
	g_pEffect->EndPass();
	g_pEffect->End();

	// �V�F�[�_�[�p�X�̊J�n.
	g_pEffect->Begin(NULL, 0);
	g_pEffect->BeginPass(0);

	// �o�b�N�o�b�t�@�ɕ`��.
	g_pD3DDevice->SetRenderTarget(0, pBackBuffer);
	g_pD3DDevice->SetTexture(0, g_pBackBufferTexture);
	g_pD3DDevice->SetTexture(1, g_pBackBufferTexture2);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, Background, sizeof(CUSTOMVERTEX));

	// �V�F�[�_�[�p�X�̏I��.
	g_pEffect->EndPass();
	g_pEffect->End();

	// �`��㏈��.
	g_pD3DDevice->EndScene();
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

