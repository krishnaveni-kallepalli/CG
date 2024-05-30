#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define DEVICE "/dev/AUDIO"
int main()
{
	int fd;
	char *buffer;
	size_t buffer_size = 1024;
	fd = open(DEVICE,O_WRONLY);
	if(fd<0)
	{
		perror("cannot open file\n");
		return errno;
	}
	buffer = (char*)malloc(buffer_szie);

	if(buffer == NULL) 
	{
		perror("Failed to allocate buffer..\n");
		close(fd);
		return errno;
	}
	if(write(fd,buffer,buffer_size)<0)
	{
		perror("failed to write..\n");
		close(fd);
		free(buffer);
		return errno;
	}
	close(fd);
	free(buffer);
	return 0;
}
