import java.util.Scanner;
public class binary_search
{
    public static void main(String[] args)
    {
        Scanner var = new Scanner(System.in);
        System.out.print("\nNumber of elements: ");
        int n = var.nextInt();
        int i;
        int[] arr = new int[n];
        for(i=0;i<n;i++)
        {
            System.out.print("Enter a number: ");
            arr[i] = var.nextInt();
        }
        System.out.print("\nNumber to be searched: ");
        int key = var.nextInt();
        System.out.print("\nArray: ");
        for(i=0;i<n;i++)
        {
            System.out.print(arr[i]+ " ");
        }
        int result = b_search(arr, n, key);
        if(result == 0)
        {
            System.out.print("\n" + key + " is NOT present");
        }
        else
        {
            System.out.print("\n" + key + " is present");
        }
        var.close();
    }
    public static int b_search(int[] arr, int n, int key)
    {
        int start = 0, end = n-1, mid=(start+end)/2, flag=0;
        while(end>=start)
        {
            if(key == arr[mid])
            {
                flag++;
                break;
            }
            else if(key > arr[mid])
            {
                start = mid + 1; 
            }
            else
            {
                end = mid - 1;
            }
            mid = (start + end) / 2;
        }
        return flag;
    }
}