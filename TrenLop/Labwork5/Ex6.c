#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int l = strlen(s);

    for(int i = l - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }
}

int main() {
    char s[INT_MAX];

    fgets(s, sizeof(s), stdin);

    reverse(s);
    return 0;
}