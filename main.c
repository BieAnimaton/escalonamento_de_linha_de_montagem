#include <stdio.h>
#include <stdlib.h>

void Fatest_way(int a[2][6], int t[2][5], int e[], int x[], int n, int *custo, int *linha) {
    int i, j;
    int f1[n], f2[n];
    int l1[n], l2[n];
    int f3, l3;
    f1[0] = e[0] + a[0][0];
    f2[1] = e[1] + a[1][0];

    for (j = 1; j < n; j++) {
        if (f1[j - 1] + a[0][j] <= f2[j - 1] + t[1][j - 1] + a[0][j]) {
            f1[j] = f1[j - 1] + a[0][j];
            l1[j] = 1;
        } else {
            f1[j] = f2[j - 1] + t[1][j - 1] + a[0][j];
            l1[j] = 2;
        }

        if (f2[j - 1] + a[1][j] <= f1[j - 1] + t[0][j - 1] + a[1][j]) {
            f2[j] = f2[j - 1] + a[1][j];
            l2[j] = 2;
        } else {
            f2[j] = f1[j - 1] + t[0][j - 1] + a[1][j];
            l2[j] = 1;
        }
    }

    if (f1[n - 1] + x[0] <= f2[n - 1] + x[1]) {
        f3 = f1[n - 1] + x[0];
        l3 = 1;
    } else {
        f3 = f2[n - 1] + x[1];
        l3 = 2;
    }

    *custo = f3;
    *linha = l3;

    //printf("\nResposta: %d", f3);
    //printf("\nLinha: %d\n", l3);
}

int main()
{
    int a[2][6] = {7, 9, 3, 4, 8, 4,
                   8, 5, 6, 4, 5, 7};
    int t[2][5] = {2, 3, 1, 3, 4,
                   2, 1, 2, 2, 1};
    int e[2] = {2, 4};
    int x[2] = {3, 2};
    int custo, linha;

    Fatest_way(a, t, e, x, 6, &custo, &linha);

    printf("\nResposta: %d", custo);
    printf("\nLinha: %d\n", linha);

    return 0;
}
