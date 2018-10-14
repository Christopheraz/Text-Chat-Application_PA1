#include <iostream>
#include "../include/global.h"
#include "../include/logger.h"
#include "../include/server.h"
#include "../include/utils.h"

void Server::PrintError() {
	std::string command_str = "ERROR";
	cse4589_print_and_log("[%s:ERROR]\n", command_str.c_str()); 
	cse4589_print_and_log("[%s:END]\n", command_str.c_str());
}

void Server::PrintAuthor() {
	std::string command_str = "AUTHOR";
	cse4589_print_and_log("[%s:SUCCESS]\n", command_str.c_str());
	cse4589_print_and_log("I, %s, have read and understood the course academic integrity policy.\n", AUTHOR_NAME);
	cse4589_print_and_log("[%s:END]\n", command_str.c_str());
}

void Server::ServerListen(std::string port) {
	memset(&hints, 0, sizeof hints); // 

	listen_port = port;
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE; // use my IP
    
	getaddrinfo(NULL, port.c_str(), &hints, &res);
	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

	bind(sockfd, res->ai_addr, res->ai_addrlen);
	listen(sockfd, BACKLOG);

	gethostname((char*)hostname.c_str(), sizeof hostname); // Get my host name
}

void Server::getIPaddress() {
 struct hostent *hend;
 struct in_addr **addr_list;
 char hostname[1024];
 gethostname(hostname,1024); ///fills ip add
 // cout << hostname << endl;

 if ((hend = gethostbyname(hostname))== NULL) {  // get the host info
  std::cout << "here" << std::endl;
  herror("gethostbyname");
 }

 // save IP of this host:
 addr_list = (struct in_addr **)hend->h_addr_list;
 for(int i = 0; addr_list[i] != NULL; i++) {
  ip_address = inet_ntoa(*addr_list[i]);
 }
}

void Server::PrintIP() {
	getIPaddress();
	std::string command_str = "IP";
	cse4589_print_and_log("[%s:SUCCESS]\n", command_str.c_str());
	cse4589_print_and_log("PORT:%s\n", ip_address.c_str());
	cse4589_print_and_log("[%s:END]\n", command_str.c_str());
}

std::string Server::PrintHostName() {
	return hostname;
}

void Server::PrintPort() {
	std::string command_str = "PORT";
	cse4589_print_and_log("[%s:SUCCESS]\n", command_str.c_str());
	cse4589_print_and_log("PORT:%s\n", listen_port.c_str());
	cse4589_print_and_log("[%s:END]\n", command_str.c_str());
}

void Server::CommandLoop() {
	while(strcmp(input, "EXIT") != 0) {
		if(strcmp(input, "AUTHOR") == 0) {
			PrintAuthor();
		} else if (strcmp(input, "IP") == 0) {
			PrintIP();
		} else if (strcmp(input, "PORT") == 0) {
			PrintPort();
		} else if (strcmp(input, "LOGIN") == 0) {
		
		}
		std::string in;
		getline (std::cin,in);
		strcpy(input,in.c_str());
	}
}
