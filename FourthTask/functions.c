#include "header.h"

//Procedure that creates a doubly linked list
node *createList(node *headNode, char argv[])
{
    FILE *fi; //fi - input file
    fi = fopen(argv, "r");

    if(fi == NULL) //If file doesnt exist returns NULL
    {
        printf("\nError! Could not open data file\n");
        exit(1);
    }

    int number;

    if(fscanf(fi, "%d", &number) != 1)
        return headNode;
    else
        headNode = getNewNode(number);

    while(!feof(fi))
    {
        if(fscanf(fi, "%d", &number) != 1)
            fgetc(fi);
        else
            headNode = addAtEnd(headNode, number);
    }
        
    headNode = fixListEnds(headNode);

    fclose(fi);

    return headNode;
}

//Procedure creates a new list Node and puts the passed value in the Node
node *getNewNode(int number)
{
    node *newNode = (node*)malloc(sizeof(node));

    newNode -> number = number;
    newNode -> previous = NULL;
    newNode -> next = NULL;

    return newNode;
}

//Procedure add a new Node at the end of an existing list 
node *addAtEnd(node *headNode, int number)
{
    node *newNode, *tempHeadNode;

    newNode = getNewNode(number);

    tempHeadNode = headNode;

    while(tempHeadNode -> next != NULL)
        tempHeadNode = tempHeadNode -> next;

    tempHeadNode -> next = newNode;
    newNode -> previous = tempHeadNode;
    
    return headNode;
}

//Procedure that creates the doubly linked list cyclical
node *fixListEnds(node *headNode)
{
    node *tempNode = headNode;

    while(tempNode -> next != NULL)
        tempNode = tempNode -> next;

    tempNode -> next = headNode;
    headNode -> previous = tempNode;

    return headNode;
}

//Procedure that frees the current list
node *freeCurrentList(node *headNode)
{
    assert(headNode != NULL);
    assert(headNode -> next != NULL);
    assert(headNode -> previous != NULL);

    node *tempNode = headNode, *freeTempNode;

    printf("\nFirstly, freeing previous list...\n");

    while(tempNode -> next != headNode)
    {
        freeTempNode = tempNode;
        tempNode = tempNode -> next;

        assert(tempNode != NULL);

        if(freeTempNode != headNode)
            free(freeTempNode);
    }

    free(headNode);
    headNode = NULL;

    return headNode;
}

//Procedure that deletes the Node which contains the biggest number
node *deleteMaxInt(node *headNode)
{
    assert(headNode != NULL);

    node *tempNode = headNode, *nextTempNode, *removedNode = headNode;
    int maxNumber = headNode -> number;

    assert(&maxNumber != NULL);

    //Finding the Node with the biggest number
    while(tempNode -> next != headNode)
    {
        tempNode = tempNode -> next;

        assert(tempNode != NULL);
        assert(&(tempNode -> number) != NULL);

        if(tempNode -> number > maxNumber)
        {
            maxNumber = tempNode -> number;
            removedNode = tempNode;
        }
    }
    
    //Deleting the Node with the biggest number
    if(removedNode != headNode)
    {
        assert(removedNode != NULL);
        assert(removedNode -> previous != NULL);
        assert(removedNode -> next != NULL);

        tempNode = removedNode -> previous; //Case, when deleting not from the start of the list 
        nextTempNode = removedNode -> next;
        nextTempNode -> previous = tempNode;
        tempNode -> next = nextTempNode;

        free(removedNode);
    }
    else
    {
        tempNode = headNode;

        assert(tempNode -> next != NULL);
        assert(tempNode -> previous != NULL);

        if(headNode == tempNode -> next) //Case, when there is only the headNode left in the list
        {
            free(headNode);
            headNode = NULL;
        }
        else
        {
            nextTempNode = headNode -> next; //Case, when the deleted Node is the headNode but there are other elements still in the list
            nextTempNode -> previous = headNode -> previous;
            tempNode = headNode -> previous;
            tempNode -> next = nextTempNode;
            free(headNode);

            return nextTempNode;
        }
    }

    return headNode;
}

//Procedure to get an integer number out of the user in the console, validation is applied
int getNumber()
{
	int number=0, index=0;
	while(index == 0)
    {
        if((scanf("%d", &number) == 0) || (getchar() != '\n'))
        {
            printf("\nBad number format, try again\n");
            while(getchar() != '\n'); 
        }
        else 
            index=1;
	}

    assert(&number != NULL);

    return number;
}

//Print menu
void printMenu()
{
    printf(" _______________________________________________________\n");
    printf("|Program menu, press number and enter to perform action |\n");
    printf("|_______________________________________________________|\n");
    printf("| 0 - Create list from data file                        |\n");
    printf("| 1 - Print current list                                |\n");
    printf("| 2 - Remove the largest data value from list           |\n");
    printf("| 3 - Exit program                                      |\n");
    printf("|_______________________________________________________|\n");

    return;
}

//Procedure that prints the current list using recursion
void printList(node *printNode, node *headNode)
{
    assert(printNode != NULL);
    assert(headNode != NULL);

    node *tempNode = printNode;

    printf("%d ", tempNode -> number);
    tempNode = tempNode -> next;

    assert(tempNode != NULL);

    if(tempNode != headNode)
        printList(tempNode, headNode);
    else
        return;

    return;
}