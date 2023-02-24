#include <iostream>
#include <cctype>

using namespace std;

#include "pilha-dinamica.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    Pilha pPF;
    Pilha pGR;
    Pilha pAuxiliar;
    ficha valor;
    bool resultado, resultado2;
    int op;

    do
    {
        system("cls");
        cout << "--------------MENU--------------" << endl;
        cout << "1: Criar ficha atendimento\n";
        cout << "2: Mostrar Ficha de Atendimento dos Clientes\n";
        cout << "3: Listar as fichas da pilha PILHAPF na ordem em que eles foram preenchidas\n";
        cout << "4: Mostrar informações dos clientes da pilha PILHAGERAL: números de clientes de cada sexo e média aritmética da idade dos clientes.\n";
        cout << "5 Mostrar a placa do veículo da pessoa mais velha)\n";
        cout << "0: Sair\n";
        cout << "Escolha a opcao: ";
        cin >> op;

        if (op == 1)
        {
            cout << "Nome: ";
            cin >> valor.nome;

            cout << "Informe a cidade:";
            fflush(stdin);
            getline(cin, valor.cidade);

            cout << "Placa: ";
            cin >> valor.plc_veiculo;

            cout << "Informe a idade:";
            cin >> valor.idade;

            cout << "Informe o sexo:";
            cin >> valor.sexo;

            if (valor.cidade == "passo fundo")
            {
                resultado = empilhaP(&pPF, valor);
            }
            else
            {
                resultado2 = empilhaP(&pGR, valor);
            }
        }
        else if (op == 2)
        {
            cout << "Ficha de Atendimento" << endl;
            cout << "\n\n";
            cout << "============ PASSO FUNDO ============" << endl;
            mostraP(&pPF);

            cout << "\n\n";
            cout << "============ GERAL ============" << endl;
            mostraP(&pGR);
        }
        else if (op == 3)
        {
            cout << "========== LISTA CONFORME FOI PREENCHIDA PILHA DE PASSO FUNDO ==========" << endl;
            while (vaziaP(&pPF) == false) // Enquanto a pilha não for vazia
            {
                valor = desempilhaP(&pPF);   // Valor recebe o desempilhamento de PF
                empilhaP(&pAuxiliar, valor); // Empilhando os valores de PF na PILHA AUXILIAR
            }
            cout << "PILHA INVERTIDA >>>>>>  ";
            mostraP(&pAuxiliar);

            while (vaziaP(&pAuxiliar) == false)
            {                                    // Enquanto a pilha não for vazia
                valor = desempilhaP(&pAuxiliar); // Valor Recebe o desempilhamento da Auxiliar
                empilhaP(&pPF, valor);           // Empilhando os valores da pilha Auxiliar na pilha de passo fundo;
            }
            cout << "PILHA VOLTA AO NORMAL >>>>>>>> ";
            mostraP(&pPF); // Mostrando os valore da PILHA PF
        }
        else if (op == 4)
        {
            cout << "======== números de clientes de cada sexo ========" << endl;
            contarsexo(&pGR);

            cout << "======== Média Aritmética da idade ========" << endl;
            contarIdade(&pGR);
        }
        else if (op == 5)
        {
            while (vaziaP(&pPF) == false) // Enquanto a pilha não for vazia
            {
                valor = desempilhaP(&pPF);   // Valor recebe o desempilhamento de PF
                empilhaP(&pAuxiliar, valor); // Empilhando os valores de PF na PILHA AUXILIAR
                valor = desempilhaP(&pGR);   // Valor recebe o desempilhamento de PF
                empilhaP(&pAuxiliar, valor); // Empilhando os valores de PF na PILHA AUXILIAR

                mostraP(&pAuxiliar);
            }
            mostrar_plc_mais_velha(&pAuxiliar);
        }
        
        else if (op > 5)
            cout << "Opcao invalida!\n\n";
        if (op > 0)
            system("pause");

    } while (op != 0);
}
