#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define tam 11
#define true 1
#define false 0

int movex[] = {-2,-1, 1, 2, 2, 1,-1,-2};
int movey[] = { 1, 2, 2, 1,-1,-2,-2,-1};
int matriz[tam][tam];
int n;
int total_quadrados = 0;
int best = 0;
typedef int bool;


typedef struct
{
	int ymin;
	int ymax;
}Limited;


Limited limit_linha[tam];


bool SeSolucao(int x, int y){

	if (x <= 0 || x > n)
		return false;
	if (y < limit_linha[x].ymin || y > limit_linha[x].ymax)
		return false;
	return true;
}


void processSolution(int k){

   if (k > best){
		best = k;
   }
   else
	return;
}


void backTrack(int x, int y,int k){

	processSolution(k);
	for (int d = 0; d < 8; d++) // 8 - Numero de possibilidades
	{
		int posx = x + movex[d];
		int posy = y + movey[d];
		if (SeSolucao(posx, posy) == true && matriz[posx][posy] == 0)
		{
			matriz[posx][posy] = 1;
			backTrack(posx, posy, k + 1);
			matriz[posx][posy] = 0;
		}
	}
	return;
}

int main()
{
	scanf("%d",&n);
	int caso = 1;
	while (n!=0){
		total_quadrados = 0;
		for (int i = 1; i <= n; i++)
		{
			int col, lin;
			scanf("%d%d", &col, &lin);
			limit_linha[i].ymin = col + 1;
			limit_linha[i].ymax = limit_linha[i].ymin + lin - 1 ;
			total_quadrados = total_quadrados + lin;
			for (int j = limit_linha[i].ymin; j <= limit_linha[i].ymax; j++)
			{
				matriz[i][j] = 0;
			}
		}
		best = 0;  // reset value
		matriz[1][1] = 1;
		backTrack(1,1,1);
		printf("Case %d, %d", caso++, (total_quadrados - best));
		if((total_quadrados - best) == 1)
			printf (" square ");
		else
			printf (" squares ");
		printf(" can not be reached.\n");
		scanf("\n%d",&n);
	}
	return 0;
}
