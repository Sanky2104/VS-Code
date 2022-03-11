//Author: Sanskriti Gupta
//Date: 18 January 2022
//Aim: Store 'n' numbers(integers or real) in an array in ascending or descending order. Conduct a binary search for a given number and and report succes or failure in the form of a suitable message
#include<stdio.h>
void search(int *a,int n, int num);
int main()
{
int a[100];
int n,i,num;
printf("Enter the number of elements in the array: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	printf("Enter the element: ");
	scanf("%d",&a[i]);
}
printf("Enter the element to be searched: ");
scanf("%d",&num);
search(a,n,num);
return 0;
}
void search(int *a, int n, int num)
{
int s=0,e=n-1,count=0,mid;
mid=(s+e)/2;
while(s<=e)
{
	if(num==a[mid])
	{
		printf("\nThe given number is present at the position: %d\n",mid+1);
		count++;
		break;
	}
	else if(num<a[mid])
	{
		e=mid-1;
	}
	else
	{
		s=mid+1;
	}
	mid=(s+e)/2;
}
if(count==0)
{
	printf("The given number is not present in the array.\n");
}
}