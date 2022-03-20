/*P15/1220/2018  KAHUHO JOSEPHINE WANJIRU
A program that adds two nxn matrices*/

#include<stdio.h>
#define M 3

/*A function that adds two matrices, A[][] and B[][],and stores the result of the addition in C[][]*/
void addmatrix(int A [][M],int B [][M], int C[][M])
{
    int i,j;
    for(i=0;i<M; i++)
        for(j=0; j<M; j++)
        C[i][j]=A[i][j]+B[i][j];
}

int main()
{
    int i,j;
    int A[M][M], B[M][M];
    int C[M][M];
    printf("Enter the elements of the first matrix:\n");
      for(i=0;i<M;i++)
      {
          for(j=0;j<M;j++)
          {
              scanf("%d", &A[i][j]);
          }
      }

      printf("The first matrix is:\n\n");
         for(i=0;i<M;i++)
      {
          for(j=0;j<M;j++)
          {
              printf("%d\t", A[i][j]);
          }
          printf("\n");
      }

      printf("Enter the elements of the second matrix:\n");
         for(i=0;i<M;i++)
         {
             for(j=0;j<M;j++)
             {
                 scanf("%d", &B[i][j]);
             }
             printf("\n");
         }


            printf("The second matrix is:\n\n");
               for(i=0;i<M;i++)
         {
             for(j=0;j<M;j++)
             {
                 printf("%d\t", B[i][j]);
             }
             printf("\n");
         }



         addmatrix(A,B,C);
          scanf("%d", &C[i][j]);
          printf("The result of the summation of the two matrices is:\n");
             for(i=0;i<M;i++)
             {
                 for(j=0;j<M;j++)
                 {
                     printf("%d\t", C[i][j]);
                 }
                 printf("\n");
             }
    return 0;

}
