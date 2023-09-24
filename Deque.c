#include <stdio.h>

int isFull();
int isEmpty();
void inject(int);//insert from rear
void push(int);//insert from front
int eject();//remove from rear
int pop();//remove from front
void display();

int dq[5];
int rear = -1;
int front = -1;

int main()
{
	int choice,element;
    while(1){
    printf("\n1.inject\n2.Eject\n3.Push\n4.Pop\n5.Display\n6.Exit");
    printf("\nInput Chpoice: ");
    scanf("%d",&choice);
    switch(choice){
    	case 1:
    	if(isFull())
    		printf("\nNot possible");
    	else{
    		printf("\nEnter element to insert: ");
    		scanf("%d",&element);
    		inject(element);
    	}
    	break;
    	case 2:
    	if(isEmpty())
    		printf("\nNot possible");
    	else{
    		element=eject();
    		printf("\n%d is deleted",element);
    	}
    	break;
    	case 3:
    	if(isFull())
    		printf("\nNot possible");
    	else{
    		printf("\nEnter element to insert: ");
    		scanf("%d",&element);
    		push(element);
    	}
    	break;
    	case 4:
    	if(isEmpty())
    		printf("\nNot possible");
    	else{
    		element=pop();
    		printf("\n%d is deleted",element);
    	}
    	break;
    	case 5:
    	if(isEmpty())
    		printf("\nNot possible");
    	else
    		display();
    	break;
    	case 6:
    	return 0;
    	break;
    }
}

}

int isFull(){
	if(((front)==0 && (rear)==4)||(front==rear+1))
		return 1;
	else
		return 0;
}

int isEmpty(){
	if (front==-1)
		return 1;
	else
		return 0;
}

void inject(int element){
	if(front==-1){
		front = 0;
		rear = 0;
	}
	else if(rear==4)
		rear = 0;
	else
		rear=rear+1;

	dq[rear]=element;

}

int eject(){
	int element=dq[rear];
	dq[rear]=0;
	if(front==rear)
	{
		front = -1;
		rear = -1;
	}
	else if(rear==0)
		rear=4;
	else
		rear = rear-1;

	return element;
}

void push(int element){
	if(front==-1){
		front = 0;
		rear = 0;
	}
	else if(front==0)
		front=4;
	else
		front=front-1;
	dq[front]=element;
}
int pop(){
	int element=dq[front];
	dq[front]=0;
	if(front==rear){
		front = -1;
		rear = -1;
	}
	else if(front==4){
		front=0;
	}
	else
		front = front + 1;
	return element;
}

void display(){
	printf("\nfront = %d and rear = %d",front,rear);
	printf("\nDequeue:");
	for(int i = 0; i<5; i++){
		printf("| %d |",dq[i]);
	}
}
