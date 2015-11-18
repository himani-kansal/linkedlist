#include<stdio.h>
#include<conio.h>
void add(int);
int flag=0;
struct node
{
    int data;
    struct node*next;
};
struct node*start,*temp,*temp1;
void main()
{

    int value;
    int choice;
    start=NULL;
    flag=0;
    printf("Do you want to add the element in the list?");
    scanf("%d",&choice);
    while(choice==1)
    {
        printf("\nEnter the value:");
        scanf("%d",&value);
        add(value);
        printf("Do you want to enter more element in the list?");
        scanf("%d",&choice);
    }
    printf("\nThe linked list is:");
    temp=start;
    printf("%d\t",temp->data);
    while(temp->next!=NULL)
    {
        temp=temp->next;
        printf("%d\t",temp->data);

    }
}
void add(int value)
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

