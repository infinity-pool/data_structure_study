#include "linkedList.h"

int main() {
    int count = 0;
    Node* singlyLinkedList = NULL;
    Node* curr = NULL;
    Node* newNode = NULL;

    // 0 1 2 3 4
    for (int i = 0; i < 5; i++) {
        newNode = SLL_CreateNode(i);
        SLL_AppendNode(&singlyLinkedList, newNode);
    }

    // -1 0 1 2 3 4
    newNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&singlyLinkedList, newNode);

    // -2 -1 0 1 2 3 4
    newNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&singlyLinkedList, newNode);

    // -2 -1 -100 0 1 2 3 4 
    newNode = SLL_CreateNode(-100);
    curr = SLL_GetNodeAt(singlyLinkedList, 2);
    SLL_InsertBefore(&singlyLinkedList, curr, newNode);

    // -2 -1 -100 100 0 1 2 3 4
    newNode = SLL_CreateNode(100);
    curr = SLL_GetNodeAt(singlyLinkedList, 2);
    SLL_InsertAfter(curr, newNode);

    // print all elements of linkedList
    count = SLL_GetNodeCount(singlyLinkedList);
    for (int i = 0; i < count; i++) {
        curr = SLL_GetNodeAt(singlyLinkedList, i);
        printf("List[%d] : %d\n", i, curr->data);
    }

    printf("\nDestroying List...\n");

    SLL_DestroyAllNodes(&singlyLinkedList);
    printf("%d\n", SLL_GetNodeCount(singlyLinkedList));

    return 0;
}