import java.util.Scanner;
class second_largest
{
    public static void main(String[] args) 
    {
        Scanner var = new Scanner(System.in);
        try
        {
            System.out.print("Enter a number: ");
            int n = var.nextInt();
            int i;
            int[] arr = new int[n];
            for(i = 0 ; i < n ; i++)
            {
                System.out.print("Enter an element: ");
                arr[i] = var.nextInt();
            }
            int largest = arr[0], second_largest = arr[0];
            for(i = 0 ; i < n ; i++)
            {
                if(arr[i] > largest)
                {
                    largest = arr[i];
                }
            }
            for(i = 0 ; i < n ; i++)
            {
                if(arr[i] > second_largest && arr[i] != largest)
                {
                    second_largest = arr[i];
                }
            }
            System.out.print("\nSecond Largest Number: " + second_largest);
        }
        finally
        {
            var.close();
        }
    }
}