//Author: Sanskriti Gupta
//Date: 25 August 2022
//Aim: To implement doubly linked list and all its functionalities
import java.util.Scanner;
public class doubly_linked_list
{
    public static class Node
    {
        public int data;
        public Node next;
        public Node prev;
        Node(int d)
        {
            this.data = d;
            this.next = null;
            this.prev = null;
        }
    }
    public static Node head;
    public static Node temp;
    public static void main(String[] args)
    {
        Scanner var = new Scanner(System.in);
        try
        {
            int choice, item, pos;
            while(true)
            {
                System.out.print("\n1. Insert at beginning");
                System.out.print("\n2. Insert at end");
                System.out.print("\n3. Insert at position");
                System.out.print("\n4. Delete at beginning");
                System.out.print("\n5. Delete at end");
                System.out.print("\n6. Delete at position");
                System.out.print("\n7. Display from beginning");
                System.out.print("\n8. Display from end");
                System.out.print("\n9. Exit\n");
                choice = var.nextInt();
                switch(choice)
                {
                    case 1:
                    {
                        System.out.print("\nEnter the element: ");
                        item = var.nextInt();
                        ins_beg(item);
                        break;
                    }
                    case 2:
                    {
                        System.out.print("\nEnter the element: ");
                        item = var.nextInt();
                        ins_end(item);
                        break;
                    }
                    case 3:
                    {
                        System.out.print("\nEnter the element: ");
                        item = var.nextInt();
                        System.out.print("\nEnter the position: ");
                        pos = var.nextInt();
                        ins_pos(item, pos);
                        break;
                    }
                    case 4:
                    {
                        item = del_beg();
                        System.out.print("\nDeleted Item: " + item);
                        break;
                    }
                    case 5:
                    {
                        item = del_end();
                        System.out.print("\nDeleted Item: " + item);
                        break;
                    }
                    case 6:
                    {
                        System.out.print("\nEnter the position: ");
                        pos = var.nextInt();
                        item = del_pos(pos);
                        System.out.print("\nDeleted Item: " + item);
                        break;
                    }
                    case 7:
                    {
                        dislpay_beg();
                        break;
                    }
                    case 8:
                    {
                        display_end();
                        break;
                    }
                    case 9:
                    {
                        System.exit(0);
                    }
                }
            }
        }
        finally
        {
            var.close();
        }
    }
    public static void ins_beg(int item)
    {
        Node new_node = new Node(item);
        if(head == null)
        {
            head = new_node;
        }
        else
        {
            new_node.next = head;
            head.prev = new_node;
            head = new_node; 
        }
    }
    public static void ins_end(int item)
    {
        Node new_node = new Node(item);
        if(head == null)
        {
            head = new_node;
        }
        else
        {
            temp = head;
            while(temp.next != null)
            {
                temp = temp.next;
            }
            new_node.prev = temp;
            temp.next = new_node;
        }
    }
    public static void ins_pos(int item, int pos)
    {
        Node new_node = new Node(item);
        if(head == null)
        {
            head = new_node;
        }
        else
        {
            int p = 1;
            temp = head;
            while(p < pos - 1)
            {
                temp = temp.next;
                p++;
            }
            new_node.prev = temp;
            new_node.next = temp.next;
            temp.next.prev = new_node;
            temp.next = new_node;
        }
    }
    public static int del_beg()
    {
        if(head == null)
        {
            System.out.print("\nNOTHING TO DELETE !!!");
            return 0;
        }
        else
        {
            int i = head.data;
            head.next.prev = null;
            head = head.next;
            return i;
        }
    }
    public static int del_end()
    {
        if(head == null)
        {
            System.out.print("\nNOTHING TO DELETE");
            return 0;
        }
        else
        {
            temp = head;
            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            int i = temp.next.data;
            temp.next = null;
            return i;
        }
    }
    public static int del_pos(int pos)
    {
        if(head == null)
        {
            System.out.print("\nNOTHING TO DELETE !!!");
            return 0;
        }
        else
        {
            int p = 1;
            temp = head;
            while(p < pos - 1)
            {
                temp = temp.next;
                p++;
            }
            int i = temp.next.data;
            temp.next.next.prev = temp;
            temp.next = temp.next.next;
            return i;
        }
    }
    public static void dislpay_beg()
    {
        if(head == null)
        {
            System.out.print("\nNOTHING TO DISPLAY !!!");
        }
        else
        {
            temp = head;
            while(temp != null)
            {
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
        }
    }
    public static void display_end()
    {
        if(head == null)
        {
            System.out.print("\nNOTHING TO DISPLAY !!!");
        }
        else
        {
            temp = head;
            while(temp.next != null)
            {
                temp = temp.next;
            }
            while(temp != null)
            {
                System.out.print(temp.data + " ");
                temp = temp.prev;
            }
        }
    }
}