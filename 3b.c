#include <stdio.h>
#include <string.h>

// Brute force string matching algorithm
void bfsm(char *text, char *pattern) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    
    for (int i = 0; i <= textLength - patternLength; i++) {
        int j;
        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j])
                break; // mismatch found, break inner loop
        }
        if (j == patternLength) // if inner loop completed without break, pattern found
            printf("Pattern found at index %d\n", i);
    }
}

int main() {
    char text[] = "ababcababcabcabc";
    char pattern[] = "abc";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);
    printf("Occurrences:\n");
    bfsm(text, pattern);

    return 0;
}

