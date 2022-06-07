import java.util.Scanner;
public class user_array
{
    public static void main(String[] args)
    {
        int[] arr= new int[5];
        int sum=0;
        Scanner var= new Scanner(System.in);
        int i=0;
        for(i=0;i<5;i++)
        {
            System.out.print("Enter: ");
            arr[i]=var.nextInt();
        }
        System.out.println("The array is: ");
        for(i=0;i<5;i++)
        {
            System.out.print(arr[i]+" ");
            sum+=arr[i];
        }
        System.out.println("\nThe sum of the array is: "+sum);
        var.close();
    }
}