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

	// WinSocket初期化.
	if (WSAStartup(MAKEWORD(2, 0), &WsaData) != 0)
	{
		printf("WSAStartupの初期化に失敗しました。\n");
		getchar();
		return;
	}

	Socket = socket(AF_INET, SOCK_STREAM, 0);

	// 接続先のアドレスを指定
	ServerAddress.sin_family = AF_INET;
	ServerAddress.sin_port = htons(50000);
	ServerAddress.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	// サーバーと接続
	connect(Socket, (sockaddr*)&ServerAddress, sizeof(sockaddr_in));
	
	memset(RecvBuffer, 0, sizeof(RecvBuffer));
	// サーバからデータ受信する
	recv(Socket, RecvBuffer, sizeof(RecvBuffer), 0);

	printf("%s\n", RecvBuffer);

	closesocket(Socket);
	WSACleanup();

	getchar();
	return;
}