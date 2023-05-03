#include <stdio.h>
typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

Node *createNode(int item, Node *next)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL)
    {
        printf("Couldn't create a node\n");
        exit(1);
    }
    newNode->data=item;
    newNode->next=next;
    return newNode;
}
void insertNode(Node *node, int item)
{
    Node *newNode=createNode(item,node->next);
    node->next=newNode;
}
Node *append(Node *head, int item)
{
    Node *newNode=createNode(item,NULL);
    if(head==NULL)
        return newNode;
    Node *currentNode=head;
    while(currentNode->next!=NULL)
    {
        currentNode=currentNode->next;
    }
    currentNode->next=newNode;
    return head;
}

Node *prepend(Node *head, int item)
{
    Node *newNode=createNode(item,head);
    return newNode;
}

Node *removeNode(Node *head, Node *node)
{
    if(node==head)
    {
        head=node->next;
        free(node);
        return(head);
    }
    Node *currentNode=head;
    while(currentNode!=NULL)
    {
        if(currentNode->next== node)
            break;
        currentNode=currentNode->next;
    }
    if(currentNode==NULL)
    {
        return head;
    }
    currentNode->next=node->next;
    free(node);
    return head;
}
void printList(Node *head)
{
    Node *currentNode=head;
    while(currentNode!=NULL)
    {
        printf("%d ",currentNode->data);
        currentNode=currentNode->next;
    }
    printf("\n");
}
int main()
{
    Node *n;
    n=createNode(10,NULL);
    printf("Data: %d\n",n->data);
}
