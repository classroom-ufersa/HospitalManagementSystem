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
void LimpaBuffer(void)
{
    int valorLido; /* valorLido deve ser int! */
    do
    {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
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
            Beep(1200, 300);
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