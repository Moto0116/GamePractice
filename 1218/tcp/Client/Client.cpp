#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <stdio.h>

#pragma comment(lib,"ws2_32.lib")

void main()
{
	WSADATA WsaData;
	SOCKET Socket;
	sockaddr_in ServerAddress;
	char RecvBuffer[32];

	// WinSocket������.
	if (WSAStartup(MAKEWORD(2, 0), &WsaData) != 0)
	{
		printf("WSAStartup�̏������Ɏ��s���܂����B\n");
		getchar();
		return;
	}

	Socket = socket(AF_INET, SOCK_STREAM, 0);

	// �ڑ���̃A�h���X���w��
	ServerAddress.sin_family = AF_INET;
	ServerAddress.sin_port = htons(50000);
	ServerAddress.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	// �T�[�o�[�Ɛڑ�
	connect(Socket, (sockaddr*)&ServerAddress, sizeof(sockaddr_in));
	
	memset(RecvBuffer, 0, sizeof(RecvBuffer));
	// �T�[�o����f�[�^��M����
	recv(Socket, RecvBuffer, sizeof(RecvBuffer), 0);

	printf("%s\n", RecvBuffer);

	closesocket(Socket);
	WSACleanup();

	getchar();
	return;
}