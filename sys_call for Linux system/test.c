/* Name: Aryan Behal
   Roll_Number: 2019026 */

#include<stdio.h>
#include<linux/kernel.h>
#include<sys/syscall.h>
#include<unistd.h>
#include <errno.h> 
#include<string.h>

#define _GNU_SOURCE
#define SYS_sh_task_info 440
int main()
{
	int pid;
	char* path;
	
	//Enter pid... 
	printf("Enter the process_pid(only integer values within range): ");
	scanf("%d",&pid);

	//File path
	printf("Enter the path of file (less than 256): ");
	scanf("%s",path);

	//syscall
	int a=syscall(SYS_sh_task_info,pid,path);

	//for getting success or error mssg
	printf("Message: %s\n", strerror(errno));
	printf("Syscall returned %d\n",errno);
	return 0;
}
