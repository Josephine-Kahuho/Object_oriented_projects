#include <stdio.h>

int main()
{
    int i, *pi;
    float f, *pf;
    pi= (int*) malloc(sizeof(int));  //requests memory allocation
    pf=(float*) malloc(sizeof(float));
    *pi=1024;
    *pf=3.14;
    printf("An integer=%d, A float=%.2f\n", *pi, *pf);
    free(pi);  //deallocates previously allocated memory
    free(pf);
  return 0;
}
