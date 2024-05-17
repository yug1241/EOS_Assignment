#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fdw,fdr, sum, cnt;
	int num1, num2;
	fdw = open("/home/sunbeam/Desktop/my_practise/eos_practise/practise_systemcall/assignment/day11/sum_fifo", O_WRONLY);
	if(fdw < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("Enter number 1: ");
	scanf("%d", &num1);
	printf("Enter number 2: ");
	scanf("%d", &num2);

	cnt = write(fdw, &num1, sizeof(num1));
	cnt =  write(fdw, &num2, sizeof(num2));

	// cnt = write(fd_w, arr, sizeof(arr));

	fdr = open("/home/sunbeam/Desktop/my_practise/eos_practise/practise_systemcall/assignment/day11/ans_fifo", O_RDONLY);
	if(fdr < 0) {
		perror("open() failed");
		_exit(1);
	}
	cnt = read (fdr, &sum, sizeof(sum));
	printf("THE result is : %d\n",sum);
	close(fdw);
	close(fdr);
	return 0;
}
