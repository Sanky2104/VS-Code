import java.util.Scanner;
public class only_odd_numbers
{
    public static void main(String[] args)
    {
        Scanner var = new Scanner(System.in);
        int n,i,count=0;
        System.out.print("\nEnter the length of the array: ");
        n = var.nextInt();
        int l = n;
        int[] arr = new int[n];
        for(i=0;i<n;i++)
        {
            System.out.print("Enter the numbers: ");
            arr[i] = var.nextInt();
        }
        while(n>=1)
        {
            if (arr[n-1]%2!=0)
            {
                count++;
            }
            n--;
        }
        if(count==l)
        {
            System.out.print("\nAll are odd numbers");
        }
        else
        {
            System.out.print("\nEven number present !!!");
        }
        var.close();
    }
}