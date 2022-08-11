#include <stdio.h>

#define true 1
#define false 0
typedef int bool;

typedef struct cubo
{
    int lado[6];
    bool unico;
} Cubo;

void zera(Cubo *cubo, int n);
bool cubosIguais(Cubo cubo1, Cubo cubo2);
bool verificaRotacoes(Cubo cubo1, Cubo cubo2);
Cubo rotacaoX(Cubo cubo);
Cubo rotacaoY(Cubo cubo);
Cubo rotacaoZ(Cubo cubo);
void verifica(Cubo *cubo, int n);
void resultado(Cubo *cubo, int n);

void zera(Cubo *cubo, int n){
    for (int i = 0; i < n; ++i) {
        cubo[i].unico = false;
    }
}

bool cubosIguais(Cubo cubo1, Cubo cubo2)
{
    for (int z = 0; z < 6; z++)
    {
        if (cubo1.lado[z] != cubo2.lado[z])
            return false;
    }
    return true;
}

bool verificaRotacoes(Cubo cubo1, Cubo cubo2){
    Cubo aux;

    aux = cubo1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                aux = rotacaoX(aux);
                if (cubosIguais(aux,cubo2))return true;
            }
            aux = rotacaoY(aux);
            if (cubosIguais(aux,cubo2))return true;
        }
        aux = rotacaoZ(aux);
        if (cubosIguais(aux,cubo2))return true;
    }

    return false;
}
Cubo rotacaoX(Cubo cubo)
{
    Cubo aux;
    aux.lado[1] = cubo.lado[1];
    aux.lado[3] = cubo.lado[3];
    aux.lado[0] = cubo.lado[2];
    aux.lado[2] = cubo.lado[5];
    aux.lado[5] = cubo.lado[4];
    aux.lado[4] = cubo.lado[0];
    return aux;


}

Cubo rotacaoY(Cubo cubo)
{
    Cubo aux;
    aux.lado[2] = cubo.lado[2];
    aux.lado[4] = cubo.lado[4];
    aux.lado[0] = cubo.lado[3];
    aux.lado[3] = cubo.lado[5];
    aux.lado[5] = cubo.lado[1];
    aux.lado[1] = cubo.lado[0];
    return aux;
}

Cubo rotacaoZ(Cubo cubo)
{
    Cubo aux;
    aux.lado[0] = cubo.lado[0];
    aux.lado[5] = cubo.lado[5];
    aux.lado[2] = cubo.lado[1];
    aux.lado[3] = cubo.lado[2];
    aux.lado[4] = cubo.lado[3];
    aux.lado[1] = cubo.lado[4];
    return aux;
}

void verifica(Cubo *cubo, int n)
{
    cubo[0].unico = true;
    if (n == 1) return;

    for (int i = 1; i < n; i++)
    {
        if(!cubo[i].unico){
            for (int j = i-1; j >= 0; j--)
            {
                if (cubosIguais(cubo[i], cubo[j])
                    || verificaRotacoes(cubo[i],cubo[j])) {
                    cubo[i].unico = false;
                    break;
                } else {
                    cubo[i].unico = true;
                }
            }
        }
    }
}

void resultado(Cubo *cubo, int n){
    int contador=0;
    for (int i = 0; i < n; i++)
    {
        if(cubo[i].unico)
            contador++;
    }
    printf("%d\n",contador);
}

int main()
{
    int n;
    scanf("%d", &n);
    Cubo cubo[1000];
    while (n != 0)
    {
        zera(cubo,n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                scanf("%d", &cubo[i].lado[j]);
            }
        }

        verifica(cubo, n);
        resultado(cubo,n);
        scanf("%d", &n);
    }
    return 0;
}