#include "linkedList.h"

Node* SLL_CreateNode(ElementType newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->nextNode = NULL;
    return newNode;
}

void SLL_DestroyNode(Node* node) {
    free(node);
}

void SLL_DestroyAllNodes(Node** head) {
    int count = SLL_GetNodeCount(*head);
    for (int i = 0; i < count; i++) {
        Node* curr = SLL_GetNodeAt(*head, 0);
        if (curr != NULL) {
            SLL_RemoveNode(head, curr);
            free(curr);
        }
    }
}

void SLL_AppendNode(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* tail = (*head);
        while (tail->nextNode != NULL) {
            tail = tail->nextNode;
        }
        tail->nextNode = newNode;
    }
}

void SLL_InsertAfter(Node* current, Node* newNode) {
    newNode->nextNode = current->nextNode;
    current->nextNode = newNode;
}

void SLL_InsertBefore(Node** head, Node* current, Node* newNode) {
    if (*head == current) {
        newNode->nextNode = *head;
        *head = newNode;
    } else {
        Node* tmpNode = *head;
        while (tmpNode->nextNode != current) {
            tmpNode = tmpNode->nextNode;
        }
        newNode->nextNode = current;
        tmpNode->nextNode = newNode;
    }
}

void SLL_InsertNewHead(Node** head, Node* newHead) {
    if (*head == NULL) {
        *head = newHead;
    } else {
        newHead->nextNode = *head;
        *head = newHead;
    }
}

void SLL_RemoveNode(Node** head, Node* removeNode) {
    if (*head == removeNode) {
        *head = removeNode->nextNode;
    } else {
        Node* current = *head;
        while (current != NULL && current->nextNode != removeNode) {
            current = current->nextNode;
        }
        if (current != NULL) {
            current->nextNode = removeNode->nextNode;
        }
    }
}

Node* SLL_GetNodeAt(Node* head, int index) {
    Node* current = head;
    while (current != NULL && (index--) > 0) {
        current = current->nextNode;
    }
    return current;
}

int SLL_GetNodeCount(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        current = current->nextNode;
        count++;
    }
    return count;
}