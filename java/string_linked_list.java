import java.util.*;
class string_linked_list
{
    public static void main(String[] args) 
    {
        LinkedList<String> l = new LinkedList<String>();
        l.add("Sanskriti");
        l.add("Gupta");
        System.out.println(l);
        l.remove(0);
        System.out.println(l);    
    }
}