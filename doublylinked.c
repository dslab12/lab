#include<stdio.h>


struct node {
    int data;
    int next;
    int prev;
};
struct node *head;
void InserAtbeginLIst()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    int item;
    scanf("%d",&item);

    temp -> data = item;
    temp -> next = NULL;
    temp -> prev = NULL;

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}
void atSpecific() {
    int item, pos;
    printf("Enter data ");
    scanf("%d", &item);
    printf("Enter pos ");
    scanf("%d", &pos);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->next = NULL;
    temp->prev = NULL;

    struct node *ptr = head;
    for (int i = 1; i < pos && ptr != NULL; i++) {
        ptr = ptr->next;
    }
    struct node *pos_ptr = temp;

    if (ptr == NULL) {
        printf("Invalid position\n");
        return;
    }

    temp->prev = ptr;
    temp->next = ptr->next;
    if (ptr->next != NULL) {
        pos_ptr = temp;
    }
    ptr->next = temp;
}
void deleterFromend(){
    struct node *ptr=head;
    struct node *pos;
    while (ptr->next!=NULL)
    {
       ptr=ptr->next;
    }
   pos= ptr->prev;
   pos->next=NULL;
    free(ptr);
    


}
void deletetionFromFirst(){


    struct node *temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
}
void insertAtLast(){
     printf("Enter data");
     int item;
    scanf("%d",&item);
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data=item;
        temp->next=NULL;
        temp->prev=NULL;
        struct node *ptr=head;
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
        
}
void display(){


    struct node *temp=head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
}

int main(){


    printf("Enter elets of list");
    int choice;
    while (1)
    {
      printf("1 For begin insert\n 2 for insert at end\n 3 dispkay\n4 for adding in a specifc place\n5 delete from end\n 6 delete from start");
      scanf("%d", &choice);
      switch(choice){
        case 1 :
        InserAtbeginLIst();
        break;
    // InserAtbeginLIst();
    case 2:
    insertAtLast();
    break;
    case  3:
    display();
    break;
    case 4:
    atSpecific();
    break;
    case 5:
    deleterFromend();
    break;
    case 6:
    deletetionFromFirst();


      }
    }
    
  
    display();

    return 0;
}