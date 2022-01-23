// koala-db.cpp : Defines the entry point for the application.
//

#include "koala-db.h"

using namespace std;

int main()
{
	WSADATA wsa;
	SOCKET s, new_socket;
	struct sockaddr_in server {}, client{};
	int c;
	char* message;

	printf("KoalaDB - Welcome!\n\n");

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		printf("Failed. Error Code : %d", WSAGetLastError());
		return 1;
	}

	printf("Initialised on OS %s.\n", OS_WINDOWS ? "Windows" : "Linux");

	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		printf("Could not create socket : %d", WSAGetLastError());
	}

	printf("Socket created.\n");

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8888);

	if (bind(s, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
		printf("Bind failed with error code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}

	listen(s, 3);

	printf("Waiting for incoming connections...");

	c = sizeof(struct sockaddr_in);

	while ((new_socket = accept(s, (struct sockaddr*) &client, &c)) != INVALID_SOCKET) {
		printf("New connection!");

		message = "Accepted\n";
		send(new_socket, message, strlen(message), 0);
	}

	if (new_socket == INVALID_SOCKET) {
		printf("accept failed with error code : %d", WSAGetLastError());
		return 1;
	}

	closesocket(s);
	WSACleanup();

	return 0;
}
