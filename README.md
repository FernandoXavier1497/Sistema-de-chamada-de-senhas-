Sistema de Fila de Senhas (Atendimento Bancário)

Programa em C que simula um sistema de chamada de senhas para atendimento bancário, com suporte a dois tipos de cartão:

Prioritário (P) — numeração a partir de 301, sempre atendido antes dos comuns.
Comum (C) — numeração a partir de 1.

A fila é implementada com uma Lista Ligada Simples (não circular), onde cada nó representa um cartão (número, prioridade e ponteiro para o próximo).

Funcionalidades
Inserção de novos clientes na fila, com numeração automática por tipo de cartão.
Regra de prioridade: clientes com senha P são sempre posicionados antes dos clientes com senha C; dentro de cada tipo, a ordem de chegada é respeitada.
Impressão da fila de clientes na ordem de atendimento.
Chamada/atendimento do próximo cliente da fila (remoção do início da lista).
Menu interativo no terminal com as opções: adicionar cliente, mostrar fila, chamar cliente e sair.
Como compilar e executar
bash
gcc fila.c -o fila
./fila
Tecnologias
Linguagem C
Estrutura de dados: Lista Ligada Simples
