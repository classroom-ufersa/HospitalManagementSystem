#include "hospital.c"

int main(void)
{
    int controle = 0, quantidade = 0;
    char nome[MaxNome];
    Listapacientes *pacientetemp = (Listapacientes *)malloc(sizeof(Listapacientes));
    FILE *arquivo;
    char caminho[] = "C:\\Users\\jhoan\\Desktop\\VScode\\GitHub\\HospitalManagementSystem\\Hospital.c\\data\\pacientes.txt"; // caminho do arquivo txt(Varia de pc para pc)
    arquivo = fopen(caminho, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo!");
        exit(1);
    }
    Hospital *HealCare = hospital_cria();
    ler_arquivo(HealCare, caminho, &quantidade);
    dados_hospital(HealCare);
    while (controle != 8) // vai repetir ate o usuario digitar 8
    {
        printf("Menu:\n");
        printf("========================================\n");
        printf("[1] Cadastrar paciente\n");
        printf("[2] Excluir paciente\n");
        printf("[3] Listar pacientes\n");
        printf("[4] Buscar paciente\n");
        printf("[5] Editar cadastro de paciente\n");
        printf("[6] Consultar vagar disponiveis de leitos no hospital\n");
        printf("[7] Consultar quantidade de pacientes\n");
        printf("[8] Sair\n");
        printf("========================================\n");
        printf("Digite o numero da opcao desejada: ");
        scanf("%d", &controle);
        system("cls");
        switch (controle)
        {
        case 1:
            HealCare = cadastra_paciente(HealCare, &quantidade);
            arquivo = add_arquivo(HealCare, caminho);
            break;
        case 2:
            printf("Insira o nome do paciente que deseja excluir: ");
            scanf(" %[^\n]s", nome);
            pacientetemp = busca_paciente(HealCare->lista, nome);
            excluir_paciente(pacientetemp, HealCare);
            add_arquivo(HealCare, caminho);
            break;
        case 3:
            lista_imprime(HealCare);
            break;
        case 4:
            printf("Insira o nome do paciente que deseja buscar: ");
            scanf(" %[^\n]s", nome);
            pacientetemp = busca_paciente(HealCare->lista, nome);
            printf("\nNome: %s\n", pacientetemp->pacientes->nome);
            printf("Enfermidade: %s\n", pacientetemp->pacientes->enfermidade);
            printf("Receita: %s\n", pacientetemp->pacientes->receita);
            printf("Internado: %s\n", pacientetemp->pacientes->internado ? "Sim" : "Nao");
            printf("Documento: %s\n\n", pacientetemp->pacientes->documento.rg);
            break;
        case 5:
            printf("Insira o nome do paciente que deseja editar: ");
            scanf(" %[^\n]s", nome);
            pacientetemp = busca_paciente(HealCare->lista, nome);
            edita_paciente(pacientetemp);
            add_arquivo(HealCare, caminho);
            break;
        case 6:
            if (HealCare->leitos > 0)
                printf("Existem %d leitos disponiveis no momento de um total de %d.\n\n", HealCare->leitos, Leitos);
            else
                printf("Nao existem leitos disponiveis no momento todos os %d estao sendo utilizados!\n\n", Leitos);
            break;
        case 7:
            printf("Existem um total de %d pacientes cadastrados!\n\n", Leitos - HealCare->leitos);
            break;
        case 8:
            printf("Obrigado por utilizar meu programa!\n");
            break;
        default:
            printf("opcao invalida!\n");
            break;
        }
    }
    free(pacientetemp);
    lista_libera(HealCare);
    return 0;
}