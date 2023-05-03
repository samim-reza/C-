#include <stdio.h>
typedef struct node Node;

struct node
{
    int *prev;
    int data;
    int *next;
};

Node *createNode(Node *prev, int item, Node *next)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL)
    {
        printf("Node cann't be created\n");
        exit(1);
    }
    newNode->prev=prev;
    newNode->data=item;
    newNode->next=next;
    return newNode;
}

void insertNode()
int main()
{

}
