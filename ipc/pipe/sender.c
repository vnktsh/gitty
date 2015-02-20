#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main() {

	char bye[] = "bye\n";
	char data[100];
	int fd= 0;
	int len = 0;
	
	

	fd = open("venkio",O_WRONLY);
	
	while(1) {
		len = read(0,data,100);
		if (len <= 1) {
			printf("Say 'bye' to exit!\n");
			continue;
			//break;
		}
		
		data[len] = '\0';
		if (!strcmp(data,bye)) {
			write(fd,data,len);
			break;
		}
		
		write(fd,data,len);
	}
	
	close(fd);
	
	return 0;
	
}
