#include <stdio.h>

#include "../include/ordenacao.h"
#include "../include/sessao.h"

static void trocar(Sessao *a, Sessao *b)
{
    Sessao temp = *a;
    *a = *b;
    *b = temp;
}

void ordenarSessoes()
{
    if(totalSessoes == 0)
    {
        printf("\nNenhuma sessao cadastrada.\n");
        return;
    }

    int criterio;

    printf("\n===== ORDENAR SESSOES =====\n");
    printf("1 - Por ID\n");
    printf("2 - Por energia consumida\n");
    printf("3 - Por valor total (custo)\n");
    printf("\nEscolha o criterio: ");
    scanf("%d", &criterio);

    if(criterio < 1 || criterio > 3)
    {
        printf("\nCriterio invalido!\n");
        return;
    }

    /* Bubble Sort */
    for(int i = 0; i < totalSessoes - 1; i++)
    {
        for(int j = 0; j < totalSessoes - 1 - i; j++)
        {
            int trocaNecessaria = 0;

            switch(criterio)
            {
                case 1:
                    trocaNecessaria = sessoes[j].id > sessoes[j + 1].id;
                    break;

                case 2:
                    trocaNecessaria = sessoes[j].energiaConsumida > sessoes[j + 1].energiaConsumida;
                    break;

                case 3:
                    trocaNecessaria = sessoes[j].valorTotal > sessoes[j + 1].valorTotal;
                    break;
            }

            if(trocaNecessaria)
            {
                trocar(&sessoes[j], &sessoes[j + 1]);
            }
        }
    }

    printf("\nSessoes ordenadas com sucesso!\n");
    listarSessoes();
}