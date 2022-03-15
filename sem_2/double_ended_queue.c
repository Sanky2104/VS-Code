//Author: Sanskriti Gupta
/*Aim: Using array functions implement Double Ended Queue (Input Restricted Dequeue and Output
 Restricted Dequeue) and its operations */
 #include<stdio.h>
 #include<stdlib.h>
 #define CAPACITY 100
 int queue[CAPACITY],front=-1,rear=-1;
 void insert_front(int item);
 void insert_rear(int item);
 int delete_front();
 int delete_rear();
 void main()
 {
     int choice,internal_choice,item;
     while(1)
     {
         printf("\n1. Input Restricted Dequeue");
         printf("\n2. Output Restricted Dequeue\n");
         printf("\n3. Exit");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1:
             printf("\nINPUT RESTRICTED DEQUEUE\n");
             while(1)
             {
                 printf("\n1. Insert");
                 printf("\n2. Delete from front");
                 pritnf("\n3. Delete from rear");
                 printf("\n4. Display");
                 printf("\n5. Exit\n");
                 scanf("%d",&internal_choice);
                 switch(internal_choice)
                 {
                     case 1:
                     printf("\nEnter the element: ");
                     scanf("%d",&item);
                     insert_rear(int item);
                     break;
                     case 2:
                     item=delete_front();
                     printf("\nDeleted Item: %d",item);
                     break;
                     case 3:
                     item=delete_rear();
                     printf("\nDeleted Item: %d",item);
                     display();
                     break;
                     case 4:
                     display();
                     break;
                     case 5:
                     break;
                     default:
                     printf("\nWrong Choice");
                 }
                 exit(0);
             }
             case 2:
             printf("\nOUTPUT RESTRICTED QUEUE\n");
             while(1)
             {
                 printf("\n1. Insert from front");
                 printf("\n2. Insert from rear");
                 printf("\n3. Delete");
                 printf("\n4. Display");
                 printf("\n5. Exit\n");
                 scanf("%d",&internal_choice);
                 switch(internal_choice)
                 {
                     case 1:
                     printf("\nEnter the element: ");
                     scanf("%d",&item);
                     insert_front(item);
                     break;
                     case 2:
                     printf("\nEnter the element: ");
                     scanf("%d",&item);
                     insert_rear(item);
                     break;
                     case 3:
                     item=delete_front();
                     printf("\nDeleted Item: %d",item);
                     break;
                     case 4:
                     display();
                     case 5:
                     break;
                     default:
                     printf("\nWrong Choice");
                 }
             }
         exit(0);
         default:
         printf("\nWrong Choice");
         }
     }
 }
void insert_front(int item)
{
    int i;
    if(queue[0]=NULL)
    {
        queue[0]=item;
        rear++;
    }
    else
    {
        for(i=1;i<rear;i++)
        {
            
        }
    }
}