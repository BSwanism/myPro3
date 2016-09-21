#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

main()
{
		  pid_t pid;
		  printf("pid=%d, ppid=%d\n",getpid(),getppid());
		  pid=fork();
		  if(pid<0){
					 printf("복사 생성 실패\n");
		  }else if(pid==0){
					 printf("자녀 프로세스\n");
		  }else{
					 printf("부모 프로세스\n");
		  }
		  printf("pid=%d, ppid=%d\n",getpid(),getppid());
}
