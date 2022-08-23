
//YE WALA GALAT HAI

import java.util.Scanner;
import java.lang.System;
public class queue_array
{
    public static int n;
    public static int front = -1;
    public static int rear = -1;
    public static void main(String[] args)
    {
        Scanner var = new Scanner(System.in);
        try
        {
            System.out.print("\nEnter the limit of queue: ");
            n = var.nextInt();
            int[] arr = new int[n];
            while(true)
            {
                System.out.print("\n1. Enqueue");
                System.out.print("\n2. Dequeue");
                System.out.print("\n3. Display");
                System.out.print("\n4. Exit\n");
                int choice = var.nextInt();
                switch(choice)
                {
                    case 1:
                        System.out.print("\nEnter an element: ");
                        int item = var.nextInt();
                        enqueue(arr, item);
                        break;
                    case 2:
                        int del = dequeue(arr);
                        System.out.print("\nDeleted Item: " + del);
                        break;
                    case 3:
                        display(arr);
                        break;
                    case 4:
                        System.exit(0);
                    default:
                        System.out.print("\nNo such choice, try again !!!");
                }
            }
        }
        finally
        {
            var.close();
        }
    }
    public static void enqueue(int[] arr, int item)
    {
        if(rear == n)
        {
            System.out.print("\nOVERFLOW !!!");
        }
        else if(front == -1 && rear == -1)
        {
            front = 0;
            rear++;
            arr[rear] = item;
        }
        else
        {
            rear++;
            arr[rear] = item;
        }
    }
    public static int dequeue(int[] arr)
    {
        if(front == -1)
        {
            System.out.print("\nUNDERFLOW !!!");
            return 0;
        }
        else
        {
            int i = arr[front];
            front++;
            return i;
        }
    }
    public static void display(int[] arr)
    {
        if(front == -1)
        {
            System.out.print("EMPTY QUEUE !!!");
        }
        int i;
        for(i = front; i <= rear; i++)
        {
            System.out.print(arr[i] + " ");
        }
    }
}