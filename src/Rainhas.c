#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int FIXED_COL;
int array[9];
int prints;
int CONTADOR = 0;
int PRIMEIRO_PRINT = 0;
int ULTIMO_PRINT= 0;
//Primeiro print ? so pra formata??o do primeiro print funcionar
//FIXED_COL = coluna da rainha fixa
//k = coluna atual
//c = cada linha do tabuleiro

void process_Solution(int *a);
void constructCandidates(int a[], int k, int candidates[], int *n);
int checkFixedQueen(int c, int k);
void bt(int a[], int k, int depth);

void process_Solution(int *a)
{
    
    if(ULTIMO_PRINT){
        printf("\n");
        ULTIMO_PRINT=0;
    }
    if (!PRIMEIRO_PRINT)
    {
        PRIMEIRO_PRINT++;
        printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
    }
    CONTADOR++;
    if(CONTADOR<10){
    printf(" %d     ", ++prints);
    }
    else
    printf("%d     ", ++prints);
    for (int i = 1; i <= 8; i++)
    {
        
        printf(" %d", a[i]);
        
    }
    if(!ULTIMO_PRINT)
    printf("\n");
    
}

void constructCandidates(int a[], int k, int candidates[], int *n)
{
    int c, i;
    int passed = 1;
    for (c = 1; c <= 8; c++)
    {                               // testar os 8 candidatos
        if (!checkFixedQueen(c, k)) //verificar se o candidato ataca a rainha fixa
            continue;
        passed = 1;
        for (i = 1; i < k; i++)
        { //verificar se o candidato ataca as rainhas anteriores
            if (a[i] == c)
            { //mesma linha
                passed = 0;
                break;
            }
            if (abs(a[i] - c) == abs(i - k))
            { //mesma diagonal
                passed = 0;
                break;
            }
        }
        if (passed)
        {
            candidates[*n] = c;
            *n += 1;
        }
    }
}
int checkFixedQueen(int c, int k)
{
    if (array[FIXED_COL] == c)
        return 0;
    if (abs(array[FIXED_COL] - c) == abs(FIXED_COL - k))
        return 0;
    return 1;
}

void bt(int a[], int k, int depth)
{
    if (depth == 8)
    {
        process_Solution(a);
        return;
    }
    if (k == FIXED_COL)
    { // se for a coluna da rainha fixa, pula para a pr?xima
        bt(a, k + 1, depth + 1);
        return;
    }
    int candidates[9], nCandidates = 0;
    memset(candidates, 0, sizeof candidates);
    constructCandidates(a, k, candidates, &nCandidates);
    for (int i = 0; i < nCandidates; i++)
    {
        a[k] = candidates[i];
        bt(a, k + 1, depth + 1);
    }
}

int main()
{
    prints = 0;
    int casos;
    int coluna, linha;
    scanf("%d", &casos);
    
        for (int i = 0; i < casos; i++)
        {
            prints = 0;
            CONTADOR = 0;
            scanf("%d%d", &linha, &FIXED_COL);
            array[FIXED_COL] = linha;
            bt(array, 1, 0);
            ULTIMO_PRINT=1;
            PRIMEIRO_PRINT=0;
        }

    return 0;
}