/***
 * Created by Raphael Oliveira 01/2021
 * Edited by Ericles Dos Santos Cunha, Kendy Ferreira, Thiago santos 12/2021
***/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef int bool;


void processSolution(int a[], int k){
    int cont=0;
    for (int i=0; i<k; i++){
        if(!verifica(a, k))
            printf("%d", a[i]);
        else
            cont++;
    }
    if(cont!=k)
        printf("\n");
}

void generateCandidates(int n, int c[], int *totalC){
    for(int i=0; i < n; i++){
        c[i] = i + 1;
        *totalC = *totalC + 1;
    }
}

bool verifica(int a[], int k){
    for(int i=0 ; i < k ; i++){
        for(int j=0; j < k; j++){
            if(i==j)
                continue;
            if(a[i] == a[j])
                return true;
        }
    }
    return false;
}



void backTrack(int a[], int n, int k, int i) {
    int array[k];

    if(i == k){ 
        processSolution(a, k);
        return;
    }
    int nCandidates = 0;
    int candidates[n];
    memset(candidates,0, sizeof(candidates));
    generateCandidates(n, candidates, &nCandidates);
    for(int c = 0; c < nCandidates; c++){
        a[i] = candidates[c];
        backTrack(a, n, k, i+1);
        //Saindo da recursao
    }
}

void generateSequence(int n, int k){
    int a[k];
    memset(a, 0, sizeof(a));
    backTrack(a, n, k, 0);
}

int main() {
    int k;
    scanf("%d", &k);
    generateSequence(k, k);
	return 0;
}
