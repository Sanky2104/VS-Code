import java.util.Scanner;
import java.lang.System;
public class doubly_linked_list 
{
    public static class Node
    {
        int data;
        public Node next;
        public Node prev;
        Node(int data)
        {
            this.data = data;
            this.next = null;
            this.prev = null;
        }
    }
    public static Node start;
    public static Node temp;
    static class doubly_ll_functions
    {
        void ins_beg(int data)
        {
            Node n = new Node(data);
            n.prev = start;
            if(start==null)
            {
                start = n;
            }
            else
            {
                n.next = start;
                start = n;
            }
        }
        void display()
        {
            if(start==null)
            {
                System.out.println("Empty list !!!");
            }
            else
            {
                temp = start;
                while(temp!=null)
                {
                    System.out.print(temp.data + " ");
                    temp = temp.next;
                }
            }
        }
        void display_reverse()
        {
            if(start==null)
            {
                System.out.println("Empty list !!!");
            }
            else
            {
                temp = start;
                while(temp.next!=null)
                {
                    temp = temp.next;
                }
                while(temp != start)
                {
                    System.out.print(temp.data + " ");
                    temp = temp.prev;
                }
            }
        }
    }
    public static void main(String[] args)
    {
        int choice,data;
        Scanner sc = new Scanner(System.in);
        doubly_ll_functions dll = new doubly_ll_functions();
        while(true)
        {
            System.out.println("\n1.Insert at beginning");
            System.out.println("2.Insert at end");
            System.out.println("3.Insert at position");
            System.out.println("4.Delete at beginning");
            System.out.println("5.Delete at end");
            System.out.println("6.Delete at position");
            System.out.println("7.Display in forward");
            System.out.println("8.Display in reverse");
            System.out.println("9.Exit");
            choice = sc.nextInt();
            switch(choice)
            {
                case 1:
                {
                    System.out.print("\nEnter the element: ");
                    data = sc.nextInt();
                    dll.ins_beg(data);
                    break;
                }
                case 7:
                {
                    dll.display();
                    break;
                }
                case 8:
                {
                    dll.display_reverse();
                    break;
                }
                case 9:
                {
                    System.exit(0);
                }
            }
        }
    }   
}