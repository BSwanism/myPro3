#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
void term_stat(int status)
{
  if(WIFEXITED(status))
    printf("normal termination, exit status=%d\n",WEXITSTATUS(status));
  else if(WIFSIGNALED(status))
    printf ("abnormal termination, signal number = %d%s\n",WTERMSIG(status),
#ifdef WCOREDUMP
	    WCOREDUMP(status)?"(core file generated)" :"");
#else
  "");
#endif
 else if(WIFSTOPPED(status))
   printf("child stopped, signal number=%d\n",WSTOPSIG(status));
}
void err_end(char* msg){
  printf("% error\n",msg);
  exit(1);
}

int main(void)
{
  pid_t pid;
  int status;
  if((pid=fork())<0)
    err_end("fork");
  else if(pid==0)
    exit(7);
  if(wait(&status)!=pid)
    err_end("wait");
  term_stat(status);
  if((pid=fork())<0)
    err_end("fork");
  else if(pid==0)
    abort();
  if(wait(&status)!=pid)
    err_end("wait");
  term_stat(status);
  if((pid=fork())<0)
    err_end("fork");
  else if(pid==0)
    status/=0;
  if(wait(&status)!=pid)
    err_end("wait error");
  term_stat(status);
  exit(0);
}

