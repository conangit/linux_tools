#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int opt;
	char *usbno = "0";
	char cmd[128] = {0};	
	char *ptr = "/dev/ttyUSB";

	while ( (opt = getopt(argc, argv, "c:")) != -1 )
    {
		switch (opt)
		{
			case 'c':
				usbno = optarg;		
				break;

			default:
                printf("unknown option: -%c\n", (char)optopt);
                return -1;
		}
	}

	sprintf(cmd, "%s%s%s", "sudo picocom -b 115200 ", ptr, usbno);
	
	printf("%s\n", cmd);
	system(cmd);	

	return 0;
}

