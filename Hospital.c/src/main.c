#include "hospital.c"

int main(void)
{
    int controle = 0, quantidade = 0;
    FILE *arquivo;
    char caminho[] = "C:\\Users\\jhoan\\Desktop\\VScode\\GitHub\\HospitalManagementSystem\\Hospital.c\\data\\pacientes.txt"; // caminho do arquivo txt(Varia de pc para pc)
    arquivo = fopen(caminho, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo!");
        exit(1);
    }
    Hospital *HealCare = lista_cria();
    ler_arquivo(HealCare, caminho, &quantidade);
    printf("+----------------------------------------------------------------+\n"
           "|        Bem-vindo ao Programa de Gerenciamento Hospitalar       |\n"
           "|                                                                |\n"
           "|           Autores: Jhoan Fernandes    Felipe Tomaz             |\n"
           "+----------------------------------------------------------------+\n\n");
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

            break;
        case 3:
            lista_imprime(HealCare);
            break;
        case 4:

            break;
        case 5:

            break;
        case 6:
            if (quantidade < Leitos)
                printf("Existem %d leitos disponiveis no momento de um total de %d\n\n", Leitos - quantidade, Leitos);
            else
                printf("Nao existem leitos disponiveis no momento todos os %d estao sendo utilizados!\n\n", Leitos);
            break;
        case 7:

            break;
        case 8:

            break;
        default:
            printf("opcao invalida!");
            break;
        }
    }
    return 0;
}