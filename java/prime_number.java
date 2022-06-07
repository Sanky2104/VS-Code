import java.util.Scanner;

import javax.lang.model.util.ElementScanner14;
public class prime_number
{
    public static void main(String[] args) 
    {
        Scanner var = new Scanner(System.in);
        System.out.print("\nEnter a number: ");
        int num = var.nextInt();
        int x = check_prime(num);
        if(x == 0 && num % 2 == 0)
        {
            System.out.println(num + " is prime and even.");
        }
        else if(x == 0 &&  num % 2 !=0)
        {
            System.out.println(num + " is prime and odd");
        }
        else if(x !=0 && num %2==0)
        {
            System.out.println(num + " is NOT prime and even.");
        }
        else 
        {
            System.out.println(num + " is NOT prime and odd.");        
        }
        var.close();
    }
    public static int check_prime(int n)
    {
        int i,flag=0;
        if(n == 0 || n == 1)
        {
            return 0;
        }
        else if(n == 2)
        {
            return 0;
        }
        else
        {
            for(i = 2 ; i <= n/2 ; i++)
            {
                if(n % i == 0)
                {
                    flag++;
                }
            }
        }
        return flag;
    }
}