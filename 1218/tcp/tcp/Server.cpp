#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <stdio.h>

#pragma comment(lib,"ws2_32.lib")

void main()
{
	WSADATA WsaData;
	SOCKET MySocket;
	SOCKET ClientSocket;
	sockaddr_in MyAddress;
	sockaddr_in ClientAddress;

	// WinSocket������
	if (WSAStartup(MAKEWORD(2, 0), &WsaData) != 0)
	{
		printf("WSAStartup�̏������Ɏ��s���܂����B\n");
		getchar();
		return;
	}

	MySocket = socket(AF_INET, SOCK_STREAM, 0);
	
	// ��M�ݒ�
	MyAddress.sin_family = AF_INET;
	MyAddress.sin_port = htons(50000);
	MyAddress.sin_addr.S_un.S_addr = INADDR_ANY;

	// �\�P�b�g�ƃA�h���X�ݒ�����т���
	bind(MySocket, (sockaddr*)&MyAddress, sizeof(sockaddr_in));

	// �ڑ��ҋ@(�u���b�L���O�֐�)
	listen(MySocket, 5);

	int Len = sizeof(ClientAddress);

	// �N���C�A���g����̐ڑ����󂯓����
	ClientSocket = accept(MySocket, (sockaddr *)&ClientAddress, &Len);

	// �f�[�^���M
	send(ClientSocket, "test",4,0);

	closesocket(ClientSocket);
	WSACleanup();

	getchar();
	return;
}