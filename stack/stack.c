#include <stdio.h>
#define MAX 10

int stack[MAX];
int top= -1;
char TRUE, FALSE;
int value;
 int isEmpty()   //checks if the stack is empty
 {
     if(top== -1)
        return 1;
     else
        return 0;
 }

 int isFull()  //checks if the stack is full
 {
     if(top==MAX)
        return 1;
     else
        return 0;
 }

 int peek()   //return the value at the top of the stack
 {
     return stack[top];
 }

 int pop()   //pops the value at the top of the stack
 {
     int value;

     if(!isEmpty())
     {
         value= stack[top];
         top= top-1;
         return value;
     }
     else
        printf("Stack is empty. There are no values to print!");
 }

 int push(int value)   //inserts values into the stack
 {
     if(!isFull())
     {
         top= top+1;
         stack[top]= value;
     }
     else
        printf("Stack is full. No more elements can be inserted into the stack!");
 }

 int main()
 {
     int i;
     push(1);
     push(5);
     push(8);
     push(3);
     push(7);
     push(16);
     push(11);
     push(19);
     push(13);
     push(15);

     printf("The element at the top: %d\n", peek());
     printf("The elements in the stack are: \n");
     while(!isEmpty())
     {
         int value= pop();
         printf("%d\n" ,value);
     }

     printf("Is the stack full?: %s\n", isEmpty()? "TRUE": "FALSE");
       printf("Is the stack empty?: %s\n", isFull()? "TRUE": "FALSE");

  return 0;
 }
