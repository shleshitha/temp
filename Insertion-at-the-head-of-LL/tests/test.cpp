#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// ListNode definition
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

// Solution class
class Solution {
public:
    ListNode* insertAtHead(ListNode*& head, int X) {
        ListNode* newNode = new ListNode(X);
        newNode->next = head;
        head = newNode;
        return head;
    }
};

// Utility to create a linked list from vector
ListNode* createList(vector<int>& arr) {
    ListNode* head = nullptr;
    for (int i = arr.size() - 1; i >= 0; --i) {
        ListNode* newNode = new ListNode(arr[i]);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// Utility to convert linked list to vector
vector<int> listToArray(ListNode* head) {
    vector<int> result;
    while (head) {
        result.push_back(head->data);
        head = head->next;
    }
    return result;
}

// Test function
void runTestCase(vector<int> inputList, int X, vector<int> expectedList, int* passed, int* total) {
    (*total)++;
    ListNode* head = createList(inputList);
    head = Solution().insertAtHead(head, X);
    vector<int> outputList = listToArray(head);
    if (outputList == expectedList) {
        cout << "Test case passed\n";
        (*passed)++;
    } else {
        cout << "Test case failed\n";
        cout << "Expected: ";
        for (int x : expectedList) cout << x << " ";
        cout << "\nGot: ";
        for (int x : outputList) cout << x << " ";
        cout << endl;
    }
}

// Main function with 10 test cases
int main() {
    int passed = 0, total = 0;

    runTestCase({1, 2, 3}, 0, {0, 1, 2, 3}, &passed, &total);           // Insert at head, normal list
    runTestCase({}, 10, {10}, &passed, &total);                        // Insert in empty list
    runTestCase({5}, 7, {7, 5}, &passed, &total);                      // Insert at head, single node
    runTestCase({-1, -2, -3}, -4, {-4, -1, -2, -3}, &passed, &total);  // Negative values
    runTestCase({100, 200}, 300, {300, 100, 200}, &passed, &total);    // Larger integers
    runTestCase({1, 1, 1}, 1, {1, 1, 1, 1}, &passed, &total);          // All elements the same
    runTestCase({9, 8, 7}, 10, {10, 9, 8, 7}, &passed, &total);        // Increasing head insert
    runTestCase({0}, 0, {0, 0}, &passed, &total);                      // Insert 0 at head
    runTestCase({INT_MAX}, INT_MIN, {INT_MIN, INT_MAX}, &passed, &total); // Edge int values
    runTestCase({2, 4, 6, 8}, 1, {1, 2, 4, 6, 8}, &passed, &total);    // General even list

    cout << passed << "/" << total << " test cases passed." << endl;
    return 0;
}
