#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void inicializarTabuleiro(char tabuleiro[SIZE][SIZE]);
void exibirTabuleiro(char tabuleiro[SIZE][SIZE]);
void posicionarEmbarcacoes(char tabuleiro[SIZE][SIZE]);
int processarTiro(char tabuleiro[SIZE][SIZE], int x, int y);
int fimDeJogo(char tabuleiro[SIZE][SIZE]);


int main()
{
    char jogador[SIZE][SIZE];
    char computador[SIZE][SIZE];
    char visivelJogador[SIZE][SIZE];
    char visivelComputador[SIZE][SIZE];

    inicializarTabuleiro(jogador);
    inicializarTabuleiro(computador);
    inicializarTabuleiro(visivelJogador);
    inicializarTabuleiro(visivelComputador);
    posicionarEmbarcacoes(jogador);
    posicionarEmbarcacoes(computador);


    srand(time(NULL));

    int x, y;

    while(1)
    {

        printf("Tabuleiro do jogador:\n");
        exibirTabuleiro(visivelJogador);

     do{
         printf("\nDigite a linha e coluna desejada:");
         scanf("%d %d", &x, &y);

     }while (x < 0 || x >= SIZE || y < 0 || y >= SIZE);


        if (processarTiro(computador, x, y))
        {
            printf("\nTiro certeiro!");
            visivelJogador[x][y] = 'X';
        }
        else
        {
            printf("\nVoce errou o tiro!");
            visivelJogador[x][y] = '~';

        }

        if (fimDeJogo(computador))
        {
            printf("Parabéns, você venceu o jogo!");
            break;
        }

        do
        {

            x = rand()% SIZE;
            y = rand()% SIZE;


        }
        while (visivelComputador[x][y] != ' ');



        if (processarTiro(jogador, x, y))
        {
            printf("\nComputador acertou nas coordenadas: %d,%d\n\n", x, y);
            visivelComputador[x][y] = 'X';
        }
        else
        {
            printf("\nComputador errou nas coordenadas: %d,%d o tiro!\n\n", x, y);
            visivelComputador[x][y] = '~';
        }

        if (fimDeJogo(jogador))
        {
            printf("O computador venceu o jogo, você perdeu!\n");
            break;
        }

    }
    return 0;

}


void inicializarTabuleiro(char tabuleiro[SIZE][SIZE])
{



    for (int i = 0 ; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
            tabuleiro[i][j] = ' ';
        }
    }

}

void exibirTabuleiro(char tabuleiro[SIZE][SIZE])
{

    for (int i = 0 ; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
            printf("|%c", tabuleiro[i][j]);
        }
        printf ("|\n");
    }

}

void posicionarEmbarcacoes(char tabuleiro[SIZE][SIZE])
{

    //Posição dos submarinos.

    tabuleiro[3][0] = 'S';
    tabuleiro[3][5] = 'S';
    tabuleiro[3][3] = 'S';
    tabuleiro[3][7] = 'S';
    tabuleiro[0][5] = 'S';


    //Posição dos Couraçados.

    //Posição 1:

    tabuleiro[5][5] = 'C';
    tabuleiro[5][7] = 'C';


    //Posição 2:

    tabuleiro[7][6] = 'C';
    tabuleiro[7][3] = 'C';


    //Posição do porta aviões;

    //Posição 1:

    tabuleiro[0][2] = 'A';

    //Posição 2:

    tabuleiro[5][1] = 'A';

    //Posição 3:

    tabuleiro[2][8] = 'A';
}

int processarTiro(char tabuleiro[SIZE][SIZE], int x, int y)
{

    if (tabuleiro[x][y] == 'S' || tabuleiro[x][y] == 'C' || tabuleiro[x][y] == 'A')
    {
        tabuleiro[x][y] = 'X';
        return 1;
    }
    else
    {
        return 0;

    }
}

int fimDeJogo(char tabuleiro[SIZE][SIZE])
{

    for (int i = 0 ; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {

            if (tabuleiro[i][j] == 'S' || tabuleiro[i][j] == 'C' || tabuleiro[i][j] == 'A')
            {
                return 0;
            }
        }
    }
    return 1;
}




