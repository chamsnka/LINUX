#include<stdio.h>
void main()
{
	// declare the variable 
	FILE *file1,*file2;
	char ch;
	//opening the file1
	file1=fopen("aaa.txt","r");
	if(file1==NULL)
	{
		printf("file open error");
	}
	//opening the file 2
	file2=fopen("aaa1.txt","w");
	if(file2==NULL)
	{
		printf("file open error");
	}
	//reading the data from one file to another char by char
	while((ch=fgetc(file1))!=EOF)
		fputc(ch,file2);
	//closeing the file
	fclose(file1);
	fclose(file2);
}
