// Write a C program to implement the Knuth-Morris-Pratt (KMP) algorithm for string matching. 
// The program should take a text and a pattern as input, and output the starting indices of all occurrences of the pattern in the text.
#include <stdio.h>
#include <string.h>

// Precomputes the LPS (Longest Prefix Suffix) array
void computeLPSArray(char* pat, int M, int* lps) {
    int len = 0; // Length of the previous longest prefix suffix
    lps[0] = 0;  // lps[0] is always 0
    int i = 1;

    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Searches for occurrences of pat[] in txt[]
void KMPSearch(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);

    int lps[M];
    computeLPSArray(pat, M, lps);

    int i = 0; // Index for txt[]
    int j = 0; // Index for pat[]
    int found = 0;

    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            found = 1;
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }

    if (!found) {
        printf("Pattern not found in the text.\n");
    }
}

int main() {
    char txt[100], pat[50];

    printf("Enter the main text: ");
    fgets(txt, sizeof(txt), stdin);
    txt[strcspn(txt, "\n")] = '\0'; // Remove trailing newline

    printf("Enter the pattern to search: ");
    fgets(pat, sizeof(pat), stdin);
    pat[strcspn(pat, "\n")] = '\0'; // Remove trailing newline

    KMPSearch(pat, txt);

    return 0;
}


// Enter the main text: the quick brown fox jumps over the lazy dog and the cat
// Enter the pattern to search: the
// Pattern found at index 0
// Pattern found at index 31
// Pattern found at index 48

// Enter the main text: ABABDABACDABABCABAB
// Enter the pattern to search: ABABCABAB
// Pattern found at index 10
