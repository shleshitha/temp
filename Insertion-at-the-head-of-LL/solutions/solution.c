#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* insertAtHead(struct ListNode* head, int X) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = X;
    newNode->next = head;
    head = newNode;
    return head;
}
