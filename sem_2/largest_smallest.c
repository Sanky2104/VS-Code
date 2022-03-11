//Author: Sanskriti Gupta
//Date: 18 January 2022
//Aim: Find out the largest and smallest number in a given array
#include<stdio.h>
int largest(int *a, int n);
int smallest(int *a, int n);
int main()
{
int a[100],i,n,big,small;
printf("Enter the number of elements in the array: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	printf("Enter the element: ");
	scanf("%d",&a[i]);
}
big=largest(a,n);
small=smallest(a,n);
printf("The largest number in the array is: %d\n",big);
printf("The smallest number in the array is: %d\n",small); 
return 0;
}
int largest(int *a, int n)
{
int i,l=0;
for(i=0;i<n;i++)
{
	if(a[i]>l)
	{
		l=a[i];
	}
}
return l;
}
int smallest(int *a, int n)
{
int i,s=a[0];
for(i=0;i<n;i++)
{
	if(a[i]<s)
	{
		s=a[i];
	}
}
return s;
}