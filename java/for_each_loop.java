import java.util.Scanner;
public class for_each_loop
{
    public static void main(String[] args) 
    {
        Scanner var = new Scanner(System.in);
        try
        {
            System.out.print("Enter the number of elements in the array: ");
            int n=var.nextInt();
            int[] arr=new int[n];
            int i=0;
            System.out.print("\nEnter the elements: ");
            for(i=0;i<n;i++)
            {
                arr[i]=var.nextInt();
            };
            System.out.println("The entered elements are: ");
            for(int t: arr)
            {
                System.out.print(t+" ");
            }
        }
        finally
        {
            var.close();
        }
    }
}