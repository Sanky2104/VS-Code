public class object
{
    public static void main(String[] args)
    {
        object obj = new object();
        obj.hello();
        System.out.println(args[0] + " " + args[1]);
    }
    void hello()
    {
        System.out.println("\nHello, World !!!");
    }
}