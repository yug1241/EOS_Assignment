#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int ret,r,n1,n2,num1,num2,res,s;
	int arr1[2],arr2[2];

	ret=pipe(arr1);
	ret=pipe(arr2);
	ret=fork();
	if(ret==0)
	{
		printf("Parent waiting for process completion.....\n");
		close(arr1[0]);
		close(arr2[1]);
		printf("Enter two numbers: ");
		scanf("%d %d",&num1,&num2);
		write(arr1[1],&num1,sizeof(num1));
		write(arr1[1],&num2,sizeof(num2));

		read(arr2[0],&res,sizeof(res));
		printf("result: %d\n",res);

		close(arr2[0]);
		close(arr1[1]);
	}

	else
	{
		close(arr1[1]);
		close(arr2[0]);
		read(arr1[0],&n1,sizeof(n1));
		read(arr1[0],&n2,sizeof(n2));

		r=n1+n2;

		write(arr2[1],&r,sizeof(r));
		printf("process completed....\n");
		close(arr2[1]);
		close(arr1[0]);
		waitpid(-1,&s,0);
	}
}
