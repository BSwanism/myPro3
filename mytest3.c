#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
int main(int argc, char**argv)
{	
		  int fd, sel, len;
		  DIR* dp;
		  struct stat statbuf;
		  struct dirent* dent;
		  char perm[11];
		  char pathname[80];
		  char buf[20];
		  char st[20];
		  if(argc<2) exit(1);
		  stat(argv[1],&statbuf);
		  if(!S_ISDIR(statbuf.st_mode)){
					 fprintf(stderr,"%s is not directory\n",argv[1]);
					
		  }
		  if((dp=opendir(argv[1]))==NULL){
					 perror("Error");
					 exit(2);
		  }
		  printf("%s\n",argv[1]);
		  printf("wanted file name :");
		  scanf("%s",st);
		  while((dent=readdir(dp))!=NULL){
					 printf("d_name :%s\n",dent->d_name);
					 if(!strcmp(argv[1],dent->d_name))
					 {
								printf("strcmp if\n");
								printf("%s\n",argv[1]);
						if(mkdir(argv[1],0666)<0)
						{		printf("mkdir");
								  break;
						}
					 }
					 printf("this\n");
		  }
}
