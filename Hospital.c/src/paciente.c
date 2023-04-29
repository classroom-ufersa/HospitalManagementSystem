#include <stdio.h>  //funções basicas da linguagem c
#include <stdlib.h> //para fazer alocação dinamica
#include <string.h> //para usar strings
#include <ctype.h>  //manipulação de caracteres
#include "C:\Users\jhoan\Desktop\VScode\GitHub\HospitalManagementSystem\Hospital.c\include\paciente.h"

#define MaxNome 100
#define Leitos 25

union document
{
    char cpf[15];
    char rg[12];
};

struct pacientes
{
    char nome[MaxNome];
    Document documento;
    char enfermidade[50];
    int internado; // sim == 1, nao == 0
    char receita[100];
};

struct listapacientes
{
    Pacientes *pacientes;
    struct listapacientes *next;
    struct listapacientes *prev;
};

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
}

Listapacientes *lista_cria(void)
{
    Listapacientes *l = (Listapacientes *)malloc(sizeof(Listapacientes));
    return l;
}

Pacientes paciente_preenche(void)
{
    Pacientes paciente;
    char opcao_documento;

    // Ler o nome do paciente
    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]", paciente.nome);
    corrige_nome(paciente.nome);
    printf("Digite a enfermidade do paciente: ");
    scanf(" %[^\n]s", paciente.enfermidade);

    printf("Digite a receita para o paciente: ");
    scanf(" %[^\n]s", paciente.receita);

    printf("Internado? (1-sim) (0-nao): ");
    scanf("%d", &paciente.internado);
    if (paciente.internado != 1 && paciente.internado != 0)
    {
        printf("Erro: entrada invalida\n");
        exit(1);
    }
    // Pedir para o usuário escolher qual documento cadastrar
    printf("Digite '1' para cadastrar o CPF ou '2' para cadastrar o RG: ");
    scanf(" %c", &opcao_documento);
    if (opcao_documento != '1' && opcao_documento != '2')
    {
        printf("Erro: entrada invalida\n");
        exit(1);
    }
    // lendo documento
    if (opcao_documento == '1')
    {
        printf("Digite o CPF do paciente (XXX.YYY.ZZZ-SS): ");
        scanf(" %[^\n]s", paciente.documento.cpf);
        if (strlen(paciente.documento.cpf) != 14)
        {
            printf("Erro: entrada invalida. Digite um CPF válido.\n");
            exit(1);
        }
    }
    else if (opcao_documento == '2')
    {
        printf("Digite o RG do paciente (XXX.YYY.ZZZ): ");
        scanf(" %[^\n]s", paciente.documento.rg);
        if (strlen(paciente.documento.rg) != 11)
        {
            printf("Erro: entrada invalida. Digite um RG válido.\n");
            exit(1);
        }
    }
    else
    {
        printf("Opcao invalida.\n");
        exit(1);
    }
    return paciente;
}

void paciente_add(Listapacientes *p, FILE *arquivo)
{
    Pacientes paciente = *(p->next->pacientes);
    fprintf(arquivo, "Nome: %s\n", paciente.nome);
    fprintf(arquivo, "Enfermidade: %s\n", paciente.enfermidade);
    fprintf(arquivo, "Receita: %s\n", paciente.receita);
    fprintf(arquivo, "Internado: %s\n", paciente.internado ? "Sim" : "Nao");
    if (strlen(paciente.documento.cpf) == 14)
    {
        fprintf(arquivo, "CPF: %s\n", paciente.documento.cpf);
    }
    else
    {
        fprintf(arquivo, "RG: %s\n", paciente.documento.rg);
    }
    fprintf(arquivo, "\n");
}

Listapacientes *lista_add(Listapacientes *l, Pacientes paciente)
{
    // Encontrar a posição correta para inserir o novo paciente
    Listapacientes *p = l;
    while (p->next != NULL && strcmp(p->next->pacientes->nome, paciente.nome) < 0)
    {
        p = p->next;
    }
    // Criar um novo nó para o novo paciente
    Listapacientes *novo_no = (Listapacientes *)malloc(sizeof(Listapacientes));
    if (novo_no == NULL)
    {
        printf("Erro: memoria insuficiente.\n");
        exit(1);
    }
    novo_no->pacientes = (Pacientes *)malloc(sizeof(Pacientes));
    if (novo_no->pacientes == NULL)
    {
        printf("Erro: memoria insuficiente.\n");
        exit(1);
    }
    *novo_no->pacientes = paciente;

    // Inserir o novo paciente na posição correta
    novo_no->next = p->next;
    novo_no->prev = p;
    if (p->next != NULL)
    {
        p->next->prev = novo_no;
    }
    p->next = novo_no;
    return l;
}

Listapacientes *busca_paciente(Listapacientes *l, char nome[])
{
    Listapacientes *p;
    for (p = l; p != NULL; p = p->next)
    {
        if (strcmp(p->pacientes->nome, nome) == 0)
        {
            return p;
        }
    }
    return NULL;
}

void edita_paciente(Listapacientes *p)
{
    int cont;
    printf("\nNome: %s\n", p->pacientes->nome);
    printf("Enfermidade: %s\n", p->pacientes->enfermidade);
    printf("Receita: %s\n", p->pacientes->receita);
    printf("Internado: %s\n", p->pacientes->internado ? "Sim" : "Nao");
    printf("Documento: %s\n\n", p->pacientes->documento.rg);
    printf("Deseja mesmo editar o paciente acima? (1-sim)(2-nao)\n");
    scanf("%d", &cont);
    if (cont == 1)
    {

        int opcao;
        printf("\nO que voce deseja editar?\n");
        printf("1 - Nome\n");
        printf("2 - Enfermidade\n");
        printf("3 - Receita\n");
        printf("4 - Internado\n");
        printf("5 - Documento\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\nDigite o novo nome: ");
            scanf(" %[^\n]s", p->pacientes->nome);
            break;
        case 2:
            printf("\nDigite a nova enfermidade: ");
            scanf(" %[^\n]s", p->pacientes->enfermidade);
            break;
        case 3:
            printf("\nDigite a nova receita: ");
            scanf(" %[^\n]s", p->pacientes->receita);
            break;
        case 4:
            printf("\nO paciente esta internado? (1-sim / 0-nao): ");
            scanf("%d", &p->pacientes->internado);
            break;
        case 5:
            printf("\nDigite '1' para editar o CPF ou '2' para editar o RG: ");
            char opcao_documento;
            scanf(" %c", &opcao_documento);

            if (opcao_documento == '1')
            {
                printf("Digite o novo CPF (XXX.YYY.ZZZ-SS): ");
                scanf(" %[^\n]s", p->pacientes->documento.cpf);
            }
            else if (opcao_documento == '2')
            {
                printf("Digite o novo RG (XXX.YYY.ZZZ): ");
                scanf(" %[^\n]s", p->pacientes->documento.rg);
            }
            else
            {
                printf("Opcao invalida!\n");
            }
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
}

void lista_libera(Listapacientes *l)
{
    Listapacientes *p = l;
    while (p != NULL)
    {
        Listapacientes *t = p->next;
        free(p);
        p = t;
    }
}

void lista_imprime(Listapacientes *l)
{
    Listapacientes *p = l->next;
    while (p != NULL)
    {
        printf("Nome: %s\n", p->pacientes->nome);
        printf("Enfermidade: %s\n", p->pacientes->enfermidade);
        printf("Receita: %s\n", p->pacientes->receita);
        printf("Internado: %s\n", p->pacientes->internado ? "Sim" : "Nao");
        if (strlen(p->pacientes->documento.cpf) == 14)
        {
            printf("CPF: %s\n", p->pacientes->documento.cpf);
        }
        else
        {
            printf("RG: %s\n", p->pacientes->documento.rg);
        }
        printf("\n");
        p = p->next;
    }
}