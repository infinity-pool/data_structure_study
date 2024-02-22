#include "doublyLinkedList.h"

int main() {
    int count = 0;
    Node* doublyLinkedList = NULL;
    Node* curr = NULL;
    Node* newNode = NULL;

    for (int i = 0; i < 5; i++) {
        newNode = DLL_CreateNode(i);
        DLL_AppendNode(&doublyLinkedList, newNode);
    }

    // 0 1 2 3 4
    count = DLL_GetNodeCount(doublyLinkedList);
    for (int i = 0; i < count; i++) {
        curr = DLL_GetNodeAt(doublyLinkedList, i);
        printf("List[%d]: %d\n", i, curr->data);
    }

    printf("\nInsert 3000 after [2]...\n");

    curr = DLL_GetNodeAt(doublyLinkedList, 2);
    newNode = DLL_CreateNode(3000);
    DLL_InsertAfter(curr, newNode);

    // 0 1 2 3000 3 4
    count = DLL_GetNodeCount(doublyLinkedList);
    for (int i = 0; i < count; i++) {
        curr = DLL_GetNodeAt(doublyLinkedList, i);
        printf("List[%d]: %d\n", i, curr->data);
    }

    PrintReverse(doublyLinkedList);

    printf("\nDestroying List...\n");
    count = DLL_GetNodeCount(doublyLinkedList);
    for (int i = 0; i < count; i++) {
        curr = DLL_GetNodeAt(doublyLinkedList, 0);
        if (curr != NULL) {
            DLL_RemoveNode(&doublyLinkedList, curr);
            DLL_DestroyNode(curr);
        }
    }
    printf("%d\n", DLL_GetNodeCount(doublyLinkedList));

    return 0;
}