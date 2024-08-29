#include<stdio.h>
#include<stdlib.h>

void printFile(char *filename){
	FILE *file=fopen(filename,"r");
	if(file==NULL){
		printf("Error in opening the file\n");
		return;
	}
	char ch;
	while((ch=fgetc(file))!=EOF)
		putchar(ch);
	fclose(file);
}

int main(int argc, char *argv[]){
	printFile(argv[1]);
	return 0;
}
