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
        void ins_pos(int data, int pos)
        {
            Node n  = new Node();
            n.data = data;
            if(start==null)
            {
                start = n;
            }
            else
            {
                int pos1=0;
                temp = start;
                while(pos1 != pos-2)
                {
                    temp = temp.next;
                    pos1++;
                }
                n.next = temp.next;
                temp.next=n;
            }
        }
        int del_beg()
        {
            if(start==null)
            {
                return 0;
            }
            else
            {
                int i = start.data;
                start = start.next;
                return i;
            }
        }
        int del_end()
        {
            if(start==null)
            {
                return 0;
            }
            else
            {
                temp = start;
                while(temp.next.next!=null)
                {
                    temp = temp.next;
                }
                int i = temp.next.data;
                temp.next=null;
                return i;
            }
        }
        int del_pos(int pos)
        {
            if(start==null)
            {
                return 0;
            }
            else
            {
                temp = start;
                int pos1 = 0;
                while(pos1!=pos-2)
                {
                    temp = temp.next;
                    pos1++;
                }
                int i = temp.next.data;
                temp.next = temp.next.next;
                return i;
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
        int choice, data, pos;
        Scanner sc = new Scanner(System.in);
        ll_functions ll = new ll_functions();
        while(true)
        {
            System.out.println("\n1.Insert at beg");
            System.out.println("2.Insert at end");
            System.out.println("3.Insert at position");
            System.out.println("4.Delete at beginning");
            System.out.println("5.Delete at end");
            System.out.println("6.Delete at position");
            System.out.println("7.Display");
            System.out.println("8.Exit");
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
                    System.out.print("Enter the element to be inserted: ");
                    data = sc.nextInt();
                    System.out.println("Enter the position: ");
                    pos = sc.nextInt();
                    ll.ins_pos(data,pos);
                    break;
                }
                case 4:
                {
                    data = ll.del_beg();
                    System.out.println("The Deleted Item: " + data);
                    break;
                }
                case 5:
                {
                    data = ll.del_end();
                    System.out.println("The Deleted Item: " + data);
                    break;
                }
                case 6:
                {
                    System.out.print("Enter the position to be deleted: ");
                    pos = sc.nextInt();
                    data = ll.del_pos(pos);
                    System.out.println("The Deleted Item: " + data);
                    break;
                }
                case 7:
                {
                    ll.display();
                    break;
                }
                case 8:
                {
                    System.exit(0);
                }
            }
        }
    }
}