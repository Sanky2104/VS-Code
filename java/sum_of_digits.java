import java.util.Scanner;
public class sum_of_digits
{
    public static void main(String[] args) 
    {
        Scanner var = new Scanner(System.in);
        System.out.print("\nEnter a number: ");
        int num = var.nextInt();
        int i,count=0,sum=0, dig;
        while(num!=0)
        {
            count++;
            num/=10;
        }
        System.out.println("Number of digits: " + count);
        for(i=0; i<count; i++)
        {
            dig = num % 10;
        }
        var.close();
    }
}