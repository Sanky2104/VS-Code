//YE WALA GALAT HAI 
import java.util.Scanner;
public class palindrome_strings
{
    public static void main(String[] args)
    {
        Scanner var = new Scanner(System.in);
        System.out.print("\nEnter a string: ");
        String str = var.nextLine();
        int n = str.length();
        int result = check_palindrome(str, n);
        if(result == 1)
        {
            System.out.print("\n" + str +" is a palindrome");
        }
        else
        {
            System.out.print("\n" + str + " is NOT a palindrome");
        }
        var.close();
    }
    public static int check_palindrome(String str, int n)
    {
        char[] ch = new char[n];
        char[] arr = new char[n];
        int i,top=0;
        for(i=0;i<n;i++)
        {
            ch[i] = str.charAt(i);
        }
        for(i=n-1;i>=0;i--)
        {
            arr[top] = ch[i];
            top++;
        }
        String original = String.copyValueOf(ch);
        String reversed = String.copyValueOf(arr);
        if(original == reversed)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}