#include <stdio.h>
#define N 3

void mostrar(int (*mE)[3], int (*mD)[3]);

int main(){
    int mEsq[N][N] = {{1,2,-1},{3,5,-2},{-2,3,-4}};
    int mDir[N][N] = {{1,0,0},{0,1,0},{0,0,1}};
    int mult, pivo;

    // k = linha pivo
    // i = linha alterada
    // j = coluna

    for (int k = 0; k < N-1; k++){                                 // k= 0
        pivo = mEsq[k][k];                                      // pivo= 1
        for (int i = k; i < N-1; i++){                             // i= 0
            mult = -(mEsq[i+1][k]/pivo);                        // mult= -3
            for (int j = 0; j < N; j++){                           // j= 1
                mEsq[i+1][j] = (mult * mEsq[k][j]) + mEsq[i+1][j]; // mEsq[1][1]= -1 
                mDir[i+1][j] = (mult * mDir[k][j]) + mDir[i+1][j]; // mDir[1][1]= 
            }
        }
        mostrar(mEsq, mDir);
    }

    for (int k = N-1; k > 0; k--){                                 // k= 2
        pivo = mEsq[k][k];                                      // pivo= 1
        for (int i = k; i > 0; i--){                               // i= 2
            mult = -(mEsq[i-1][k]/pivo);                        // mult= -1
            for (int j = N-1; j >= 0; j--){                         // j= 0
                mEsq[i-1][j] = (mult * mEsq[k][j]) + mEsq[i-1][j]; // mEsq[1][2]=  
                mDir[i-1][j] = (mult * mDir[k][j]) + mDir[i-1][j]; // mDir[1][0]= 19+-3
            }
        }
        mostrar(mEsq, mDir);
    }

    for (int i = 0; i < N; i++){
        pivo = mEsq[i][i];
        for (int j = 0; j < N; j++){                           
            mEsq[i][j] = mEsq[i][j]/pivo;
            mDir[i][j] = mDir[i][j]/pivo;
        }
    }

    mostrar(mEsq, mDir);

    return 0;
}

void mostrar(int (*mE)[3], int (*mD)[3]){

    for (int i = 0; i < N; i++){
        printf("[ ");

        for (int j = 0; j < N; j++){
            printf("%3d ", mE[i][j]);
        }

        printf("| ");

        for (int j = 0; j < N; j++){
            printf("%3d ", mD[i][j]);
        }

        printf("]\n");
    }
    printf("\n-------------------------------\n\n");
}