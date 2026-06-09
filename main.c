#include <stdio.h>

#include "include/sessao.h"
#include "include/tarifa.h"
#include "include/relatorio.h"
#include "include/sistema.h"

int main()
{
    int opcao;

    do
    {
        limparTela();
        
        menu();
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                cadastrarSessao();
                break;

            case 2:
                iniciarRecarga();
                break;

            case 3:
                encerrarRecarga();
                break;

            case 4:
                listarSessoes();
                break;

            case 5:
                controleDemanda();
                break;

            case 6:
                simularOCPP();
                break;

            case 7:
                gerarRelatorio();
                break;

            case 0:
                printf("\nEncerrando sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

        if(opcao != 0)
        {
            pausarSistema();
        }

    } while(opcao != 0);

    return 0;
}