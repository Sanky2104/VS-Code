#include <stdio.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h>     // for sleep()
 
// main function to find the execution time of a C program
int main()
{
    int n, temp,i;
    // to store the execution time of code
    double time_spent=0.0;
    time_t now=time(NULL);
 
    // do some stuff here
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    for(i=0 ; i<n ; i++)
    {
        temp = rand();
        a[i] = temp;   
    }
    printf("\nArray: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
 
    time_t now2 = time(NULL)-now;
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(now2) / CLOCKS_PER_SEC;
 
    printf("\nThe elapsed time is %f seconds", time_spent);
 
    return 0;
}


void timeExecution(){
    double time_spent = 0.0;
 
    clock_t begin = clock();
 
    // do some stuff here
    sleep(3);
 
    clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds", time_spent);
 
}