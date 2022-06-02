import java.util.Scanner;
public class switch_case
{
    public static void main(String[] args)
    {
        Scanner var= new Scanner(System.in);
        System.out.println("Enter the number: ");
        int num= var.nextInt();
        String day=switch(num)
        {
            case 1,2,3,4,5->"Working Day";
            case 6,7->"Holiday";
            default->"Invalid Day";
        };
        System.out.println(day);
    }
}