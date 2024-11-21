#include <stdio.h>

 nhapMaTranA (int a[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}
xuatMaTranA (int a[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("  %d ", a[i][j]);
        }
        printf("\n");
    }  
}
 tinhTich(int a[][100], int b[][100], int c[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }   
}
int main() {
    int t, n, m, a[100][100], b[100][100], c[100][100];
    scanf("%d", &t);
    for (int k = 1; k <= t; k++) {
        scanf("%d %d", &n, &m);
        nhapMaTranA(a, n, m);       
        // tinh ma tran       
        for (int i = 0; i < n; i++) {
            for (int j = i; j < m; j++) {
                int temp = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = temp;
            }
        }
        // tinh tich
        tinhTich(a, a, c, n, m);
        printf("Test 1 %d:\n", k);
        xuatMaTranA(c, n, n);
    }   
    return 0;
}
