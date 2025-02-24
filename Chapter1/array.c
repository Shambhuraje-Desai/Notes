#include <stdio.h>

int longestIncreasingSubsequence(int arr[], int n) {
    int lis[n];  // Array to store LIS values for each index
    int max = 1; // Variable to store the max LIS length

    // Initialize LIS values as 1 for all elements
    for (int i = 0; i < n; i++) {
        lis[i] = 1;
    }

    // Compute LIS for each element
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
        if (lis[i] > max) {
            max = lis[i]; // Update max LIS length
        }
    }

    return max;
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = longestIncreasingSubsequence(arr, n);
    printf("Length of Longest Increasing Subsequence: %d\n", result);

    return 0;
}
