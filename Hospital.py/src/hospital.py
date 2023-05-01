from paciente import *

class Hospital:
    def __init__(self, codigo=77, leitos=25, localizacao="Cidade: UmariGomes", nome="HealCare", lista=ListaPacientes(), numpacientes = 0):
        self.codigo = codigo
        self.leitos = leitos
        self.localizacao = localizacao
        self.nome = nome
        self.lista = lista
        self.num_pacientes = numpacientes

def cadastra_paciente(hospital):
    if hospital.num_pacientes == 25:
        print("Capacidade máxima atingida!\n")
        return
    paciente = paciente_preenche()
    # Adicionando o paciente na lista do hospital
    lista_add(hospital, paciente)
    hospital.num_pacientes += 1
    hospital.leitos -= 1
    print("Paciente cadastrado com sucesso.\n\n")
    return hospital

def ler_arquivo(hospital, caminho):
    try:
        with open(caminho, "r") as arquivo:
            num_pacientes = 0

            # Cria uma lista para armazenar todos os pacientes lidos do arquivo
            pacientes = []

            # Lê o arquivo linha por linha
            for linha in arquivo:
                paciente = Paciente()

                # Lê as informações do paciente até encontrar uma linha em branco
                while linha.strip() != "":
                    if linha.startswith("Nome:"):
                        paciente.nome = linha[6:].strip()
                    elif linha.startswith("Enfermidade:"):
                        paciente.enfermidade = linha[13:].strip()
                    elif linha.startswith("Receita:"):
                        paciente.receita = linha[9:].strip()
                    elif linha.startswith("Internado:"):
                        paciente.internado = 1 if linha[11:].strip().lower() == "sim" else 0
                    elif linha.startswith("CPF:"):
                        paciente.documento.cpf = linha[5:].strip()
                    elif linha.startswith("RG:"):
                        paciente.documento.rg = linha[4:].strip()

                    linha = arquivo.readline()

                # Adiciona o paciente lido à lista de pacientes
                pacientes.append(paciente)

            # Adiciona todos os pacientes da lista ao hospital
            for paciente in pacientes:
                lista_add(hospital, paciente)
                hospital.num_pacientes += 1
                hospital.leitos -= 1
            return hospital

    except FileNotFoundError:
        print("Arquivo nao encontrado.\n")
        return


def edita_paciente(p):
    print(f"\nNome: {p.nome}")
    print(f"Enfermidade: {p.enfermidade}")
    print(f"Receita: {p.receita}")
    print(f"Internado: {'Sim' if p.internado else 'Nao'}")
    print(f"Documento: {p.documento.rg}\n")
    cont = int(input("Deseja mesmo editar o paciente acima? (1-sim)(2-nao)\n"))
    if cont == 1:
        opcao = int(input("\nO que voce deseja editar?\n1 - Nome\n2 - Enfermidade\n3 - Receita\n4 - Internado\n5 - Documento\nOpcao: "))
        if opcao == 1:
            p.nome = input("\nDigite o novo nome: ")
        elif opcao == 2:
            p.enfermidade = input("\nDigite a nova enfermidade: ")
        elif opcao == 3:
            p.receita = input("\nDigite a nova receita: ")
        elif opcao == 4:
            p.internado = int(input("\nO paciente esta internado? (1-sim / 0-nao): "))
        elif opcao == 5:
            opcao_documento = input("\nDigite '1' para editar o CPF ou '2' para editar o RG: ")
            if opcao_documento == '1':
                p.documento.cpf = input("Digite o novo CPF (XXX.YYY.ZZZ-SS): ")
            elif opcao_documento == '2':
                p.documento.rg = input("Digite o novo RG (XXX.YYY.ZZZ): ")
            else:
                print("Opcao invalida!")
                return
        else:
            print("Opcao invalida!")
            return
        print("Paciente editado com sucesso!")

def excluir_paciente (paciente,hospital):
    if paciente == None:
        return paciente
    else:
        if hospital.lista == paciente:
            hospital.lista = paciente.next
        else:
            paciente.prev.next = paciente.next
        if paciente.next != None:
            paciente.next.prev = paciente.prev
        hospital.leitos += 1
        hospital.num_pacientes -= 1
        print("Paciente excluido com sucesso!")
    return hospital

def dados_hospital(h):
    print("+----------------------------------------------------------------+")
    print("| Bem-vindo ao Hospital {}                                 |".format(h.nome))
    print("| Codigo: {:d}                                                     |".format(h.codigo))
    print("| Localizado na {}                               |".format(h.localizacao))
    print("| Horario de funcionamento das 07:00 as 21:00                    |")
    print("|                                                                |")
    print("| Socios: Jhoan Fernandes Felipe Tomaz                           |")
    print("+----------------------------------------------------------------+\n")