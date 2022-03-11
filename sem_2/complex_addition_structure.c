//Author: Sanskriti Gupta
//Date: 18 January 2022
//Aim: Add 2 complex numbers by passing structure to a function as argument. 
#include<stdio.h>
struct complex
{
	int real;
	int imag;
};
void add_com(struct complex *number);
int main()
{
struct complex number[2];
struct complex *ptr;
ptr=number;
int i;
for(i=0;i<2;i++)
{
	printf("Enter the real part: ");
	scanf("%d",&number[i].real);
	printf("Enter the imaginary part: ");
	scanf("%d",&number[i].imag);
}
add_com(number);
return 0;
}
void add_com(struct complex *number)
{
int a=number[0].real + number[1].real;
int b=number[0].imag + number[1].imag;
printf("Sum: %d + %di\n",a,b);
}