#include <stack>
#include <unordered_map>
#include <string>  // Required for std::string
using namespace std; 
 
// ListNode.h
#ifndef LISTNODE_H
#define LISTNODE_H

struct ListNode {
    int data;
    ListNode* next;

    ListNode(int val) {
        data = val;
        next = nullptr;
    }
};

#endif


class Solution {
    public:
        ListNode* insertAtHead(ListNode* &head, int X) {
            ListNode* newNode = new ListNode(X);
            newNode->next = head;
            head = newNode;  
            return head; 
        }
    };
    
