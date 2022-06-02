import java.util.Scanner;
public class user_input
{
    public static void main(String[] args)
    {
        Scanner var= new Scanner(System.in);
        System.out.println("Enter your name: ");
        String name= var.nextLine();
        System.out.println("Enter your age: ");
        int age =var.nextInt();
        System.out.println("Entered name: "+ name);
        if(age>=18)
        {
            System.out.println(name+" is allowed to vote");
        }
        else
        {
            System.out.println(name+" is NOT allowed to vote");
        }
    }
}