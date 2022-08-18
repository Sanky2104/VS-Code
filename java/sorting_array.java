import java.util.Scanner;
public class sorting_array
{
    public static void main(String[] args)
    {
        Scanner var = new Scanner(System.in);
        try
        {
            System.out.print("\nEnter a number: ");
            int n = var.nextInt();
            int[] arr = new int[n];
            int i=0;
            for(i=0;i<n;i++)
            {
                System.out.print("\nEnter the number: ");
                arr[i] = var.nextInt();
            }
            System.out.print("\nOriginal Array: ");
            for(i=0;i<n;i++)
            {
                System.out.print(arr[i] + " ");
            }
            for(i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(arr[i]>arr[j])
                    {
                        int key = arr[i];
                        arr[i] = arr[j];
                        arr[j] = key;
                    }
                }
            }
            System.out.print("\nSorted Array: ");
            for(i=0;i<n;i++)
            {
                System.out.print(arr[i]+ " ");
            }
        }
        finally
        {
            var.close();
        }
    }
}