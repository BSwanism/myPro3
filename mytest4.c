#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
void memoDirRead();//디렉토리 읽기
int memoRead();//파일 목록 출력
void memoWrite();//파일 입력
char files[256][100];//읽은 디렉토리 저장
int cnt;
void main(){
		  int menu, flag=1;
		  if(access("memoDir",F_OK)!=0){
					 mkdir("memoDir",0777);
					 printf("memoDir 디렉토리 생성\n");
		  }
		  while(flag){
					 puts("1,read, 2.write, 3.stop");
					 scanf("%d",&menu);
					 switch(menu){
								case 1:
										  memoDirRead();
										  if(memoRead()<=0){printf("error read");}
										  break;
								case 2:
										  memoWrite();
										  break;
								case 3:
										  return;
										  break;
					 }
		  }
}
void memoDirRead(){
		  DIR *dp;
		  struct stat statbuf;
		  struct dirent *dire;
		  cnt=0;
		  dp=opendir("memoDir");
		  if(dp==NULL){
					 puts("directory open error");
					 return;
		  }
		  while((dire=readdir(dp))!=NULL){
					 if(strcmp(".",dire->d_name)==0||
										  strcmp("..",dire->d_name)==0)
								continue;
				strcpy(files[cnt],dire->d_name);	 
				cnt++;
		  }
		  closedir(dp);
}
int memoRead(){
		  int i,fd;
		  char fileName[256];
		  char buf;
		  for(i=0;i<cnt;i++){
					 printf("%d, %s\n",i,files[i]);
		  }
		  puts("select files number ");
		  scanf("%d",&i);
		  if(i>=cnt){
					 puts("wrong number without range");
					 return;
		  }
		  strcpy(fileName,"memoDir/");
		  strcat(fileName,files[i]);
		  fileName[strlen(fileName)+1]='\0';
		  fd=open(fileName,O_RDONLY);
		  if(fd<0){
					 puts("file open error");
					 return;
		  }
		  while(read(fd,&buf, 1)==1){
					 printf("%c",buf);
		  }
		  puts("\n");
		  close(fd);								
		  return i;
}
void memoWrite(){
		  char fileName[256];
		  int i,flag=1;
		  while(flag){
					 puts("new file name");
					 scanf("%s",fileName);
					 for(i=0;i<cnt;i++){
								if(!strcmp(fileName,files[1])){
										  puts("duplicated file name");
										  break;
								}
					 }
					 if(i==cnt){
								flag=0;
								printf("new file %s create completely \n",fileName);
					 }
							
					 
		  }
}
