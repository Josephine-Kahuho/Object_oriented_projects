#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct link{
    int coeff;
    int expon;
    struct link *next;
};

 struct link *poly1=NULL, *poly2=NULL, *poly3= NULL;
void create(struct link *node)        //creates a polynomial of type link
{
    char response;
    do   //allows you to enter the values of the polynomial if your answer is a yes
    {
        printf("\n Enter the value of the coefficient:");
        scanf("%d", &node->coeff);
        printf("\n Enter the value of the exponent:");
        scanf("%d", &node->expon);
        node->next= (struct link*)malloc(sizeof(struct link));
        node= node->next;
        node->next= NULL;
        printf("\n Continue(y/n):");
        response= getch();
    }
    while(response=='y' || response=='Y');
}

void display(struct link *node)   //displays the values entered in the polynomial as an expression
{
    while(node->next !=NULL)
    {
        printf("%dx^%d", node->coeff, node->expon);
        node= node->next;
        if(node->next !=NULL)
            printf("+");
    }
}

void polyadd(struct link *poly1, struct link *poly2, struct link *poly3)  //adds the two polynomials input and stores them in a third polynomial
{
    while(poly1->next && poly2->next)
    {
        if(poly1->expon > poly2->expon)
        {
            poly3->expon = poly1->expon;
            poly3->coeff = poly1->coeff;
            poly1= poly1->next;
        }
        else if(poly1->expon < poly2->expon)
        {
             poly3->expon = poly2->expon;
            poly3->coeff = poly2->coeff;
            poly2= poly2->next;
        }
        else
        {
            poly3->expon = poly1->expon;
            poly3->coeff = poly1->coeff + poly2->coeff;
            poly1= poly1->next;
            poly2 = poly2->next;
        }
        poly3->next= (struct link*)malloc(sizeof(struct link));
        poly3= poly3->next;
        poly3->next= NULL;
    }

    while(poly1->next || poly2->next)
    {
        if(poly1->next)
        {
            poly3->expon= poly1->expon;
            poly3->coeff= poly1->coeff;
            poly1= poly1->next;
        }

       if(poly2->next)
       {
           poly3->expon= poly2->expon;
           poly3->coeff= poly2->coeff;
           poly2= poly2->next;
       }
       poly3->next= (struct link*)malloc(sizeof(struct link));
       poly3= poly3->next;
       poly3->next= NULL;
    }
}

int main()
    {
        char response;
        do      //allows you to continue entering values in that polynomial if you type in a yes. if no, you go to the second polynomial
        {
            poly1=(struct link*)malloc(sizeof(struct link));
            poly2=(struct link*)malloc(sizeof(struct link));
            poly3=(struct link*)malloc(sizeof(struct link));
            printf("\n Enter the first polynomial:");
            create(poly1);
            printf("\n Enter the second polynomial:");
            create(poly2);
            printf("\nFirst number:");
            display(poly1);
            printf("\n\nSecond number:");
            display(poly2);
            polyadd(poly1, poly2, poly3);
            printf("\n\nSum of the two polynomials is:");
            display(poly3);
            printf("\nAdd more numbers:");   //if you wan to add more numbers to your polynomial, type y. if no type no to end the program
            response= getch();
        }
        while(response=='y' || response=='Y');

}
