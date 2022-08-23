//Date: 23 August 2022
//Aim: To create a linked list without using the inbuilt functions and using a class
import java.util.Scanner;
import java.util.LinkedList;
import java.io.*;
import java.lang.System;
public class self_linked_list
{
    static class Node //made statis so as to make it accessible to main
    {
        int data;
        Node next;
        Node(int d) //constructor
        {
            data = d;
            next = null;
        }
    }
    Node head;
    public static void main(String[] args)
    {
        Scanner var = new Scanner(System.in);
        try
        {
            LinkedList list = new LinkedList<>();
            while(true)
            {
                System.out.print("\n1. Insert");
                System.out.print("\n2. Traversal");
                System.out.print("\n3. Exit\n");
                int choice = var.nextInt();
                switch(choice)
                {
                    case 1:
                        System.out.print("\nEnter an element: ");
                        int item = var.nextInt();
                        list = insert(list, item);
                    case 2:
                        display(list);
                    case 3:
                        System.exit(0);
                }
            }
        }
        finally
        {
            var.close();
        }
    }
    public static LinkedList insert(LinkedList list, int data)
    {
        Node new_node = new Node(data);
        if(list.head == null)
        {
            list.head = new_node;
        }
        else
        {
            Node last = list.head;
            while(last.next != null)
            {
                last = last.next;
            }
            last.next = new_node;
        }
        return list;
    }
    public static void display(LinkedList list)
    {
        Node curnode = list.head;
        while(curnode != null)
        {
            System.out.print(curnode.data + " ");
            curnode= curnode.next;
        }
    } 
}