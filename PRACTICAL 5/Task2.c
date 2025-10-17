#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
        char S[100];
       int i, j;
    printf("Enter a DNA sequence: ");
    scanf("%s", S);
     int n = strlen(S);
    int L[n+1][n+1];

    // Build LRS table using modified LCS logic
    for(i = 0; i <= n; i++) {
        for(j = 0; j <= n; j++) {
            if(i == 0 || j == 0)
                L[i][j] = 0;
             else if(S[i-1] == S[j-1] && i != j)
             L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    printf("\nLength of Longest Repeating Subsequence: %d\n", L[n][n]);
    return 0;
}
