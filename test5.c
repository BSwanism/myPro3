#include<stdio.h>
#include<stdlib.h>
main(int argc, char**argv)
{
		  int fd;
		  int nbyte;
		  char buf[50];
					
		  if(argc!=3){
					 printf("usage:symlink_1 actualname symname\n");
					 exit(1);
		  }
		  if(symlink(argv[1],argv[2])<0){
					 printf("symlink call error\n");
					 exit(2);
		  }
		  else
					 printf("symlink : %s->%s\n",argv[2],argv[1]);
		  if((nbyte=readlink(argv[2],buf,50))<0){
					 printf("readlink call error\n");
					 exit(2);
		  }
		  else{
					 buf[nbyte]='\0';
					 printf("buf : %s \n",buf);
		  }
}
