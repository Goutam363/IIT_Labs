#include<stdio.h>

void countFile(FILE *file,int *lines,int *words,int *chars){
	int ch, prev = EOF;
	*lines=0;
	*words=0;
	*chars=0;
	while((ch = fgetc(file)) != EOF){
		(*chars)++;
		if((ch == ' ' || ch == '\t' || ch == '\n') && !(prev == ' ' || prev == '\t' || prev == '\n'))
			(*words)++;
		if(ch=='\n')
			(*lines)++;
		prev = ch;
	}
	if(!(prev == ' ' || prev == '\t' || prev == '\n'))	//Special check for the last character
		(*words)++;
}

int main(int argc, char *argv[]){
	FILE *file=fopen(argv[1],"r"); //Opening in read mode
	if(file==NULL){
		printf("Unable to open file");
		return -1;
	}
	int lines, words, chars;
	countFile(file,&lines,&words,&chars);
	fclose(file); //Closing the file
	printf("%d %d %d\n", lines, words, chars);
	return 0;
}
