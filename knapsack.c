

#include <stdio.h>
#include <stdbool.h>

#define MAX_ITEMS 10

int weights[MAX_ITEMS];
int values[MAX_ITEMS];
int numItems;
int maxWeight;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int index, int currentWeight, int currentValue) {
    if (index == numItems || currentWeight >= maxWeight)
        return currentValue;
    
    // Include the current item if it fits
    int include = 0;
    if (currentWeight + weights[index] <= maxWeight)
        include = knapsack(index + 1, currentWeight + weights[index], currentValue + values[index]);
    
    // Exclude the current item
    int exclude = knapsack(index + 1, currentWeight, currentValue);
    
    return max(include, exclude);
}

int main() {
    printf("Enter the number of items: ");
    scanf("%d", &numItems);
    
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < numItems; i++) {
        scanf("%d", &weights[i]);
    }
    
    printf("Enter the values of the items:\n");
    for (int i = 0; i < numItems; i++) {
        scanf("%d", &values[i]);
    }
    
    printf("Enter the maximum weight of the knapsack: ");
    scanf("%d", &maxWeight);
    
    int maxValue = knapsack(0, 0, 0);
    
    printf("Maximum value of items that can be included in the knapsack: %d\n", maxValue);
    
    return 0;
}
