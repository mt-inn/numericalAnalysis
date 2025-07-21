#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void main(void)
{
    /*
    変数を定義
    a: 入力する行列
    inv: 逆行列になる場所
    p, aik: 計算中の係数を格納
    i,j,k,l,n: 繰り返し処理のカウンター。可読性のために別々に用意
    */
    double a[10][10], inv[10][10], p, aik;
    int i = 0, j, k, l, n;
    printf("元数を入力:\n");
    scanf("%d", &n);
    printf("定数を入力:\n");
    /*
    計算する行列を1文字ずつ入力
    下のような入力順
      | 1 2 3 |
      | 4 5 6 |
      | 7 8 9 |

    */
    for (i = 0;i < n;i++) {
        for (j = 0;j < n;j++) {
            scanf("%lf", &a[i][j]);
            inv[i][j] = 0;
        }
        //出力先の行列を単位行列にする
        inv[i][i] = 1;
    }

    //入力した行列を表示
    printf("入力された行列:\n");
    for (i = 0;i < n;i++) {
        for (j = 0;j < n;j++) {
            printf("  |  %lf", a[i][j]);
        }
        printf("  |");
        printf("\n");
    }
    printf("\n");
    for (k = 0;k < n;k++) {
        //k行目について処理していく
        p = 1.0 / a[k][k];
        for (j = 0;j < n;j++) {
            a[k][j] = a[k][j] * p;
            inv[k][j] = inv[k][j] * p;
        }

        for (i = 0;i < n;i++) {
            //i列目かつk行目じゃない部分について計算
            if (i != k) {
                aik = a[i][k];
                for (j = 0; j < n; j++) {
                    a[i][j] = a[i][j] - aik * a[k][j];
                    inv[i][j] = inv[i][j] - aik * inv[k][j];
                }
            }
        }
        //計算過程を表示
        for (i = 0; i < n; i++) {
            printf("  |  ");
            for (j = 0;j < n;j++) {
                printf("%8.3lf  ", inv[i][j]);
            }
            printf("|\n");
        }
        //計算が終わった場所を明示
        printf("---------------------------------\n");
    }
    printf("逆行列\n");
    for (i = 0; i < n; i++) {
        printf("  |  ");
        for (j = 0;j < n;j++) {
            printf("%8.3lf  ", inv[i][j]);
        }
        printf("|\n");
    }
}
