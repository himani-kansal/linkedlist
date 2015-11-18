#include<stdio.h>
#include<conio.h>
int flag=0;
void create(int);
void insertionsort();
struct node
{

    int data;
    struct node *next;
};
struct node *start,*ptr1,*ptr2,*temp1,*ptr,*temp,*lptr;
void main()
{
   int i=0,value;
   char ch;
   printf("Create a linked list\n");
   do
   {
       printf("Enter the value:");
       scanf("%d",&value);
       create(value);
       i++;
       fflush(stdin);
       printf("Do you want to add more element in the list?(y/n)");
       scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    insertionsort();
    printf("The linked list after sorting is:");
    ptr=start;
    printf("%d ",ptr->data);
    while(ptr->next!=NULL)
    { ptr=ptr->next;
      printf("%d ",ptr->data);

    }

}
void create(int value)
{
    if(flag==0)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=value;
        temp->next=NULL;
        start=temp;
        flag++;
    }
    else
    {
        temp1=(struct node*)malloc(sizeof(struct node));
        temp1->data=value;
        temp1->next=NULL;
        temp->next=temp1;
        temp=temp1;
    }
}
void insertionsort()
{  ptr1=start;
   int v;
   while(ptr1->next!=NULL)
   { ptr1=ptr1->next;
     int zoo=0;
     v=ptr1->data;
     ptr2=ptr1;
     do
     {  temp=start;

          while(temp->next!=ptr2)
         {
             temp=temp->next;
         }
         ptr2=temp;
          if(v<ptr2->data)
         ptr2->next->data=ptr2->data;
         else
         {
             zoo++; break;
         }

     }while(ptr2!=start);
    if(zoo)
     ptr2->next->data=v;
     else
        ptr2->data=v;
   }


}
