#include <stdio.h>
#include "rand.h"
int main()
{
    FILE *fptr;
    fptr = fopen("random.txt","w");
    for (int i = 0; i < 10; i++)
    {
        fprintf(fptr, "%d", ownrand());
        fprintf(fptr, "\n");
    }
  return 0;
}

#HEADER FILE
#include <stdlib.h>
int ownrand()
{
  return rand()%10;
}


