 ///Minidicion�rio com STRUCTS em C///

//Importa��o das bibliotecas necess�rioas ao programa.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

//Constru��o da estrutura que representar� o minidicin�rio
struct dicionario{

    char palavra[20];
    char definicao[50];
};

//Fun��o para verficar se a palavra digitada pelo existe no dicion�rio.
bool compararStrings(char palavra1[],char palavra2[]){

    int i = 0;  //Contador de itera��es para o l�ao "while".
    //Verifica��o de igualdade entre palavras caractere por caractere [i] at� o final('\0') caso sejam iguais.
    while(palavra1[i] == palavra2[i] && palavra1[i] != '\0' && palavra2[i] != '\0'){
        i++;    //O incremento s� ocorre caso haja correspond�ncias entre os caracteres a cada itera��o.
    }
    if(palavra1[i] == '\0' && palavra2[i] == '\0'){ //Verifica se amabas as palavras chegaram ao �ltmio caractere, ou seja, se s�o iguais.
        return true;
    }else{
        return false;
    }
}

//Fun��o que busca a defini��o correspondente a palavra que foi digitada pelo usu�rio, caso esta conste na rela��o de palavras.
int procurarStrings(struct dicionario lingua[],char procurar[],int numDePalavras){

    int i;
    while(i < numDePalavras){   //O limite de itera��es para o la�o "while" � o n�mero de palavras do mindicion�rio.
        if(compararStrings(procurar, lingua[i].palavra)){   //Uso da fun��o anterior para verificar a igualdade das palavras.
            return i;           //i representa a palvra constante no minidicion�rio cuja defini��o ser� referenciada pelo valor de i.
        }else{
            i++;    //Caso a palavra n�o seja igual a digitada pelo usu�rio, o la�o segue para a pr�xima itera��o para comparar com apr�xima palavra
        }
    }
    printf("Palavra n�o enconrada!");   //Caso n�o haja palavra correspondente no minidicion�rio.
    return -1;
}

int main(){         //Fun��o principal.

    char palavra[20];   //Palavra digitada pelo usu�rio.
    int numeroDeDefinicoes = 7; //Quantidade de palavras/defini��es do minidicion�rio.
    int resultadoPesquisa;      //Receber� o valor inteiro retornado pela fun��o "procurarStrings" para futura refer�ncia da defini�ao constante na struct "minidicionario".
    struct dicionario portugues[] = //Inicializa��o do minidiocnario - "palavra", "defini��o".
       {{"pao", "comida de farinha"},
        {"mortadela", "comida de carne"},
        {"feijao", "comida brasileira"},
        {"tropeiro", "tipo de feijao"},
        {"queijo", "de minas"},
        {"macarronada", "tipico de vo"},
        {"pizza", "tipico da Italia"}};
    setlocale(LC_ALL, "");          //Exibi��o de caracteres especiais e acntua��o gr�fica.
    printf("Digite uma palavra: "); //Intera��o com usu�rio.
    scanf("%s", palavra);
    resultadoPesquisa = procurarStrings(portugues, palavra, 7); //Chamada �s fun��es do minidicionario e atribui��o do valor � vari�vel "resultadoPesquisa".
    printf("%s", portugues[resultadoPesquisa].definicao); //Exibi��o da defini��o correspondente no minidicionario.
    return 0;
}
