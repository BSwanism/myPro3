#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
int main(){
		  pid_t pid;
		  sleep(5);
		  printf("\n process id =%d\n", pid= getpid());
		  printf("parent process id=%d\n",getppid());
		  printf("real user id=%d\n",getuid());
		  printf("effective user id=%d\n",geteuid());
		  printf("real group id=%d\n",getgid());
		  printf("effect group id=%d\n",getegid());
}
