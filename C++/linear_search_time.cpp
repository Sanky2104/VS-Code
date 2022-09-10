#include<iostream>
using namespace std;
int main()
{
    int n,item,count=0,i;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        a[i]=rand();
    }
    cout<<"Array: ";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\nItem to be searched: ";
    cin>>item;
    clock_t start=clock();
    for(i=0;i<n;i++)
    {
        if(a[i]==item)
        {
            break;
        }
        else
        {
            count++;
        }
    }
    clock_t stop=clock();
    double time_spent=0.0;
    time_spent += (double)(stop-start)/CLOCKS_PER_SEC;
    if(count==n)
    {
        cout<<"No such element";
    }
    else
    {
        cout<<item<<" is present on the index: "<<count;
    }
    printf("\nTime elapsed: %f seconds",time_spent);
    return 0;
}