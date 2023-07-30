#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main(){
  FILE *fp;
  char pattern[10],temp[200],file_name[20];
  printf("Enter the file name\n");
  scanf("%s",file_name);
  printf("Enter the pattern\n");
  scanf("%s",pattern);
  fp=fopen(file_name,"r");
  if(fp==NULL){
   printf("The file doesnt is not present\n");
   return;
  } 
  while(!feof(fp)){
   fgets(temp,100,fp);
   if(strstr(temp,pattern)){
       printf("The pattern is present in the file\n");
       printf("%s",temp);
       }
  }
  fclose(fp);
}
