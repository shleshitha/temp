package tests;


import solutions.ListNode;
import solutions.Solution;

import java.util.Arrays;

public class Test {
    // Helper to convert list to array
    public static int[] listToArray(ListNode head) {
        int[] arr = new int[100];
        int i = 0;
        while (head != null) {
            arr[i++] = head.val;
            head = head.next;
        }
        return Arrays.copyOf(arr, i);
    }

    // Compare two arrays
    public static boolean arraysEqual(int[] a, int[] b) {
        return Arrays.equals(a, b);
    }

    // Run one test case
    public static void runTest(int[] input, int[] expected, int[] passCount) {
        Solution solution = new Solution();
        ListNode head = null;

        for (int val : input) {
            head = solution.insertAtHead(head, val);
        }

        int[] actual = listToArray(head);

        if (arraysEqual(actual, expected)) {
            passCount[0]++;
            System.out.println("✅ Test " + passCount[0] + " passed");
        } else {
            System.out.println("❌ Test failed. Expected: " + Arrays.toString(expected) + ", Got: " + Arrays.toString(actual));
        }
    }

    public static void main(String[] args) {
        int[] passCount = {0};

        runTest(new int[]{1, 2, 3}, new int[]{3, 2, 1}, passCount);
        runTest(new int[]{10}, new int[]{10}, passCount);
        runTest(new int[]{}, new int[]{}, passCount);
        runTest(new int[]{4, 4, 4}, new int[]{4, 4, 4}, passCount);
        runTest(new int[]{-1, -2, -3}, new int[]{-3, -2, -1}, passCount);
        runTest(new int[]{0}, new int[]{0}, passCount);
        runTest(new int[]{1, 2, 3, 4}, new int[]{4, 3, 2, 1}, passCount);
        runTest(new int[]{9, 8, 7}, new int[]{7, 8, 9}, passCount);
        runTest(new int[]{-1, 0, 1}, new int[]{1, 0, -1}, passCount);
        runTest(new int[]{1,2,3,4,5,6,7,8,9,10}, new int[]{10,9,8,7,6,5,4,3,2,1}, passCount);

        System.out.println("\n✅ Passed " + passCount[0] + " / 10 test cases!");
    }
}
