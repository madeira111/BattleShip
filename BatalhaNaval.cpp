#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>


using namespace std;

void limpaTela(){
    system("CLS");
}

void IniciaTabuleiro(char tabuleiro[10][10],char mascara[10][10] ){
    for(int i = 0; i < 10; i++){

            for(int j = 0; j < 10; j++){
                tabuleiro[i][j] = 'a';
                mascara[i][j] = '*';
            }
    }
}

void posicoesBarcos(char tabuleiro[10][10]){

    int quantidade = 10, quantidadePosi = 0;

    while(quantidadePosi < quantidade){
        if(tabuleiro[rand()%10][rand()%10] == 'A'){
            tabuleiro[rand()%10][rand()%10] = 'P';
            quantidadePosi++;
        }
    }
}

void jogo(){

    char tabuleiro[10][10], mascara[10][10];
    int LinhaJogada, ColunaJogada;
    int estadoDeJogo = 1;
    int pontos = 0;

    IniciaTabuleiro(tabuleiro,mascara);
    posicoesBarcos(tabuleiro);

    while(estadoDeJogo == 1){
        limpaTela();

        for(int i = 0; i < 10; i++){
            //cout << i << " - ";
            for(int j = 0; j < 10; j++){
                cout << " "<<tabuleiro[i][j];
            }
            cout << "\n";
        }

        cout<< "Pontos: " << pontos;

        cout <<"Digite uma Linha: ";
        cin >>LinhaJogada;

        cout <<"Digite uma Coluna: ";
        cin >>ColunaJogada;

        if(tabuleiro[LinhaJogada][ColunaJogada] == 'P'){
            pontos = pontos + 1 ;
        }




        mascara[LinhaJogada][ColunaJogada] = tabuleiro[LinhaJogada][ColunaJogada];

    }

}


void menuInicial(){

    int opcao = 0;

    while(opcao < 1 || opcao > 3){
        limpaTela();
        cout << "Bem vindo ao Jogo\n";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair";
        cout << "\nEscolha uma ocao e click Enter: ";
        cin  >> opcao;

        switch(opcao){
        case 1:
            cout << "Jogo Iniciado\n";
            jogo();
            break;
        case 2:
            cout << "Sobre o Jogo\n";
            break;
        case 3:
            cout << "Ate Logo\n";
            break;
        }
    }
}


int main(){

    srand((unsigned)time(NULL));

    menuInicial();


return 0;}






