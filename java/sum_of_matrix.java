import java.util.Scanner;
public class sum_of_matrix
{
    public static void main(String[] args) 
    {
        Scanner var = new Scanner(System.in);
        try
        {
            int i, j, a, b;
            System.out.print("\nEnter the number of columns of the matrices: ");
            a = var.nextInt();
            System.out.print("\nEnter the number of rows of the matrices: ");
            b = var.nextInt();
            int[][] m1 = new int[a][b];
            System.out.print("\nMATRIX 1\n");
            for(i = 0; i < a; i++)
            {
                for(j = 0; j < b; j++)
                {
                    System.out.print("\nEnter the element: ");
                    m1[i][j] = var.nextInt();
                }
            }
            int[][] m2 = new int[a][b];
            System.out.print("\nMATRIX 2\n");
            for(i = 0; i < a; i++)
            {
                for(j = 0; j < b; j++)
                {
                    System.out.print("\nEnter the element: ");
                    m2[i][j] = var.nextInt();
                }
            }
            System.out.print("\nMATRIX 1: \n\n");
            for(i = 0; i < a; i++)
            {
                for(j = 0; j < b; j++)
                {
                    System.out.print(m1[i][j] + " ");
                }
                System.out.print("\n");
            }
            System.out.print("\n\nMATRIX 2: \n\n");
            for(i = 0; i < a; i++)
            {
                for(j = 0; j < b; j++)
                {
                    System.out.print(m2[i][j] + " ");
                }
                System.out.print("\n");
            }
            int[][] m3 = new int[a][b];
            System.out.println("\n\nMATRIX 3 (SUM): \n\n");
            for(i = 0; i < a; i++)
            {
                for(j = 0; j < b; j++)
                {
                    m3[i][j] = m1[i][j] + m2[i][j];
                    System.out.print(m3[i][j] + " ");
                }
                System.out.print("\n");
            }
            System.out.print("\n");
        }
        finally
        {
            var.close();
        }
    }
}