
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int k = 5, ok = 0, qtdNewVetor = 0, cont = 0;
int newVetor[214748364], solucao[214748364]; // intMax: 2147483647
int aux1[5], aux2[5];

int compar(int aux1[], int aux2[])
{
    for (int c = 0; c < 5; c++)
    {
        for (int h = 0; h < 5; h++)
        {
            if (aux1[c] == aux2[h])
            {
                return 1;
            }
        }
    }
    return 0;
}

void fragmenta(int vetor, int j, int aux[])
{
    aux[0] = (vetor / 10000);
    aux[1] = ((vetor / 1000) % 10);
    aux[2] = ((vetor / 100) % 10);
    aux[3] = ((vetor / 10) % 10);
    aux[4] = vetor % 10;
}

void seq(int *vetor, int fim, int encontre)
{
    for (int c = 0; c < fim; c++)
    {
        for (int j = 0; j < fim; j++)
        {
            float result = (float)vetor[c] / vetor[j];
            if (result == encontre)
            {
                fragmenta(vetor[j], j, aux1);
                fragmenta(vetor[c], c, aux2);

                ok = compar(aux1, aux2);

                if (!ok)
                {
                    if (vetor[c] < 10000)
                        printf("0%d", vetor[c]);
                    else if (vetor[c] >= 10000)
                        printf("%d", vetor[c]);
                    if (vetor[j] < 10000)
                        printf(" / 0%d = %d\n", vetor[j], encontre);
                    else if (vetor[j] >= 10000)
                        printf(" / %d = %d\n", vetor[j], encontre);
                }
            }
        }
    }
}

void processSolution(int a[], int k, int encontre)
{
    if (cont == 0)
        printf("There are no solutions for %d.\n", encontre);
    else
        for (int i = 0; i < k; i += 2)
        {
            if (a[i] < 10000)
                printf("0%d", a[i]);
            else if (a[i] >= 10000)
                printf("%d", a[i]);
            if (a[i + 1] < 10000)
                printf(" / 0%d = %d\n", a[i + 1], encontre);
            else if (a[i + 1] >= 10000)
                printf(" / %d = %d\n", a[i + 1], encontre);
        }
    printf("\n");
}

void generateCandidates(int n, int c[], int *totalC)
{
    for (int i = 0; i < n; i++)
    {
        c[i] = i;
        *totalC = *totalC + 1;
    }
}

void backTrack(int a[], int n, int k, int i)
{

    if (i == k)
    {
        // Percorrer as 5 posições e se for igual seta o ok com 1
        for (int c = 0; c < k; c++)
        {
            for (int j = 0; j < k; j++)
            {
                if (c != j && a[c] == a[j])
                {
                    ok = 1;
                    break;
                }
            }
        }

        if (ok == 0)
        {
            int parte1 = (a[0] * 10000) + (a[1] * 1000) + (a[2] * 100) + (a[3] * 10) + a[4];
            // if (parte1 % 2 == 0)
            // {

            newVetor[qtdNewVetor++] = parte1;
            // }
            // processSolution(a, k);
        }
        ok = 0;
        return;
    }
    int nCandidates = 0;
    int candidates[n];
    memset(candidates, 0, sizeof(candidates));
    generateCandidates(n, candidates, &nCandidates);
    for (int c = 0; c < nCandidates; c++)
    {
        a[i] = candidates[c];
        backTrack(a, n, k, i + 1);
        // Saindo da recursao
    }
}

void generateSequence(int n)
{
    int a[k];

    memset(a, 0, sizeof(a));
    backTrack(a, n, k, 0);
}

int main()
{
    int n = 10, encontre;

    generateSequence(n);

    scanf("%d", &encontre);
    while (encontre != 0)
    {
        if (encontre >= 2 && encontre <= 79)
            seq(newVetor, qtdNewVetor, encontre);
        // divisao(newVetor, 0, qtdNewVetor-1, encontre);
        // processSolution(solucao, cont, encontre);
        printf("\n");
        memset(solucao, 0, sizeof(solucao));
        cont = 0;
        scanf("%d", &encontre);
    }

    return 0;
}