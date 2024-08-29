#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

struct arr_stack{
    int top;
    int capacity;
    int* array;
};

struct arr_stack* create_stack_arr(int capacity){
    struct arr_stack* stack=(struct arr_stack *)malloc(sizeof(struct arr_stack));
    stack->capacity=capacity;
    stack->top=-1;
    stack->array=(int*)malloc(stack->capacity*sizeof(int));
    return stack;
}

bool isFull_arrStack(struct arr_stack* stack){
    return (stack->top == stack->capacity-1);
}

bool isEmpty_arrStack(struct arr_stack* stack){
    return (stack->top == -1);
}

void push_arrStack(struct arr_stack* stack, int item){
    if(isFull_arrStack(stack))
        return;
    stack->top++;
    stack->array[stack->top]=item;
}

int pop_arrStack(struct arr_stack* stack){
    if(isEmpty_arrStack(stack))
        return INT_MIN;
    int temp=stack->array[stack->top];
    stack->top--;
    return temp;
}

int top_arrStack(struct arr_stack* stack){
    if(isEmpty_arrStack(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

struct stack_node{
    int data;
    struct stack_node* next;
};

struct stack_node* create_stack_list(){
    struct stack_node* stack=NULL;
    return stack;
}

bool isEmpty_listStack(struct stack_node* stack){
    return stack==NULL;
}

void push_listStack(struct stack_node** top_ref, int new_data){
    struct stack_node* new_node=(struct stack_node*)malloc(sizeof(struct stack_node));
    new_node->data=new_data;
    new_node->next=(*top_ref);
    (*top_ref)=new_node;
}

int pop_listStack(struct stack_node** top_ref){
    if(isEmpty_listStack(*top_ref))
        return INT_MIN;
    int temp=(*top_ref)->data;
    struct stack_node* top_node=*top_ref;
    *top_ref=(*top_ref)->next;
    free(top_node);
    return temp;
}

int main(){
    struct arr_stack* arrStack=create_stack_arr(5);
    push_arrStack(arrStack, 10);
    push_arrStack(arrStack, 20);
    push_arrStack(arrStack, 30);
    push_arrStack(arrStack, 40);
    push_arrStack(arrStack, 50);
    push_arrStack(arrStack, 60);
    int temp = pop_arrStack(arrStack);
    printf("Popped from stack: %d\n", temp);
    temp= pop_arrStack(arrStack);
    printf("Popped from stack: %d\n", temp);
    temp= pop_arrStack(arrStack);
    printf("Popped from stack: %d\n", temp);
    temp= pop_arrStack(arrStack);
    printf("Popped from stack: %d\n", temp);
    temp= pop_arrStack(arrStack);
    printf("Popped from stack: %d\n", temp);
    temp= pop_arrStack(arrStack);
    printf("Popped from stack: %d\n", temp);
    temp= pop_arrStack(arrStack);
    printf("Popped from stack: %d\n\n", temp);

    struct stack_node* listStack=create_stack_list(5);
    push_listStack(&listStack, 10);
    push_listStack(&listStack, 20);
    push_listStack(&listStack, 30);
    push_listStack(&listStack, 40);
    push_listStack(&listStack, 50);
    push_listStack(&listStack, 60);
    temp= pop_listStack(&listStack);
    printf("Popped from stack: %d\n", temp);
    temp= pop_listStack(&listStack);
    printf("Popped from stack: %d\n", temp);
    temp= pop_listStack(&listStack);
    printf("Popped from stack: %d\n", temp);
    temp= pop_listStack(&listStack);
    printf("Popped from stack: %d\n", temp);
    temp= pop_listStack(&listStack);
    printf("Popped from stack: %d\n", temp);
    temp= pop_listStack(&listStack);
    printf("Popped from stack: %d\n", temp);
    temp= pop_listStack(&listStack);
    printf("Popped from stack: %d\n", temp);
}