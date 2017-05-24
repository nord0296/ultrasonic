#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main (int argc, char *argv[])
{
	char buf[4096];

	int fd = open("inputcap", O_RDONLY);
	memset(buf, 0, 4096);
	int ret = read(fd, buf, 4000);
	if (ret < 0) exit(0);
	int i;
	int count;
    for (i = 0; i < 4000; ++i)
    {
		char byte = buf[i];
		int mask = 0x80;
		while (mask)
		{
			if (mask & byte) ++count;
			mask >>= 1;
		}
	}
	printf("Distance = %6d us, %6.2f inches\n", count, (float)count / 148.0f);
	
	return 0;
}
