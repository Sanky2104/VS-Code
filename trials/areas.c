#include<stdio.h>
#include<stdlib.h>
void main()
{
    int choice;
    float a,b,c;
    while(1)
    {
        printf("\n1. Parallelogram");
        printf("\n2. Trapezoid");
        printf("\n3. Rhombus");
        printf("\n4. Sphere");
        printf("\n5. Ellipse");
        printf("\n6. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the base and height of the parallelogram: ");
                scanf("%f%f",&a,&b);
                printf("\nArea of parallelogram: %f",a*b);
                break;
            case 2:
                printf("\nEnter the 1st base, 2nd base & the height of the trapezoid: ");
                scanf("%f%f%f",&a,&b,&c);
                printf("\nArea of trapezoid: %f",(a+b)*(c/2));
                break;
            case 3:
                printf("\nEnter the 1st and 2nd diagonal of the rhombus: ");
                scanf("%f%f",&a,&b);
                printf("\nArea of rhombus: %f",(a*b)/2);
                break;
            case 4:
                printf("\nEnter the radius of the sphere: ");
                scanf("%f",&a);
                printf("\nArea of sphere: %f",4*a*a*3.14);
                break;
            case 5:
                printf("\nEnter the 1st & 2nd axis of the ellipse: ");
                scanf("%f%f",&a,&b);
                printf("\nArea of the ellipse: %f",3.14*a*b);
                break;
            case 6:
                exit(0);
        }
    }
}