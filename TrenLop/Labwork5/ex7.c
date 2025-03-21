#include <stdio.h>
#include <string.h>

int solve(char s[]) {
    int n = strlen(s);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'n') {
            ++cnt;
        }
    }
    return cnt;
}

int main() {
    char s[INT_MAX];
    fgets(s, sizeof(s), stdin);

    printf("%d", solve(s));
    return 0;
}