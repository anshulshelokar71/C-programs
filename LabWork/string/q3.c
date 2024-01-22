#include <stdio.h>
#include <string.h>

// Function to find the longest common subsequence
int longestSubsequence(char *str1, char *str2, char **subsequence) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int maxLen = 0;
    char *maxSubsequence = NULL;

    for (int i = 0; i < len2; i++) {
        for (int j = 0; j < len1; j++) {
            if (str2[i] == str1[j]) {
                int currentLen = 1;
                int m = i + 1;
                for (int n = j + 1; n < len1 && m < len2; n++) {
                    if (str2[m] == str1[n]) {
                        currentLen++;
                        m++;
                    }
                }
                if (currentLen > maxLen) {
                    maxLen = currentLen;
                    maxSubsequence = &str1[j];
                }
            }
        }
    }

    *subsequence = maxSubsequence;
    return maxLen;
}

int main() {
    char inputString1[100], inputString2[100];
    char *subsequence;

    // Get input strings from the user
    printf("Enter the first string: ");
    fgets(inputString1, sizeof(inputString1), stdin);

    // Remove newline character if present
    if (inputString1[strlen(inputString1) - 1] == '\n') {
        inputString1[strlen(inputString1) - 1] = '\0';
    }

    printf("Enter the second string: ");
    fgets(inputString2, sizeof(inputString2), stdin);

    // Remove newline character if present
    if (inputString2[strlen(inputString2) - 1] == '\n') {
        inputString2[strlen(inputString2) - 1] = '\0';
    }

    // Find and display the result
    int result = longestSubsequence(inputString1, inputString2, &subsequence);

    if (result > 0) {
        printf("The longest common subsequence is '%.*s' with length %d.\n", result, subsequence, result);
    } else {
        printf("No common subsequence found.\n");
    }

    return 0;
}
