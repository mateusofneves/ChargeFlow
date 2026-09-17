#include <stdio.h>

#include "../include/sessao.h"
#include "../include/relatorio.h"

void gerarRelatorio()
{
    float energiaTotal = 0;
    float faturamentoTotal = 0;
    int ativas = 0;

    printf("\n====================================");
    printf("\n      RELATORIO CHARGEFLOW");
    printf("\n====================================\n");

    for(int i = 0; i < totalSessoes; i++)
    {
        energiaTotal += sessoes[i].energiaConsumida;
        faturamentoTotal += sessoes[i].valorTotal;

        if(sessoes[i].ativa)
        {
            ativas++;
        }

        printf("\nID: %d", sessoes[i].id);
        printf("\nVeiculo: %s", sessoes[i].veiculo);
        printf("\nBateria Atual: %.1f%%", sessoes[i].bateriaAtual);
        printf("\nEnergia Consumida: %.2f kWh", sessoes[i].energiaConsumida);
        printf("\nTarifa: R$ %.2f", sessoes[i].tarifaAplicada);
        printf("\nValor Pago: R$ %.2f", sessoes[i].valorTotal);

        printf("\nStatus: %s",
               sessoes[i].ativa ? "ATIVA" : "ENCERRADA");

        printf("\n------------------------------------\n");
    }

    printf("\nResumo Geral");
    printf("\nTotal de sessoes: %d", totalSessoes);
    printf("\nSessoes ativas: %d", ativas);
    printf("\nEnergia total: %.2f kWh", energiaTotal);
    printf("\nFaturamento total: R$ %.2f", faturamentoTotal);

    printf("\n====================================\n");

}

void mostrarEstatisticas()
{
    if(totalSessoes == 0)
    {
        printf("\nNenhuma sessao cadastrada.\n");
        return;
    }

    float energiaTotal = 0;
    float faturamentoTotal = 0;
    float maiorConsumo = sessoes[0].energiaConsumida;
    float menorConsumo = sessoes[0].energiaConsumida;

    for(int i = 0; i < totalSessoes; i++)
    {
        energiaTotal += sessoes[i].energiaConsumida;
        faturamentoTotal += sessoes[i].valorTotal;

        if(sessoes[i].energiaConsumida > maiorConsumo)
        {
            maiorConsumo = sessoes[i].energiaConsumida;
        }

        if(sessoes[i].energiaConsumida < menorConsumo)
        {
            menorConsumo = sessoes[i].energiaConsumida;
        }
    }

    float ticketMedio = faturamentoTotal / totalSessoes;

    printf("\n========= ESTATISTICAS =========\n");
    printf("\nSessoes cadastradas: %d\n", totalSessoes);
    printf("Energia fornecida: %.2f kWh\n", energiaTotal);
    printf("Faturamento: R$ %.2f\n", faturamentoTotal);
    printf("Ticket medio: R$ %.2f\n", ticketMedio);
    printf("\nMaior consumo: %.2f kWh\n", maiorConsumo);
    printf("Menor consumo: %.2f kWh\n", menorConsumo);
    printf("=================================\n");
}