#include <ctype.h>
#include <stdlib.h>

bool IsValidPort(char *port) {
	/* if the char type port is all digit */
	for (int i = 0; port[i] != 0; i ++)
		if (!isdigit(port[i]))
			return false;	
		
	/* If the port in the valid range */
	int p = atoi(port);
	return (p >= 0 && p <= 65535) ? true : false;
}