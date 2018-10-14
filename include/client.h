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
using namespace std;

class Client {
    private:
        std::string listen_port;
        std::string hostname;
        struct sockaddr_storage their_addr;
        struct addrinfo hints, *res;
        struct in_addr **addr_list;
        struct hostent *he;
        socklen_t addr_size;

        int sockfd, new_fd;
        char input[10];

    public:
        void PrintIP();
        void CommandLoop();
        void PrintError();
        void PrintAuthor();
        void Setup(string port_str);
        std::string PrintHostName();
        void PrintPort();
};
