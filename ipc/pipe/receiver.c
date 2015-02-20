#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {

	char data[100];
	int fd= 0;
	int len = 0;
	printf("Chat with Venky started\n");
	
	unlink("venkio");
	mkfifo("venkio",0660);
	fd = open("venkio",O_RDONLY);
	
	
	while(1) {
		len = read(fd,data,100);
		if (len <= 0) {
			break;
		}
		
		data[len] = '\0';
		printf("Venky: %s",data);
	}
	
	close(fd);
	
	return 0;
	
}
			
	
