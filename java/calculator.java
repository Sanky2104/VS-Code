import java.util.Scanner;
public class calculator
{
    public static void main(String[] args) 
    {
        Scanner var = new Scanner(System.in);
        try
        {
            int a, b, result ;
            while(true)
            {
                System.out.print("\n1. Addition");
                System.out.print("\n2. Subtraction");
                System.out.print("\n3. Multiplication");
                System.out.print("\n4. Division");
                System.out.print("\n5. Exit\n");
                int choice = var.nextInt();
                switch(choice)
                {
                    case 1:
                    {
                        System.out.print("\nEnter the first number: ");
                        a = var.nextInt();
                        System.out.print("\nEnter the second number: ");
                        b = var.nextInt();
                        result = add(a,b);
                        System.out.print("\nSum of " + a + " and " + b + ": " + result + "\n");
                        break;
                    }
                    case 2:
                    {
                        System.out.print("\nEnter the first number: ");
                        a = var.nextInt();
                        System.out.print("\nEnter the second number: ");
                        b = var.nextInt();
                        result = subtract(a,b);
                        System.out.print("\nDifference of " + a + " and " + b + ": " + result + "\n");
                        break;
                    }
                    case 3:
                    {
                        System.out.print("\nEnter the first number: ");
                        a = var.nextInt();
                        System.out.print("\nEnter the second number: ");
                        b = var.nextInt();
                        result = multiply(a,b);
                        System.out.print("\nProduct of " + a + " and " + b + ": " + result + "\n");
                        break;
                    }
                    case 4:
                    {
                        System.out.print("\nEnter the first number: ");
                        a = var.nextInt();
                        System.out.print("\nEnter the second number: ");
                        b = var.nextInt();
                        float res = divide(a,b);
                        System.out.print("\nDivision of " + a + " and " + b + ": " + res + "\n");
                        break;
                    }
                    case 5:
                    {
                        System.exit(0);
                    }
                    default:
                    {
                        System.out.print("\nNo such choice !!!");
                    }
                }
            }
        }
        finally
        {
            var.close();
        } 
    }
    public static int add(int a, int b)
    {
        return (a+b);
    }
    public static int subtract(int a, int b)
    {
        return (a-b);
    }
    public static int multiply(int a, int b)
    {
        return (a*b);
    }
    public static float divide(int a, int b)
    {
        return ((float)a/b);
    }
}