#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    int position;
    scanf("%d",&position);
    if(position<1 || position>n){
        printf("Invalid position!");
        return 0;
    }
    for(int i=position-1;i<n-1;i++)
        arr[i]=arr[i+1];
    arr=(int *)realloc(arr,(n-1)*sizeof(int));
    printf("Answer--------------------------------\n");
    for(int i=0; i<n-1; i++)
        printf("%d ",arr[i]);
    free(arr);
    return 0;
}