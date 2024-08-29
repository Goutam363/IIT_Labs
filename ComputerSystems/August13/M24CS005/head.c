#include<stdio.h>
#include<stdlib.h>

void printFirstNLines(char *filename, int numLines){
	FILE *file=fopen(filename,"r");
	if(file==NULL){
		printf("Error while opening the file\n");
		return;
	}
	char line[BUFSIZ];
	int lineCount=0;
	while(fgets(line,sizeof(line),file)!=NULL && lineCount<numLines){
		printf("%s",line);
		lineCount++;
	}
	fclose(file);
}

int main(int argc, char *argv[]){
	int numLines=atoi(argv[1]);
	printFirstNLines(argv[2],numLines);
	return 0;
}
