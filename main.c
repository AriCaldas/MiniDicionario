 ///Minidicionário com STRUCTS em C///

//Importação das bibliotecas necessárioas ao programa.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

//Construção da estrutura que representará o minidicinário
struct dicionario{

    char palavra[20];
    char definicao[50];
};

//Função para verficar se a palavra digitada pelo existe no dicionário.
bool compararStrings(char palavra1[],char palavra2[]){

    int i = 0;  //Contador de iterações para o lçao "while".
    //Verificação de igualdade entre palavras caractere por caractere [i] até o final('\0') caso sejam iguais.
    while(palavra1[i] == palavra2[i] && palavra1[i] != '\0' && palavra2[i] != '\0'){
        i++;    //O incremento só ocorre caso haja correspondências entre os caracteres a cada iteração.
    }
    if(palavra1[i] == '\0' && palavra2[i] == '\0'){ //Verifica se amabas as palavras chegaram ao últmio caractere, ou seja, se são iguais.
        return true;
    }else{
        return false;
    }
}

//Função que busca a definição correspondente a palavra que foi digitada pelo usuário, caso esta conste na relação de palavras.
int procurarStrings(struct dicionario lingua[],char procurar[],int numDePalavras){

    int i;
    while(i < numDePalavras){   //O limite de iterações para o laço "while" é o número de palavras do mindicionário.
        if(compararStrings(procurar, lingua[i].palavra)){   //Uso da função anterior para verificar a igualdade das palavras.
            return i;           //i representa a palvra constante no minidicionário cuja definição será referenciada pelo valor de i.
        }else{
            i++;    //Caso a palavra não seja igual a digitada pelo usuário, o laço segue para a próxima iteração para comparar com apróxima palavra
        }
    }
    printf("Palavra não enconrada!");   //Caso não haja palavra correspondente no minidicionário.
    return -1;
}

int main(){         //Função principal.

    char palavra[20];   //Palavra digitada pelo usuário.
    int numeroDeDefinicoes = 7; //Quantidade de palavras/definições do minidicionário.
    int resultadoPesquisa;      //Receberá o valor inteiro retornado pela função "procurarStrings" para futura referência da definiçao constante na struct "minidicionario".
    struct dicionario portugues[] = //Inicialização do minidiocnario - "palavra", "definição".
       {{"pao", "comida de farinha"},
        {"mortadela", "comida de carne"},
        {"feijao", "comida brasileira"},
        {"tropeiro", "tipo de feijao"},
        {"queijo", "de minas"},
        {"macarronada", "tipico de vo"},
        {"pizza", "tipico da Italia"}};
    setlocale(LC_ALL, "");          //Exibição de caracteres especiais e acntuação gráfica.
    printf("Digite uma palavra: "); //Interação com usuário.
    scanf("%s", palavra);
    resultadoPesquisa = procurarStrings(portugues, palavra, 7); //Chamada às funções do minidicionario e atribuição do valor à variável "resultadoPesquisa".
    printf("%s", portugues[resultadoPesquisa].definicao); //Exibição da definição correspondente no minidicionario.
    return 0;
}
