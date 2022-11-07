#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100
int top = -1;
int stack[N];

void push(int d){
    // Checking for stack overflow
    if(top == N-1){
        printf("Stack OverFLow!");
    }
    else{
        // Top increased by 1
        top = top + 1;
        // Pushing data d on top of the stack;
        stack[top] = d;
    }
}

void pop(){
    // Checking UnderFlow
    if(top == -1){
        printf("Stack UnderFlow");
    }
    else{
        // Storing top data to print
        int x = stack[top];
        printf("Popped %d from stack", x);
        // Decresing top 
        top = top - 1;
    }
}

int peek(){
    // Returning the top most element of the stack
    int x = stack[top];
    return x;
}

bool isEmpty(){
    // If top == -1 that means stack is empty and it will return true and if top != -1 then it will return false;
    if (top == -1)
        return true;
    else
        return false;
}

bool isFull(){
    // If top == N - 1 that means our array is full hence it will return true else false;
    // return top == N - 1;
    if(top == N - 1)
        return true;
    else
        return false;
}

int main(){
    // INDIVIDUAL FUNCTION CALLING
    // push(1);
    // push(2);
    // push(3);
    // push(4);
    // push(5);
    // printf("%d", peek());

    int c;
    bool x;

    while(1){
        printf("\nChoose any of the following options:\n");
        printf(" 0: Exit            1: Push            2: Pop            3: Peek\n");
        printf(" 4: isEmpty     5: isFull\n\n");
        scanf("%d", &c);

        switch (c)
        {
        case 0:
            exit(0);
        case 1:
            int d;
            printf("Enter Element to Push : ");
            scanf("%d", &d);
            push(d);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("%d is on Top", peek());
            break;
        case 4:
            x = isEmpty();
            printf(x ? "Stack Empty" : "Stack not Empty");
            break;
        case 5:
            x = isFull();
            printf(x ? "Stack Full" : "Stack not Full");
            break;
        default:
            printf("Invalid Choice");
        }
    }
}