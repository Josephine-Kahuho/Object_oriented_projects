# include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
 {
     char data;
     int key;
     struct node *next;
 };

 struct node *head = NULL;
 struct node *curr = NULL;

 //insert link
 void insertval(int key, char data)
 {
     struct node *link = (struct node*) malloc(sizeof(struct node)); //creating a link and allocating memory space
     link ->key = key;
     link->data = data;
     link->next = head;  //points it to the old first node
     head = link;       //points to first new node
 }

 //print out the list
 void prntList()
 {
     struct node *ptr = head;
     printf("\n[");

     while(ptr !=NULL)
     {
         printf("(%d, %s)", ptr->key,ptr->data);
         ptr = ptr->next;
     }
     printf("]");

 }

 //checking if the list is empty
 bool isEmpty()
 {
     return head == NULL;
 }

 //check length of the list
      int length()
      {
          int length = 0;
          struct node *curr;
          for(curr= head; curr!=NULL; curr= curr->next)
          {
              length++;
          }
          return length;
      }

 //delete the first item in the link
 struct node *deletFirst()
 {
     struct node *temp = head;  //save the reference of the first link
     head= head->next;   //mark the next link to the first one as the first link

     return temp;  //return the deleted link
 };

 //delete a link when specified for a key
 struct node *delete(int key)
 {
     struct node *curr =head; //start looking from the first link
     struct node *prev= NULL;

     if(head== NULL)   //check if key is empty
     {
         return NULL;
     }

     while(curr->key != key)
     {
         if(curr->next== NULL)
         {
             return NULL;
         }
         else
         {
             prev= curr;
             curr= curr->next;
         }
     }
     if(curr== head)
     {
         head= head->next;
     }
     else
     {
         prev->next= curr->next;
     }
     return curr;
 };

 void main()
 {
     int i;

   insertval(1, 'A');
   insertval(2,'B');
   insertval(3, 'C');
   insertval(4, 'D');
   insertval(5, 'E');
   insertval(6, 'F');
   insertval(7, 'G');
   insertval(8, 'H');
   insertval(9, 'L');
   insertval(10, 'M');
   insertval(11, 'N');
   insertval(12, 'P');

   printf("\nValues in the list are: ");
   prntList();

  for(i=0; i<=2; i++)
   {
       struct node *temp = deletFirst();
       printf("\n\nDeleted value:");
       printf("(%d, %s)", temp->key, temp->data);
   }
   printf("\n\n");

   printf("\nThe current list is:");
   prntList();
 }
