#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct _Node {
    ElementType data;
    struct _Node* prevNode;
    struct _Node* nextNode;
} Node;

Node* DLL_CreateNode(ElementType newData);
void DLL_DestroyNode(Node* node);
void DLL_AppendNode(Node** head, Node* newNode);
void DLL_InsertAfter(Node* current, Node* newNode);
void DLL_RemoveNode(Node** head, Node* removeNode);
Node* DLL_GetNodeAt(Node* head, int index);
int DLL_GetNodeCount(Node* head);
void PrintNode(Node* node);
void PrintReverse(Node* head);

#endif