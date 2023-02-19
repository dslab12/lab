
#include<stdio.h>
#include<stdio.h>

struct node {
    int data;
    int next;
};

struct node *head1,*head2;
int count=0;


void insertAtlast(int item){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data=item;
    temp->next=NULL;
    if (count==0)
    {
        if(head1==NULL){
        head1=temp;
    }
    else{
        struct node *ptr=head1;
        while (ptr->next!=NULL)
        {
           ptr=ptr->next;
        }
        ptr->next=temp;

        
        
    }
    }
    else{
         if(head2==NULL){
        head2=temp;
    }
    else{
        struct node *ptr=head2;
        while (ptr->next!=NULL)
        {
           ptr=ptr->next;
        }
        ptr->next=temp;

        
        
    }
    }
   



}
void display(struct node *head){

        struct node *ptr;
        ptr=head;
        if (ptr==NULL)
        {
            printf("NOthing to display ");
        }
        else{
            printf("printing values ");
            while (ptr!=NULL)
            {
                printf("%d ",ptr->data);
                ptr=ptr->next;
            }
            
        }
        


}
void createLinkedlist(){
    int item;

    for (int i = 0; i < 3; i++)
    {
       printf("Enter data for %d ", i+1);
       scanf("%d",&item);
       insertAtlast(item);
    }
    



}
void append(){


    struct node *ptr1=head1;
    while (ptr1->next!=NULL)
    {

        ptr1=ptr1->next;
    }
    
    ptr1->next=head2;
    // free(head2);
    head2=NULL;
    

    
}

int main(){

        printf("Enter linked list 1");
        createLinkedlist();
        count++;
        printf("Enter list 2");
        createLinkedlist();
        display(head1);
        display(head2);
        append();
        display(head1);
   
   
    


    return 0;
}