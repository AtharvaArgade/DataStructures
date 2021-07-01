#include<iostream>
using namespace std;


typedef struct node
{
	int data;
	struct node *next;
}NODE, * PNODE;

class Stack
{
private:
	PNODE Head;
	int iSize;

public:
	Stack();		 
	~Stack();		 
	void Push(int);  
	int Pop();		
	int Peek();     
	void Display();
	int Count();
};

Stack :: Stack()
{
	cout<<"Inside Constructor\n";
	this->Head = NULL;     // Head = NULL;
	this->iSize = 0;
}

Stack :: ~Stack()
{
	cout<<"Inside Destructor\n";
	PNODE temp = NULL;

	while(Head != NULL)
	{
		temp = Head;
		Head = Head->next;
		delete temp;
	}
}

void Stack :: Push(int iNo)
{
	PNODE newn = new NODE;
	newn->data = iNo;
	newn->next = NULL;

	newn->next = Head;
	Head = newn;
	iSize++;
}

int Stack :: Pop()
{
	int iRet = -1;

	if(iSize == 0)
	{
		cout<<"Stack is empty\n";
	}
	else
	{
		PNODE temp  = Head;

		Head = Head->next;
		iRet = temp->data;
		delete temp;
		iSize--;
	}
	return iRet;
}

void Stack :: Display()
{
	PNODE temp = Head;

	while(temp != NULL)
	{
		cout<<temp->data<<"\t";
		temp = temp->next;
	}
	cout<<"\n";
}

int Stack :: Count()
{
	return this->iSize;
}

int Stack :: Peek()
{
	if(iSize == 0)
	{
		cout<<"Stack is empty\n";
		return -1;
	}
	else
	{
		return Head->data;
	}
}

int main()
{
	Stack *sobj = new Stack;   // Stack sobj;   It implicitly calls the constructor

	int iChoice = 1, iNo = 0, iRet = 0;

	while(iChoice != 0)
	{
		cout<<"Enter your choice\n";
		cout<<"1 : Push the element\n";
		cout<<"2 : Pop the element\n";
		cout<<"3 : Display the elements of stack\n";
		cout<<"4 : Count the elements in stack\n";
		cout<<"5 : Peek the element\n";
		cout<<"0 : Exit the application\n";	
		cin>>iChoice;

		switch(iChoice)
		{
			case 1:
				cout<<"Enter the element to push\n";
				cin>>iNo;
				sobj->Push(iNo);
				break;

			case 2:
				iRet = sobj->Pop();
				cout<<"Poped element is "<<iRet<<endl;
				break;

			case 3:
				cout<<"Elements of the stack are : \n";
				sobj->Display();
				break;

			case 4:
				iRet = sobj->Count();
				cout<<"Number of elements in stack are "<<iRet<<endl;
				break;

			case 5:
				iRet = sobj->Peek();
				cout<<"Value of top element is : "<<iRet<<endl;
				break;

			case 0:
				cout<<"Thankyou for using the application\n";
				delete sobj;    // It implicitly calls the destructor
				break;
				
			default:
				cout<<"Please enter the valid choice\n";
				break;
		}
	}
	return 0;
}
