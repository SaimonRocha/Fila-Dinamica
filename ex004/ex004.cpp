#include <iostream>
using namespace std;

#include "fila-dinamica.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila U, P, N;
    ficha valor;
    ficha auxiliar;

    int op, contadorU = 0,
            contadorP = 0,
            contadorN = 0,
            numero_paginaU = 0,
            numero_paginaP = 0,
            numero_paginaN = 0;
    char fila;

    do
    {
        system("cls");
        cout << "--------------MENU--------------" << endl;
        cout << "1: Enviar documento para impressao\n";
        cout << "2: Mostrar o nome dos documentos armazenados nas filas\n";
        cout << "3: Imprimir documento\n";
        cout << "4: Total de Documentos e numero de Pg\n";
        cout << "5: Fila e suas informacoes\n";
        cout << "0: Sair\n";
        cout << "Escolha a opcao: ";
        cin >> op;

        if (op == 1)
        {
            cout << "Nome: ";
            cin >> valor.nome;

            cout << "Tamanho: MB";
            cin >> valor.tamanho;

            cout << "Quantidade de Páginas: ";
            cin >> valor.quantidade;

            cout << "Ano: ";
            cin >> valor.ano;

            cout << "Prioridade: ";
            cin >> valor.prioridade;

            if (valor.prioridade == "U")
            {
                enfileiraF(&U, valor);
                cout << "Adicionado para impressao U" << endl;
                contadorU = contadorU + 1;                          // Toda vez que adicionar um doc o contador recebe 1
                numero_paginaU = valor.quantidade + numero_paginaU; // Armazeno somente as paginas de U
            }
            else if (valor.prioridade == "P")
            {
                enfileiraF(&P, valor);
                cout << "Adicionado para impressao P" << endl;
                contadorP = contadorP + 1;                          // Toda vez que adicionar um doc o contador recebe 1
                numero_paginaP = valor.quantidade + numero_paginaP; // Armazeno somente as paginas de P
            }
            else if (valor.prioridade == "N")
            {
                enfileiraF(&N, valor);
                cout << "Adicionado para impressao N" << endl;
                contadorN = contadorN + 1;                          // Toda vez que adicionar um doc o contador recebe 1
                numero_paginaN = valor.quantidade + numero_paginaN; // Armazeno somente as paginas de N
            }
        }
        if (op == 2)
        {
            cout << "Mostrando fila de impressao" << endl;
            if (vaziaF(&U) == false)
            {
                cout << "Lista U" << endl;
                mostraF(&U);
            }
            if (vaziaF(&P) == false)
            {
                cout << "Lista P" << endl;
                mostraF(&P);
            }
            if (vaziaF(&N) == false)
            {
                cout << "Lista N" << endl;
                mostraF(&N);
            }
        }
        if (op == 3)
        {
            cout << "Imprimindo documento" << endl;
            if (vaziaF(&U) == false)
            {
                auxiliar = desenfileiraF(&U);
                cout << "Documento impresso: " << auxiliar.nome << endl;
            }
            else if (vaziaF(&P) == false && vaziaF(&U) == true)
            {
                auxiliar = desenfileiraF(&P);
                cout << "Documento impresso: " << auxiliar.nome << endl;
            }
            else if (vaziaF(&N) == false && vaziaF(&P) == true && vaziaF(&U) == true)
            {
                auxiliar = desenfileiraF(&N);
                cout << "Documento impresso: " << auxiliar.nome << endl;
            }
            else
            {
                cout << "Não Existe mais documentos a serem impresso";
            }
        }
        if (op == 4)
        {
            int contTotal = 0;
            int numero_pagina_total = 0;
            contTotal = contadorU + contadorP + contadorN;                          // Somando todos os doc adicionados
            numero_pagina_total = numero_paginaU + numero_paginaP + numero_paginaN; // Somando todos os numeros de pagina

            cout << "Total de Documentos a Serem Impressos: " << contTotal << endl;
            cout << "Numero de Paginas a serem impresso: " << numero_pagina_total << endl;
        }
        if (op == 5)
        {
            int maior = valor.tamanho;
            int menor = valor.quantidade;

            cout << "Informe a fila que deseja informacoes U/P/N: ";
            cin >> fila;

            if (fila == 'U')
            {
                cout << "Numero de documentos na fila: " << contadorU << endl;

                if (maior < valor.tamanho)
                {
                    maior = valor.tamanho;
                }
                cout << " " << maior;

                if (menor > valor.quantidade)
                {
                    menor = valor.quantidade;
                }
                cout << " " << menor;
            }
        }

        else if (op > 5)
            cout << "Opcao invalida!\n\n";
        if (op > 0)
            system("pause");

    } while (op != 0);
} // final do main
