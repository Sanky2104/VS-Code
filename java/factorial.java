import java.util.Scanner;
public class factorial
{
    public static void main(String[] args)
    {
        Scanner var = new Scanner(System.in);
        System.out.print("\nEnter a number: ");
        int n = var.nextInt();
        System.out.print("\nFactorial of " + n + " is: " + fact(n));
        var.close();
    }
    public static int fact(int n)
    {
        if(n == 1 || n == 0)
        {
            return 1;
        }
        else
        {
            return (n*fact(n-1));
        }
    }
}