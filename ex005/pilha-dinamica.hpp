#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <iomanip> //biblioteca usada para formatar a impress�o da pilha

struct ficha
{
    string nome;
    string cidade;
    string plc_veiculo;
    int idade;
    char sexo;
};

struct NoPilha
{
    ficha dado;    // informação
    NoPilha *prox; // próximo elemento
};

struct Pilha
{
    NoPilha *topo;

    Pilha()
    { // Construtor. Inicialização da pilha
        topo = nullptr;
        string nome = "", cidade = "", plc_veiculo = "";
        int idade = 0;
        char sexo;
    }
};

bool vaziaP(Pilha *p)
{
    if (p->topo == NULL)
        return true;
    else
        return false;
}

// push
bool empilhaP(Pilha *p, ficha dado)
{
    NoPilha *novo = new NoPilha(); // cria um novo nó
    if (novo == NULL)              /// sistema não conseguiu alocar a memória
        return false;
    novo->dado = dado;    // armazena a informação no nó
    novo->prox = p->topo; // o pr�ximo elemento do n� criado ser� o �ltimo elemento da pilha
    p->topo = novo;       // atualiza o topo da pilha para o n� criado.
    return true;
}

// pop
ficha desempilhaP(Pilha *p)
{
    ficha dado;

    // se não estiver vazia, retira valor
    if (vaziaP(p) == false)
    {
        dado = p->topo->dado;      // pega o dado armazenado no nó do topo
        NoPilha *apagar = p->topo; // guarda o nó do topo em uma variável auxiliar;
        p->topo = p->topo->prox;   // atualiza o topo para o próximo elemento;

        delete apagar; /// libera a memória
    }

    return dado;
}

// peek
// ficha espiaP(Pilha *p)
// {
//     ficha dado;
//     dado.nome;
//     dado.cidade;
//     dado.plc_veiculo;
//     dado.idade;
//     dado.sexo;

//     if (vaziaP(p) == false)
//         dado = p->topo->dado;

//     return dado;
// }

void mostraP(Pilha *p)
{
    cout << "PILHA: " << endl;

    if (vaziaP(p) == false)
    {
        cout << "--------------------------------------------" << endl;
        cout << setfill(' ') << std::setw(13) << "Nó"
             << " | ";
        cout << setfill(' ') << std::setw(13) << "Prox"
             << " | ";
        cout << setfill(' ') << std::setw(10) << "Dado"
             << " |" << endl;
        cout << "--------------------------------------------" << endl;
        NoPilha *no = p->topo;
        while (no != NULL)
        {
            cout << setfill(' ') << std::setw(13) << no << " | ";
            cout << setfill(' ') << std::setw(13) << no->prox << " | ";
            cout << setfill(' ') << std::setw(10) << no->dado.nome << ", " << no->dado.cidade << ", " << no->dado.plc_veiculo << ", " << no->dado.idade << ", " << no->dado.sexo << " |" << endl;
            no = no->prox;
        }
        cout << "--------------------------------------------" << endl;
    }
}

void contarsexo(Pilha *p)
{
    int aux_sexoM = 0, aux_sexoF = 0;

    if (vaziaP(p) == false)
    {
        NoPilha *no = p->topo;
        while (no != NULL)
        {
            if (no->dado.sexo == 'm')
            {
                aux_sexoM = aux_sexoM + 1;
            }
            else
            {
                aux_sexoF = aux_sexoF + 1;
            }
            no = no->prox;
        }
        cout << "Sexo Masculino: " << aux_sexoM << endl;
        cout << "Sexo Feminino: " << aux_sexoF << endl;
    }
}
void contarIdade(Pilha *p)
{
    int soma = 0, quantidade = 0, aux_idade = 0;
    float media = 0.0;

    if (vaziaP(p) == false)
    {
        NoPilha *no = p->topo;
        while (no != NULL)
        {
            if (no->dado.idade > 0)
            {
                quantidade = quantidade + 1;            // Toda vez que indicar idade recebe + 1
                soma = no->dado.idade + no->dado.idade; // Soma recebe idade + idade
                media = soma / quantidade;              // Irá fazer a média
            }

            no = no->prox;
        }
        // cout << "Soma da Idade: " << quantidade << endl;
        // cout << "Soma da Soma: " << soma << endl;
        cout << "Média Aritmética: " << media << endl;
    }
}
void mostrar_plc_mais_velha(Pilha *p)
{
    int idade_velha = 0;

    if (vaziaP(p) == false)
    {
        NoPilha *no = p->topo;
        while (no != NULL)
        {
            if (no->dado.idade > idade_velha)
            {
                idade_velha = no->dado.idade;

                if (idade_velha > 0)
                {
                    cout << "Placa do veiculo: " << no->dado.plc_veiculo << endl;
                }
            }
            no = no->prox;
        }
    }
}
/// retorna true se o valor existe na pilha
/// retorna false se o valor n�o existe na pilha
// bool buscaP(Pilha *p, char dado)
// {

//     NoPilha *no = p->topo;
//     while (no != NULL)
//     {
//         if (no->dado == dado)
//             return true;

//         no = no->prox;
//     }

//     return false;
//}

// void destroiP(Pilha *p)
// {
//     char dado;
//     while (vaziaP(p) == false)
//         dado = desempilhaP(p); // desempilha e descarta o valor desempilhado
// }

#endif // _HPP_PILHA_DINAMICA
