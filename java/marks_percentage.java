import java.util.Scanner;
public class marks_percentage
{
    public static void main(String[] args) 
    {
        Scanner var = new Scanner(System.in);
        try
        {
            int[] arr = new int[5];
            int i, sum = 0;
            for(i = 0 ; i < 5 ; i++)
            {
                System.out.print("\nEnter the marks: ");
                arr[i] = var.nextInt();
                sum += arr[i];
            }
            System.out.print("\nEnter the maximum marks: ");
            int max = var.nextInt();
            float per = ((float)sum/(max*5)) * 100;
            System.out.print("\nTotal marks: " + sum);
            System.out.print("\nPercentage: " + per + " %");
        }
        finally
        {
            var.close();
        }
    }
}