//Author: Sanskriti Gupta
//Aim: Create an array 'a1' with 'n' elements.
// a)Copy all elements of 'a1' into another array 'a2' using pointers. Display the contents of both the arrays using pointers.
// b)Merge the contents of 'a1' and 'a2' into a new array 'a3'  
#include <stdio.h>
void input(int *A, int n);
void display(int n, int A[n]);
void copy(int *A2, int n, int A1[n]);
void merge(int *A3, int n, int A1[n], int A2[n]);
int main()
{
    int n;
    printf("Enter the Size of array: ");
    scanf("%d", &n);
    int a1[n];  
    int a2[n];  
    int a3[n];  
    input((int *)a1, n); 
    printf("Array1 is :\n");    
    display(n, a1);  
    copy((int *)a2, n, a1); 
    printf("Array2 is :\n");    
    display(n, a2);  
    merge((int *)a3, n, a1, a2); 
    printf("Array3 is :\n");    
    display(n, a3);  
}
void input(int *A, int n)  // function to input data in the array
{
    for(int i = 0; i < n; i++)
    {
        printf("Enter a Number: ");
        scanf("%d", &A[i]);  // user input
    } 
}

void display(int n, int A[n])  // function to display data in the array
{
    for(int i = 0; i < n; i++)
    {
        printf("%d \t", A[i]);
    }
    printf("\n");
}
void copy(int *A2, int n, int A1[n])  // function to copy the datas of the array
{
    for(int i = 0; i < n; i++)
    {
        A2[i] = A1[i];
    }
}
void merge(int *A3, int n, int A1[n], int A2[n])  // function to merge the datas of the array
{
    for ( int i = 0; i < n; i++)
    {
        A3[i] = A1[i] + A2[i];
    }
}