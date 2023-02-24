#include <iostream>
using namespace std;

#include "fila-dinamica.hpp"
#include "pilha-dinamica.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f1;
    Pilha p1;
    int valor, opMenu, dados;

    do
    {
        system("cls");
        cout << "================ MENU ================" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Inserir" << endl;
        cout << "2 - Remover" << endl;
        cout << "3 - Mostrar" << endl;
        cout << "4 - Inverter" << endl;
        cout << "Sua escolha: ";
        cin >> opMenu;

        if (opMenu == 1)
        {
            cout<<"Digite um número: ";
            cin>>valor;
            enfileiraF(&f1, valor);
        }

        if (opMenu == 2)
        {
            desenfileiraF(&f1);
            cout<<"Removido com sucesso!"<<endl;
        }

        if (opMenu == 3)
        {
            mostraF(&f1);
        }

        if (opMenu == 4)
        {
            while(vaziaF(&f1) == false)
            {
                dados = desenfileiraF(&f1);
                empilhaP(&p1, dados);
            }

            while(vaziaP(&p1) == false)
            {
                dados = desempilhaP(&p1);
                enfileiraF(&f1, dados);
            }

            mostraF(&f1);
        }

        if (opMenu > 0)
            system("pause");

    } while (opMenu != 0);

    destroiF(&f1);

    return EXIT_SUCCESS;

} //final do main
