
//YE WALA GALAT HAI, NUMBER OF DIGITS SAHI HAI BUT SUM OF DIGITS GALAT HAI

import java.util.Scanner;
import java.lang.Math;
public class sum_of_digits
{
    public static void main(String[] args) 
    {
        Scanner var = new Scanner(System.in);
        try
        {
            System.out.print("\nEnter a number: ");
            int num = var.nextInt();
            int original = num;
            int i,count = 0 , sum = 0 , dig;
            while(num != 0)
            {
                count++;
                num/=10;
            }
            System.out.println("Number of digits: " + count);
            for(i = 0 ; i < count ; i++)
            {
                dig = (int)(original % (Math.pow(10,count-(i-1))));
                sum = sum + dig;
            }
            System.out.println("Sum of digits: " + sum);
        }
        finally
        {
            var.close();
        }
    }
}