#ifndef _HPP_PILHA_DINAMICA
#define _HPP_PILHA_DINAMICA

#include <iomanip> //biblioteca usada para formatar a impress�o da pilha


struct NoPilha
{
    int dado; //informa��o do n�
    NoPilha *prox; //pr�ximo elemento
};

struct Pilha
{
    NoPilha *topo;

    Pilha(){ //Construtor. Inicializa��o da pilha
        topo = nullptr;
    }
};


bool vaziaP(Pilha *p)
{
    if (p->topo == NULL)
        return true;
    else
        return false;
}


//push
bool empilhaP(Pilha *p, int dado)
{
    NoPilha *novo =  new NoPilha(); //cria um novo n�
    if (novo == NULL) /// sistema n�o conseguiu alocar a mem�ria
        return false;

    novo->dado = dado; //armazena a informa��o no n�
    novo->prox = p->topo; //o pr�ximo elemento do n� criado ser� o �ltimo elemento da pilha
    p->topo = novo; //atualiza o topo da pilha para o n� criado.
    return true;
}

//pop
int desempilhaP(Pilha *p)
{
    int dado = 0;

    // se n�o estiver vazia, retira valor
    if (vaziaP(p) == false)
    {
        dado = p->topo->dado; //pega o dado armazenado no n� do topo
        NoPilha *apagar = p->topo; //guarda o n� do topo em uma vari�vel auxiliar;
        p->topo = p->topo->prox; //atualiza o topo para o pr�ximo elemento;

        delete apagar;  /// libera a mem�ria
    }

    return dado;
}

//peek
int espiaP(Pilha* p)
{
    int dado = 0;

    if (vaziaP(p) == false)
        dado = p->topo->dado;

    return dado;
}


void mostraP(Pilha *p)
{
    cout << "PILHA: " << endl;

    if(vaziaP(p) == false)
    {
        cout << "--------------------------------------------" << endl;
        cout << setfill(' ') << std::setw(13) << "N�" << " | ";
        cout << setfill(' ') << std::setw(13) << "Prox" << " | ";
        cout << setfill(' ') << std::setw(10) << "Dado" << " |" << endl;
        cout << "--------------------------------------------" << endl;
        NoPilha *no = p->topo;
        while (no != NULL)
        {
            cout << setfill(' ') << std::setw(13) << no << " | ";
            cout << setfill(' ') << std::setw(13) << no->prox << " | ";
            cout << setfill(' ') << std::setw(10) << no->dado << " |" << endl;

            no = no->prox;
        }
        cout << "--------------------------------------------" << endl;
    }
}

/// retorna true se o valor existe na pilha
/// retorna false se o valor n�o existe na pilha
bool buscaP(Pilha *p, int dado)
{
    NoPilha *no = p->topo;
    
    while (no != NULL)
    {
        if(no->dado == dado)
            return true;

        no = no->prox;
    }

    return false;
}

void destroiP(Pilha *p)
{
    int dado;
    while(vaziaP(p) == false)
        dado = desempilhaP(p); //desempilha e descarta o valor desempilhado
}

void empilhaOrdenado(Pilha *p, int valor)
{
    int d;
    Pilha aux;

    while (!vaziaP(p) && espiaP(p) < valor)
    {
        d = desempilhaP(p);
        empilhaP(&aux, d);
    }

    empilhaP(p, valor);

    while (!vaziaP(&aux))
    {
        d = desempilhaP(&aux);
        empilhaP(p, d);
    }

}

#endif // _HPP_PILHA_DINAMICA





