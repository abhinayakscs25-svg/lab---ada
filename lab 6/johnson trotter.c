#include <stdio.h>

#define LEFT -1
#define RIGHT 1

int mobile(int a[], int dir[], int n) {
    int mobile_prev = 0, mobile_index = -1;

    for (int i = 0; i < n; i++) {
        if (dir[a[i] - 1] == LEFT && i != 0) {
            if (a[i] > a[i - 1] && a[i] > mobile_prev) {
                mobile_prev = a[i];
                mobile_index = i;
            }
        }
        if (dir[a[i] - 1] == RIGHT && i != n - 1) {
            if (a[i] > a[i + 1] && a[i] > mobile_prev) {
                mobile_prev = a[i];
                mobile_index = i;
            }
        }
    }
    return mobile_index;
}

void printPermutation(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void johnsonTrotter(int n) {
    int a[n], dir[n];

    // Initialize
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(a, n);

    while (1) {
        int mob = mobile(a, dir, n);
        if (mob == -1) break;

        int swap_with = mob + (dir[a[mob] - 1] == LEFT ? -1 : 1);

        // Swap
        int temp = a[mob];
        a[mob] = a[swap_with];
        a[swap_with] = temp;

        // Reverse directions of larger elements
        for (int i = 0; i < n; i++) {
            if (a[i] > temp)
                dir[a[i] - 1] *= -1;
        }

        printPermutation(a, n);
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    johnsonTrotter(n);
    return 0;
}
