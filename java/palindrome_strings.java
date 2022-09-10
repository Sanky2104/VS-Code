import java.util.Scanner;
public class palindrome_strings
{
    public static void main(String[] args)
    {
        Scanner var = new Scanner(System.in);
        try
        {
            String str;
            System.out.print("\nEnter a string: ");
            str = var.nextLine();
            int i = string_palindrome(str);
            if(i==1)
            {
                System.out.print("\n" + str + " is a Palindrome");
            }
            else
            {
                System.out.print("\n" + str + " is NOT a palindrome");
            }
        }
        finally
        {
            var.close();
        }
    }
    public static int string_palindrome(String str)
    {
        char[] reverse = new char[str.length()];
        int i,count=0;
        for(i=0;i<str.length();i++)
        {
            reverse[i] = str.charAt(str.length()-i-1);
        }
        String rev = new String(reverse);
        System.out.print("\nReverse String: " + rev);
        for(i=0;i<str.length();i++)
        {
            if(reverse[i] == str.charAt(i))
            {
                count++;
            }
        }
        if(count == str.length())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}