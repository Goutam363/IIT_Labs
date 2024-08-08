#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void createNewNode(struct Node **head, int data){
    if(*head==NULL){
        *head = (struct Node *)malloc(sizeof(struct Node));
        (*head)->data = data;
        (*head)->next = NULL;
        return;
    }
    struct Node *temp = *head;
    while(temp->next)
        temp=temp->next;
    temp->next=(struct Node *)malloc(sizeof(struct Node));
    temp=temp->next;
    temp->data=data;
    temp->next=NULL;
    return;
}

void showList(struct Node **head){
    struct Node *temp=*head;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    struct Node *head=NULL;
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int data;
        scanf("%d",&data);
        createNewNode(&head,data);
    }
    printf("Original List: ");
    showList(&head);

    // To add new node in particular position
    int newNum,position;
    scanf("%d",&newNum);
    scanf("%d",&position);
    if(position < 0 || position > n+1){
        printf("Invalid position!\n");
        return 0;
    }
    struct Node *temp=head;
    if(position==1){
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = newNum;
        temp->next = head;
        head = temp;
    }
    else if(position==n+1)
        createNewNode(&head,newNum);
    else{
        for(int i=0;i<position-2;i++)
            temp=temp->next;
        struct Node* newNode=(struct Node *)malloc(sizeof(struct Node));
        newNode->data=newNum;
        newNode->next=temp->next;
        temp->next=newNode;
    }
    n++;
    printf("Updated List(After insertion): ");
    showList(&head);

    // To delete a node from particular position
    int delPosition;
    scanf("%d",&delPosition);
    if(delPosition < 1 || delPosition > n){
        printf("Invalid position!\n");
        return 0;
    }
    if(delPosition==1){
        temp=head;
        head=head->next;
        free(temp);
    }
    else{
        struct Node* prev=NULL;
        temp=head;
        for(int i=0;i<delPosition-1;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);
    }
    printf("Updated List(After deletion): ");
    showList(&head);

    return 0;
}