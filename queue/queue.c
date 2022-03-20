#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

int queue[MAX];
int front=0, rear= -1;
int count= 0;

int size()  //finds the number of elements in the queue
{
    return count;
}

bool isEmpty()   //checks if the queue is empty
{
    return count==0;
}

bool isFull()    //checks if the queue is full
{
    return count==MAX;
}

void insertval(int value) //inserts a value into the queue
{
    if(!isFull())
    {
        if(rear==MAX - 1)
        {
            rear= -1;
        }
        queue[++rear]= value;
        count++;
    }
    else
    {
        printf("Queue is full");
    }
}

int peek()  //displays the first value in he queue
{
    return queue[front];
}

int deleteval()  //a function to delete a value at front of the queue
{
    int value= queue[front++];
    if(front==MAX)
    {
        front = 0;
    }
    count--;
    return value;
}

 int main()
 {
     int i;
   insertval(4);
   insertval(9);
   insertval(14);
   insertval(1);
   insertval(20);
   insertval(12);
   insertval(5);
   insertval(10);
   insertval(23);
   insertval(34);

   if(isFull())
   {
       printf("The queue is full!! ");
   }
   printf("\n\n");

    printf("Values in the queue are:\n");
    printf("Index\t Value\n");
    for(int i=0; i<MAX; i++)
    {
        printf(" %d\t", i);
        printf(" %d\n", queue[i]);
    }

   printf("\n\n");

   int len;
   len=size();
   printf("The size of the queue is: %d\n", len);
   printf("\n\n");

   int val;
    val =deleteval();
   printf("The value that was deleted is: %d\n", val);
    printf("\n\n");

     peek();
     printf("The element at the front of the queue is: %d\n", peek());


return 0;
}



