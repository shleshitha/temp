#include <iostream>
#include <vector>
#include <climits>
#include "../solutions/solution.cpp"  // This file already has ListNode and Solution

using namespace std;

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

// Main function
int main() {
    int passed = 0, total = 0;

    runTestCase({1, 2, 3}, 0, {0, 1, 2, 3}, &passed, &total);
    runTestCase({}, 10, {10}, &passed, &total);
    runTestCase({5}, 7, {7, 5}, &passed, &total);
    runTestCase({-1, -2, -3}, -4, {-4, -1, -2, -3}, &passed, &total);
    runTestCase({100, 200}, 300, {300, 100, 200}, &passed, &total);
    runTestCase({1, 1, 1}, 1, {1, 1, 1, 1}, &passed, &total);
    runTestCase({9, 8, 7}, 10, {10, 9, 8, 7}, &passed, &total);
    runTestCase({0}, 0, {0, 0}, &passed, &total);
    runTestCase({INT_MAX}, INT_MIN, {INT_MIN, INT_MAX}, &passed, &total);
    runTestCase({2, 4, 6, 8}, 1, {1, 2, 4, 6, 8}, &passed, &total);

    cout << passed << "/" << total << " test cases passed." << endl;
    return 0;
}
