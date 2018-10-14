/**
 * @nannanzh_assignment1
 * @author  Nannan Zhai <nannanzh@buffalo.edu>
 * @version 1.0
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 *
 * This contains the main function. Add further description here....
 */
#include <iostream>
#include <stdio.h>

#include "../include/global.h"
#include "../include/logger.h"
#include "../include/server.h"
#include "../include/utils.h"

using namespace std;

/**
 * main function
 *
 * @param  argc Number of arguments
 * @param  argv The argument list
 * @return 0 EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	/*Init. Logger*/
	cse4589_init_log(argv[2]);

	/* Clear LOGFILE*/
    fclose(fopen(LOGFILE, "w"));

	/*Start Here*/
	if (argc != 3) {
		cout << ("usage: ./assignment1 s/c port") << endl;
		return 1;
	}
	if (strcmp(argv[1], "s") == 0) {
		Server s;
		if(!IsValidPort(argv[2])) {
			cse4589_print_and_log("[%s:ERROR]\n", "PORT");
			cse4589_print_and_log("The port is invalid.\n");
			cse4589_print_and_log("[%s:END]\n", "PORT");
			return 0;	
		}
		s.ServerListen(argv[2]);
		s.CommandLoop();
	} else if (strcmp(argv[1], "c") == 0) {
		cout << "ClientInit();" << endl;
	} else {
		cout << ("usage: ./assignment1 s/c port") << endl;
		return 1;	
	}
	
	return 0;
}
