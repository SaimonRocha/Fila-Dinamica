#include <iostream>
using namespace std;

#include "fila-dinamica.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Fila f1, f2, f3;

    enfileiraF(&f1, 1);
    enfileiraF(&f1, 2);
    enfileiraF(&f1, 3);
    enfileiraF(&f1, 4);
    enfileiraF(&f1, 5);

    enfileiraF(&f2, 6);
    enfileiraF(&f2, 7);
    enfileiraF(&f2, 8);
    enfileiraF(&f2, 9);
    enfileiraF(&f2, 10);

    concatenaF(&f1, &f2, &f3);

    mostraF(&f3);

    destroiF(&f1);

    return EXIT_SUCCESS;
} // final do main
