#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N_OPCOES 8

#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'
#define OPCAO7 '7'
#define OPCAO8 '8'

void LimpaBuffer(void)
{
    int valorLido;
    do
    {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
}

int LeOpcao(int menorValor, int maiorValor)
{
    int op;
    char entrada[50];
    while (1)
    {
        printf("Digite sua opcao: ");
        scanf(" %[^\n]", entrada);
        op = entrada[0];
        if (op >= menorValor && op <= maiorValor && strlen(entrada) == 1)
        {
            LimpaBuffer();
            break;
        }
        else
        {
            printf("Opcao invalida. A opcao deve estar entre %c e %c. \n", menorValor, maiorValor);
            LimpaBuffer();
        }
    }
    return op;
}

void corrige_nome(char nome[])
{
    int tamanho_do_nome = strlen(nome);
    int i, j;
    char ultimo_caractere = ' ';

    for (i = 0, j = 0; i < tamanho_do_nome; i++)
    {
        if (isalpha(nome[i]) || nome[i] == ' ')
        {
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
    nome[0] = toupper(nome[0]);
    for (i = 1; i < j; i++)
    {
        nome[i] = tolower(nome[i]);
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

int validarCPF(const char *cpf)
{
    if (strlen(cpf) != 14)
    {
        return 1;
    }

    for (int i = 0; i < 14; i++)
    {
        if (i != 3 && i != 7 && i != 11)
        {
            if (!isdigit(cpf[i]))
            {
                return 1;
            }
        }
    }

    if (cpf[3] != '.' || cpf[7] != '.' || cpf[11] != '-')
    {
        return 1;
    }

    return 0;
}

int validarRG(const char *rg)
{
    if (strlen(rg) != 11)
    {
        return 1;
    }

    for (int i = 0; i < 11; i++)
    {
        if (i != 3 && i != 7)
        {
            if (!isdigit(rg[i]))
            {
                return 1;
            }
        }
    }

    if (rg[3] != '.' || rg[7] != '.')
    {
        return 1;
    }
    return 0;
}

void lerCPF(char cpf[])
{
    do
    {
        printf("Digite o CPF do paciente (XXX.YYY.ZZZ-SS): ");
        scanf(" %[^\n]", cpf);
        LimpaBuffer();
        if (validarCPF(cpf))
        {
            printf("Erro: digite um CPF valido.\n");
        }
    } while (validarCPF(cpf));
}

void lerRG(char rg[])
{
    do
    {
        printf("Digite o RG do paciente (XXX.YYY.ZZZ): ");
        scanf(" %[^\n]", rg);
        LimpaBuffer();
        if (validarRG(rg))
        {
            printf("Erro: digite um RG valido.\n");
        }
    } while (validarRG(rg));
}