#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    if (scanf("%s", s) != 1) return 0;

    int count[26] = {0};
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }

    for (int i = 0; i < len; i++) {
        if (count[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    printf("$\n");
    return 0;
}