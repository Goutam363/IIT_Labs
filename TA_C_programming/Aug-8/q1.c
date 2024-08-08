#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int newNum, position;
    scanf("%d",&newNum);
    scanf("%d",&position);
    if(position<1 || position>n+1){
        printf("Invalid position!\n");
        return 0;
    }
    arr=(int *)realloc(arr,(n+1)*sizeof(int));
    for(int i=n;i>position-1;i--){
        arr[i]=arr[i-1];
    }
    arr[position-1]=newNum;
    printf("Answer--------------------------------\n");
    for(int i=0;i<=n;i++)
        printf("%d ",arr[i]);
    free(arr);
    return 0;
}