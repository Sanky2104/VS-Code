//Author: Sanskriti Gupta
//Date: 25 January 2022
//Aim: Create an integer array of user defined size n1 with dynamic memory allocation. Store data after reading from keyboard. Expand the size of array with n2. Read new values (n2 values from keyboard). Print state of array with all (n1+n2) values.
#include<stdio.h>
#include<stdlib.h>
int main()
{
int n1,n2,i;
printf("Enter the number of elements: ");
scanf("%d",&n1);
int* arr=(int*)malloc((n1)*sizeof(int));
for(i=0;i<n1;i++)
{
	printf("Enter the element: ");
	scanf("%d",&arr[i]);
}
printf("Enter the new size of array: ");
scanf("%d",&n2);
arr=(int*)realloc(arr,(n2)*sizeof(int));
for(i=n1;i<n2;i++)
{
	printf("Enter the element: ");
	scanf("%d",&arr[i]);
}
for(i=0;i<n2;i++)
{
	printf("%d ",arr[i]);
}
printf("\n");
return 0;
}