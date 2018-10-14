#include "../include/global.h"
#include "../include/logger.h"
#include "../include/client.h"
#include "../include/utils.h"

using namespace std;

/* constructor of client class */
void Client::Setup(string port_str) {
    listen_port = port_str;
}

void Client::PrintError() {
	std::string command_str = "ERROR";
	cse4589_print_and_log("[%s:ERROR]\n", command_str.c_str()); 
	cse4589_print_and_log("[%s:END]\n", command_str.c_str());
}

void Client::PrintAuthor() {
	std::string command_str = "AUTHOR";
	cse4589_print_and_log("[%s:SUCCESS]\n", command_str.c_str());
	cse4589_print_and_log("I, %s, have read and understood the course academic integrity policy.\n", AUTHOR_NAME);
	cse4589_print_and_log("[%s:END]\n", command_str.c_str());
}

void Client::PrintIP() {
	if ((he = gethostbyname(hostname.c_str())) == NULL) { // get the host info
		herror("gethostbyname");
		// return 2;
	}
	addr_list = (struct in_addr **)he->h_addr_list;
	for(int i = 0; addr_list[i] != NULL; i++) {
		std::cout << inet_ntoa(*addr_list[i]) << std::endl;
	}
}

std::string Client::PrintHostName() {
	return hostname;
}

void Client::PrintPort() {
	std::string command_str = "PORT";
	cse4589_print_and_log("[%s:SUCCESS]\n", command_str.c_str());
	cse4589_print_and_log("PORT:%s\n", listen_port.c_str());
	cse4589_print_and_log("[%s:END]\n", command_str.c_str());
}

void Client::CommandLoop() {
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
