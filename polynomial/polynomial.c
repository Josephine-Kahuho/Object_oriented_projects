#include <stdio.h>

struct poly
{
    int coef;
    int expon;
};

struct poly pol1[10], pol2[10], pol3[10];  //declare 3 arrays of type structure poly.

int readPoly(struct poly[]);                                        //function prototypes
int addPoly(struct poly[], struct poly[], int, int, struct poly[]);
void display(struct poly[], int terms);

int readPoly(struct poly pol[10])
{
    int term1,i;
    printf("Enter the number of elements in your polynomial:\n");
    scanf("%d", &term1);
    printf("Enter the Coefficient and Exponent:");
    for(i=0; i<term1; i++)
    {
        printf("Enter the Coefficient (%d):", i+1);
        scanf("%d", &pol[i].coef);
        printf("Enter the Exponent (%d):", i+1);
        scanf("%d", &pol[i].expon);
    }
    return (term1);
}

int addPoly(struct poly pol1[10], struct poly pol2[10],int term1,int term2, struct poly pol3[10])
{
    int j,k,n;
    j=0; k=0; n=0;
    while(j<term1 && k<term2)
    {
        if (pol1[j].expon== pol2[k].expon)
        {
            pol3[n].coef= pol1[j].coef + pol2[k].coef;
            pol3[n].expon= pol1[j].expon;
            j++; k++; n++;
        }
        else if(pol1[j].expon>pol2[k].expon)
                {
                    pol3[n].coef= pol1[j].coef;
                    pol3[n].expon= pol1[j].expon;
                    j++; n++;
                }
        else
        {
            pol3[n].coef= pol2[k].coef;
            pol3[n].expon= pol2[k].expon;
            k++; n++;
        }
    }

    while(j<term1)   //for the rest above terms of polynomial 1
    {
        pol3[n]= pol1[j].coef;
        pol3[n].expon= pol1[j].expon;
        j++; n++;
    }

    while(k<term1)   //for the rest above terms of polynomial 1
    {
        pol3[n]= pol2[k].coef;
        pol3[n].expon= pol2[k].expon;
        k++; n++;
    }
 return (n);
}

void display(struct poly pol[10], int term)
{
    int m;
    for(m=0; m<term-1; m++)
    {
        printf("%d(x^%d)",pol[m].coef, pol[m].expon);
        printf("%d(x^%d)", pol[term-1].coef, pol[term-1].expon);
    }
}

int main()
{
    int term1, term2, term3;

    term1= readPoly(pol1);
    printf("The first polynomial:");
    display(pol1, term1);
    printf("\n\n");

    term2= readPoly(pol2);
    printf("The second polynomial:");
    display(pol2, term2);
    printf("\n\n");

    term3= readPoly(pol3);
    printf("The result of the addition of the polynomials:");
    display(pol3, term3);

  return 0;
}
