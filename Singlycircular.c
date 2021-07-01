#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;



int main()
{
    PNODE First = NULL;
    PNODE Last = NULL;
    int iRet = 0, iOption = 1, iValue = 0, iPos=0;
    
    while(iOption != 0)
    {
        printf("\n____________________________________\n");
        printf("Enter your action on Linked list : \n");
        printf("1 : Insert node at first position\n");
        printf("2 : Insert node at last position\n");
        printf("3 : Insert node at given position\n");
		printf("4 : Delete first node\n");
        printf("5 : Delete last node\n");
        printf("6 : Delete node at given position\n");
        printf("7 : Display the contents of linked list\n");
        printf("8 : Count number of nodes of linked list\n");
        printf("0 : Exit the application\n");
        scanf("%d",&iOption);
        printf("\n____________________________________\n");
        
        switch(iOption)
        {
            case 1 :
                printf("Enter data to insert : \n");
                scanf("%d",&iValue);
                InsertFirst(&First,&Last,iValue);
                break;
                
            case 2 :
                printf("Enter data to insert : \n");
                scanf("%d",&iValue);
                InsertLast(&First,&Last,iValue);
                break;

            case 3 :
                printf("Enter data to insert : \n");
                scanf("%d",&iValue);
                printf("Enter the position\n");
                scanf("%d",&iPos);
                InsertAtPosition(&First,&Last,iValue,iPos);
                break;

            case 4 :
            	DeleteFirst(&First,&Last);
            	break;

            case 5 :
            	DeleteLast(&First,&Last);
            	break;

            case 6 :
            	printf("Enter the position\n");
            	scanf("%d",&iPos);
            	DeleteAtPosition(&First,&Last, iPos);
            	break;
                
            case 7 :
                printf("Nodes of linked list are : \n");
                Display(First,Last);
                break;

			case 8 :
                iRet = Count(First,Last);
                printf("Number of nodes are : %d\n",iRet);
                break;
                
            case 0:
                printf("Thank you for using Marvellous Linked list application \n");
                break;
                
            default:
                printf("Please enter valid option \n");
                break;

        } 
    } 

    return 0;

} 
