#include<stdio.h>
int main(){
    int m,n;
    scanf("%d",&m);
    int A[m];
    for(int i=0;i<m;i++)
        scanf("%d",&A[i]);
    scanf("%d",&n);
    int B[n];
    for(int i=0;i<n;i++)
        scanf("%d",&B[i]);
    int i=0,j=0,k=0;
    int C[m+n];
    while(i<m && j<n){
        if(A[i]<=B[j]){
            C[k]=A[i];
            i++;
        }
        else{
            C[k]=B[j];
            j++;
        }
        k++;
    }
    while(i<m){
        C[k]=A[i];
        i++;
        k++;
    }
    while (j<n){
        C[k]=B[j];
        j++;
        k++;
    }

    printf("\n Merged Array: ");
    for(int i=0; i<m+n; i++)
        printf("%d ", C[i]);
    printf("\n");
    return 0;
}