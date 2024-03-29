#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BACKLOG 10

class Server {
    private:
        std::string listen_port;
        std::string hostname;
        std::string ip_address;
        struct sockaddr_storage their_addr;
        struct addrinfo hints, *res;
        struct in_addr **addr_list;
        struct hostent *he;
        socklen_t addr_size;

        int sockfd, new_fd;
        char input[10];

    public:
        void PrintIP();
        void PrintList();
        void CommandLoop();
        void PrintSTAT();
        void PrintError();
        void PrintAuthor();
        void ServerListen(std::string port);
        std::string PrintHostName();
        void PrintPort();
        void getIPaddress();
};
