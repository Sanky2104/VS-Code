import java.util.Scanner;
public class reverse_string
{
    public static void main(String[] args) 
    {
        Scanner var = new Scanner(System.in);
        System.out.print("\nEnter a string: ");
        String str = var.nextLine();
        String rev = reverse_the_string(str);
        System.out.println("Reversed String: " + rev);
        var.close();
    }
    public static String reverse_the_string(String str)
    {
        int n = str.length();
        int i;
        char[] new_arr = new char[n];
        for(i = n-1 ; i >= 0 ; i--)
        {
            new_arr[n-1-i] = str.charAt(i);
        }
        String rev = new String(new_arr);
        return rev;
    }
}