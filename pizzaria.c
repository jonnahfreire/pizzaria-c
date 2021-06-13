#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
    ADS - IFCE - CANINDÉ
    ATIVIDADE 04 - PROGRAMAÇÃO ESTRUTURADA
    PROF: MANOEL LOPES
    ALUNO: JONAS DE SOUSA FREIRE
    MATRÍCULA: 20202103020045
*/

char *strToUpperCase(char *str);
void clear();
void menu(char* sabores[5], char* precos[5][4], char* bebidas[5][2]);
void sep(int chr, int l);




int main() {
    int pizzaIdSabor=0, pizzaIdTam=0, bebidaIdSabor=0, i=0;
    float pPreco = 0, bPreco = 0, total = 0;

    char pizzaPedido, bebidaPedido;
    char tam[2]="";
    char pedido;

    char* sigTam[5] = {"P", "M", "G", "GG"};
    char* sabores[5] = {
        "Mussarela", "Calabresa",
        "Marguerita", "Portuguesa", "Mista"
    };

    char* precos[5][4] = {
        // P         M        G        GG
        {"13.00", "18.50", "24.00", "30.00"}, // Mussarela
        {"14.70", "19.90", "25.30", "32.40"}, // Calabresa
        {"13.70", "19.95", "26.35", "34.50"}, // Marguerita
        {"15.60", "20.20", "25.30", "30.10"}, // Portuguesa
        {"15.00", "18.20", "23.30", "30.00"}  // Mista
    };

    char* bebidas[5][2] = {
        {"Cajuina 1L", "6.00"},
        {"Fanta Laranja 350ML", "4.00"},
        {"Guarana 1L", "6.00"},
        {"Pepsi 1L", "6.00"},
        {"Coca Cola 2L", "10.00"}
    };

    clear();
    menu(sabores, precos, bebidas);

    sep('-', 0);
    printf("\nDeseja pedir alguma pizza? [s/n]: ");
    fflush(stdin);
    scanf("%c", &pizzaPedido);

    if(pizzaPedido == 's' || pizzaPedido == 'S'){
        int condition;
        do {
            printf("Digite o numero do sabor desejado: ");
            scanf("%d", &pizzaIdSabor);
            sep('-', 0);

            condition = (pizzaIdSabor > 5) || (pizzaIdSabor < 1);
            if(condition)
                printf("\nNumero invalido! Escolha um numero valido.\n");
        }while(condition);

        int err=0;
        do {
            printf("\nEscolha o tamanho [P] [M] [G] [GG]: ");
            fflush(stdin);
            scanf("%s", tam);
            sep('-', 0);

            if(strcmp(strToUpperCase(tam), strToUpperCase(sigTam[0])) == 0
               || strcmp(strToUpperCase(tam), strToUpperCase(sigTam[1])) == 0
               || strcmp(strToUpperCase(tam), strToUpperCase(sigTam[2])) == 0
               || strcmp(strToUpperCase(tam), strToUpperCase(sigTam[3])) == 0
            ) err = 0;
            else err = 1;

            if(err == 1)
                printf("\nTamanho invalido! Escolha um tamanho valido.\n");
        }while(err == 1);
    }

    printf("\nDeseja pedir alguma bebida? [s/n]: ");
    fflush(stdin);
    scanf("%c", &bebidaPedido);

    if(bebidaPedido == 's' || bebidaPedido == 'S'){
        int condition;
        do {
            printf("Digite o numero da bebida desejada: ");
            scanf("%d", &bebidaIdSabor);
            sep('-', 0);

            condition = (bebidaIdSabor > 5) || (bebidaIdSabor < 1);
            if(condition)
                printf("\nNumero invalido! Escolha um numero valido.\n");
        }while(condition);
    }

    if(pizzaPedido == 's' || pizzaPedido == 'S'){
        for(i = 0; i < 4; i++){
            if((strcmp(strToUpperCase(tam), strToUpperCase(sigTam[i])) == 0)
               && (strlen(tam) == strlen(sigTam[i])))
            {
                pizzaIdTam = i;
            }
        }
    }

    for(i = 0; i < 5; i++){
        if((pizzaIdSabor-1 == i) && (bebidaIdSabor == 0)){
            printf("\nVoce pediu 1 %s tamanho %s.\nValor a pagar: R$%s\n",
               sabores[pizzaIdSabor-1],
               sigTam[pizzaIdTam],
               precos[i][pizzaIdTam]);

        } else if((pizzaIdSabor-1 == i) && (bebidaIdSabor > 0)){
            pPreco = strtod(precos[i][pizzaIdTam], NULL);
            bPreco = strtod(bebidas[bebidaIdSabor-1][1], NULL);
            total = pPreco + bPreco;

            printf("\nVoce pediu 1 %s tamanho %s, e 1 %s.\nValor a pagar: R$%.2f\n",
               sabores[pizzaIdSabor-1],
               sigTam[pizzaIdTam],
               bebidas[bebidaIdSabor-1][0],
               total);

        } else if((pizzaIdSabor == 0) && (bebidaIdSabor > 0)){
            printf("\nVoce pediu 1 %s.\nValor a pagar: R$%s\n",
               bebidas[bebidaIdSabor-1][0],
               bebidas[bebidaIdSabor-1][1]);
               break;
        }
    }

    printf("\nDeseja realizar um novo pedido? [s/n]: ");
    fflush(stdin);
    scanf("%c", &pedido);

    if(pedido == 's' || pedido == 'S') main();

    clear();
    printf("\nObrigado, e volte sempre!!\n\n");
    exit(0);

    return 0;
}




char *strToUpperCase(char *str){
    char upperStr[strlen(str)];
    char *nstr = (char*) calloc(1, sizeof(char));
    int i;
    for(i = 0; str[i] != '\0'; i++){
        upperStr[i] = toupper(str[i]);
    }
    strcpy(nstr, upperStr);
    return nstr;
}


void menu(char* sabores[5], char* precos[5][4], char* bebidas[5][2]){
    int i, e, c, pLineLength = 16, bLineLEngth = 46;

    sep('=', 0);
    printf("\n\t\tBEM-VINDOS AO IMPERIO DOS SABORES\n");

    sep('=', 0);
    printf("\n    Sabor\t\tP\t   M\t     G\t      GG\n");
    sep('-', 1);

	for(i = 0; i < 5; i++){
        printf("%d - %s ", i+1, sabores[i]); // Nomes das pizzas

        for(c = 0; c < pLineLength - strlen(sabores[i]); c++){
            printf(".");
        }

        for(e = 0; e < 4; e++){ // Preços das pizzas
            if(e != 3 && e == 0) printf(" R$%s - ", precos[i][e]);
            else if(e != 3 && e > 0) printf("R$%s - ", precos[i][e]);
            else printf("R$%s", precos[i][e]);
        }
        printf("\n");
	}

    sep('-', 1);

	for(i = 0; i < 5; i++){ // bebidas
        printf("%d - %s ", i+1, bebidas[i][0]);

        for(c = 0; c < bLineLEngth - strlen(bebidas[i][0]); c++){
            printf(".");
        }
        printf(" R$%s", bebidas[i][1]);
        printf("\n");
	}
}


void clear() {
    #ifdef _WIN32
	    system("cls");
	#else
        #if __linux__
            system("clear");
        #endif
    #endif
}


void sep(int chr, int l) {
    int i;
    for(i = 0; i<59; i++)printf("%c", chr);
    if (l != 0) printf("\n");
}

