import java.util.Scanner;
public class sum_of_digits
{
	public static void main(String[] args) 
    {
        Scanner var = new Scanner(System.in);
        try
        {
            System.out.print("\nEnter a number: ");
            int num = var.nextInt();
            int sum=0, digit;
            while(num>0)
            {
                digit = num%10;
                sum=sum+digit;
                num=num/10;
            }
            System.out.print("\nSum of the digits: " + sum);
        }
        finally
        {
            var.close();
        }
	}
}
