#include <stdio.h>
#include <stdlib.h>

void findMinMax(int *a, int n, int *min, int *max) {
    *min = INT_MAX;
    *max = INT_MIN;
    for(int i = 0; i < n; i++ ){
        if(a[i] < *min) {
            *min = a[i];
        }
        if(a[i] > *max) {
            *max = a[i];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));
    // n * sizeof(int) -> n phan tu kieu int

    if(a != NULL) {
        for(int i = 0; i < n; i++) {
            scanf("%d", a[i]);
        }
        int min, max;
        findMinMax(a, n, &min, &max);

        printf("%d %d", min, max);
        // Free memory
        free(a);
    }
    return 0;
}