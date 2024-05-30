#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define DEVICE "/dev/AUDIO"
int main()
{
	int err;
	char *buffer;
	size_t buffer_size = 1024;
	fd = open(DEVICE,O_WRONLY);
	
	buffer = (char*)malloc(buffer_szie);

	if(buffer == NULL) 
	{
		perror("Failed to allocate buffer..\n");
		close(fd);
		return errno;
	}
	snd_pcm_t *handle;
    	if ((err = snd_pcm_open(&handle, DEVICE, SND_PCM_STREAM_PLAYBACK, 0)) < 0) 
	{
        	fprintf(stderr, "Error opening PCM device %s: %s\n", DEVICE, snd_strerror(err));
    	        return err;
    	}	
	while(1)
	{
		if ((err = snd_pcm_writei(handle, buffer, buffer_size)) < 0)
	      	{
			fprintf(stderr, "Write to PCM device failed: %s\n", snd_strerror(err));
			break;
		}
	}
	snd_pcm_close(handle);
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
