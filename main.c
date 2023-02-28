#include <stdio.h>
#include <stdlib.h>

/*Funcao que o usuario escolhe converter ou sair.
  Retorna o numero da opcao escolhida.*/
int Comeco(){
    int i;
    printf("\n\033[1m1- Converter\n2- Sair\033[m\n");
    scanf("%d", &i);
    return i;
}
/*Funcao que apresenta as opcoes de temperatura.
  Retorna o numero da opcao escolhida.*/
int Opcoes(){
    int i;
    printf("\n\033[1m1- Celsius\n2- Fahrenheit\n3- Kelvin\n\033[m");
    scanf("%d",&i);
    return i;
}
/*Funcao que printa uma sequencia de asteriscos.*/
void Asterisco(int n){
    int i;
    char a;
    a = '*';
    for(i=0; i<n; i++) printf("\033[1;33m%c\033[m",a);
    printf("\n");
}
/*Funcao que printa o nome da calculadora.*/
void Nome(){
    Asterisco(100);
    printf("\t\t\033[1;35m###### CONVERSOR DE TEMPERATURA #######\033[m\n");
}

float Converte(float valor, int n1, int n2){
    switch (n1){
        case 1:
            switch (n2){
            case 1:
                return valor;
                break;
            case 2:
                return valor*1.8 + 32;
                break;
            case 3:
                return valor + 273.15;
                break;
            }
            break;
        
        case 2:
            switch (n2){
            case 1:
                return (valor-32)/1.8;
                break;
            case 2:
                return valor;
                break;
            case 3:
                return ((valor-32)/1.8)+ 273.15;
                break;
            }
            break;
        case 3:
            switch (n2){
            case 1:
                return valor - 273.15;
                break;
            case 2:
                return (valor-273.15)*1.8 + 32;
                break;
            case 3:
                return valor;
                break;
            }
            break;
               
    }
}

/*Funcao principal que conecta tudo.*/
int main(){
    int n1, n2, converte;
    float valor, resultado;
    char temperatura[3]={'C', 'F', 'K'};
    Nome();
    converte = Comeco();
    while(converte == 1){
        printf("\n\033[1;32mQual unidade sera convertida: \033[m");
        n1 = Opcoes();
        printf("\n\033[1;32mDigite ao valor do temperatura: \033[m");
        scanf("%f", &valor);
        printf("\n\033[1;32mPara qual unidade sera convertida: \033[m");
        n2 = Opcoes();
        resultado = Converte(valor, n1, n2);
        printf("\n\033[1;34m# %.2f °%c correspondem a %.2f °%c\n\033[m", valor, temperatura[n1-1], resultado, temperatura[n2-1]);
        converte = Comeco();
    }
    Asterisco(100);
    return 0;
}