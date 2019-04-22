//initial position=50 tracks are 55,58,60,70,18,90,150,160,184
#include<stdio.h>
#include<math.h>
int main()
{
	int n=10,max=199,track[10],dist[10],temp,i,j,min1,max1=10000,currt=50,thm=0,st=0,a,b;
	for(i=0;i<10;i++)
	scanf("%d",&track[i]);
	for(i=0;i<10;i++){
	for(j=0;j<10;j++)
	{
		if(track[i]<track[j])
		{
			temp=track[i];
			track[i]=track[j];
			track[j]=temp;
		}
	}
}
for(i=0;i<10;i++)
	if(track[i]>currt){
		min1=track[i];break;
	}
for(i=0;i<10;i++)
	if(track[i]<currt)
		max1=track[i];
a=min1;
b=max1;
min1=abs(min1-currt);
max1=abs(max1-currt);
printf("%d %d\n",min1,max1);
if(min1<max1)
thm=(max-currt)+(max)+b;
else
thm=(currt)+max+(max-a);
printf("%d",thm);
st=thm*5;
printf("seek time=%d",st);
}

