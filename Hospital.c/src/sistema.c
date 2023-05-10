#include <stdio.h>
#include <stdarg.h>
#include <windows.h>
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>
#include "C:\Users\jhoan\Desktop\VScode\GitHub\HospitalManagementSystem\Hospital.c\include\hospital.h"  

#define N_OPCOES 8

#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'
#define OPCAO7 '7'
#define OPCAO8 '8'

/****
 * Função: LimpaBuffer()
 * Descrição: Lê e descarta caracteres encontrados na entrada
 * Parâmetros: Nenhum
 * Retorno: Nada
 ****/
void LimpaBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Descarta os caracteres do buffer até encontrar uma nova linha ou o fim do arquivo
    }
}

/****
 * Função: LeOpcao()
 * Descrição: Lê e valida a opção digitada pelo usuário
 * Parâmetros:
 *   menorValor (entrada): o menor valor válido
 *   maiorValor (entrada): o maior valor válido
 * Retorno: A opção lida é validada
 ****/
int LeOpcao(int menorValor, int maiorValor)
{
    int op;
    while (1)
    {
        printf("Digite sua opcao: ");
        op = getchar();
        if (op >= menorValor && op <= maiorValor)
        {
            LimpaBuffer();
            break;
        }
        else
        {
            printf("\nOpcao invalida. Tente novamente.");
            printf("\nA opcao deve estar entre %c e %c. \n",
                   menorValor, maiorValor);
            LimpaBuffer();
        }
    }
    return op;
}
/****
 * Função: LeInteiro()
 * Descrição: Lê um número inteiro introduzido pelo usuário
 * Parâmetros: Nenhum
 * Retorno: O inteiro lido
 ****/
int LeInteiro(void)
{
    int umInt, nValoresLidos;
    printf("Digite um valor inteiro: ");
    nValoresLidos = scanf("%d", &umInt);
    while (nValoresLidos == 0)
    { /*Nenhum inteiro foi lido*/
        LimpaBuffer();
        printf("Entrada incorreta. Digite um valor inteiro: ");
        nValoresLidos = scanf("%d", &umInt);
    }
    LimpaBuffer();
    return umInt;
}

void corrige_nome(char nome[])
{
    // Verificar se o nome contém apenas letras e espaços
    int tamanho_do_nome = strlen(nome);
    int i, j;
    char ultimo_caractere = ' ';

    // verificando se possui apenas letras e espaços
    for (i = 0, j = 0; i < tamanho_do_nome; i++)
    {
        if (isalpha(nome[i]) || nome[i] == ' ')
        {
            // Remover dois espaços consecutivos
            if (nome[i] == ' ' && ultimo_caractere == ' ')
            {
                continue;
            }
            nome[j] = nome[i];
            j++;
            ultimo_caractere = nome[i];
        }
    }
    nome[j] = '\0';

    nome[0] = toupper(nome[0]); // convertendo o primeiro caractere para maiúsculo
    // Percorra os caracteres restantes e convertendo para minúsculo
    for (i = 1; i < j; i++)
    {
        nome[i] = tolower(nome[i]);
        // Verificando se o caractere anterior é um espaço em branco. Se sim, converte o caractere atual para maiúsculo
        if (nome[i - 1] == ' ')
        {
            nome[i] = toupper(nome[i]);
        }
    }
    tamanho_do_nome = strlen(nome);
    if (j == 1 && nome[tamanho_do_nome] == ' ')
    {
        nome[tamanho_do_nome] = '\0';
    }
}