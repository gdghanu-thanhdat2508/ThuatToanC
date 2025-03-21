#include <stdio.h>

int oddSum, evenSum;
int sumEvenOdd(int n, int *oddSum, int *evenSum) {
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 0) {
            *oddSum += i;
        } else {
            *evenSum += i;
        }
    }
}

int main() {
    int n; 
    scanf("%d", &n);
    sumEvenOdd(n, &oddSum, &evenSum);
    printf("%d %d", oddSum, evenSum);
    return 0;
}