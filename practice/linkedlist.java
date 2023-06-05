//package practice;
import java.util.Scanner;
import java.lang.System;
public class linkedlist
{
    public static class Node
    {
        int data;
        Node next;
        Node()
        {
            this.next = null;
        }
    }
    public static Node start;
    public static Node temp;
    static class ll_functions
    {
        void ins_beg(int data)
        {
            Node n = new Node();
            n.data = data;
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
        void ins_end(int data)
        {
            Node n = new Node();
            n.data = data;
            if(start==null)
            {
                start = n;
            }
            else
            {
                temp = start;
                while(temp.next!=null)
                {
                    temp = temp.next;
                }
                temp.next = n;
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
    }
    public static void main(String[] args)
    {
        int choice, data;
        Scanner sc = new Scanner(System.in);
        ll_functions ll = new ll_functions();
        while(true)
        {
            System.out.println("\n1.Insert at beg");
            System.out.println("2.Insert at end");
            System.out.println("3.Display");
            System.out.println("4.Exit");
            choice = sc.nextInt();
            switch(choice)
            {
                case 1:
                {
                    System.out.print("Enter the element to be inserted: ");
                    data = sc.nextInt();
                    ll.ins_beg(data);
                    break;
                }
                case 2:
                {
                    System.out.print("Enter the element to be inserted: ");
                    data = sc.nextInt();
                    ll.ins_end(data);
                    break;
                }
                case 3:
                {
                    ll.display();
                    break;
                }
                case 4:
                {
                    System.exit(0);
                }
            }
        }
    }
}