#include <stdio.h>
#include <stdlib.h>

#include "../include/sistema.h"
#include "../include/sessao.h"

void limparTela()
{
    system("cls");

}

void pausarSistema()
{
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();

}

void menu()
{
    printf("\n==============================");
    printf("\n CHARGEFLOW");
    printf("\n Sistema Inteligente de Recarga");
    printf("\n==============================\n");

    printf("1 - Cadastrar Sessao\n");
    printf("2 - Iniciar Recarga\n");
    printf("3 - Encerrar Recarga\n");
    printf("4 - Listar Sessoes\n");
    printf("5 - Controle de Demanda\n");
    printf("6 - Simular OCPP\n");
    printf("7 - Gerar Relatorio\n");
    printf("0 - Sair\n");

    printf("\nOpcao: ");

}

void simularOCPP()
{
    int id;

    printf("\nInforme o ID da sessao: ");
    scanf("%d", &id);

    Sessao *sessao = buscarSessaoPorId(id);

    if(sessao == NULL)
    {
        printf("\nSessao nao encontrada!\n");
        return;
    }

    printf("\n==================================\n");
    printf("     SIMULACAO OCPP 1.6\n");
    printf("==================================\n");

    printf("{\n");
    printf("  \"messageType\": \"StatusNotification\",\n");
    printf("  \"sessionId\": %d,\n", sessao->id);
    printf("  \"vehicle\": \"%s\",\n", sessao->veiculo);
    printf("  \"energy\": %.2f,\n", sessao->energiaConsumida);
    printf("  \"status\": \"%s\"\n",
           sessao->ativa ? "Charging" : "Stopped");
    printf("}\n");

    printf("\n[Servidor]\n");
    printf("{\n");
    printf("  \"response\": \"Accepted\"\n");
    printf("}\n");

}