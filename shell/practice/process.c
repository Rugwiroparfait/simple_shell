#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int a = 1;
	int b = 2;
	int addition = a + b;
	pid_t ppid;
	pid_t pid;
	ppid = getppid();	
	pid = getpid();

	printf("%d, is the sum of %d and %d\n",addition,a,b);
	printf("%d, is process parent proccess id\n",ppid);
	printf("%d, is the actual process\n",pid);
	return (0);
}
