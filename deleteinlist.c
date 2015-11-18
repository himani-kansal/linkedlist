#include<stdio.h>
#include<conio.h>
int flag=0;
void create(int);
void deleteend();
void deletebeg();
void deleten(int);
struct node
{
    int data;
    struct node*next;

};
struct node*temp,*temp1,*start,*ptr1,*ptr2;
void main()
{start=NULL;
    int value,pos,choice,k=0;
    char ans,ch;
    printf("MENU DRIVEN PROGRAM:\n");
    printf("1.Create linked list\n");
    printf("2.Delete the value from the end\n");
    printf("3.Delete the value from the begining\n");
    printf("4.Delete the value from nth position\n");
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
                {
                 deleteend();
                }
                else printf("\nFirstly create a linked list!!!!");
                break;
         case 3:if(k==1)
                {
                 deletebeg(value);
                }
                else printf("\nFirstly create a linked list!!!!");
                break;
         case 4:if(k==1)
                {printf("\nEnter  position:");
                 scanf("%d",&pos);
                 deleten(pos);
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
    { temp=(struct node*)malloc(sizeof(struct node));
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
void deleteend()
{
    ptr2=start;
    while(ptr2->next!=NULL)
    { ptr1=ptr2;
      ptr2=ptr1->next;
    }
    ptr1->next=NULL;

}
void deletebeg()
{   temp=start;
    start=temp->next;
}
void deleten(int position)
{int i;
    ptr2=start;
    for(i=0;i<position-1;i++)
    {
       ptr1=ptr2;
       ptr2=ptr1->next;
    }
    ptr1->next=ptr2->next;

}






