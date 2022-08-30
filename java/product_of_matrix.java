import java.util.Scanner;
public class product_of_matrix
{
    public static void main(String[] args) 
    {
        Scanner var = new Scanner(System.in);
        try
        {
            int i, j, k;
            System.out.print("\nEnter the number of columns: ");
            int c = var.nextInt();
            System.out.print("\nEnter the number of rows: ");
            int r = var.nextInt();
            int[][] m1 = new int[r][c];
            System.out.print("\nMATRIX 1: \n");
            for(i = 0 ; i < r ; i++)
            {
                for(j = 0 ; j < c ; j++)
                {
                    System.out.print("\nEnter a number: ");
                    m1[i][j] = var.nextInt();
                }
            }
            int[][] m2 = new int[r][c];
            System.out.print("\nMATRIX 2: \n");
            for(i = 0 ; i < r ; i++)
            {
                for(j = 0 ; j < c ; j++)
                {
                    System.out.print("\nEnter a number: ");
                    m2[i][j] = var.nextInt();
                }
            }
            int[][] m3 = new int[r][c];
            for(i = 0 ; i < r ; i++)
            {
                for(j = 0 ; j < c ; j++)
                {
                    m3[i][j] = 0;
                    for(k = 0 ; k < c ; k++)
                    {
                        m3[i][j] += m1[i][k]*m2[k][j];
                    }
                }
            }
            System.out.print("\nMATRIX 1: \n\n");
            for(i = 0; i < r; i++)
            {
                for(j = 0; j < c; j++)
                {
                    System.out.print(m1[i][j] + " ");
                }
                System.out.print("\n");
            }
            System.out.print("\n\nMATRIX 2: \n\n");
            for(i = 0 ; i < r ; i++)
            {
                for(j = 0; j < c ; j++)
                {
                    System.out.print(m2[i][j] + " ");
                }
                System.out.print("\n");
            }
            System.out.println("\n\nMATRIX 3 (PRODUCT): \n\n");
            for(i = 0 ; i < r ; i++)
            {
                for(j = 0 ; j < c ; j++)
                {
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