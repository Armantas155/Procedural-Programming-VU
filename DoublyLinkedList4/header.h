#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

typedef struct node
{
    int number;
    struct node *previous;
    struct node *next;
}node;

#define maxChar 255

node *createList(node *headNode, char file[]);
node *getNewNode(int number);
node *addAtEnd(node *headNode, int number);
node *fixListEnds(node *headNode);
node *freeCurrentList(node *headNode);
node *deleteMaxInt(node *headNode);
int getNumber();
void printMenu();
void printList(node *headNode, node *nextNode);

#endif