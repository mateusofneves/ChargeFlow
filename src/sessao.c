#include <stdio.h>
#include <string.h>

#include "../include/sessao.h"
#include "../include/tarifa.h"

Sessao sessoes[MAX_SESSOES];

int totalSessoes = 0;
int proximoId = 1;

Sessao* buscarSessaoPorId(int id)
{
    for (int i = 0; i < totalSessoes; i++)
    {
        if (sessoes[i].id == id)
        {
            return &sessoes[i];
        }
    }
    return NULL;

}

void cadastrarSessao()
{
    if(totalSessoes >= MAX_SESSOES)
    {
        printf("\nLimite de sessoes atingido.\n");
        return;
    }

    Sessao* sessao = &sessoes[totalSessoes];

    sessao->id = proximoId++;

    printf("\nDigite o modelo do veiculo: ");
    scanf(" %[^\n]", sessao->veiculo);

    printf("Digite a bateria inicial (%%): ");
    scanf("%f", &sessao->bateriaInicial);

    sessao->bateriaAtual = sessao->bateriaInicial;
    sessao->energiaConsumida = 0;
    sessao->tarifaAplicada = 0;
    sessao->valorTotal = 0;

    /* Sessao nasce inativa */
    sessao->ativa = 0;

    totalSessoes++;

    printf("\nSessao cadastrada com sucesso!\n");
    printf("ID: %d\n", sessao->id);
}

void listarSessoes()
{
    if(totalSessoes == 0)
    {
        printf("\nNenhuma sessao cadastrada.\n");
        return;
    }

    printf("\n=========== SESSOES ===========\n");

    for(int i = 0; i < totalSessoes; i++)
    {
        Sessao* sessao = &sessoes[i];

        printf("\nID: %d\n", sessao->id);
        printf("Veiculo: %s\n", sessao->veiculo);
        printf("Bateria Inicial: %.1f%%\n", sessao->bateriaInicial);
        printf("Bateria Atual: %.1f%%\n", sessao->bateriaAtual);

        printf("Status: %s\n",
               sessao->ativa ? "ATIVA" : "INATIVA");
    }
}

void iniciarRecarga()
{
    int id;

    printf("\nDigite o ID da sessao: ");
    scanf("%d", &id);

    Sessao* sessao = buscarSessaoPorId(id);

    if(sessao == NULL)
    {
        printf("\nSessao nao encontrada.\n");
        return;
    }

    if(sessao->ativa)
    {
        printf("\nEsta sessao ja esta ativa.\n");
        return;
    }

    sessao->ativa = 1;

    printf("\nRecarga iniciada com sucesso!\n");
    printf("Veiculo: %s\n", sessao->veiculo);
}

void encerrarRecarga()
{
    int id;

    printf("\nDigite o ID da sessao: ");
    scanf("%d", &id);

    Sessao* sessao = buscarSessaoPorId(id);

    if(sessao == NULL)
    {
        printf("\nSessao nao encontrada.\n");
        return;
    }

    if(!sessao->ativa)
    {
        printf("\nEsta sessao nao esta ativa.\n");
        return;
    }

    printf("Energia consumida (kWh): ");
    scanf("%f", &sessao->energiaConsumida);

    float bateriaAnterior = sessao->bateriaAtual;

    /* Simulacao de carregamento */
    sessao->bateriaAtual +=
        sessao->energiaConsumida * 0.8f;

    if(sessao->bateriaAtual > 100)
    {
        sessao->bateriaAtual = 100;
    }

    sessao->tarifaAplicada = calcularTarifa();

    sessao->valorTotal =
        sessao->energiaConsumida *
        sessao->tarifaAplicada;

    sessao->ativa = 0;

    printf("\n===== RECARGA FINALIZADA =====\n");

    printf("Veiculo: %s\n", sessao->veiculo);

    printf("Bateria: %.1f%% -> %.1f%%\n",
           bateriaAnterior,
           sessao->bateriaAtual);

    printf("Energia: %.2f kWh\n",
           sessao->energiaConsumida);

    printf("Tarifa: R$ %.2f/kWh\n",
           sessao->tarifaAplicada);

    printf("Valor Total: R$ %.2f\n",
           sessao->valorTotal);
}