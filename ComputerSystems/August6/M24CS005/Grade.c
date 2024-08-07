#include<stdio.h>

int main(){
	char gd;
	scanf("%c",&gd);
	switch(gd){
		case 'A':
			printf("Your performance is excellent\n");
			break;
		case 'B':
			printf("Your performance is good\n");
			break;
		case 'C':
			printf("Your performance is fair\n");
			break;
		case 'D':
			printf("Your performance is poor\n");
			break;
		case 'E':
			printf("Your grade is not complete\n");
			break;
		case 'F':
			printf("You are failed\n");
			break;
		default:
			printf("Invalid character\n");
			break;
	}
	return 0;
}
