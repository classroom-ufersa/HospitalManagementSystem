#include <stdio.h>
#include <stdarg.h>
#include <windows.h>
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>
#include "sistema.h"  

#define N_OPCOES 8
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO1 '5'
#define OPCAO2 '6'
#define OPCAO3 '7'
#define OPCAO4 '8'

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
        printf("\nDigite sua opcao: ");
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
/****
 * Função: ApresentaMenu
 * Descrição: Apresenta menu com número indeterminado de opções
 * Parâmetros:
 *   nItens (entrada): número de itens no menu
 *   menorOpcao (entrada): caractere associado ao item I
 * Retorno: Nada
 ****/

int main(void)
{
    unsigned char op;
    int inteiro1, inteiro2;
    unsigned int saida = 0;

    do
    {
        op = LeOpcao(OPCAO1, OPCAO1 + N_OPCOES - 1);
        switch (op)
        {
        case OPCAO1:
            Beep(1000, 500); /* Emite um beep */
            inteiro1 = LeInteiro();
            inteiro2 = LeInteiro();
            printf("%d + %d = %d\n", inteiro1, inteiro2,
                   inteiro1 + inteiro2);
            break;

        case OPCAO2:
            Beep(1000, 500);
            inteiro1 = LeInteiro();
            inteiro2 = LeInteiro();
            printf("%d * %d = %d\n", inteiro1, inteiro2,
                   inteiro1 * inteiro2);
            break;

        case OPCAO3:
            Beep(1000, 500);
            inteiro1 = LeInteiro();
            inteiro2 = LeInteiro();
            printf("%d / %d = %d\n", inteiro1, inteiro2,
                   inteiro1 / inteiro2);
            break;

        case OPCAO4:
            Beep(1000, 500);
            saida = 1;
            printf("Obrigado por usar este programa.");
            break;

        default:
            printf("Este programa possui um bug.");
            return 1;
        }
    } while (!saida);
    return 0;
}