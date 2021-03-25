//Create a cyclical doubly linked list. In addition, create a procedure that deletes the biggest number out of the list.
//Armantas Pikšrys 4.8 task

#include "header.h"

int main(int argc, char *argv[])
{
    int index = 1;
    
    node *headNode;
    headNode = NULL;

    while(index)
    {
        printMenu();

        switch(getNumber())
        {
            //Create list
            case 0:
                if(headNode != NULL)
                    headNode = freeCurrentList(headNode);
                
                char fileName[maxChar];
                printf("\nEnter data file name: ");
                scanf("%[^\n]s", fileName);
                printf("\n");

                headNode = createList(headNode, fileName);

                if(headNode == NULL)
                    printf("\nNo data in data file \n");
                else
                    printf("\nSuccessfully created new list from data file \n");
                
                break;
            
            //Print list
            case 1:
                if(headNode != NULL)
                {
                    printf("\nLinked list: ");
                    printList(headNode, headNode);
                    printf("\n");
                }
                else
                    printf("\nList is empty or not created \n");
                
                break;

            //Delete the biggest number
            case 2:
                if(headNode != NULL)
                {
                    headNode = deleteMaxInt(headNode);
                    printf("\n Successfully deleted the maximum value element from list\n");
                }
                else
                    printf("\nList is empty or not created\n");
                
                break;
            
            //Exit program
            case 3:
                if(headNode != NULL)
                    headNode = freeCurrentList(headNode);
                
                printf("\nExiting program...\n");
                index = 0;

                break;

            default:
                printf("\nError! Please enter a correct number \n");

                break;
        }
    }

    return 0;
}