#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct _Node {
    ElementType data;
    struct _Node* nextNode;
} Node;

Node* SLL_CreateNode(ElementType newData);
void SLL_DestroyNode(Node* node);
void SLL_DestroyAllNodes(Node** head);
void SLL_AppendNode(Node** head, Node* newNode);
void SLL_InsertAfter(Node* current, Node* newNode);
void SLL_InsertBefore(Node** head, Node* current, Node* newNode);
void SLL_InsertNewHead(Node** head, Node* newHead);
void SLL_RemoveNode(Node** head, Node* removeNode);
Node* SLL_GetNodeAt(Node* head, int index);
int SLL_GetNodeCount(Node* head);

#endif