#include <stdio.h>

#include "../include/sessao.h"
#include "../include/tarifa.h"

float calcularTarifa()
{
    int hora;
    int sessoesAtivas = 0;

    printf("\nInforme a hora atual (0-23): ");
    scanf("%d", &hora);

    for(int i = 0; i < totalSessoes; i++)
    {
        if(sessoes[i].ativa)
        {
            sessoesAtivas++;
        }
    }

    float tarifa = 1.20;

    /* Horário de pico */
    if(hora >= 18 && hora <= 22)
    {
        tarifa += 0.50;
    }

    /* Alta demanda */
    if(sessoesAtivas >= 3)
    {
        tarifa += 0.30;
    }

    return tarifa;

}
    
void controleDemanda()
{
    int ativas = 0;

    for(int i = 0; i < totalSessoes; i++)
    {
        if(sessoes[i].ativa)
        {
            ativas++;
        }
    }

    if(ativas == 0)
    {
        printf("\nNenhuma sessao ativa.\n");
        return;
    }

    float potenciaTotal = 100.0;
    float potenciaPorSessao = potenciaTotal / ativas;

    printf("\n===== CONTROLE DE DEMANDA =====\n");
    printf("Sessoes ativas: %d\n", ativas);
    printf("Potencia total: %.1f kW\n", potenciaTotal);
    printf("Potencia por sessao: %.1f kW\n", potenciaPorSessao);

}