import java.util.Scanner;
public class fibonacci_series
{
    public static void main(String[] args)
    {
        Scanner var = new Scanner(System.in);
        System.out.print("\nEnter a number: ");
        int num = var.nextInt();
        fibonacci(num);
        var.close();
    }
    public static void fibonacci(int n)
    {
        int a=0, b=1, c=1, i;
        System.out.print(a+" "+b + " ");
        for(i = 1 ; i < n-1 ; i++)
        {
            c = a + b;
            a = b;
            b = c;
            System.out.print(c+ " ");
        }
    }
}