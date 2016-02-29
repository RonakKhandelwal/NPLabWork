#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>


	
int main() 
{
   FILE *f1,*f2;
   char a;
   f1=fopen("sample.txt","r");
   f2=fopen("output.txt","w");
   do 
   {
      a = fgetc(fp1);
      fputc(a, fp2);
   } while (a != EOF);
 
   fclose(fp1);
   fclose(fp2);
 
}	
