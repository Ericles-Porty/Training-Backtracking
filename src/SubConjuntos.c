/***
 * Created by Raphael Oliveira 01/2021
 * Edited by Ericles Dos Santos Cunha, Kendy Ferreira, Thiago santos 12/2021
***/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define NMAX 1000
#define MAXCANDIDATES 2

void processSolution(int a[], int k) {
    printf("{ ");
    for (int i = 1; i <= k; i++)
        if (a[i] == 1)
            printf("%d ", i);
    printf("}\n");
}

int isSolution(int k, int n) {
    return (k == n);
}

void generateCandidates(int c[], int* totalC) {
    c[0] = 1;
    c[1] = 0;
    *totalC = 2;
}

void backTrack(int a[], int k, int n) {
    if (isSolution(k, n)) {
        processSolution(a, k);
    }
    else {
        int nCandidates;
        int candidates[MAXCANDIDATES];
        memset(candidates, 0, sizeof(candidates));
        k = k + 1;
        generateCandidates(candidates, &nCandidates);
        for (int i = 0; i < nCandidates; i++) {
            a[k] = candidates[i];
            backTrack(a, k, n);
        }
    }
}

void generateSubSets(int n) {
    int a[NMAX];
    memset(a, 0, sizeof(a));
    backTrack(a, 0, n);
}

int main() {
    int n = 0;
    scanf("%d", &n);
    generateSubSets(n);
    return 0;
}