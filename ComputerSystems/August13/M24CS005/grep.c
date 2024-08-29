#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void searchFile(char *filename, char *searchString){
        FILE *file=fopen(filename,"r");
        if(file==NULL){
                printf("Error while opening the file\n");
                return;
        }

        int lineNumber = 0;
        int ch;
        char line[1024];  // Assuming a maximum line length of 1024 characters
        int index = 0;

        while ((ch = fgetc(file)) != EOF) {
                if (ch != '\n') 
                        line[index++]=ch;
                else {
                        lineNumber++;
                        if (strstr(line, searchString) != NULL)
                                printf("Line %d: %s\n", lineNumber, line);
                        index = 0;  // Reset the index for the next line
                }
        }

        // Alternative
        // char line[BUFSIZ];
        // int lineNumber=0;
        // while(fgets(line,sizeof(line),file)!=NULL){
        //         lineNumber++;
	// 	if(strstr(line, searchString)!=NULL)
	// 		printf("Line %d: %s", lineNumber, line);
        // }
        fclose(file);
}

int main(int argc, char *argv[]){
        searchFile(argv[2],argv[1]);
        return 0;
}
