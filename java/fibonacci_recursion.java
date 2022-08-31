import java.util.Scanner;
public class fibonacci_recursion 
{
    public static void main(String[] args) 
    {
        Scanner var = new Scanner(System.in);
        try
        {
            int n, i, m = 0;
            System.out.print("\nEnter total number of terms: ");
            n = var.nextInt();
            System.out.print("Fibonacci Series: ");
            for(i = 1 ; i <= n ; i++)
            {
                System.out.print(fib_recur(m) + " ");
                m++;
            }
        }
        finally
        {
            var.close();
        }
    }
    public static int fib_recur(int n)
    {
        if(n == 0 || n == 1)
        {
            return n;
        }
        else
        {
            return (fib_recur(n - 1) + fib_recur(n - 2));
        }
    }
}