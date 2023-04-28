class Document:
    def __init__(self, cpf="", rg=""):
        self.cpf = cpf
        self.rg = rg

class Paciente:
    def __init__(self, nome="", documento=None, enfermidade="", internado=0, receita=""):
        self.nome = nome
        self.documento = documento if documento is not None else Document()
        self.enfermidade = enfermidade
        self.internado = internado
        self.receita = receita

class ListaPacientes:
    def __init__(self, paciente=Paciente()):
        self.paciente = paciente
        self.next = None
        self.prev = None       