import java.util.Scanner;
public class strings
{
    public static void main(String[] args)
    {
        Scanner var= new Scanner(System.in);
        System.out.println("Enter any string: ");
        String str= var.nextLine();
        int i=0;
        for(i=0;i<str.length();i++)
        {
            System.out.print(str.charAt(i)+" ");
        };
    }
}