#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node * next;
	struct node *prev;
}NODE , *PNODE;

class DoublyCL
{
private:
	PNODE Head;
	PNODE Tail;
	int iSize;

public:
	DoublyCL()
	{
		Head = NULL;
		Tail = NULL;
		iSize = 0;
	}

	void InsertFirst(int);
	void InsertLast(int);
	void InsertAtPosition(int , int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPosition(int);
	void Display();
	int Count();
};

void DoublyCL::InsertFirst(int iNo)
{
	PNODE newn = NULL;
	newn = new NODE;
	newn->data = iNo;
	newn->next = NULL;
	newn->prev = NULL;

	if((Head==NULL) && (Tail==NULL))
	{
		Head = newn;
		Tail = newn;	
	}
	else 
	{
		newn->next = Head;
		Head->prev = newn;
		Head = newn;
	}
	Tail->next = Head;
	Head->prev = Tail;
	iSize++;
}

void DoublyCL::InsertLast(int iNo)
{
	PNODE newn = NULL;
	newn = new NODE;
	newn->data = iNo;
	newn->next = NULL;
	newn->prev = NULL;

	if((Head==NULL) && (Tail==NULL))
	{
		Head = newn;
		Tail = newn;	
	}
	else 
	{
		Tail->next = newn;
		newn->prev = Tail;
		Tail = newn;
	}
	Tail->next = Head;
	Head->prev = Tail;
	iSize++;
}

void DoublyCL::InsertAtPosition(int iNo, int iPos)
{
	if((iPos<1) || (iPos>iSize+1))
	{
		return;
	}
	if(iPos == 1)
	{
		InsertFirst(iNo);
	}
	else if(iPos == iSize+1)
	{
		InsertLast(iNo);
	}
	else
	{
		PNODE newn = new NODE;
		newn->data = iNo;
		newn->prev = NULL;
		newn->next = NULL;

		PNODE temp = Head;
		for(int i=1;i<iPos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
		iSize++;
	}
}

void DoublyCL::DeleteFirst()
{
	if(iSize == 0)
	{
		return;
	}
	else if(iSize == 1)
	{
		delete Head;
		Head = NULL;
		Tail =NULL;
		iSize = 0;
	}
	else
	{
		Head = Head->next;
		delete Head->prev;
		Head->prev = Tail;
		Tail->next = Head;
		iSize--;
	}
}

void DoublyCL::DeleteLast()
{
	if(iSize == 0)
	{
		return;
	}
	else if(iSize == 1)
	{
		delete Head;
		Head = NULL;
		Tail =NULL;
		iSize = 0;
	}
	else
	{
		Tail = Tail->prev;
		delete Tail->next;
		Tail->next = Head;
		Head->prev = Tail;
		iSize--;
	}
}

void DoublyCL::DeleteAtPosition(int iPos)
{
	if((iPos<1) || (iPos>iSize))
	{
		return;
	}
	if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == iSize)
	{
		DeleteLast();
	}
	else
	{
		PNODE temp = Head;
		for(int i=1;i<iPos-1;i++)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
		delete temp->next->prev;
		temp->next->prev = temp;
		iSize--;
	}
}

void DoublyCL::Display()
{
	PNODE temp = Head;
	for(int i=1;i<=iSize;i++)
	{
		cout<<"|"<<temp->data<<"|->";
		temp = temp->next;
	}
	cout<<"\n";
}

int DoublyCL::Count()
{
	return iSize;
}

int main()
{
	int iChoice = 1, iNo = 0, iRet = 0, iPos = 0;
	DoublyCL obj;

	while(iChoice != 0)
	{
		cout<<"Enter your choice:\n";
		cout<<"1 : Insert first"<<endl;
		cout<<"2 : Insert last"<<endl;
		cout<<"3 : Insert at position"<<endl;
		cout<<"4 : Delete first"<<endl;
		cout<<"5 : Delete last"<<endl;
		cout<<"6 : Delete at position"<<endl;
		cout<<"7 : Display the elements"<<endl;
		cout<<"8 : Count the elements"<<endl;
		cout<<"0 : Exit the application"<<endl;
		cin>>iChoice;

		switch(iChoice)
		{
			case 1:
				cout<<"Enter the number\n";
				cin>>iNo;
				obj.InsertFirst(iNo);
				break;
			case 2:
				cout<<"Enter the number\n";
				cin>>iNo;
				obj.InsertLast(iNo);
				break;
			case 3:
				cout<<"Enter the number\n";
				cin>>iNo;
				cout<<"Enter the position\n";
				cin>>iPos;
				obj.InsertAtPosition(iNo,iPos);
				break;
			case 4:
				obj.DeleteFirst();
				break;
			case 5:
				obj.DeleteLast();
				break;
			case 6:
				cout<<"Enter the position\n";
				cin>>iPos;
				obj.DeleteAtPosition(iPos);
				break;
			case 7:
				cout<<"Elements of LL are : \n";
				obj.Display();
				break;
			case 8:
				iRet = obj.Count();
				cout<<"Number of nodes are : "<<iRet<<endl;
				break;
			case 0:
				cout<<"Thankyou for using application\n";
				break;
			default:
				cout<<"Please enter proper option\n";
				break;	 
		}

	}
	return 0;
}