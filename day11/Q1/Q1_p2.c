#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fdw,fdr, num1, num2, sum,ret;
    fdw = open("/home/sunbeam/Desktop/my_practise/eos_practise/practise_systemcall/assignment/day11/sum_fifo", O_RDONLY);
    if(fdw < 0) {
        perror("open() failed");
        _exit(1);
    }

    ret = read(fdw, &num1, sizeof(num1));
    ret = read(fdw, &num2, sizeof(num2));

    sum = num1 + num2;

    //close(fd);

    fdr = open("/home/sunbeam/Desktop/my_practise/eos_practise/practise_systemcall/assignment/day11/ans_fifo", O_WRONLY);
    ret = write(fdr, &sum, sizeof(sum));
    close(fdr);
	close(fdw);

    return 0;
}

