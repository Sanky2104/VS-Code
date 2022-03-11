//Author: Sanskriti Gupta
//Date: 18 January 2022
//Aim: Store 'n' numbers (integers or real) in an array. Conduct a linear search for a given number and report success or failure in the form of a suitable message.
#include<stdio.h>
void search(float *a,float num, int n);
int main()
{
int n,i;
float a[100],num;
printf("\nEnter the number of elements in the array: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	printf("Enter the element: ");
	scanf("%f",&a[i]);
}
printf("The array: ");
for(i=0;i<n;i++)
{
	printf("%f ",a[i]);
}
printf("\nEnter the number to be searched: ");
scanf("%f",&num);
search(&a,num,n);
return 0;
}
void search(float *a, float num, int n)
{
int i,count=0;
for(i=0;i<n;i++)
{
	if(num==a[i])
	{
		count+=1;
	}
	else
	{
		continue;
	}
}
if(count==0)
{
	printf("\nThe searched element is NOT present in the array\n");
}
else
{
	printf("\nThe element to be searched is present in the array.\n");
}
}