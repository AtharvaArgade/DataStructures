using namespace std;

#include<iostream>

typedef struct node
{
	int data;
	struct node * next;
	struct node * prev;
}NODE, *PNODE;

class DoublyLL
{
private:
	PNODE Head;
	int iSize;

public:
	DoublyLL()
	{
		Head = NULL;
		iSize = 0;
	}

	int Count()
	{
		return iSize;
	}

	void InsertFirst(int iValue)
	{
		PNODE newn = NULL;
		newn = new NODE;
		newn->data = iValue;
		newn->next = NULL;
		newn->prev = NULL;

		if(Head == NULL)
		{
			Head = newn;
		}
		else
		{
			newn->next = Head;
			Head->prev = newn;
			Head = newn;
		}
		iSize++;
	}

	void InsertLast(int iValue)
	{
		PNODE newn = NULL;
		newn = new NODE;
		newn->data = iValue;
		newn->next = NULL;
		newn->prev = NULL;

		PNODE temp = Head;

		if(Head == NULL)
		{
			Head = newn;
		}
		else
		{
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newn;
			newn->prev = temp;
		}
		iSize++;
	}

	void Display()
	{
		PNODE temp = Head;
		while(temp != NULL)
		{
			cout<<"|"<<temp->data<<"|->";
			temp = temp->next;
		}
		cout<<"NULL"<<endl;
	}

	void DeleteFirst()
	{
		if(Head == NULL)
		{
			return;
		}
		else if(Head->next == NULL)
		{
			delete Head;
			Head = NULL;
			iSize--;
		}
		else
		{
			Head = Head->next;
			delete Head->prev;
			Head->prev = NULL;
			iSize--;
		}
	}

	void DeleteLast()
	{
		if(Head == NULL)
		{
			return;
		}
		else if(Head->next == NULL)
		{
			delete Head;
			Head = NULL;
			iSize--;
		}
		else
		{
			PNODE temp = Head;
			while(temp->next->next != NULL)
			{
				temp = temp->next;
			}
			delete temp->next;
			temp->next = NULL;
			iSize--;
		}
	}

	void InsertAtPosition(int iValue, int iPos)
	{
		if((iPos<1) || (iPos>iSize+1))
		{
			return;
		}

		if(iPos == 1)
		{
			InsertFirst(iValue);
		}
		else if(iPos == iSize+1)
		{
			InsertLast(iValue);
		}
		else
		{
			PNODE temp = Head;
			PNODE newn = NULL;
			newn = new NODE;
			newn->data = iValue;
			newn->next = NULL;
			newn->prev = NULL;

			for(int i=1;i<iPos-1;i++)
			{
				temp = temp->next;
			}

			newn->next = temp->next;
			temp->next->prev = newn;
			temp->next=newn;
			newn->prev = temp;
			iSize++;
		}
	}

	void DeleteAtPosition(int iPos)
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
};

int main()
{
	int iChoice = 1, iNo = 0, iPos = 0;

	DoublyLL obj1;

	while(iChoice != 0)
	{
		cout<<"Enter your choice : "<<"\n";
		cout<<"1 : Insert at first position"<<endl;
		cout<<"2 : Insert at last position"<<endl;
		cout<<"3 : Insert at given position"<<endl;
		cout<<"4 : Delete at first position"<<endl;
		cout<<"5 : Delete at last position"<<endl;
		cout<<"6 : Delete at given position"<<endl;
		cout<<"7 : Display the contents"<<endl;
		cout<<"8 : Count the number os nodes"<<endl;
		cout<<"0 : Exit the application"<<endl;
		cin>>iChoice;

		switch(iChoice)
		{
			case 1:
				cout<<"Enter number\n";
				cin>>iNo;
				obj1.InsertFirst(iNo);
				break;
			case 2:
				cout<<"Enter number\n";
				cin>>iNo;
				obj1.InsertLast(iNo);
				break;
			case 3:
				cout<<"Enter the number\n";
				cin>>iNo;
				cout<<"Enter the position"<<endl;
				cin>>iPos;
				obj1.InsertAtPosition(iNo, iPos);
				break;
			case 4:
				obj1.DeleteFirst();
				break;
			case 5:
				obj1.DeleteLast();
				break;
			case 6:
				cout<<"Enter position\n";
				cin>>iPos;
				obj1.DeleteAtPosition(iPos);
				break;
			case 7:
				obj1.Display();
				break;
			case 8:
				iNo = obj1.Count();
				cout<<"Number of elements are : "<<iNo<<endl;
				break;
			case 0:
				cout<<"Thankyou for using the application !\n";
				break;
			default:
				cout<<"Please select the proper choice\n";
		}

	}
	return 0;
}
