#include<stdio.h>
#include<conio.h>
int flag=0;
void create(int);
void selectionsort();
struct node
{

    int data;
    struct node *next;
};
struct node *start,*ptr1,*ptr2,*temp1,*ptr,*temp;
void main()
{
   int i,value;
   char ch;
   printf("Create a linked list\n");
   do
   {
       printf("Enter the value:");
       scanf("%d",&value);
       create(value);
       fflush(stdin);
       printf("Do you want to add more element in the list?(y/n)");
       scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    selectionsort();
    printf("The linked list after sorting is:");
    ptr=start;
    printf("%d",ptr->data);
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
void selectionsort()
{int v;

    ptr1=start;
    while(ptr1->next!=NULL)
    {ptr2=ptr1;
        do
        {ptr2=ptr2->next;
        if(ptr1->data>ptr2->data)
        {

            v=ptr1->data;
            ptr1->data=ptr2->data;
            ptr2->data=v;
        }

        }while(ptr2->next!=NULL);
    ptr1=ptr1->next;
    }

}
