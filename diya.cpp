#include<stdio.h>
#include<stdlib.h>
int *arr;
int *arr2;
int *diya;
int sum=0;
void read_values(int n,int *p)
{
                int i;
                for(i=0;i<n;i++)
                {
                                printf("\nenter value %d:",i);
                                scanf("%d",&p[i]);
                }
}
void collect_values(int *p1,int *p2,int low, int n)
{
                
                int i;
                for(i=0;i<n;i++)
                {
                                p1[low+i]=p2[i];
                                sum+=p1[low];
                                printf("%d ",p1[low]);
                }
                
}
int main()
{
                int n,m;
                printf("enter no of values for Riya");
                scanf("%d",&n);
                arr=(int*)malloc(sizeof(int)*n);
                printf("please enter %d values",n);
                read_values(n,arr);

                printf("enter no of values for Siya");
                scanf("%d",&m);
                arr2=(int*)malloc(sizeof(int)*m);
                printf("please enter %d values",m);
                read_values(m,arr2);
                diya=(int*)malloc(sizeof(int)*n);
                collect_values(diya,arr,0,n);
                diya=(int*)realloc(diya,sizeof(arr2));
                collect_values(diya,arr2,n,m);
                printf("\ntotal sum is %d",sum);
                free(arr);
                free(arr2);
                free(diya);
                return 0;
}

