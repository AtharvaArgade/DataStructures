#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE, *PNODE;

class SinglyCL
{
private:
	PNODE Head;
	PNODE Tail;
	int iSize;
public:
	SinglyCL()
	{
		Head = NULL;
		Tail = NULL;
		iSize = 0;
	}

	void InsertFirst(int iNo)
	{
		PNODE newn = NULL;
		newn = new NODE;
		newn->data = iNo;
		newn->next = NULL;

		if((Head == NULL) && (Tail == NULL))
		{
			Head = newn;
			Tail = newn;
		}
		else
		{
			newn->next = Head;
			Head = newn;
		}

		iSize++;
		Tail->next = Head;
	}

	void InsertLast(int iNo)
	{
		PNODE newn = NULL;
		newn = new NODE;
		newn->data = iNo;
		newn->next = NULL;

		if((Head == NULL) && (Tail == NULL))
		{
			Head = newn;
			Tail = newn;	
		}
		else
		{
			Tail->next = newn;
			Tail = newn;
		}

		iSize++;
		Tail->next = Head;
	}

	void DeleteLast()
	{
		if(iSize == 0)
		{
			return;
		}
		else if(iSize == 1)
		{
			delete Head;
			Head = NULL;
			Tail = NULL;
			iSize--;
		}
		else
		{
			PNODE temp = Head;
			for(int i = 1;i<iSize-1;i++)
			{
				temp = temp->next;
			}
			delete Tail;
			Tail = temp;
			Tail->next = Head;
			iSize--;
		}
	}

	void DeleteFirst()
	{
		if(iSize == 0)
		{
			return;
		}
		else if(iSize == 1)
		{
			delete Head;
			Head = NULL;
			Tail = NULL;
			iSize--;
		}
		else
		{
			Head = Head->next;
			delete Tail->next;
			Tail->next = Head;
			iSize--;	
		}
	}

	int Count()
	{
		return iSize;
	}

	void Display()
	{
		PNODE temp = Head;
		int i=0;
		for(i=1;i<=iSize;i++)
		{
			cout<<"|"<<temp->data<<"|->";
			temp = temp->next;
		}
		cout<<"NULL"<<endl;
	}

	void InsertAtPosition(int iValue, int iPos)
	{
		if((iPos<1) || (iPos>iSize+1))
		{
			return;
		}

		if(iPos==1)
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

			for(int i=1;i<iPos-1;i++)
			{
				temp = temp->next;
			}
			newn->next = temp->next;
			temp->next = newn;
			iSize++;
		}
	}

	void DeleteAtPosition(int iPos)
	{
		if((iPos<1) || (iPos>iSize))
		{
			return;
		}

		if(iPos==1)
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
			PNODE target = NULL;

			for(int i=1;i<iPos-1;i++)
			{
				temp = temp->next;
			}
			target = temp->next;
			temp->next = temp->next->next;
			delete target;
			iSize--;
		}
	}
};

int main()
{
	SinglyCL obj;
	int iChoice = 1, iRet = 0, iPos = 0, iValue = 0;

	while(iChoice != 0)
	{
		cout<<"Enter your choice"<<endl;
		cout<<"1: Insert First"<<endl;
		cout<<"2: Insert Last"<<endl;
		cout<<"3: Insert at position"<<endl;
		cout<<"4: Delete first"<<endl;
		cout<<"5: Delete last"<<endl;
		cout<<"6: Delete at position"<<endl;
		cout<<"7: Display list"<<endl;
		cout<<"8: count number of elements"<<endl;
		cout<<"0: Exit the application"<<endl;
		cin>>iChoice;

		switch(iChoice)
		{
			case 1:
				cout<<"Enter the number"<<endl;
				cin>>iValue;
				obj.InsertFirst(iValue);
				break;
			case 2:
				cout<<"Enter the number"<<endl;
				cin>>iValue;
				obj.InsertLast(iValue);
				break;
			case 3:
				cout<<"Enter the number"<<endl;
				cin>>iValue;
				cout<<"Enter the position"<<endl;
				cin>>iPos;
				obj.InsertAtPosition(iValue, iPos);
				break;
			case 4:
				obj.DeleteFirst();
				break;
			case 5:
				obj.DeleteLast();
				break;
			case 6:
				cout<<"Enter the position"<<endl;
				cin>>iPos;
				obj.DeleteAtPosition(iPos);
				break;
			case 7:
				obj.Display();
				break;
			case 8:
				iRet = obj.Count();
				cout<<"Number of nodes are : "<<iRet<<endl;
				break;
			case 0:
				cout<<"Thankyou for using Application"<<endl;
				break;
			default:
				cout<<"Please select the proper choice\n";
				break;
		}
	}

	return 0;
}