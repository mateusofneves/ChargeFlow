# ChargeFlow - Sistema Inteligente de Gerenciamento de Recarga

## Sobre o Projeto

O ChargeFlow é um sistema desenvolvido em linguagem C para simular o gerenciamento inteligente de estações de recarga de veículos elétricos.

O projeto foi desenvolvido como parte da Sprint 2, com foco na aplicação de conceitos de programação estruturada, gerenciamento de múltiplas sessões, controle de demanda energética, tarifação dinâmica e geração de relatórios.

O sistema busca simular o funcionamento de uma estação de carregamento real, permitindo o cadastro de veículos, início e encerramento de recargas, monitoramento de consumo energético e cálculo de custos.

---

# Objetivos

* Gerenciar múltiplas sessões de recarga.
* Simular o controle de distribuição de potência.
* Aplicar tarifação dinâmica baseada em horário e demanda.
* Simular comunicação com plataforma externa.
* Gerar relatórios operacionais.
* Aplicar conceitos de modularização em C.

---

# Funcionalidades

## Cadastro de Sessões

Permite registrar veículos que utilizarão a estação de recarga.

Informações armazenadas:

* ID da sessão
* Modelo do veículo
* Bateria inicial
* Bateria atual
* Energia consumida
* Tarifa aplicada
* Valor total da recarga
* Status da sessão

---

## Início de Recarga

Após o cadastro, o usuário pode iniciar uma sessão de recarga.

O sistema verifica:

* Se a sessão existe
* Se a sessão já está ativa

Caso esteja tudo correto, a sessão é ativada.

---

## Encerramento de Recarga

Ao finalizar uma recarga o sistema:

* Solicita a energia consumida
* Atualiza o nível da bateria
* Calcula a tarifa dinâmica
* Calcula o valor total da sessão
* Encerra a sessão

---

## Controle Inteligente de Demanda

O sistema simula uma estação de recarga com potência máxima de 100 kW, distribuindo automaticamente a carga entre as sessões ativas para evitar sobrecarga da infraestrutura.

Potência disponível:

100 kW

A potência é distribuída igualmente entre todas as sessões ativas.

Exemplo:

1 sessão ativa:

100 kW

2 sessões ativas:

50 kW por sessão

4 sessões ativas:

25 kW por sessão

---

## Tarifação Dinâmica

O valor da energia varia conforme as condições de utilização.

### Tarifa Base

R$ 1,20 por kWh

### Horário de Pico

Entre 18h e 22h:

* R$ 0,50 por kWh

### Alta Demanda

3 ou mais sessões simultâneas:

* R$ 0,30 por kWh

---

## Simulação de Comunicação Externa

O sistema realiza uma simulação simples de integração com uma plataforma externa.

São exibidas informações da sessão como:

* ID
* Veículo
* Energia consumida
* Status da recarga

Esta funcionalidade representa uma simulação simplificada de protocolos utilizados em carregadores inteligentes.

---

## Relatórios

O sistema gera relatórios contendo:

### Dados por Sessão

* ID
* Veículo
* Bateria atual
* Energia consumida
* Tarifa aplicada
* Valor pago
* Status

### Resumo Geral

* Total de sessões
* Sessões ativas
* Energia total consumida
* Faturamento total

---

# Estrutura do Projeto

```text
ChargeFlow/
│
├── main.c
│
├── include/
│   ├── sessao.h
│   ├── tarifa.h
│   ├── relatorio.h
│   └── sistema.h
│
├── src/
│   ├── sessao.c
│   ├── tarifa.c
│   ├── relatorio.c
│   └── sistema.c
│
├── assets/
│
├── docs/
│
├── fluxograma/
│
└── README.md
```

---

# Organização dos Arquivos

## main.c

Responsável pelo menu principal e fluxo geral do sistema.

---

## sessao.c

Responsável pelo gerenciamento das sessões.

Funções:

* cadastrarSessao()
* listarSessoes()
* iniciarRecarga()
* encerrarRecarga()
* buscarSessaoPorId()

---

## tarifa.c

Responsável pelos cálculos relacionados à energia.

Funções:

* calcularTarifa()
* controleDemanda()

---

## relatorio.c

Responsável pela geração de relatórios operacionais.

Funções:

* gerarRelatorio()

---

## sistema.c

Responsável pelas funções auxiliares do sistema.

Funções:

* menu()
* limparTela()
* pausarSistema()
* simularOCPP()

---

# Estrutura de Dados

O sistema utiliza uma estrutura do tipo struct para armazenar informações de cada sessão.

```c
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
```

---

# Como Executar

## Pré-requisitos

* GCC
* MinGW (Windows)
* VS Code (opcional)

---

## Compilação

No terminal execute:

```bash
gcc main.c src/*.c -Iinclude -o chargeflow
```

---

## Execução

Windows:

```bash
chargeflow.exe
```

ou

```bash
.\chargeflow.exe
```

Linux:

```bash
./chargeflow
```

---

# Exemplo de Uso

## Cadastro

```text
Digite o modelo do veiculo:
BYD Dolphin

Digite a bateria inicial:
40
```

---

## Iniciar Recarga

```text
Digite o ID da sessao:
1

Recarga iniciada com sucesso!
```

---

## Encerrar Recarga

```text
Energia consumida:
20

Hora atual:
19
```

Resultado:

```text
Bateria: 40% -> 56%

Tarifa:
R$ 1.70/kWh

Valor Total:
R$ 34.00
```

---

# Conceitos Aplicados

* Programação Estruturada
* Modularização em C
* Structs
* Vetores
* Manipulação de Funções
* Controle de Fluxo
* Simulação de Sistemas Embarcados
* Controle de Energia
* Tarifação Dinâmica

---

| Integrante | RM |
|------------|------------|
| Mateus de Oliveira Fernandes Neves | RM572431 |
| Pedro Soares de Souza | RM571285 |
| Paulo Henrique Lira Bilac de Araujo | RM569496 |
| Olavo Dadario Vianna Barreto | RM569272 |
| Angela Sousa Takezawa | RM570797 |

---

Projeto acadêmico desenvolvido para a Sprint 2 - Sistema Inteligente de Gerenciamento de Recarga.
