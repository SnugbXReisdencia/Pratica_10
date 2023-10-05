#include <iostream>
#include <limits>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void pause();
void pause2();
void limpaTela();

int menu();
int menuAlterarAluno(string);

void bubbleSort(vector<string>& nomes, vector<float>& notas1, vector<float>& notas2);

int main()
{
    limpaTela();

    int N, opcao, opcao2, aux;
    string nomeParaExcluir, nome;
    float nota1, nota2;
    
    cout << "Digite o limite de alunos (N): ";
    cin >> N;

    vector<string> nomes;
    vector<float> notas1;
    vector<float> notas2;

    auto it = nomes.end();

    char sn;

    do
    {
        limpaTela();
        opcao = menu();
        switch (opcao)
        {
        case 1:
            do
            {
                if (int(nomes.size()) >= N)
                {
                    cout << "Limite de alunos atingido. Não é possível adicionar mais alunos." << endl;
                    pause();
                    break;
                }

                cout << "Digite o nome do aluno: ";
                cin.ignore();
                getline(cin, nome);

                cout << "Digite a primeira nota do aluno: ";
                cin >> nota1;

                cout << "Digite a segunda nota do aluno: ";
                cin >> nota2;

                nomes.push_back(nome);
                notas1.push_back(nota1);
                notas2.push_back(nota2);

                if(nomes.size() > 1)
                {
                    bubbleSort(nomes, notas1, notas2);
                }

                cout << "Deseja incluir mais alunos (s/n)? ";
                cin >> sn;
            } while (sn == 's' || sn == 'S');

            for (size_t i = 0; i < nomes.size() - 1; i++)
            {
                for (size_t j = 0; j < nomes.size() - i - 1; j++)
                {
                    if (nomes[j] > nomes[j + 1])
                    {
                        swap(nomes[j], nomes[j + 1]);
                        swap(notas1[j], notas1[j + 1]);
                        swap(notas2[j], notas2[j + 1]);
                    }
                }
            }
            break;
        case 2:
            cout << "Digite o nome do aluno que deseja excluir: ";
            cin.ignore();
            getline(cin, nomeParaExcluir);
            
            it = find(nomes.begin(), nomes.end(), nomeParaExcluir);

            if (it != nomes.end())
            {
                size_t indice = distance(nomes.begin(), it);
                if (indice < nomes.size())
                { 
                    nomes.erase(nomes.begin() + indice);
                    notas1.erase(notas1.begin() + indice);
                    notas2.erase(notas2.begin() + indice);

                    cout << "Aluno excluído com sucesso." << endl;
                }
                else
                {
                    cout << "Erro: Índice do aluno fora dos limites." << endl;
                }
            }
            else
            {
                cout << "Aluno não encontrado." << endl;
            }
            pause2();            
            break;
        case 3:
            limpaTela();
            cout << "\n######### Lista de Alunos #########" << endl;
            for (size_t i = 0; i < nomes.size(); i++)
            {
                if (i < notas1.size() && i < notas2.size())
                { 
                    cout << "Aluno " << i + 1 << "ª: " << endl;
                    cout << "Nome: " << nomes[i] << "\nNota 1: " << fixed << setprecision(1) << notas1[i] << "\nNota 2: " << notas2[i] << endl;
                    cout << "Media: " << (notas1[i] + notas2[i]) / 2 << endl;
                    (notas1[i] + notas2[i]) / 2 >= 7 ? cout << "Aluno aprovado." << endl : cout << "Aluno reprovado." << endl;
                    cout << "------------------------------------------------" << endl;
                }
                else
                {
                    cout << "Erro: Índice do aluno fora dos limites." << endl;
                }
            }
            pause();
            break;
        case 4:
            limpaTela();
            cout << "Digite o nome do aluno que deseja alterar: ";
            cin.ignore();
            getline(cin, nome);

            it = find(nomes.begin(), nomes.end(), nome);

            if(it != nomes.end())
            {
                aux = distance(nomes.begin(), it);
            }else{
                cout << "Aluno não encontrado." << endl;
                pause();
                break;
            }
            opcao2 = menuAlterarAluno(nomes[aux]);
            switch (opcao2){
            case 1:
                cout << "Digite a nova nota 1: ";
                cin >> nota1;
                notas1[aux] = nota1;
                cout << "Nota 1 alterada com sucesso !!" << endl;
                pause();
                break;
            case 2:
                cout << "Digite a nova nota 2: ";
                cin >> nota2;
                notas2[aux] = nota2;
                cout << "Nota 2 alterada com sucesso !!" << endl;
                pause();
                break;
            case 0:
                break;
            default:
                cout << "Opção invalida." << endl;
                pause();
                break;
            }
        case 0:
            break;
        default:
            cout << "Opção invalida." << endl;
            pause();
            break;
        }
    } while (opcao != 0);
    return 0;
}

void bubbleSort(vector<string>& nomes, vector<float>& notas1, vector<float>& notas2) {
    size_t n = nomes.size();

    bool trocou;
    do {
        trocou = false;
        for (size_t j = 0; j < n - 1; j++) {
            if (nomes[j] > nomes[j + 1]) {
                // Troque os elementos nos vetores nomes, notas1 e notas2
                swap(nomes[j], nomes[j + 1]);
                swap(notas1[j], notas1[j + 1]);
                swap(notas2[j], notas2[j + 1]);
                trocou = true;
            }
        }
        n--;
    } while (trocou);
}


int menu()
{
    int opcao;
    cout << "############## Menu de Alunos ##############\n\n";
    cout << "1 - Incluir\n";
    cout << "2 - Excluir\n";
    cout << "3 - Listar\n";
    cout << "4 - Alterar\n";
    cout << "0 - Sair\n";
    cout << "\nEscolha uma opcao: ";
    cin >> opcao;
    return opcao;
}

int menuAlterarAluno(string nome)
{
    int opcao;
    cout << "############## Alterar Dados do " << nome << " ##############\n\n";
    cout << "1 - Nota 1\n";
    cout << "2 - Nota 2\n";
    cout << "0 - Voltar Menu Aluno\n";
    cout << "\nEscolha uma opcao: ";
    cin >> opcao;
    return opcao;
}

void pause()
{
    cin.ignore();
    cout << "\nPressione a tecla Enter para continuar...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void pause2()
{
    cout.clear();
    cin.sync();
    cout << "\nPressione a tecla Enter para continuar...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void limpaTela()
{
    cin.clear();

    // Verifica se a variável de ambiente WINDIR está definida (ambiente Windows)
    const char *windir = getenv("WINDIR");

    if (windir != nullptr && strlen(windir) > 0)
    {
        // Se estiver definida, estamos no Windows, então use "cls"
        system("cls");
    }
    else
    {
        // Caso contrário, estamos em um ambiente Unix/Linux, use "clear"
        system("clear");
    }
}