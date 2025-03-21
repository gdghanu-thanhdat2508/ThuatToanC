#include <stdio.h>

void delete(char s[], char x) {
    int i = 0, j = 0;

    while(s[i] != '\0') {
        if(s[i] != x) {
            s[j] = s[i];
            j++;
        }
        i++;
    }
    s[j] = '\0';
}

int main() {
    char s[INT_MAX], x;

    fgets(s, sizeof(s), stdin);

    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == '\n') {
            s[i] = '\0';
            break;
        }
    } // REMOVE NEWLINE SYMBOL

    scanf("%c", &c);

    delete(s, x);

    printf("%s", s);
    return 0;
}