//Author: Sanskriti Gupta
//Aim: Create an array ‘a1’ with ‘n’ elements. Insert an element in ith position of ‘a1’ and also delete an element from jth position of ‘a1’.
#include <stdio.h>
void input(int *A, int n);
void AddIndex(int *A, int n);
void DeleteIndex(int *A , int n);
void display ( int *A , int n);
int main()
{
    int n;  // size of array
    printf("Enter the Size of Array: ");
    scanf("%d",&n);  
    int a1[n];
    input(a1, n);
    display(a1, n);
    DeleteIndex(a1, n);
    AddIndex(a1, n);
    display(a1, n);
    return 0;
}
void input(int *A, int n)   // function to input elements
{
    for(int i = 0; i < n; i++)  
    {
        printf("Enter a Number: ");  
        scanf("%d", &A[i]);
    }
}
void AddIndex(int *A, int n)  // function to add elemts
{
    int i, num;
    printf("Enter the position to add the index and the Number to add:\n");  
    scanf("%d %d", &i, &num );  // user input
    for(int k = n-1; k > i; k--)
    {
        A[k] = A[k-1];
    }
    A[i-1] = num;
}
void DeleteIndex(int *A , int n)  // function to delete the element of index
{
    int j;
    printf("\nEnter the position to delete the index:\n");  // accept the position to delete
    scanf("%d" , &j);
    for(int i = j-1; i < n-1; i++)
    {
        A[i] = A[i+1];
    }
}
void display ( int *A , int n)
{ 
    printf("The Array Elements are: \n");
    for(int i = 0; i < n; i++)  // display array
    {
        printf("%d ", A[i]);
    }
}