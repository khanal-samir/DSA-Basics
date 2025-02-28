#include<stdio.h>
#define maxSize 20

int stack [maxSize];
int tos=-1;

int isEmpty(){
    return tos==-1;
}

int isFull() {
    return tos == maxSize - 1;
}

void push (int item){
  if(isFull()){
    printf("Stack overflow\n");
  }else{
    tos++;
    stack[tos]=item;
  }
}

int pop(){
    if(isEmpty()){
        printf("Stack underflow\n");
        return -1;
    }else{
        return stack[tos--];//post decrement
    }
}

void displayStack(){
   if(isEmpty()){
    printf("Stack is empty\n");
   }else{
    for(int i=tos;i>=0;i--){
        printf("%d\t",stack[i]);
    }
    printf("\n");
   }
}

void displayTos(){
    if(isEmpty()){
        printf("Stack is empty \n");
       
    }else{
        printf("Top of the stack is %d\n",stack[tos]);
    }
}

int main(){
displayStack();

push(1);
push(2);
displayTos();
displayStack();

int item=pop();
displayStack();
displayTos();
}
