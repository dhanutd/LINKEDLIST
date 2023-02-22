#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*next;
}*start;
void insert()
{
    struct Node*ins;
    int value;
    printf("enter a element to be inserted :");
    scanf("%d",&value);
    if(start==NULL)
    {
        start=(struct Node*)malloc(sizeof(struct Node));
        start->next=NULL;
        start->data=value;
        return;
    }
    ins=(struct Node*)malloc(sizeof(struct Node));
    ins->data=value;
    ins->next=start;
    start=ins;
    
}
void display()
{
    struct Node*dis;
    if(start==NULL)
    {
        printf("There is no element in list\n");
    }
    else{
        dis=start;
        while(dis!=NULL)
        {
            printf("%d-->",dis->data);
            dis=dis->next;
        }
        printf("NULL");
    }
}
void insertbefore()
{
    struct Node*insa;
    struct Node*ptr,*ptr1;
    int value,val;
    printf("Enter a element to be insertted\n");
    scanf("%d",&value);
    if(start==NULL)
    {
        start=(struct Node*)malloc(sizeof(struct Node));
        start->next=NULL;
        start->data=value;
        return; 
    }
    insa=(struct Node*)malloc(sizeof(struct Node));
    insa->data=value;
    insa->next=NULL;
    printf("Enter a specific value \nWhen given value element is inserted at before specific value \n");
    scanf("%d",&val);
    if(start->data==val)
    {
        insa->next=start;
        start=insa;
        return;
    }
    ptr=NULL;
    ptr1=start;
    while(ptr1!=NULL && ptr1->data!=val)
    {
       ptr=ptr1;
       ptr1=ptr1->next; 
    }
    insa->next=ptr->next;
    ptr->next=insa;

    
}
void insertafter()
{
    struct Node*insb;
    struct Node*ptr,*ptr1;
    int value,val;
    printf("enter a element to be inserted\n");
    scanf("%d",&value);
    if(start==NULL)
    {
        start=(struct Node*)malloc(sizeof(struct Node));
        start->next=NULL;
        start->data=value;
        return; 
    }
    insb=(struct Node*)malloc(sizeof(struct Node));
    insb->data=value;
    insb->next=NULL;
    printf("Enter a specific value \nWhen given value element is inserted at after specific value \n");
    scanf("%d",&val);
    ptr=start;
    ptr1=start->next;
    while(ptr!=NULL && ptr->data!=val)
    {
        ptr=ptr1;
        ptr1=ptr->next;
    }
    insb->next=ptr->next;
    ptr->next=insb;

}
void delete()
{
    struct Node*del,*ptr;
    int val;
    if(start==NULL)
    {
        printf("Delete is not possible\n");
        return;
    }
    printf("Enter a specific value for delete element\n");
    scanf("%d",&val);
    if(start->data==val)
    {
        del=start;
        start=start->next;
        printf("Deleted element is:%d",del->data);
        free(del);
        return;
    }
    del=start;
    ptr=NULL;
    while(del!=NULL && del->data!=val)
    {
        ptr=del;
        del=del->next;
    }
    ptr->next=del->next;
    printf("Deleted element is:%d",del->data);
    free(del);
}
void deletebefore()
{
    struct Node*ptr,*delb,*vlu;
    int valu;
    printf("Enter a specific value \nWhen given value element is deleted at before specific value \n ");
    scanf("%d",&valu);
    if(start->data==valu)
    {
        printf("Delete is not possible\n");
        return;
    }
    ptr=NULL;
    delb=start;
    vlu=start->next;
    if(vlu->data==valu)
    {
        ptr=start;
        delb=start->next;
        start=delb;
        printf("Deleted element is:%d",ptr->data);
        free(ptr);
        return;
    }
    while(vlu!=NULL && vlu->data!=valu)
    {
        ptr=delb;
        delb=vlu;
        vlu=vlu->next;
    }
    ptr->next=delb->next;
    printf("Deleted element is:%d",delb->data);
    free(delb);
}
void deleteafter()
{
    struct Node*ptr,*val,*del;
    struct Node*check;
    int value;
    printf("Enter a specific value \nWhen given value element is deleted at after specific value \n");
    scanf("%d",&value);
    if(start==NULL)
    {
        printf("Deletion it is not possiable\n");
        return;
    }
    check=start;
    while(check->data!=value)
    {
        check=check->next;
    }
    if(check->next==NULL)
    { 
        printf("Delete is not possiable\n");
        return;
    }
    if(start->data==value)
    {
        val=start;
        del=start->next;
        val->next=del->next;
        printf("Deleted element is:%d",del->data);
        free(del);
        return ;
    }
    ptr=NULL;
    val=start;
    del=start->next;
    while(val!=NULL && val->data!=value)
    {
        ptr=val;
        val=del;
        del=del->next;
    }
    val->next=del->next;
    printf("Deleted element is:%d",del->data);
    free(del);
}
int main()
{
    int choice,choicei,choiced;
    do{
        printf("\n1.Insert 2.Display 3.Delete 4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                   printf("\n1.Normal_insert 2.Insert before value 3.Insert after value\n");
                   scanf("%d",&choicei);
                   switch(choicei)
                   {
                      case 1: insert();
                            break;
                      case 2:insertbefore();
                            break;
                      case 3: insertafter();
                             break;
                   }
                   break;
            case 2:
                    display();
                    break;
            case 3:printf("\n1.Normal delete 2.Delete before 3.Delete after\n");
                   scanf("%d",&choiced);
                   switch(choiced)
                   {
                    case 1:delete();
                           break;
                    case 2:deletebefore();
                          break;
                    case 3:deleteafter();
                           break;

                   }
                   
        }
    }while(choice!=4);
}