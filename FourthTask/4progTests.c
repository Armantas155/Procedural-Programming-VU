
#include "header.h"

int main(int argc, char *argv[])
{
    printf("\nTesting program...\n");

    node *headNode, *tempNode, *nextTempNode;
    headNode = NULL;

    //GetNewNode() testing
    headNode = getNewNode(5);

    assert(headNode != NULL);
    assert(headNode -> number == 5);
    assert(headNode -> next == NULL);
    assert(headNode -> previous == NULL);

    //addAtEnd() and fixListEnds() testing, testing both at the same time, because addAtEnd() create a simple linked list and fixListEnds() turns it into doubly linked list
    headNode = addAtEnd(headNode, 10);
    headNode = addAtEnd(headNode, 15);
    headNode = addAtEnd(headNode, 20);
    headNode = fixListEnds(headNode);

    tempNode = headNode;

    for(int i = 1; i <= 4; ++i) //testing doubly linked list: (5, 10, 15, 20)
    {
        assert(tempNode != NULL);
        assert(tempNode -> number == (i * 5));
        assert(tempNode -> next != NULL);
        assert(tempNode -> previous != NULL);

        tempNode = tempNode -> next;
    }

    //deleteMaxInt() testing, current list (5, 10, 15, 20), testing: biggest element deletion from the end and the start leaving an empty list
    int counter = 20;

    while(headNode != NULL)
    {
        tempNode = headNode -> previous; //testing the first element after deletion

        assert(tempNode != NULL);
        assert(tempNode -> next != NULL);
        assert(tempNode -> previous != NULL);
        assert(tempNode -> number == counter);

        counter -= 5;
        headNode = deleteMaxInt(headNode);
    }

    assert(headNode == NULL);

    //deleteMaxInt() testing, current list (20, 15, 10, 5), testing: biggest element deletion from the start, the headNode
    headNode = getNewNode(20);
    headNode = addAtEnd(headNode, 15);
    headNode = addAtEnd(headNode, 10);
    headNode = addAtEnd(headNode, 5);
    headNode = fixListEnds(headNode);

    counter = 20;

    while(headNode != NULL)
    {
        assert(headNode != NULL); //testing the first element after deletion
        assert(headNode -> next != NULL);
        assert(headNode -> previous != NULL);
        assert(headNode -> number == counter);

        counter -= 5;
        headNode = deleteMaxInt(headNode);
    }

    assert(headNode == NULL);

    //deleteMaxInt() testing, current list (2, 15, 2), testing: biggest element deletion from the middle
    headNode = getNewNode(2);
    headNode = addAtEnd(headNode, 15);
    headNode = addAtEnd(headNode, 2);
    headNode = fixListEnds(headNode);

    tempNode = headNode -> next; //second element 15

    assert(tempNode -> number == 15);

    headNode = deleteMaxInt(headNode);
    tempNode = headNode -> next; //after deletion second element should be 2

    assert(tempNode != NULL);
    assert(tempNode -> previous == headNode);
    assert(tempNode -> next == headNode);
    assert(tempNode -> number == 2);

    //freeCurrentList() testing, headNode should be NULL
    headNode = getNewNode(2);
    headNode = addAtEnd(headNode, 15);
    headNode = addAtEnd(headNode, 2);
    headNode = fixListEnds(headNode);

    assert(headNode != NULL);

    headNode = freeCurrentList(headNode);

    assert(headNode == NULL);

    printf("\nTesting success...\n");

    return 0;
}