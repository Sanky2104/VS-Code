import java.util.*;
public class first_linked_list
{
    public static void main(String[] args) 
    {
        LinkedList<Integer> ll = new LinkedList<Integer>();
        ll.add(1);
        ll.add(2);
        ll.add(3);
        ll.add(4);
        ll.add(2,5);
        System.out.println(ll);
        ll.remove(2);
        ll.remove(3);
        ll.removeFirst();
        ll.removeLast();
        System.out.println(ll);
    }
}