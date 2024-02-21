#include "linkedList.h"

int main() {
    int count = 0;
    Node* linkedList = NULL;
    Node* curr = NULL;
    Node* newNode = NULL;

    // 0 1 2 3 4
    for (int i = 0; i < 5; i++) {
        newNode = SLL_CreateNode(i);
        SLL_AppendNode(&linkedList, newNode);
    }

    // -1 0 1 2 3 4
    newNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&linkedList, newNode);

    // -2 -1 0 1 2 3 4
    newNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&linkedList, newNode);

    // -2 -1 -100 0 1 2 3 4 
    newNode = SLL_CreateNode(-100);
    curr = SLL_GetNodeAt(linkedList, 2);
    SLL_InsertBefore(&linkedList, curr, newNode);

    // -2 -1 -100 100 0 1 2 3 4
    newNode = SLL_CreateNode(100);
    curr = SLL_GetNodeAt(linkedList, 2);
    SLL_InsertAfter(curr, newNode);

    // print all elements of linkedList
    count = SLL_GetNodeCount(linkedList);
    for (int i = 0; i < count; i++) {
        curr = SLL_GetNodeAt(linkedList, i);
        printf("List[%d] : %d\n", i, curr->data);
    }

    printf("\nDestroying List...\n");

    SLL_DestroyAllNodes(&linkedList);
    printf("%d\n", SLL_GetNodeCount(linkedList));

    return 0;
}