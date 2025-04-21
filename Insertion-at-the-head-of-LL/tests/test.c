#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "../solutions/solution.c"

// Convert linked list to array
int* linkedListToArray(struct ListNode* head, int* length) {
    int* arr = malloc(100 * sizeof(int));
    int i = 0;
    while (head) {
        arr[i++] = head->val;
        head = head->next;
    }
    *length = i;
    return arr;
}

// Compare two arrays
bool compareArrays(int* a, int* b, int len) {
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// Run test case
void runTestCase(int* input, int inputLen, int* expected, int expectedLen, int* passedCount, int* total) {
    (*total)++;
    struct ListNode* head = NULL;

    for (int i = 0; i < inputLen; i++) {
        head = insertAtHead(head, input[i]);
    }

    int actualLen;
    int* actualArr = linkedListToArray(head, &actualLen);

    if (actualLen == expectedLen && compareArrays(actualArr, expected, expectedLen)) {
        (*passedCount)++;
        printf("\n✅ Test %d Passed", *passedCount);
    } else {
        printf("\n❌ Test %d Failed. Expected: ", *total);
        for (int i = 0; i < expectedLen; i++) printf("%d ", expected[i]);
        printf("\nActual: ");
        for (int i = 0; i < actualLen; i++) printf("%d ", actualArr[i]);
        printf("\n");
    }

    free(actualArr);
}

int main() {
    int passedCount = 0;
    int total = 0;

    // Test 1: Insert 3 elements
    int in1[] = {1, 2, 3};      int ex1[] = {3, 2, 1};
    runTestCase(in1, 3, ex1, 3, &passedCount, &total);

    // Test 2: Single element
    int in2[] = {10};          int ex2[] = {10};
    runTestCase(in2, 1, ex2, 1, &passedCount, &total);

    // Test 3: Empty list
    int in3[] = {};            int ex3[] = {};
    runTestCase(in3, 0, ex3, 0, &passedCount, &total);

    // Test 4: Duplicate values
    int in4[] = {4, 4, 4};     int ex4[] = {4, 4, 4};
    runTestCase(in4, 3, ex4, 3, &passedCount, &total);

    // Test 5: Negative values
    int in5[] = {-1, -2, -3};  int ex5[] = {-3, -2, -1};
    runTestCase(in5, 3, ex5, 3, &passedCount, &total);

    // Test 6: Zero
    int in6[] = {0};           int ex6[] = {0};
    runTestCase(in6, 1, ex6, 1, &passedCount, &total);

    // Test 7: Ascending input
    int in7[] = {1, 2, 3, 4};  int ex7[] = {4, 3, 2, 1};
    runTestCase(in7, 4, ex7, 4, &passedCount, &total);

    // Test 8: Descending input
    int in8[] = {9, 8, 7};     int ex8[] = {7, 8, 9};
    runTestCase(in8, 3, ex8, 3, &passedCount, &total);

    // Test 9: Mix of positives and negatives
    int in9[] = {-1, 0, 1};    int ex9[] = {1, 0, -1};
    runTestCase(in9, 3, ex9, 3, &passedCount, &total);

    // Test 10: Larger list
    int in10[] = {1,2,3,4,5,6,7,8,9,10}; int ex10[] = {10,9,8,7,6,5,4,3,2,1};
    runTestCase(in10, 10, ex10, 10, &passedCount, &total);

    // Summary
    printf("\n\n✅ Passed %d / %d test cases!\n", passedCount, total);
    if (passedCount != total) {
        assert(0); // Fail if any test fails
    }

    return 0;
}
