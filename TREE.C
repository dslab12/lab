#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *head = NULL;


struct node *newNode(int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
// void preorderTraversal(struct node *root)
// {
//     if (root == NULL)
//         return;

//     struct node *temp;
//     struct node *stack[100];
//     int top = -1;

//     stack[++top] = root;

//     while (top >= 0)
//     {
//         temp = stack[top--];
//         printf("%d ", temp->data);
//         if (temp->right)
//             stack[++top] = temp->right;
//         if (temp->left)
//             stack[++top] = temp->left;
//     }
// }

void postorderTraversal(struct node *root)
{
    if (root == NULL)
        return;

    struct node *temp;
    struct node *stack1[100];
    int top1 = -1;

    struct node *stack2[100];
    int top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0)
    {
        temp = stack1[top1--];
        stack2[++top2] = temp;

        if (temp->left)
            stack1[++top1] = temp->left;
        if (temp->right)
            stack1[++top1] = temp->right;
    }

    while (top2 >= 0)
    {
        temp = stack2[top2--];
        printf("%d ", temp->data);
    }
}

struct node *insert(struct node *root, int data) {
    if (root == NULL)
        return newNode(data);
    if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void displayTree(struct node *root) {
    if (root == NULL)
        return;
    displayTree(root->left);
    printf("%d ", root->data);
    displayTree(root->right);
}



int countNodes(struct node *root){
    int count = 0;
    if (root == NULL)
        return count;

    struct node *temp;
    struct node *stack[100];
    int top = -1;

    stack[++top] = root;

    while (top >= 0)
    {
        temp = stack[top--];
        count++;
        if (temp->right)
            stack[++top] = temp->right;
        if (temp->left)
            stack[++top] = temp->left;
    }

    return count;
    
}

int heightofTree(struct node *root){
    if (root == NULL)
        return 0;

    int leftHeight = heightofTree(root->left);
    int rightHeight = heightofTree(root->right);

    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}
int inorderTraversal(struct node *root)
{   int mirror[5];
     int count=0;
    if (root == NULL)
        return 0;

    struct node *temp;
    struct node *stack[100];
    int top = -1;

    temp = root;
    int i=0;
    while (temp || top >= 0)
    {
        while (temp)
        {
            stack[++top] = temp;
            temp = temp->left;
        }

        temp = stack[top--];
        printf("%d ", temp->data);
        mirror[i]=temp->data;
        i++;
        count++;
        temp = temp->right;
    }
    // for (int i = 0; i < 4 ; i++)
    // {
    //     printf("\n%d",mirror[i]);
    // }
//    printf("Reversed array: ");
//     for (int i = 5-1; i>=0; i--){
//         printf("%d ", mirror[i]);
//     }
    return count;
}
void preorderTraversal(struct node *root)
{
    if (root == NULL)
        return;

    struct node *temp;
    struct node *stack[100];
    int top = -1;

    stack[++top] = root;

    while (top >= 0)
    {
        temp = stack[top--];
        printf("%d ", temp->data);
        if (temp->right)
            stack[++top] = temp->right;
        if (temp->left)
            stack[++top] = temp->left;
    }
}
int countLeafNodes(struct node *root)
{
    if (root == NULL)
        return 0;

    int count = 0;
    struct node *temp;
    struct node *stack[100];
    int top = -1;

    stack[++top] = root;

    while (top >= 0)
    {
        temp = stack[top--];

        if (temp->left == NULL && temp->right == NULL)
            count++;

        if (temp->right)
            stack[++top] = temp->right;
        if (temp->left)
            stack[++top] = temp->left;
    }

    return count;
}
// void insertionsort() {
//    struct node *current = head->next;
//    struct node *prev = head;

//    while (current != NULL) {
//       while (prev->data > current->data) {
//          int temp = prev->data;
//          prev->data = current->data;
//          current->data = temp;
//          prev = head;
//       }
//       prev = current;
//       current = current->next;
//    }
// }
  

int main() {
    int data;
    struct node *root = NULL;
    int count=0;
    printf("Enter elements of the binary tree, 0 to stop: ");
    while (1) {
        scanf("%d", &data);
        if (data == 0)
            break;
        root = insert(root, data);
        count++;
    }
//     printf("\nDisplaying binary tree: ");
//     displayTree(root);
//     printf("\nCounting numbe of nodes in tree ");
//    count= countNodes(root);
//    printf("\nCount == %d",count);
//    int height=0;
//     height= heightofTree(root);
//    printf("\nHeight  == %d ",height);
   
    int countnodes=0; 
   inorderTraversal (root);
      printf("\nNodes == %d ",countnodes);
    return 0;
}
