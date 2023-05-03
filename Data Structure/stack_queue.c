#include <stdio.h>
#define SIZE 5

void enQueue1(int);
int deQueue1();
void enQueue2(int);
int deQueue2();
//void display();
void push()
{
    printf("Enter your element\n");
    int s;
    scanf("%d",&s);
    int t=deQueue1();
    while(t!=-1)
    {
        enQueue2(t);
        t=deQueue1();
    }
    enQueue1(s);
    int t2=deQueue2();
    while(t2!=-1)
    {
        enQueue1(t2);
        t2=deQueue2();
    }
    call();
}
int items1[SIZE], front1 = -1, rear1 = -1;
int items2[SIZE], front2 = -1, rear2 = -1;
void call()
{
printf("1.Push\n2.Pop\n3.exit others\n");
    int a;
    while(1)
    {
        scanf("%d",&a);
        if(a==1)
            push();
        else if(a==2)
        {
            int x=deQueue1();
            printf("%d popped\n",x);
        }
        else
            return 0;
    }
}
int main()
{

call();
}

void enQueue1(int value)
{
    if (rear1 == SIZE - 1)
    {
        printf("\nQueue is Full!!");
    }

    else
    {
        if (front1 == -1)
            front1 = 0;
        rear1++;
        items1[rear1] = value;
        printf("Inserted -> %d\n", value);

    }
}
void enQueue2(int value)
{
    if (rear2 == SIZE - 1)
        printf("\nQueue is Full!!");
    else
    {
        if (front2 == -1)
            front2 = 0;
        rear2++;
        items2[rear2] = value;
        //printf("\nInserted -> %d", value);
    }
}
int deQueue1()
{
    if (front1 == -1)
        return -1;
    else
    {
        int t= items1[front1];
        front1++;
        if (front1 > rear1)
            front1 = rear1 = -1;
        return t;
    }
}
int deQueue2()
{
    if (front2 == -1)
        return -1;
    else
    {
        int t= items2[front2];
        front2++;
        if (front2 > rear2)
            front2 = rear2 = -1;
        return t;
    }
}
// Function to print the queue
/*void display()
{
    if (rear == -1)
        printf("\nQueue is Empty!!!");
    else
    {
        int i;
        printf("\nQueue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d  ", items[i]);
    }
    printf("\n");*/

