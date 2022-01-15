#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h> // for getnameinfo()
#include <pthread.h>

// Usual socket headers
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>

#include "../config.h"
#include "../utils/logger.h"
#include "../file/file.h"

#define BACKLOG 10
volatile sig_atomic_t done = 0;

void term(int signal);

void startServer(int port, string path) {
    struct sigaction action;
    memset(&action, 0, sizeof(action));
    action.sa_handler = term;
    sigaction(SIGTERM, &action, NULL);

    int serverSocket = socket(
            AF_INET,
            SOCK_STREAM,
            0
    );
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &(int) {1}, sizeof(int));


    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);


    bind(
            serverSocket,
            (struct sockaddr *) &serverAddress,
            sizeof(serverAddress)
    );


    int listening = listen(serverSocket, BACKLOG);
    if (listening < 0) {
        throwError("The server isnt listening");
    }
    int clientSocket;

    while (true) {
        char *buff = (char *) malloc(1000);
        clientSocket = accept(serverSocket, NULL, NULL);
        throwLog("Connection established");

        read(clientSocket, buff, 1000);
        SendData sendData = setHttpHeader(buff, path);
        free(buff);

        send(clientSocket, sendData.header, sendData.size, 0);
        close(clientSocket);

        throwLog("Connection closed");

        if (done == 1) {
            close(serverSocket);
            exit(0);
        }
    }

}


void term(int signal) {
    throwLog("Closing Server");
    done = 1;
}
