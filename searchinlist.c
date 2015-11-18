#include<stdio.h>
#include<conio.h>
int flag=0;
void create(int);
void search(int);
struct node
{
    int data;
    struct node*next;
};
struct node*temp,*start,*temp1,*ptr1,*ptr2;
void main()
{   start=NULL;
    int k=0,choice,value;
    char ans,ch;
    printf("MENU DRIVEN PROGRAM\n");
    printf("1.Create a linked list\n");
    printf("2.Search a value\n");
    do
    { printf("What do you want to do?");
      scanf("%d",&choice);
      switch(choice)
      {
          case 1:if(k==1)
                  printf("You have already created a linked list!!!!!\n");
                  else
                  {
                      do
                      {
                          printf("Enter the value:");
                          scanf("%d",&value);
                          create(value);
                          fflush(stdin);
                          printf("Do you want to add more element(y/n)?");
                          scanf("%c",&ch);
                      }while(ch=='y'||ch=='Y');
                   k++;
                  }
                  break;
          case 2:
                  if(k==0)
                    printf("Firstly create a linked list\n");
                  else
                  {
                      printf("Enter the value to be searched:");
                      scanf("%d",&value);
                      search(value);
                  }
                  break;
      }
      fflush(stdin);
      printf("Do you want to perform another operation(y/n)?");
      scanf("%c",&ans);
    }while(ans=='y'||ans=='Y');
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
void search(int value)
{int i=1,f=0,pos;
    ptr1=start;
    if(ptr1->data==value)
        return 1;
    do
    {
        ptr1=ptr1->next;
        if(ptr1->data==value)
          {
            f++;
            pos=i+1; break;
          }
        i++;
    }while(ptr1->next!=NULL);
    if(f)
    {
        printf("The element is found at position:%d\n",pos);
    }
}
