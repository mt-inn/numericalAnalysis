#define _CRT_SECURE_NO_WARNINGS
//scanfの警告を消すやつ
#include <stdio.h>
#include <math.h>

void main(void)
{
    double a[10][10], inv[10][10], p, aik;
	/*
	aは入力された行列
	invは答えになる単位行列
	p、aikは計算時に使用
	*/
    int i, j, k, l, n;
	/*
	i,j,k,lはfor文用
	nは行列の大きさを決める
	*/
	//ここはサンプルのまま
    printf("元数を入力:\n");
    scanf("%d", &n);
    printf("定数を入力:\n");
    //計算する行列を1文字ずつ入力
    for (i = 0;i < n;i++) {
        for (j = 0;j < n;j++) {
            scanf("%lf", &a[i][j]);
			//invの全体に0を入力
            inv[i][j] = 0;
        }
        //invを単位行列にする(斜めに1を入力)
        inv[i][i] = 1;
    }

    //入力した行列を表示
    printf("入力された行列:\n");
    for (i = 0;i < n;i++) {
        for (j = 0;j < n;j++) {
            printf("%lf  ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (k = 0;k < n;k++) {
        //k行目について処理していく
        p = 1.0 / a[k][k];
        for (j = 0;j < n;j++) {
            a[k][j] = a[k][j] * p;
			/*
			invの同じ列に同じpを掛けて、こんな感じに計算
			|  7 4 2 |   | 7p 4p 2p  |
			|  3 2 1 | → |  3  2  1  |
			| 10 5 3 |   | 10  5  3  |
			| 1 0 0 |   | p 0 0 |
			| 0 1 0 | → | 0 1 0 |
			| 0 0 1 |   | 0 0 1 |

			*/
            inv[k][j] = inv[k][j] * p;
        }

        for (i = 0;i < n;i++) {
            if (i != k) {
                aik = a[i][k];
                for (j = 0; j < n; j++) {
					/*
					aと同じ操作をinvにもしていく。
					手計算では
					|  7 4 2 1 0 0 |
					|  3 2 1 0 1 0 |
					| 10 5 3 0 0 1 |
					としていたのを分けて計算するため。
					*/
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
		//区切りを分かりやすくしているだけ。
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
