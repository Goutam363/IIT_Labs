#include<stdio.h>
#include<stdlib.h>

void printLastNLines(char *filename, int numLines){
        FILE *file=fopen(filename,"r");
        if(file==NULL){
                printf("Error while opening the file\n");
                return;
        }
        char buffer[BUFSIZ];
        int totalLines=0;
        while(fgets(buffer,sizeof(buffer),file)!=NULL)
                totalLines++;
	rewind(file);
	int startLine=totalLines-numLines;
	if(startLine<0)
		startLine=0;
	int currentLine=0;
	while(fgets(buffer,sizeof(buffer),file)!=NULL){
		if(currentLine>=startLine)
			printf("%s",buffer);
		currentLine++;
	}
        fclose(file);
}

int main(int argc, char *argv[]){
        int numLines=atoi(argv[1]);
        printLastNLines(argv[2],numLines);
        return 0;
}

