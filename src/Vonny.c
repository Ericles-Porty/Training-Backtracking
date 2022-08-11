#include <stdio.h>
#include <stdlib.h>

int flag_board[7][7];
int resul = 0;
int visitados[7][8];
int dx[2] = {0, 1};
int dy[2] = {1, 0};

int is_a_solution(int x); //é uma solução?
void DominoParaMatriz(int x, int y, int matriz[7][8]);


int main()
{
    int numTestes;

    int matriz[7][8];

    for(int i=0; i<=6; i++)
        for(int j=i; j<=6; j++)
            flag_board[i][j] = 1;

    //lê numero de testes
    scanf("%d", &numTestes);

    //preenche a matriz com dados de leitura do tabuleiro
    for(int cont =0; cont < numTestes; cont++){
        for(int i = 0; i<7; i++)
            for(int j = 0; j < 8; j ++)
                scanf("%d", &matriz[i][j]);

        resul = 0;
        DominoParaMatriz(0, 0, matriz);
        printf("%d\n", resul);
    }

    return 0;
}

int is_a_solution(int x){
    if(x==7)
        return 1;
    return 0;
}

void DominoParaMatriz(int x, int y, int matriz[7][8]){
    if(is_a_solution(x)){
        resul++;
        return;
    }
    if(visitados[x][y]==0){
        int n1, n2;
        n1 = matriz[x][y];

        for(int i=0; i<2; i++){
            int x_aux = x + dx[i];
            int y_aux = y + dy[i];

            if(x_aux>=0 && x_aux<7 && y_aux>=0 && y_aux<8 && visitados[x_aux][y_aux] == 0){
                n2 = matriz[x_aux][y_aux];

                if(n1<=n2 && flag_board[n1][n2]){
                    flag_board[n1][n2] = 0;
                    visitados[x][y] = visitados[x_aux][y_aux] = 1;

                    if(y<7)
                        DominoParaMatriz(x, y+1,matriz);
                    else
                        DominoParaMatriz(x+1, 0,matriz);

                    visitados[x][y] = visitados[x_aux][y_aux] = 0;
                    flag_board[n1][n2] = 1;
                }
                else if(flag_board[n2][n1]){
                    flag_board[n2][n1] = 0;
                    visitados[x][y] = visitados[x_aux][y_aux] = 1;

                    if(y<7)
                        DominoParaMatriz(x, y+1,matriz);
                    else
                        DominoParaMatriz(x+1, 0,matriz);

                    visitados[x][y] = visitados[x_aux][y_aux] = 0;
                    flag_board[n2][n1] = 1;
                }
            }
        }
    }
    else{
        if(y<7)
            DominoParaMatriz(x, y+1,matriz);
        else
            DominoParaMatriz(x+1, 0,matriz);
    }
}
