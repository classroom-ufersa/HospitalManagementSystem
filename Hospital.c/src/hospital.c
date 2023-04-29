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

void lista_imprime(Hospital *h)
{
    Listapacientes *p = h->lista->next;
    while (p != NULL)
    {
        printf("Nome: %s\n", p->pacientes->nome);
        printf("Enfermidade: %s\n", p->pacientes->enfermidade);
        printf("Receita: %s\n", p->pacientes->receita);
        printf("Internado: %s\n", p->pacientes->internado ? "Sim" : "Nao");
        printf("Documento: %s\n", p->pacientes->documento.cpf[0] != '\0' ? p->pacientes->documento.cpf : p->pacientes->documento.rg);
        printf("\n");
        p = p->next;
    }
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
        sscanf(linha, "Internado: %d", &paciente.internado);
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

Listapacientes *busca_paciente(Hospital *h, char nome[])
{
    Listapacientes *p;
    for (p = h->lista; p != NULL; p = p->next)
    {
        if (strcmp(p->pacientes->nome, nome) == 0)
        {
            return p;
        }
    }
    return NULL; // nao achou
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
        printf("Paciente excluido com sucesso!\n");
    }
    return h;
}

void lista_libera(Hospital *h)
{
    Listapacientes *p = h->lista;
    while (p != NULL)
    {
        Listapacientes *t = p->next;
        free(p);
        p = t;
    }
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