//Date: 23 August 2022
//Aim: To create a linked list without using the inbuilt functions and using a class

//CREATED BY SELF

import java.util.Scanner;
import java.lang.System;
public class self_linked_list
{
    public static class Node //made statis so as to make it accessible to main
    {
        public int data;
        public Node next;
        public Node(int d) //constructor
        {
            this.data = d;
            this.next = null;
        }
    }
    public static Node head;
    public static Node temp;
    public static void main(String[] args)
    {
        Scanner var = new Scanner(System.in);
        try
        {
            int item, choice, pos;
            while(true)
            {
                System.out.print("\n1. Insert at beginning");
                System.out.print("\n2. Insert at end");
                System.out.print("\n3. Insert at position");
                System.out.print("\n4. Delete at beginning");
                System.out.print("\n5. Delete at end");
                System.out.print("\n6. Delete at position");
                System.out.print("\n7. Display");
                System.out.print("\n8. Exit\n");
                choice = var.nextInt();
                switch(choice)
                {
                    case 1:
                    {
                        System.out.print("\nEnter an element: ");
                        item = var.nextInt();
                        insert_at_beg(item);
                        break;
                    }
                    case 2:
                    {
                        System.out.print("\nEnter an element: ");
                        item = var.nextInt();
                        insert_at_end(item);
                        break;
                    }
                    case 3:
                    {
                        System.out.print("\nEnter an element: ");
                        item = var.nextInt();
                        System.out.print("\nEnter the position: ");
                        pos = var.nextInt();
                        insert_at_pos(item, pos);
                        break;
                    }
                    case 4:
                    {
                        item = del_at_beg();
                        System.out.print("\nDeleted Item: " + item);
                        break;
                    }
                    case 5:
                    {
                        item = del_at_end();
                        System.out.print("\nDeleted Item: " + item);
                        break;
                    }
                    case 6:
                    {
                        System.out.print("\nEnter the position: ");
                        pos = var.nextInt();
                        item = del_at_pos(pos);
                        System.out.print("\nDeleted Item: " + item);
                        break;
                    }
                    case 7:
                    {
                        display();
                        break;
                    }
                    case 8:
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
    public static void insert_at_end(int item)
    {
        Node new_node = new Node(item);
        new_node.data = item;
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
            temp.next = new_node;
        }
    }
    public static void insert_at_beg(int item)
    {
        Node new_node = new Node(item);
        if(head == null)
        {
            head = new_node;
        }
        else
        {
            new_node.next = head;
            head = new_node;
        }
    }
    public static void insert_at_pos(int item, int pos)
    {
        Node new_node = new Node(item);
        if(head == null)
        {
            head = new_node;
        }
        else
        {
            temp = head;
            int p = 1;
            while(p < pos - 1)
            {
                temp = temp.next;
                p++;
            }
            new_node.next = temp.next;
            temp.next = new_node;
        }
    }
    public static int del_at_beg()
    {
        if(head == null)
        {
            System.out.print("\nNOTHING TO DELETE !!!");
            return 0;
        }
        else
        {
            int i = head.data;
            head = head.next;
            return i;
        }
    }
    public static int del_at_end()
    {
        if(head == null)
        {
            System.out.print("\nNOTHING TO DELETE !!!");
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
    public static int del_at_pos(int pos)
    {
        if(head == null)
        {
            System.out.print("\nNOTHING TO DELETE");
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
            temp.next = temp.next.next;
            return i;
        }
    }
    public static void display()
    {
        temp = head;
        while(temp != null)
        {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }
}