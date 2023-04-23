#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "C:\Users\jhoan\Desktop\VScode\GitHub\HospitalManagementSystem\Hospital.c\include\hospital.h"

#define MaxNome 100
#define Leitos 25
#define codigohospital 77

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
    char receita[50];
};
struct listapacientes
{
    Pacientes *pacientes;
    struct listapacientes *next;
    struct listapacientes *prev;
};

struct hospital
{
    int codigo;
    int leitos;
    char localizacao[20];
    char nome[15];
    Listapacientes *lista;
};

Hospital *lista_cria(Hospital *h)
{
    h = (Hospital *)malloc(sizeof(Hospital));
    h->lista = (Listapacientes *)malloc(sizeof(Listapacientes));
    if (h->lista == NULL)
    {
        printf("Erro: memoria insuficiente.\n");
        exit(1);
    }
    h->lista = NULL;
    h->lista->next = NULL;
    h->lista->prev = NULL;
    h->leitos = Leitos;
    h->codigo = codigohospital;
    strcpy(h->nome, "HealCare");
    return h;
}

FILE *cadastra_paciente(FILE *arquivo, char *caminho)
{
    Pacientes paciente;
    int i;
    char opcao_documento;

    // Abrir o arquivo para escrita
    arquivo = fopen(caminho, "a");

    // Verificar se o arquivo foi aberto com sucesso
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]s", paciente.nome);
    // Formatando nome
    int tamanhodonome = strlen(paciente.nome);
    paciente.nome[0] = toupper(paciente.nome[0]); // convertendo o primeiro caractere para maiusculo
    // Percorra os caracteres restantes e convertendo para minúscula
    for (i = 1; i < tamanhodonome; i++)
    {
        paciente.nome[i] = tolower(paciente.nome[i]);
        // Verificando se o caractere anterior é um espaço em branco Se sim, converte o caractere atual para maiúscula
        if (paciente.nome[i - 1] == ' ')
        {
            paciente.nome[i] = toupper(paciente.nome[i]);
        }
    }

    printf("Digite a enfermidade do paciente: ");
    scanf(" %[^\n]s", paciente.enfermidade);

    printf("Digite a receita para o paciente: ");
    scanf(" %[^\n]s", paciente.receita);

    printf("Internado? (1-sim) (0-nao)");
    scanf(" %d", &paciente.internado);
    // Pedir para o usuário escolher qual documento cadastrar
    printf("Digite '1' para cadastrar o CPF ou '2' para cadastrar o RG: ");
    scanf(" %c", &opcao_documento);

    // Ler o documento escolhido pelo usuário
    if (opcao_documento == '1')
    {
        printf("Digite o CPF do paciente (XXX.YYY.ZZZ-SS): ");
        scanf(" %s", paciente.documento.cpf);
    }
    else if (opcao_documento == '2')
    {
        printf("Digite o RG do paciente (XXX.YYY.ZZZ): ");
        scanf(" %s", paciente.documento.rg);
    }
    else
    {
        printf("Opcao invalida.\n");
        exit(1);
    }

    // Escrever os dados do aluno no arquivo
    if (opcao_documento == '1')
        fprintf(arquivo, "%s\t%s\t%s\t%s\t%i\n", paciente.nome, paciente.documento.cpf, paciente.enfermidade, paciente.receita, paciente.internado);
    else
        fprintf(arquivo, "%s\t%s\t%s\t%s\t%i\n", paciente.nome, paciente.documento.rg, paciente.enfermidade, paciente.receita, paciente.internado);

    // Fechar o arquivo
    fclose(arquivo);
    ordena_pacientes(caminho);
    printf("Paciente cadastrado com sucesso.\n\n");
    return arquivo;
}

// Função para comparar dois pacientes por nome (usado no quicksort)
int compare_pacientes(const void *a, const void *b)
{
    Pacientes *pa = (Pacientes *)a;
    Pacientes *pb = (Pacientes *)b;
    return strcmp(pa->nome, pb->nome);
}

// Função para ler e escrever os pacientes em ordem alfabética no arquivo
void ordena_pacientes(char *caminho)
{
    // Abrir o arquivo para leitura
    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Contar o número de pacientes no arquivo
    int num_pacientes = 0;
    char linha[MaxNome + 100];
    while (fgets(linha, MaxNome + 100, arquivo))
    {
        num_pacientes++;
    }
    rewind(arquivo); // Voltar o ponteiro do arquivo para o início

    // Alocar memória para a matriz de pacientes
    Pacientes *pacientes = (Pacientes *)malloc(num_pacientes * sizeof(Pacientes));
    if (pacientes == NULL)
    {
        printf("Erro: memoria insuficiente.\n");
        exit(1);
    }

    // Ler os pacientes do arquivo para a matriz
    for (int i = 0; i < num_pacientes; i++)
    {
        fgets(linha, MaxNome + 100, arquivo);
        sscanf(linha, "%[^'\t']\t%s\t%[^'\t']\t%[^'\t']\t%d\n",
               pacientes[i].nome, pacientes[i].documento, pacientes[i].enfermidade,
               pacientes[i].receita, &pacientes[i].internado);
    }

    // Ordenar a matriz de pacientes por nome
    qsort(pacientes, num_pacientes, sizeof(Pacientes), compare_pacientes);

    // Fechar o arquivo de leitura e abrir o arquivo de escrita
    fclose(arquivo);
    arquivo = fopen(caminho, "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Escrever os pacientes ordenados no arquivo
    for (int i = 0; i < num_pacientes; i++)
    {
        fprintf(arquivo, "%s\t%s\t%s\t%s\t%d\n",pacientes[i].nome, pacientes[i].documento, pacientes[i].enfermidade,pacientes[i].receita, pacientes[i].internado);
    }

    // Fechar o arquivo de escrita e liberar a memória alocada
    fclose(arquivo);
    free(pacientes);
}
