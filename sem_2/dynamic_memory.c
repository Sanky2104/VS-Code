//Author: Sanskriti Gupta
//Date:25 January 2022
//Aim: Design a structure 'subject' to store the details of the subject like subject name and subject code. Using structure pointer allocate memory for the structure dynamically so as to obtain details of 'n' subjects using for loop
#include<stdio.h>
#include<stdlib.h>
int main()
{
struct subject
{
	char name[20];
	int id;
};
int n,i;
printf("Enter the number of subjects: ");
scanf("%d",&n);
struct subject* sub=(struct student*)malloc(n*sizeof(struct subject));
for(i=0;i<n;i++)
{
	printf("Enter subject name: ");
	scanf("%s",sub[i].name);
	printf("Enter subject ID: ");
	scanf("%d",&sub[i].id);
}
return 0;
}