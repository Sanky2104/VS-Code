import java.util.Scanner;
import java.lang.Character;
public class number_of_words
{
    public static void main(String[] args)
    {
        Scanner var = new Scanner(System.in);
        System.out.print("\nEnter any sentence: ");
        String sen = var.nextLine();
        int num = no_of_words(sen);
        System.out.print("\nNumber of words: " + num);
        var.close();
    }
    public static int no_of_words(String sen)
    {
        int i, count = 1;
        int n = sen.length();
        char[] arr = new char[n];
        for(i=0;i<n;i++)
        {
            arr[i] = sen.charAt(i);
        }
        for(i=0;i<n;i++)
        {
            if(Character.isWhitespace(arr[i]))
            {
                count++;
            }
        }
        return count;
    }
}