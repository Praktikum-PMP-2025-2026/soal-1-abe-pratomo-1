#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    int nnLeft = -1, nnRight = -1;

    scanf("%d", &N);

    int *arr = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] != -1) {
                nnLeft = arr[j];
            }
        }

        for (int j = N - 1; j > i; j--) {
            if (arr[j] != -1) {
                nnRight = arr[j];
            }
        }

        if (arr[i] == -1) {
            if(nnLeft != -1 && nnRight != -1) {
                arr[i] = (nnLeft + nnRight) / 2;
            }
            else if (nnLeft != -1) {
                arr[i] = nnLeft;
            }
            else if (nnRight != -1) {
                arr[i] = nnRight;
            }

            else {
                arr[i] = 0;
            }
        }

        nnLeft = -1;
        nnRight = -1;
    }

    int sum = arr[0];
    int sumCurrent;

    for (int i = 0; i < N; i++) {
        sumCurrent = arr[i];
        for (int j = i; j < N; j++) {
            if (sumCurrent + arr[j] > sumCurrent) {
                sumCurrent += arr[j];
            }
        }

        if (sumCurrent > sum) {
            sum = sumCurrent;
        }
    }

    printf("RECOVERED");
    for (int i = 0; i < N; i++) {
        printf(" %d", arr[i]);
    }

    printf("\nMAX_SUM %d", sum);

    free(arr);

    return 0;
}
