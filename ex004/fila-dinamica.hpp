#ifndef _HPP_FILA_DINAMICA
#define _HPP_FILA_DINAMICA

struct ficha
{
    string nome, prioridade;
    int tamanho, quantidade, ano;
};

struct NoFila
{
    ficha dado; //informacao do n�
    NoFila *prox; //proximo elemento da fila
};

struct Fila
{
    NoFila *inicio;
    NoFila *fim;

    Fila(){ //Construtor. Usado para inicializar os dados das vari�veis da struct
        inicio = nullptr;
        fim = nullptr;
    }
};


bool vaziaF(Fila *f)
{
    if (f->inicio == NULL) //verifica se a fila est� vazia, ou seja, (f->inicio == NULL)
        return true;
    else
        return false;
}


//Enqueue
bool enfileiraF(Fila *f, ficha dado)
{
    NoFila *novo = new NoFila();
    if (novo == NULL) /// n�o conseguiu alocar mem�ria (novo == NULL)
        return false;

    novo->dado = dado;
    novo->prox = nullptr;
    if (f->inicio == NULL) //verifica se a fila est� vazia, ou seja, (f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return true;
}

//Dequeue
ficha desenfileiraF(Fila *f)
{
    ficha dado;

    // se n�o estiver vazia, retira valor
    if (vaziaF(f) == false) //verifica se a fila n�o est� vazia, ou seja, (f->inicio != NULL)
    {
        dado = f->inicio->dado; //pega o dado armazenado no primeiro n�
        NoFila *apagar = f->inicio; //guarda o primeiro n� em uma vari�vel auxiliar;
        f->inicio = f->inicio->prox; // atualiza o in�cio da fila
        delete apagar;  // libera a mem�ria

        if (f->inicio == NULL) //verifica se a fila est� vazia, ou seja, (f->inicio == NULL)
            f->fim = nullptr;
    }

    return dado;
}

//peek
ficha espiaF(Fila* f)
{
    ficha dado;

    if (vaziaF(f) == false) //verifica se a fila n�o est� vazia, ou seja, (f->inicio != NULL)
    {
        dado = f->inicio->dado;
    }

    return dado;
}

//show
void mostraF(Fila *f)
{
    cout << "Fila: ";

    if(vaziaF(f) == false) //verifica se a fila n�o est� vazia
    {

        cout << "[";

        NoFila *no = f->inicio;
        while (no != NULL) //fa�a enquanto (no != NULL)
        {
            cout << no->dado.nome << ", " << no->dado.tamanho<<", " << no->dado.quantidade<<", "<< no->dado.ano<<", "<< no->dado.prioridade<<", ";
            no = no->prox;

            if(no != NULL) //verifica se o pr�ximo n� n�o � nulo (no != NULL)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    else
        cout << "vazia!\n";
}

// retorna true se o valor existe na fila
// retorna false se o valor n�o existe na fila
// bool buscaF(Fila *f, ficha dado)
// {

//     NoFila *no = f->inicio;
//     while (no != NULL) //fa�a enquanto (no != NULL)
//     {
//         if(no->dado.nome == dado)
//             return true;

//         no = no->prox;
//     }

//     return false;
// }

void destroiF(Fila *f)
{

    NoFila *no = f->inicio;
    while (no != NULL) //fa�a enquanto (no != NULL)
    {
        NoFila *apagar = no; //guarda o n� em uma vari�vel auxiliar;

        no = no->prox;

        delete apagar;
    }

    f->inicio = nullptr;
    f->fim = nullptr;
}

#endif // _HPP_FILA_DINAMICA





