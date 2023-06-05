import java.util.Scanner;
import java.lang.System;
public class array_insertion_deletion 
{
    public static class array_ops
    {
        int n, i;
        int[] arr = new int[100];
        Scanner sc = new Scanner(System.in);
        public void array_create(int n)
        {
            this.n = n;
            for(i=0;i<n;i++)
            {
                System.out.print("\nEnter any number: ");
                arr[i] = sc.nextInt();
            }
        }
        public void ins_pos_arr(int data, int pos)
        {
            this.n = this.n +1;
            for(i=n-1;i>=pos-1;i--)
            {
                arr[i+1] = arr[i];
            }
            arr[pos-1] = data;
        }
        public int del_pos_arr(int pos)
        {
            if(n==0)
            {
                return 0;
            }
            else
            {
                int data = arr[pos-1];
                for(i=pos-1;i<n;i++)
                {
                    arr[i] = arr[i+1];
                }
                this.n = n-1;
                return data;
            }
        }
        public void display()
        {
            for(i=0;i<n;i++)
            {
                System.out.print(arr[i] + " ");
            }
        }
    }
    public static void main(String[] args) 
    {
        int choice, data;
        Scanner sc = new Scanner(System.in);
        array_ops a = new array_ops();
        while(true)
        {
            System.out.println("\n1.Create an array");
            System.out.println("2.Insert an element at a certain position");
            System.out.println("3.Delete at position");
            System.out.println("4.Display");
            System.out.println("5.Exit");
            choice = sc.nextInt();
            switch(choice)
            {
                case 1:
                {
                    System.out.print("\nEnter the number of elements: ");
                    data = sc.nextInt();
                    a.array_create(data);
                    break;
                }
                case 2:
                {
                    System.out.print("\nEnter the element to be inserted: ");
                    data = sc.nextInt();
                    System.out.print("\nEnter the position in which insertion needs to be performed: ");
                    int pos = sc.nextInt();
                    a.ins_pos_arr(data, pos);
                    break;
                }
                case 3:
                {
                    System.out.print("\nEnter the position in which deletion needs to be performed: ");
                    int pos = sc.nextInt();
                    data = a.del_pos_arr(pos);
                    System.out.println("The Deleted Item: " + data);
                    break;
                }
                case 4:
                {
                    a.display();
                    break;
                }
                case 5:
                {
                    sc.close();
                    System.exit(0);
                }
            }
        }
    }
}