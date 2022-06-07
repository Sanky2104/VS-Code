import java.util.Scanner;
public class palindrome
{
    public static void main(String[] args) 
    {
        Scanner var = new Scanner(System.in);
        System.out.print("\nEnter a number: ");
        int num = var.nextInt();
        int x = check_palindrome(num);
        if(x == 1)
        {
            System.out.println("Thus, Its a palindrome");
        }
        else
        {
            System.out.println("Thus, Its NOT a palindrome");
        }
        var.close();    
    }
    public static int check_palindrome(int num)
    {
        if(num>=0 && num<=9)
        {
            System.out.println("The reversed string is: " + num);
            return 1;
        }
        else
        {
            String str = String.valueOf(num);
            int l = str.length();
            char[] arr = new char[l];
            int i,flag=0;
            for(i=l-1;i>=0;i--)
            {
                arr[l-1-i]=str.charAt(i);
            }
            String new_string = String.copyValueOf(arr);
            System.out.println("The reversed string is: " + new_string);
            for(i=0;i<l;i++)
            {
                if(arr[i] == str.charAt(i))
                {
                    flag++;
                }
                else
                {
                    flag--;
                }
            }
            if(flag==l)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}