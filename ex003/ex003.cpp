#include <iostream>
using namespace std;

#include "fila-dinamica.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f1, f2;
    int N = 4;

    enfileiraF(&f1, 1);
    enfileiraF(&f1, 2);
    enfileiraF(&f1, 3);
    enfileiraF(&f1, 4);
    enfileiraF(&f1, 5);

    separaF(N, &f1, &f2);

    mostraF(&f1);
    mostraF(&f2);


    destroiF(&f1);
    destroiF(&f2);

    
    return EXIT_SUCCESS;
}
