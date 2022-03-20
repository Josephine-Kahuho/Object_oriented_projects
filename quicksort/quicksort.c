#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int quick[MAX]= {6,4,7,3,2};

void println(int count)
{
    int k;
    for(k=0; k<count-1; k++)
    {
        printf("=");
    }
    printf("=\n");
}

void display()
{
    int m;
    printf("[");
    for(m=0; m<MAX; m++)
    {
        printf("%d", quick[m]);
    }
    printf("]\n");
}

 int partition(int left, int right, int pivot)
 {
     int leftptr= left-1;
     int rightptr= right;

     while(true)
     {
         while(quick[leftptr++])
          {}
          while(rightptr >0 && quick[rightptr--] > pivot)
            {}
         if(leftptr>= rightptr)
         {
             break;
         }
         else
         {
             printf("\nThe item swapped is: %d, %d", quick[leftptr], quick[rightptr]);
             swapval(leftptr, rightptr);
         }
     }
     printf("\nThe pivot swapped is :%d,%d", quick[leftptr], quick[rightptr]);
     swap(leftptr, right);
     printf("\nThe updated array is:");
     display();
     return leftptr;
 }

 void quicksort(int left, int right)
 {
     if(right-left <=0)
     {
         return;
     }
     else
     {
         int pivot= quick[right];
         int partitionpstn= partition(left, right, pivot);
         quicksort(left, partitionpstn-1);
         quicksort(partitionpstn+1, right);
     }
 }

 int main()
 {
     printf("\nEnter the values in the quick array:");
     display();
     println(30);
     quicksort(0, MAX-1);
     printf("\nThe output array is:");
     display();
     println(30);
 }
