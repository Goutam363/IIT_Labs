#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insertBegin(struct node **head, int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void insertEnd(struct node **head, int data){
    struct node *temp = *head;
    while(temp->next)
        temp=temp->next;
    temp->next = (struct node*)malloc(sizeof(struct node));
    temp=temp->next;
    temp->data = data;
    temp->next = NULL;
}

void insertBeforeNodeVal(struct node **head, int val, int data){
    struct node *temp = *head;
    struct node *prev = NULL;
    while(temp->data != val && temp->next){
        prev=temp;
        temp=temp->next;
    }
    if(prev == NULL){
        insertBegin(&*head, data);
        return;
    }
    if(temp->data == val){
        prev->next=(struct node*)malloc(sizeof(struct node));
        prev=prev->next;
        prev->data = data;
        prev->next = temp;
    }
}

void deleteBegin(struct node **head){
    struct node *temp = *head;
    if(*head){
        *head=(*head)->next;
        free(temp);
    }
}

void deleteEnd(struct node **head){
    struct node *temp = *head;
    struct node *prev = NULL;
    while(temp->next->next)
        temp = temp->next;
    prev = temp;
    temp=temp->next;
    prev->next = NULL;
    free(temp);
}

void deleteNodeVal(struct node **head, int val){
    struct node *temp = *head;
    struct node *prev = NULL;
    while(temp->data!=val && temp->next){
        prev=temp;
        temp=temp->next;
    }
    if(prev == NULL){
        deleteBegin(&*head);
        return;
    }
    if(temp->data == val){
        prev->next=temp->next;
        free(temp);
    }
}

void showList(struct node **head){
    struct node *temp = *head;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void reverseByIterative(struct node **head){
    if((*head)==NULL || (*head)->next==NULL)
        return;
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *nextNode = NULL;
    while(current){
        nextNode=current->next;
        current->next=prev;
        prev=current;
        current=nextNode;
    }
    *head=prev;
}

struct node* reverseByRecursive(struct node **head){
    if((*head)->next==NULL || (*head)==NULL)
        return *head;
    struct node *temp=reverseByRecursive(&(*head)->next);
    (*head)->next->next=*head;
    (*head)->next=NULL;
    return temp;
}

int main(){
    // Question 1
    struct node *head = NULL;
    insertBegin(&head, 10);
    insertBegin(&head, 20);
    insertBegin(&head, 30);
    insertEnd(&head, 50);
    insertEnd(&head, 70);
    showList(&head);
    insertBeforeNodeVal(&head, 30, 56);
    insertBeforeNodeVal(&head, 55, 22);
    showList(&head);
    deleteBegin(&head);
    deleteEnd(&head);
    showList(&head);
    deleteNodeVal(&head,20);
    showList(&head);
    deleteNodeVal(&head,30);
    showList(&head);
    deleteNodeVal(&head,50);
    showList(&head);

    // Question 2
    insertBegin(&head, 20);
    insertBegin(&head, 30);
    insertEnd(&head, 50);
    showList(&head);
    // Reverse by iterative method
    reverseByIterative(&head);
    showList(&head);
    // Reverse by recursive method
    head=reverseByRecursive(&head);
    showList(&head);
    return 0;
}