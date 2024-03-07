#include <stdio.h>

// Function to check if a subset of array elements can form a sum equal to the given sum
int isSubsetSum(int arr[], int n, int sum) {
    // Base cases
    if (sum == 0)
        return 1;
    if (n == 0 && sum != 0)
        return 0;
    
    // If last element is greater than sum, then ignore it
    if (arr[n - 1] > sum)
        return isSubsetSum(arr, n - 1, sum);
    
    // Check if sum can be obtained by including the last element or excluding it
    return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

// Function to check if given array can be partitioned into two subsets with equal sum
int canPartition(int arr[], int n) {
    // Calculate sum of all elements in array
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    
    // If sum is odd, array cannot be partitioned into two subsets with equal sum
    if (sum % 2 != 0)
        return 0;
    
    // Return true if there exists a subset with sum equal to half of total sum
    return isSubsetSum(arr, n, sum / 2);
}

int main() {
    int arr[] = {3, 1, 5, 9, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    if (canPartition(arr, n))
        printf("The array can be partitioned into two subsets with equal sum.\n");
    else
        printf("The array cannot be partitioned into two subsets with equal sum.\n");
    
    return 0;
}
