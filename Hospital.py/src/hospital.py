class Document:
    def __init__(self, cpf="", rg=""):
        self.cpf = cpf
        self.rg = rg

class Paciente:
    def __init__(self, nome="", documento=Document(), enfermidade="", internado=0, receita=""):
        self.nome = nome
        self.documento = documento
        self.enfermidade = enfermidade
        self.internado = internado
        self.receita = receita

class ListaPacientes:
    def __init__(self, paciente=Paciente()):
        self.paciente = paciente
        self.next = None
        self.prev = None

class Hospital:
    def __init__(self, codigo=77, leitos=25, localizacao="", nome="", lista=None, numpacientes = 0):
        self.codigo = codigo
        self.leitos = leitos
        self.localizacao = localizacao
        self.nome = nome
        self.lista = lista
        self.num_pacientes = numpacientes

def lista_cria():
    h = Hospital()
    h.lista = ListaPacientes()
    h.lista.next = None
    h.lista.prev = None
    h.leitos = 25
    h.num_pacientes = 0  
    h.codigo = 77
    h.nome = "HealCare"
    h.localizacao = "Cidade: UmariGomes"
    return h

def cadastra_paciente(hospital, qnt):
    if qnt == 25:
        print("Capacidade máxima atingida!\n")
        return

    paciente = Paciente()
    paciente.nome = input("Digite o nome do paciente: ").title()
    paciente.enfermidade = input("Digite a enfermidade do paciente: ")
    paciente.receita = input("Digite a receita para o paciente: ")
    paciente.internado = int(input("Internado? (1-sim) (0-nao): "))
    opcao_documento = input("Digite '1' para cadastrar o CPF ou '2' para cadastrar o RG: ")
    if opcao_documento == '1':
        paciente.documento.cpf = input("Digite o CPF do paciente (XXX.YYY.ZZZ-SS): ")
    elif opcao_documento == '2':
        paciente.documento.rg = input("Digite o RG do paciente (XXX.YYY.ZZZ): ")
    else:
        print("Opcao invalida.\n")
        return
    # Adicionando o paciente na lista do hospital
    lista_add(hospital, paciente)
    hospital.num_pacientes += 1
    hospital.leitos -= 1
    print("Paciente cadastrado com sucesso.\n\n")
    return hospital

def lista_add(self, paciente):
    # Encontrar a posição correta para inserir o novo paciente
    p = self.lista
    while p.next is not None and p.next.paciente.nome < paciente.nome:
        p = p.next

    # Criar um novo nó para o novo paciente
    novo_no = ListaPacientes(Paciente())
    novo_no.paciente = paciente

    # Inserir o novo paciente na posição correta
    novo_no.next = p.next
    novo_no.prev = p
    if p.next is not None:
        p.next.prev = novo_no
    p.next = novo_no
    
def lista_imprime(h):
    p = h.lista.next
    while p != None:
        print("Nome:", p.paciente.nome)
        print("Enfermidade:", p.paciente.enfermidade)
        print("Receita:", p.paciente.receita)
        print("Internado:", "Sim" if p.paciente.internado else "Nao")
        if p.paciente.documento.cpf or p.paciente.documento.rg:
            if p.paciente.documento.cpf:
                print("CPF:", p.paciente.documento.cpf)
            else:
                print("RG:", p.paciente.documento.rg)
        print()
        p = p.next

def add_arquivo(h, caminho):
    arquivo = open(caminho, "w")
    if arquivo == None:
        print("Erro ao abrir o arquivo.\n")
        exit(1)

    p = h.lista
    while p.next != None:
        paciente = p.next.paciente
        arquivo.write(f"Nome: {paciente.nome}\n")
        arquivo.write(f"Enfermidade: {paciente.enfermidade}\n")
        arquivo.write(f"Receita: {paciente.receita}\n")
        arquivo.write(f"Internado: {'Sim' if paciente.internado else 'Nao'}\n")
        if len(paciente.documento.cpf) == 14:
            arquivo.write(f"CPF: {paciente.documento.cpf}\n")
        else:
            arquivo.write(f"RG: {paciente.documento.rg}\n")
        arquivo.write("\n")
        p = p.next

    arquivo.close()
    return arquivo

def ler_arquivo(hospital, caminho):
    try:
        with open(caminho, "r") as arquivo:
            num_pacientes = 0

            for linha in arquivo:
                paciente = Paciente()

                if linha.startswith("Nome:"):
                    paciente.nome = linha[6:].strip()

                linha = arquivo.readline()
                if linha.startswith("Enfermidade:"):
                    paciente.enfermidade = linha[13:].strip()

                linha = arquivo.readline()
                if linha.startswith("Receita:"):
                    paciente.receita = linha[8:].strip()

                linha = arquivo.readline()
                if linha.startswith("Internado:"):
                    paciente.internado = 1 if linha[10:].strip().lower() == "sim" else 0

                linha = arquivo.readline()
                if linha.startswith("CPF:"):
                    paciente.documento.cpf = linha[5:].strip()
                elif linha.startswith("RG:"):
                    paciente.documento.rg = linha[4:].strip()
                else:
                    raise ValueError("Documento inválido")

                lista_add(hospital, paciente)
                num_pacientes += 1

        hospital.num_pacientes += num_pacientes
        hospital.leitos -= num_pacientes
        print(f"{num_pacientes} pacientes adicionados com sucesso.")
    except FileNotFoundError:
        print("Arquivo não encontrado.")
    except ValueError as e:
        print(f"Erro na leitura do arquivo: {str(e)}")
    except Exception:
        print("Ocorreu um erro na leitura do arquivo.")

def busca_paciente(lista_pacientes, nome):
    for paciente in lista_pacientes:
        if paciente.nome == nome:
            return paciente
    print(f"Paciente {nome} não encontrado na lista.")
    return None


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
