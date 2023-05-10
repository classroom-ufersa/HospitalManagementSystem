#include "paciente.c"
#include "C:\Users\jhoan\Desktop\VScode\GitHub\HospitalManagementSystem\Hospital.c\include\hospital.h"

#define MaxNome 100
#define Leitos 25
#define codigohospital 77

struct hospital
{
    int codigo;
    int leitos;
    char localizacao[20];
    char nome[10];
    Listapacientes *lista;
};

Hospital *hospital_cria(void)
{
    Hospital *h = (Hospital *)malloc(sizeof(Hospital));
    if (h == NULL)
    {
        printf("ERRO de alocacao de memoria!\n");
        exit(1);
    }
    h->lista = lista_cria();
    h->lista->next = NULL;
    h->lista->prev = NULL;
    h->leitos = Leitos;
    h->codigo = codigohospital;
    strcpy(h->nome, "HealCare");
    strcpy(h->localizacao, "Cidade: UmariGomes");
    return h;
}

Hospital *cadastra_paciente(Hospital *h, int *qnt)
{
    if ((*qnt) == Leitos)
    {
        printf("Capacidade máxima atingida!\n");
        exit(1);
    }
    // Adicionando o paciente na lista do hospital
    Pacientes p = paciente_preenche();
    h->lista = lista_add((h->lista), p);
    (*qnt)++;
    (h->leitos)--;
    printf("Paciente cadastrado com sucesso.\n\n");
    return h;
}

FILE *add_arquivo(Hospital *h, char *caminho)
{
    FILE *arquivo = fopen(caminho, "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    Listapacientes *p = h->lista;
    while (p->next != NULL)
    {
        paciente_add(p, arquivo);
        p = p->next;
    }
    fclose(arquivo);
    return arquivo;
}

void ler_arquivo(Hospital *h, char *caminho, int *num_pacientes)
{
    Pacientes paciente;
    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    char linha[100];
    int i = 0;
    while (fgets(linha, 100, arquivo) != NULL)
    {
        sscanf(linha, "Nome: %[^\n]", paciente.nome);
        fgets(linha, 100, arquivo);
        sscanf(linha, "Enfermidade: %[^\n]", paciente.enfermidade);
        fgets(linha, 100, arquivo);
        sscanf(linha, "Receita: %[^\n]", paciente.receita);
        fgets(linha, 100, arquivo);
        sscanf(linha, "Internado: %c", &paciente.internado);
        fgets(linha, 100, arquivo);
        if (strstr(linha, "CPF") != NULL)
        {
            sscanf(linha, "CPF: %s", paciente.documento.cpf);
            fgets(linha, 100, arquivo);
            sscanf(linha, "RG: %s", paciente.documento.rg);
        }
        else
        {
            sscanf(linha, "RG: %s", paciente.documento.rg);
            fgets(linha, 100, arquivo);
            sscanf(linha, "CPF: %s", paciente.documento.cpf);
        }
        h->lista = lista_add(h->lista, paciente);
        i++;
    }
    fclose(arquivo);
    *num_pacientes = i;
    h->leitos -= i;
}

Hospital *excluir_paciente(Listapacientes *p, Hospital *h)
{
    if (p == NULL)
    {
        return h; // não achou
    }
    else
    {
        // retira o elemento
        if (h->lista == p) // testa se é o primeiro elemento
        {
            h->lista = p->next;
        }
        else
        {
            p->prev->next = p->next; // retira o do meio
        }
        if (p->next != NULL) // testa se é o ultimo elemento
        {
            p->next->prev = p->prev;
        }
        free(p);
        h->leitos++;
        printf("Paciente excluido com sucesso!\n\n");
    }
    return h;
}

void dados_hospital(Hospital *h)
{
    printf("+----------------------------------------------------------------+\n"
           "|      Bem-vindo ao Hospital %s                            |\n"
           "|      Codigo: %d                                                |\n"
           "|      Localizado na %s                          |\n"
           "|      Horario de funcionamento das 07:00 as 21:00               |\n"
           "|                                                                |\n"
           "|      Socios: Jhoan Fernandes    Felipe Tomaz                   |\n"
           "+----------------------------------------------------------------+\n\n",
           h->nome, h->codigo, h->localizacao);
}