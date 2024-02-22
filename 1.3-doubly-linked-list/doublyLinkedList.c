#include "doublyLinkedList.h"

Node* DLL_CreateNode(ElementType newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->prevNode = NULL;
    newNode->nextNode = NULL;
    return newNode;
}

void DLL_DestroyNode(Node* node) {
    free(node);
}

void DLL_AppendNode(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* tail = (*head);
        while (tail->nextNode != NULL) {
            tail = tail->nextNode;
        }
        tail->nextNode = newNode;
        newNode->prevNode = tail;
    }
}

void DLL_InsertAfter(Node* current, Node* newNode) {
    newNode->nextNode = current->nextNode;
    newNode->prevNode = current;

    if (current->nextNode != NULL) {
        current->nextNode->prevNode = newNode;
    }
    current->nextNode = newNode;
}

void DLL_RemoveNode(Node** head, Node* removeNode) {
    if (*head == removeNode) {
        *head = removeNode->nextNode;
        if (*head != NULL)
            (*head)->prevNode = NULL;
        removeNode->prevNode = NULL;
        removeNode->nextNode = NULL;
    } else {
        Node* tmp = removeNode;
        if (removeNode->prevNode != NULL)
            removeNode->prevNode ->nextNode = tmp->nextNode;
        if (removeNode->nextNode != NULL)
            removeNode->nextNode->prevNode = tmp->prevNode;
        removeNode->prevNode = NULL;
        removeNode->nextNode = NULL;
    }
}

Node* DLL_GetNodeAt(Node* head, int index) {
    Node* current = head;
    while (current != NULL && (index--) > 0) {
        current = current->nextNode;
    }
    return current;
}

int DLL_GetNodeCount(Node* head) {
    unsigned int count = 0;
    Node* current = head;
    while (current != NULL) {
        current = current->nextNode;
        count++;
    }
    return count;
}

void printNode(Node* node) {
    if (node->prevNode == NULL)
        printf("Prev: NULL ");
    else
        printf("Prev: %d ", node->prevNode->data);
    printf("Current: %d ", node->data);
    if (node->nextNode == NULL)
        printf("Next: NULL\n");
    else
        printf("Next: %d\n", node->nextNode->data);
}