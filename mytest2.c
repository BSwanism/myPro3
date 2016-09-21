#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
main(int argc, char** argv){
		  DIR *dp;
		  struct stat statbuf;
		  struct dirent *dent;
		  char perm[11];
		  char pathname[80];
		  char st[80];
		  int sel;
		  int fd,len;
		  char buf[20];
		  if(argc<2)exit(1);
		  stat(argv[1],&statbuf);
		  if(!S_ISDIR(statbuf.st_mode)){
					 frpintf(stderr,"%s is not directory\n",argv[1]);
					 exit(1);
		  }
		  if((dp=opendir(argv[1]))==NULL){
					 perror("Error:");
					 exit(1);
		  }
		  while((dent=readdir(dp))!=NULL){
					 if(!strcmp(argv[1],dent->d_name))
					 {
								printf("re insert dir: ");
								scanf("%s",st);
							if(mkdir(st,0666)<0)
								break;
							break;
					 }
		  }
		  printf("1. read,  2.write  3.finish ");
		  scanf("%d".&sel);
		  if(sel==1){
				if((fd=open(argv[1],O_RDWR,0666))<0){
						  perror("open error");
						  exit(-1);
				}
				if(write(fd,"How are you?",12)!=12){
						  perror("write error");
						  exit(-1);
				}
				if((len=read(fd,buf,sizeof(buf)))<=0){
						  perror("read error");
						  exit(-1);
				}
				printf("%S",buf);
		  }
		  else if(sel==2)
		  {
				if(
		  
		  }
		  else if(sel==3)
		  {
					 exit(3);
		  }

		  
}
