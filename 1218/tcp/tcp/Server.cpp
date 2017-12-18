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

	// WinSocket初期化
	if (WSAStartup(MAKEWORD(2, 0), &WsaData) != 0)
	{
		printf("WSAStartupの初期化に失敗しました。\n");
		getchar();
		return;
	}

	MySocket = socket(AF_INET, SOCK_STREAM, 0);
	
	// 受信設定
	MyAddress.sin_family = AF_INET;
	MyAddress.sin_port = htons(50000);
	MyAddress.sin_addr.S_un.S_addr = INADDR_ANY;

	// ソケットとアドレス設定を結びつける
	bind(MySocket, (sockaddr*)&MyAddress, sizeof(sockaddr_in));

	// 接続待機(ブロッキング関数)
	listen(MySocket, 5);

	int Len = sizeof(ClientAddress);

	// クライアントからの接続を受け入れる
	ClientSocket = accept(MySocket, (sockaddr *)&ClientAddress, &Len);

	// データ送信
	send(ClientSocket, "test",4,0);

	closesocket(ClientSocket);
	WSACleanup();

	getchar();
	return;
}