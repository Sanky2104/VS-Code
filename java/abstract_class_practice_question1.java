abstract class Parent
{
    abstract void message();
}
class SubClass1 extends Parent
{
    @Override
    void message()
    {
        System.out.println("This is first subclass");
    }
}
class  SubClass2 extends Parent
{
    @Override
    void message()
    {
        System.out.println("This is second subclass");
    }
}
public class abstract_class_practice_question1 
{
    public static void main(String[] args) 
    {
        Parent s1 = new SubClass1();
        s1.message();
        SubClass2 s2 = new SubClass2();
        s2.message();
    }
}