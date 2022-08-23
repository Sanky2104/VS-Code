//Author: Sanskriti Gupta
//Date: 19 August 2022
//Aim: To implement integer stack data structure using an integer array

//SAHI HAI YE CODE

import java.util.Scanner;
import java.lang.System;
public class stack_array
{
    public static int top = -1;
    public static int n;
    public static void main(String[] args)
    {
        Scanner var  = new Scanner(System.in);
        try
        {
            System.out.print("\nEnter the limit of the stack: ");
            n = var.nextInt();
            int[] arr = new int[n];
            while(true)
            {
                System.out.print("\n1. Push");
                System.out.print("\n2. Pop");
                System.out.print("\n3. Peek");
                System.out.print("\n4. Display");
                System.out.print("\n5. Exit\n");
                int choice = var.nextInt();
                switch(choice)
                {
                    case 1:
                        System.out.print("\nEnter the element: ");
                        int item = var.nextInt(); 
                        push(arr,item);
                        break;
                    case 2:
                        int i = pop(arr);
                        System.out.println("\nDeleted Item: " + i);
                        break;
                    case 3:
                        int a = peek(arr);
                        System.out.println("\nTopmost Item: " + a);
                        break;
                    case 4:
                        display(arr);
                        break;
                    case 5:
                        System.exit(0);
                    default:
                        System.out.print("\nNo such choice, try again !!!");
                }
            }
        }

        //USED FINALLY SO AS TO SUCCESSFULLY CLOSE THE SCANNER

        finally
        {
            var.close();
        }
    }
    public static void push(int[] arr,int item)
    {
        if(top == n-1)
        {
            System.out.println("OVERFLOW !!!");
        }
        else
        {
            top++;
            arr[top] = item;
        }
    }
    public static int pop(int[] arr)
    {
        if(top == -1)
        {
            System.out.println("UNDERFLOW !!!");
            return 0;
        }
        else
        {
            int i = arr[top];
            top--;
            return i;
        }
    }
    public static int peek(int[] arr)
    {
        if(top > -1)
        {
            return arr[top];
        }
        else
        {
            System.out.println("EMPTY STACK !!!");
            return 0;
        }
    }
    public static void display(int[] arr)
    {
        if(top == -1)
        {
            System.out.print("\nEMPTY STACK !!!");
        }
        else
        {
            int i = top;
            while(i != -1)
            {
                System.out.print(arr[i] + " ");
                i--;
            }
        }
    }
}