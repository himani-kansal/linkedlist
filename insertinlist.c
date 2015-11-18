#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int flag=0;
void create(int);
void insertend(int);
void insertbeg(int);
void insertn(int,int);
struct node
{
    int data;
    struct node*next;
};
struct node*temp,*temp1,*start,*ptr1,*ptr2;
void main()
{ start=NULL;
    int value,k=0,choice,pos;
    char ans,ch;
    printf("MENU DRIVEN PROGRAM:\n");
    printf("1.Create linked list\n");
    printf("2.Insert the value at the end\n");
    printf("3.Insert the value at the begining\n");
    printf("4.Insert the value at nth position\n");
    do
    {
     printf("What do you want to do:");
     scanf("%d",&choice);
     switch(choice)
     {
         case 1:if(k==1)
                printf("\nYou have already created linked list!!!!! ");
                else
                {
                do
                {
                    printf("\nEnter the value:");
                    scanf("%d",&value);
                    create(value);
                    fflush(stdin);
                    printf("Do you want to add more element in the list?");
                    scanf("%c",&ch);
                }while(ch=='y'||ch=='Y');
                 k++;
                }break;
         case 2:if(k==1)
                {printf("\nEnter the value to insert at the end:");
                 scanf("%d",&value);
                 insertend(value);
                }
                else printf("\nFirstly create a linked list!!!!");
                break;
         case 3:if(k==1)
                {printf("\nEnter the value to insert at the begining:");
                 scanf("%d",&value);
                 insertbeg(value);
                }
                else printf("\nFirstly create a linked list!!!!");
                break;
         case 4:if(k==1)
                {printf("\nEnter the value and position:");
                 scanf("%d%d",&value,&pos);
                 insertn(value,pos);
                }
                else printf("\nFirstly create a linked list!!!!");
                break;
     }
     fflush(stdin);
      printf("\nDo you want to perform another operation?");
      scanf("%c",&ans);
    }while(ans=='y'||ans=='Y');
    printf("\nThe linked list is:");
    temp=start;
    printf("%d\t",temp->data);
    while(temp->next!=NULL)
    {
        temp=temp->next;
        printf("%d\t",temp->data);

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
void insertend(int value)
{
    temp1=(struct node*)malloc(sizeof(struct node));
        temp1->data=value;
        temp1->next=NULL;
        temp->next=temp1;
        temp=temp1;
}
void insertbeg(int value)
{
    temp1=(struct node*)malloc(sizeof(struct node));
        temp1->data=value;
        temp1->next=start;
        start=temp1;

}
void insertn(int value,int position)
{  int i;
     temp1=(struct node*)malloc(sizeof(struct node));
        temp1->data=value;
        ptr2=start;
        for(i=0;i<position-1;i++)
        { ptr1=ptr2;
          ptr2=ptr1->next;
        }
        temp1->next=ptr2;
        ptr1->next=temp1;

}

