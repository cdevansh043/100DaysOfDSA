#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    if (scanf("%s", s) != 1) return 0;

    int hash[26];
    for (int i = 0; i < 26; i++) {
        hash[i] = 0;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        int val = s[i] - 'a';
        if (hash[val] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
        hash[val]++;
    }

    printf("-1\n");
    return 0;
}