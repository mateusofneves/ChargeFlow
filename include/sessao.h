#ifndef SESSAO_H
#define SESSAO_H

#define MAX_SESSOES 10

typedef struct
{
    int id;
    char veiculo[50];

    float bateriaInicial;
    float bateriaAtual;

    float energiaConsumida;

    float tarifaAplicada;
    float valorTotal;

    int ativa;

} Sessao;

extern Sessao sessoes[MAX_SESSOES];
extern int totalSessoes;
extern int proximoId;

Sessao* buscarSessaoPorId(int id);

void cadastrarSessao();
void listarSessoes();
void iniciarRecarga();
void encerrarRecarga();

#endif