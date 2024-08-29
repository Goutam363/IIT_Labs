#include<stdio.h>
#include<stdlib.h>

void copyFile(char *src, char *dst ){
	FILE *srcFile=fopen(src,"r");
	if(srcFile==NULL){
		printf("Error in opening the source file\n");
		return;
	}
	FILE *dstFile=fopen(dst,"w");
	if(dstFile==NULL){
		printf("Error in opening the destination file\n");
		return;
	}
	int ch;
    while ((ch = fgetc(srcFile)) != EOF) {
        fputc(ch, dstFile);
    }

	//Alternative
	// char buffer[BUFSIZ];
	// size_t bytesRead;
	// while((bytesRead=fread(buffer,1,BUFSIZ,srcFile))>0)
	// 	fwrite(buffer,1,bytesRead,dstFile);
	
	fclose(srcFile);
	fclose(dstFile);

}

int main(int argc, char *argv[]){
	copyFile(argv[1],argv[2]);
	return 0;
}
