import java.util.*;
class iterating_linked_list
{
    public static void main(String[] args) 
    {
        LinkedList<String> l = new LinkedList<String>();
        l.add("Sanskriti");
        l.add("is");
        l.add("a");
        l.add("student");
        l.add("of");
        l.add("UPES");
        //USING GET METHOD AND FOR LOOP
        for(int i=0 ; i < l.size(); i++)
        {
            System.out.print(" " + l.get(i));
        }
        System.out.println();
        // USING THE FOR EACH LOOP
        for(String str: l)
        {
            System.out.println(str + " ");
        }
    }
}