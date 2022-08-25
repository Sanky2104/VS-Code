//Author: Sanskriti Gupta
//Date: 25 August 2022
//Aim: To implement stack and its functionalities through linked list
import java.lang.System;
import java.util.Scanner;
public class stack_linked_list
{
    public static class Node
    {
        public int data;
        public Node next;
        Node(int d)
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
            int item, choice;
            while(true)
            {
                System.out.print("\n1. Push");
                System.out.print("\n2. Pop");
                System.out.print("\n3. Peek");
                System.out.print("\n4. Display");
                System.out.print("\n5. Exit\n");
                choice = var.nextInt();
                switch(choice)
                {
                    case 1:
                    {
                        System.out.print("\nEnter the element: ");
                        item = var.nextInt();
                        push(item);
                        break;
                    }
                    case 2:
                    {
                        item = pop();
                        System.out.print("\nDeleted Item: " + item);
                        break;
                    }
                    case 3:
                    {
                        item = peek();
                        System.out.print("\nTopmost Element: " + item);
                        break;
                    }
                    case 4:
                    {
                        display();
                        break;
                    }
                    case 5:
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
    public static void push(int item)
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
    public static int pop()
    {
        if(head == null)
        {
            System.out.print("\nUNDERFLOW: EMPTY STACK");
            return 0;
        }
        else
        {
            int i = head.data;
            head = head.next;
            return i;
        }
    }
    public static int peek()
    {
        if(head == null)
        {
            System.out.print("\nUNDERFLOW: EMPTY STACK");
            return 0;
        }
        else
        {
            int i = head.data;
            return i;
        }
    }
    public static void display()
    {
        if(head == null)
        {
            System.out.print("\nUNDERFLOW: EMPTY STACK");
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
}