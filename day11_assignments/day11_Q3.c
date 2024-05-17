//3. Find the size of pipe buﬀer in your system.


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include<string.h>

int arr[2];

void sigint_handler(int sig){
	printf("SIGINT caught: %d\n", sig);
	close(arr[1]);
	close(arr[0]);
	_exit(0);
}

int main()
{
	char ch = 'A';
	int ret, i=1;
	ret = pipe(arr);
	struct sigaction sa;
	// step2: register signal handler
	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = sigint_handler;
	ret = sigaction(SIGINT, &sa, NULL);
	if(ret < 0) {
		perror("sigaction() failed");
		_exit(1);
		}
		int count = 0;

		while(1){
			write(arr[1], &ch, 1);
			count ++;
			printf("bytes written: %d\n",count);
		}
	return 0;

}
