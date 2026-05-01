#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char **votes = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        votes[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", votes[i]);
    }

    qsort(votes, n, sizeof(char *), compareStrings);

    char *winner = votes[0];
    int max_votes = 0;
    
    int current_count = 0;
    char *current_candidate = votes[0];

    for (int i = 0; i < n; i++) {
        if (strcmp(votes[i], current_candidate) == 0) {
            current_count++;
        } else {
            if (current_count > max_votes) {
                max_votes = current_count;
                winner = current_candidate;
            }
            current_candidate = votes[i];
            current_count = 1;
        }
    }

    if (current_count > max_votes) {
        max_votes = current_count;
        winner = current_candidate;
    }

    printf("%s %d\n", winner, max_votes);

    for (int i = 0; i < n; i++) {
        free(votes[i]);
    }
    free(votes);

    return 0;
}