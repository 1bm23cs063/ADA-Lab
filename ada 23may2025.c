#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1

void printPermutation(int *perm, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}

int getMobile(int *perm, int *dir, int n) {
    int mobile_prev = 0;
    int mobile_index = -1;
    for (int i = 0; i < n; i++) {
        int next_pos = i + dir[i];
        if (next_pos >= 0 && next_pos < n) {
            if (perm[i] > perm[next_pos] && perm[i] > mobile_prev) {
                mobile_prev = perm[i];
                mobile_index = i;
            }
        }
    }
    return mobile_index;
}

void johnsonTrotter(int n) {
    int *perm = malloc(n * sizeof(int));
    int *dir = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(perm, n);

    while (1) {
        int mobile = getMobile(perm, dir, n);
        if (mobile == -1)
            break;

        int swap_pos = mobile + dir[mobile];

        int temp = perm[mobile];
        perm[mobile] = perm[swap_pos];
        perm[swap_pos] = temp;

        int temp_dir = dir[mobile];
        dir[mobile] = dir[swap_pos];
        dir[swap_pos] = temp_dir;

        mobile = swap_pos;

        for (int i = 0; i < n; i++) {
            if (perm[i] > perm[mobile]) {
                dir[i] = -dir[i];
            }
        }

        printPermutation(perm, n);
    }

    free(perm);
    free(dir);
}

int main() {
    int n = 3;
    printf("All permutations of 1..%d generated by Johnson-Trotter:\n", n);
    johnsonTrotter(n);
    return 0;
}
