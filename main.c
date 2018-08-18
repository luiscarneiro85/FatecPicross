#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#define WIDTH 1024
#define HEIGHT 768

/*
typedef struct{
    int tamanho;
    int save;
    int tentativa;
    char *nomeImagem;
    SDL_Texture *textura;
    int matriz[15][15];
}Desafio;

Desafio gato = {5,1,7,"tabelacat.png",NULL,{
    {0,0,1,0,1},
    {0,0,1,1,1},
    {1,1,1,1,1},
    {1,1,1,1,0},
    {1,1,1,1,1}
}};
*/

typedef struct{
    char *nomeImagem;
    SDL_Texture *textura;
    SDL_Rect posicao;
}Imagem;


Imagem vazio = {"vazio.png",NULL};
Imagem backgroundPlay = {"backgroundPlay.jpg",NULL};
Imagem preenchido = {"preenchido.png",NULL};
Imagem backgroundMenu = {"background.jpg",NULL};
Imagem completa = {"concluido.png",NULL};
Imagem botaoJogar = {"botaojogar.png",NULL,{(WIDTH/2)-70,(HEIGHT/2)-30,140,60}};
Imagem botaoJogar2 = {"botaojogar2.png",NULL,};
Imagem botaoVoltar = {"botaovoltar.png",NULL,{(WIDTH-100),(HEIGHT-50),100,50}};
Imagem botaoVoltar2 = {"botaovoltar2.png",NULL};
Imagem botaoSair = {"botaosair.png",NULL,{(WIDTH/2)-70,674,140,60}};
Imagem botaoSair2 = {"botaosair2.png",NULL};
Imagem botaoTutorial = {"botaotutorial.png",NULL,{(WIDTH/2)-70,434,140,60}};
Imagem botaoTutorial2 = {"botaotutorial2.png",NULL};
Imagem botaoGaleria = {"botaogaleria.png",NULL,{(WIDTH/2)-70,514,140,60}};
Imagem botaoGaleria2 = {"botaogaleria2.png",NULL};
Imagem botaoCreditos = {"botaocreditos.png",NULL,{(WIDTH/2)-70,594,140,60}};
Imagem botaoCreditos2 = {"botaocreditos2.png",NULL};
Imagem botaoDesafio5x5 = {"botaodesafio5x5.png",NULL};
Imagem botaoDesafio10x10 = {"botaodesafio10x10.png",NULL};
Imagem botaoDesafio15x15 = {"desafio15x15.png",NULL};
Imagem logo = {"logo.png",NULL,{(WIDTH/2)-300,25,600,300}};
Imagem botaoVisualizar = {"botaovisualizar.png",NULL};
Imagem botaoVisualizar2 = {"botaovisualizar2.png",NULL};
Imagem interrogacao = {"interrogacao.png",NULL};
Imagem creditos = {"creditos.jpg",NULL};
Imagem tutorial = {"tutorial.jpg",NULL};
Imagem coracao = {"coracao.png",NULL};
Imagem foto1 = {"gato.png",NULL,{50,200,100,100}};
Imagem foto2 = {"dino.png",NULL,{250,200,100,100}};
Imagem foto3 = {"smile.png",NULL,{450,200,100,100}};
Imagem foto4 = {"mario.png",NULL,{650,200,100,100}};
Imagem foto5 = {"coelho.png",NULL,{850,200,100,100}};
Imagem foto6 = {"boo.png",NULL,{50,400,100,100}};
Imagem foto7 = {"ovo.png",NULL,{250,400,100,100}};
Imagem foto8 = {"panda.png",NULL,{450,400,100,100}};
Imagem foto9 = {"snail.png",NULL,{650,400,100,100}};
Imagem foto10 = {"gameboy.png",NULL,{850,400,100,100}};
Imagem foto11 = {"estrela.png",NULL,{50,600,100,100}};
Imagem foto12 = {"gomba.png",NULL,{250,600,100,100}};
Imagem tabelaGato = {"tabelacat.png",NULL};
Imagem tabelaDino = {"tabeladino.png",NULL};
Imagem tabelaSmile = {"tabelasmile.png",NULL};
Imagem tabelaMario = {"tabelamario.png",NULL};
Imagem tabelaCoelho = {"tabelacoelho.png",NULL};
Imagem tabelaBoo = {"tabelaboo.png",NULL};
Imagem tabelaOvo = {"tabelaovo.png",NULL};
Imagem tabelaPanda = {"tabelapanda.png",NULL};
Imagem tabelaSnail = {"tabelasnail.png",NULL};
Imagem tabelaGameBoy = {"tabelagameboy.png",NULL};
Imagem tabelaEstrela = {"tabelaestrela.png",NULL};
Imagem tabelaGomba = {"tabelagomba.png",NULL};


Mix_Music *bgm = NULL;          // guarda a musica
Mix_Music *vitoria = NULL;      // guarda o som de vitoria
//Mix_Chunk *efeito = NULL;

SDL_Surface *texto = NULL;
SDL_Texture *texturaTabela = NULL;
SDL_Texture *texturaFoto = NULL;
SDL_Texture *texturaTexto = NULL;
SDL_Texture *texturaTexto2 = NULL;
SDL_Texture *texturaTexto3 = NULL;

SDL_Renderer *tela = NULL;      //variavel para criaçao de um render
SDL_Window *janela = NULL;      // variavel para criaçao de uma janela

SDL_Point posicaoMouse;         // variavel que recebe as coordendas x e y o evento.motion

SDL_Event evento;               // variavel para capturar eventos

TTF_Font *fonte;                // guarda a fonte para os textos


int matrizSmile [5][5] = {      // ma triz usada para guarda os desenhos
    {0,1,0,1,0},
    {0,1,0,1,0},
    {0,0,0,0,0},
    {1,0,0,0,1},
    {0,1,1,1,0}
};

int matrizCat [5][5] = {
    {0,0,1,0,1},
    {0,0,1,1,1},
    {1,1,1,1,1},
    {1,1,1,1,0},
    {1,1,1,1,1}
};

int matrizDino [5][5] = {
    {1,1,0,0,0},
    {1,1,1,0,0},
    {0,1,1,1,0},
    {0,1,1,1,1},
    {0,1,0,1,0}
};

int matrizCoelho[10][10] = {        // usada para guardar os deenhos de 10x10
    {1,1,0,0,1,1,0,0,1,1},
    {1,1,0,0,1,1,0,0,1,1},
    {1,1,0,0,1,1,0,0,1,1},
    {1,1,0,0,1,1,0,0,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,1,0,0},
    {0,0,0,0,1,1,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,1}
};

int matrizBoo[10][10] = {
    {1,1,0,0,0,0,0,1,1,1},
    {1,0,0,0,0,0,0,0,1,1},
    {0,0,0,0,0,0,0,0,0,1},
    {0,1,0,1,0,0,0,0,0,1},
    {0,1,0,1,0,0,1,1,0,1},
    {0,0,0,0,0,0,0,1,0,0},
    {0,1,1,1,0,0,1,1,0,0},
    {0,0,1,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,0,0,0,0,1,1,1}
};

int matrizMario[10][10] = {
    {0,0,1,1,1,1,1,1,1,0},
    {0,0,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {0,0,1,0,1,0,0,1,1,1},
    {1,1,1,0,1,0,0,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,0,0,0,0,0,1},
    {0,1,1,1,1,0,0,0,1,1},
    {0,0,1,0,0,0,0,1,1,0},
    {0,0,0,1,1,1,1,1,0,0}
};

int matrizOvo[10][10] = {
    {1,1,1,1,0,0,1,1,1,1},
    {1,1,1,0,0,0,0,1,1,1},
    {1,1,0,0,0,1,1,0,1,1},
    {1,1,0,1,0,1,1,0,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,0,0,1,1,0,1},
    {1,0,1,1,0,1,1,1,0,1},
    {1,1,0,0,0,1,1,0,1,1},
    {1,1,1,0,0,0,0,1,1,1}
};

int matrizPanda[10][10] = {
    {1,1,1,0,0,0,0,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {0,1,0,0,0,0,0,0,1,0},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,0,0,1,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,1,1,0,0,1,1,0,1},
    {1,1,0,0,1,1,0,0,1,1},
    {0,1,1,0,0,0,0,1,1,0},
    {0,0,1,1,1,1,1,1,0,0}
};
int matrizSnail[10][10] = {
    {1,0,1,0,0,1,1,1,1,0},
    {1,0,1,0,1,1,1,1,1,1},
    {1,1,1,0,1,1,0,0,1,1},
    {1,0,0,1,1,0,1,1,0,1},
    {1,0,0,1,1,0,0,1,0,1},
    {0,1,0,1,1,1,1,1,0,1},
    {0,1,0,0,1,0,0,0,1,1},
    {0,1,0,0,0,1,1,1,1,1},
    {0,0,1,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1}
};

int matrizGameboy [15][15] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,1,1,1,1,1,1,1,1,1,0,1,1},
    {1,1,0,1,1,0,0,0,0,0,1,1,0,1,1},
    {1,1,0,1,1,0,0,0,0,0,1,1,0,1,1},
    {1,1,0,1,1,0,0,0,0,0,1,1,0,1,1},
    {1,1,0,1,1,0,0,0,0,0,1,1,0,1,1},
    {1,1,0,1,1,1,1,1,1,1,1,1,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,1,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,1,1,1,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,1,0,0,0,0,1,1,1,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int matrizEstrela [15][15] = {
    {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,1,1,1,0,0,0,0,0,1,1,1,1,1},
    {1,1,1,1,1,0,0,0,0,0,1,1,1,1,1},
    {0,0,0,0,0,0,1,0,1,0,0,0,0,0,0},
    {1,0,0,0,0,0,1,0,1,0,0,0,0,0,1},
    {1,1,0,0,0,0,1,0,1,0,0,0,0,1,1},
    {1,1,1,0,0,0,0,0,0,0,0,0,1,1,1},
    {1,1,1,1,0,0,0,0,0,0,0,1,1,1,1},
    {1,1,1,0,0,0,0,0,0,0,0,0,1,1,1},
    {1,1,1,0,0,0,0,0,0,0,0,0,1,1,1},
    {1,1,0,0,0,0,0,1,0,0,0,0,0,1,1},
    {1,1,0,0,0,0,1,1,1,0,0,0,0,1,1},
    {1,0,0,0,1,1,1,1,1,1,1,0,0,0,1}
};

int matrizGomba [15][15] = {
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,0,0,1,1,1,1,1,1,1,0,0,1,0},
    {0,1,0,0,0,0,1,1,1,0,0,0,0,1,0},
    {1,1,0,0,0,1,1,1,1,1,0,0,0,1,1},
    {1,1,0,0,0,1,0,1,0,1,0,0,0,1,1},
    {1,1,1,0,0,0,1,1,1,0,0,0,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,1,0,0,0,0,0,0,0,1,0,0,0},
    {0,1,1,1,1,0,0,0,0,0,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,0,0,1,1,1,1,1,1}
};

int matrizBranca [15][15] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

int largura, altura;            // para o query dos textos

int matrizDesenho[15][15];              // matriz de desenho generica usada no codigo para nao alterar as originais

int tamanhoMatriz;                      // indica o tamanho da matriz e auxilia na verificacao e na funçao imprimir tela

int concluido[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};     // vetor usado para guardar quais desfios foram concluidos

int save;                                       // orienta dentro do vetor acima para habilitar cada posiçao

int tentativa;                                  // indica quantas tentativas o jogador ai tem

FILE *gravacao;                                 // ponteiro para utilizar gravaçao em txt

SDL_Rect offsetVoltar = {(WIDTH-100),0,100,50};        // botao voltar em cima

int loadSave();
int inicializacao();
int jogada(int matrizDesenho[tamanhoMatriz][tamanhoMatriz]);
int imprimeTela();
int telaCheia(SDL_Texture *desenho);
int mostraGaleria();
int verificaVitoria(int branca[15][15], int desenho[tamanhoMatriz][tamanhoMatriz]);
int loading(Imagem *temp);
void menuTutorial();
void menuCredito();
void zeraMatriz();
void copiaMatriz(int matrizOriginal[tamanhoMatriz][tamanhoMatriz], int matrizCopia[tamanhoMatriz][tamanhoMatriz]);
void encerraPrograma();

int main(int argc, char * args[])
{
    inicializacao();

    loadSave();

    int loop = 1;                           // variavel para manter atualizando a janela

    while(loop == 1)
    {

        posicaoMouse.x = evento.motion.x;       // atribui o valor do evento.motion
        posicaoMouse.y = evento.motion.y;

        while(SDL_PollEvent(&evento))
        {

            switch(evento.type)                 // faz um switch do tipo de evento, se é movimentaçao ou click
            {
                case SDL_QUIT:
                    loop = 0;
                    break;
                case SDL_MOUSEBUTTONDOWN:       // se foi clickdown e botaoesquerdo e se o click foi encimadorec correspondente
                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&botaoJogar.posicao,NULL))
                    {
menu:
                        while(menuJogo() == 1)          //fica aqui enquantoa funçao menujogo nao retorna 1
                        {
                            if(jogada(matrizDesenho) == 0)      // fica aqui enquanto a funçaojogada nao retorna 0
                            {
                                goto menu;
                            }


                        }
                    }

                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&botaoTutorial.posicao,NULL))
                    {
                        menuTutorial();
                    }
                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&botaoGaleria.posicao,NULL))
                    {
                        mostraGaleria();
                    }
                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&botaoCreditos.posicao,NULL))
                    {
                        menuCredito();
                    }
                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&botaoSair.posicao,NULL))
                    {
                        loop = 0;
                    }
                    break;

            }

        }

        SDL_RenderCopy(tela,backgroundMenu.textura,NULL,NULL);                         //aplica a textura em um determinadoretangulo
        SDL_RenderCopy(tela,logo.textura,NULL,&logo.posicao);
        SDL_RenderCopy(tela,botaoJogar.textura,NULL,&botaoJogar.posicao);
        SDL_RenderCopy(tela,botaoTutorial.textura,NULL,&botaoTutorial.posicao);
        SDL_RenderCopy(tela,botaoGaleria.textura,NULL,&botaoGaleria.posicao);
        SDL_RenderCopy(tela,botaoCreditos.textura,NULL,&botaoCreditos.posicao);
        SDL_RenderCopy(tela,botaoSair.textura,NULL,&botaoSair.posicao);


        if(SDL_EnclosePoints(&posicaoMouse,1,&botaoJogar.posicao,NULL))             // animaçao de quando os botoes sao selecionados
        {
            SDL_RenderCopy(tela,botaoJogar2.textura,NULL,&botaoJogar.posicao);
        }
        if(SDL_EnclosePoints(&posicaoMouse,1,&botaoTutorial.posicao,NULL))
        {
            SDL_RenderCopy(tela,botaoTutorial2.textura,NULL,&botaoTutorial.posicao);
        }
        if(SDL_EnclosePoints(&posicaoMouse,1,&botaoGaleria.posicao,NULL))
        {
            SDL_RenderCopy(tela,botaoGaleria2.textura,NULL,&botaoGaleria.posicao);
        }
        if(SDL_EnclosePoints(&posicaoMouse,1,&botaoCreditos.posicao,NULL))
        {
            SDL_RenderCopy(tela,botaoCreditos2.textura,NULL,&botaoCreditos.posicao);
        }
        if(SDL_EnclosePoints(&posicaoMouse,1,&botaoSair.posicao,NULL))
        {
            SDL_RenderCopy(tela,botaoSair2.textura,NULL,&botaoSair.posicao);
        }

        SDL_RenderPresent(tela);        // atualiza a tela render
        SDL_Delay(10);              // delay para ajustar +- 60 quadros

    }

    encerraPrograma();
    return 0;

}

void copiaMatriz(int matrizCopia[tamanhoMatriz][tamanhoMatriz],int matrizOriginal[tamanhoMatriz][tamanhoMatriz])
{
    int linha, coluna;

    for(linha=0;linha<tamanhoMatriz;linha++)
    {
        for(coluna=0;coluna<tamanhoMatriz;coluna++)
        {
            matrizCopia[linha][coluna] = matrizOriginal[linha][coluna];
        }
    }

}

void zeraMatriz()
{
    int linha, coluna;

    for(linha=0;linha<15;linha++)
        for(coluna=0;coluna<15;coluna++)
    {
        matrizBranca[linha][coluna] = 0;
    }

}

int verificaVitoria(int branca[15][15], int desenho[tamanhoMatriz][tamanhoMatriz])
{
    int linha, coluna, contagem = 0;

    for(linha=0;linha<tamanhoMatriz;linha++)
        for(coluna=0;coluna<tamanhoMatriz;coluna++)
    {
        if(branca[coluna][linha] == desenho[linha][coluna])
        {
            contagem++;
        }


    }
    if(contagem == (tamanhoMatriz*tamanhoMatriz))
    {
        concluido[save] = 1;
        gravacao = fopen("./Save/save.txt","w");
        for(linha=0;linha<15;linha++)
        {
            fprintf(gravacao,"%d ", concluido[linha]);
        }


      //  Mix_PlayChannel(-1,efeito,0);
        Mix_PlayMusic(vitoria,1);
        telaCheia(texturaFoto);
        Mix_PlayMusic(bgm,-1);

       return 1;
    }


    return 0;
}

int menuJogo()
{

    zeraMatriz();

    SDL_Rect posicaoBotao1 = {100,200,100,50};
    SDL_Rect posicaoBotao2 = {100,300,100,50};
    SDL_Rect posicaoBotao3 = {100,400,100,50};
    SDL_Rect posicaoBotao4 = {100,500,100,50};
    SDL_Rect posicaoBotao5 = {100,600,100,50};
    SDL_Rect posicaoBotao6 = {450,200,100,50};
    SDL_Rect posicaoBotao7 = {450,300,100,50};
    SDL_Rect posicaoBotao8 = {450,400,100,50};
    SDL_Rect posicaoBotao9 = {450,500,100,50};
    SDL_Rect posicaoBotao10 = {450,600,100,50};
    SDL_Rect posicaoBotao11 = {800,200,100,50};
    SDL_Rect posicaoBotao12 = {800,300,100,50};
    SDL_Rect concluido1 = {220,190,100,50};
    SDL_Rect concluido2 = {220,290,100,50};
    SDL_Rect concluido3 = {220,390,100,50};
    SDL_Rect concluido4 = {220,490,100,50};
    SDL_Rect concluido5 = {220,590,100,50};
    SDL_Rect concluido6 = {570,190,100,50};
    SDL_Rect concluido7 = {570,290,100,50};
    SDL_Rect concluido8 = {570,390,100,50};
    SDL_Rect concluido9 = {570,490,100,50};
    SDL_Rect concluido10 = {570,590,100,50};
    SDL_Rect concluido11 = {920,190,100,50};
    SDL_Rect concluido12 = {920,290,100,50};

    SDL_QueryTexture(texturaTexto2,NULL,NULL,&largura,&altura);
    SDL_Rect textoRect = {323,20,largura*2,altura*3};

int loop = 1;

while(loop == 1)
{

    posicaoMouse.x = evento.motion.x;
    posicaoMouse.y = evento.motion.y;

    while(SDL_PollEvent(&evento))
    {

        switch(evento.type)
        {
            case SDL_QUIT:
                SDL_Quit();
                break;
           case SDL_MOUSEBUTTONDOWN:
                if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao1,NULL))
                {
                    tamanhoMatriz = 5;
                    save = 1;
                    tentativa = 7;
                    copiaMatriz(matrizDesenho,matrizCat);
                    texturaTabela = tabelaGato.textura;
                    texturaFoto = foto1.textura;
                    return 1;
                }
                if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao2,NULL))
                {
                    tamanhoMatriz = 5;
                    save = 2;
                    tentativa = 7;
                    copiaMatriz(matrizDesenho,matrizDino);
                    texturaTabela =tabelaDino.textura;
                    texturaFoto = foto2.textura;
                    return 1;
                }
                if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao3,NULL))
                {
                    tamanhoMatriz = 5;
                    save = 3;
                    tentativa = 7;
                    copiaMatriz(matrizDesenho,matrizSmile);
                    texturaTabela = tabelaSmile.textura;
                    texturaFoto = foto3.textura;
                    return 1;
                }
                if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao4,NULL))
                {
                    tamanhoMatriz = 10;
                    save = 4;
                    tentativa = 14;
                    copiaMatriz(matrizDesenho,matrizMario);
                    texturaTabela = tabelaMario.textura;
                    texturaFoto = foto4.textura;

                    return 1;
                }
                if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao5,NULL))
                {
                    tamanhoMatriz = 10;
                    save = 5;
                    tentativa = 14;
                    copiaMatriz(matrizDesenho,matrizCoelho);
                    texturaTabela = tabelaCoelho.textura;
                    texturaFoto = foto5.textura;
                    return 1;
                }
                if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao6,NULL))
                {
                    tamanhoMatriz = 10;
                    save = 6;
                    tentativa = 14;
                    copiaMatriz(matrizDesenho,matrizBoo);
                    texturaTabela = tabelaBoo.textura;
                    texturaFoto = foto6.textura;
                    return 1;
                }
                if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao7,NULL))
                {
                    tamanhoMatriz = 10;
                    save = 7;
                    tentativa = 14;
                    copiaMatriz(matrizDesenho,matrizOvo);
                    texturaTabela = tabelaOvo.textura;
                    texturaFoto = foto7.textura;
                    return 1;
                }
                if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao8,NULL))
                {
                    tamanhoMatriz = 10;
                    save = 8;
                    tentativa = 14;
                    copiaMatriz(matrizDesenho,matrizPanda);
                    texturaTabela = tabelaPanda.textura;
                    texturaFoto = foto8.textura;
                    return 1;
                }
                if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao9,NULL))
                {
                    tamanhoMatriz = 10;
                    save = 9;
                    tentativa = 14;
                    copiaMatriz(matrizDesenho,matrizSnail);
                    texturaTabela = tabelaSnail.textura;
                    texturaFoto = foto9.textura;
                    return 1;
                }
                if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao10,NULL))
                {
                    tamanhoMatriz = 15;
                    save = 10;
                    tentativa = 14;
                    copiaMatriz(matrizDesenho,matrizGameboy);
                    texturaTabela = tabelaGameBoy.textura;
                    texturaFoto = foto10.textura;
                    return 1;
                }
                if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao11,NULL))
                {
                    tamanhoMatriz = 15;
                    save = 11;
                    tentativa = 14;
                    copiaMatriz(matrizDesenho,matrizEstrela);
                    texturaTabela = tabelaEstrela.textura;
                    texturaFoto = foto11.textura;
                    return 1;
                }
                if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao12,NULL))
                {
                    tamanhoMatriz = 15;
                    save = 12;
                    tentativa = 14;
                    copiaMatriz(matrizDesenho,matrizGomba);
                    texturaTabela = tabelaGomba.textura;
                    texturaFoto = foto12.textura;
                    return 1;
                }
                 if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&botaoVoltar.posicao,NULL))
                 {
                     loop = 0;
                 }
                break;
        }

    }


        SDL_RenderCopy(tela,backgroundMenu.textura,NULL,NULL);
        SDL_RenderCopy(tela,botaoDesafio5x5.textura,NULL,&posicaoBotao1);
        SDL_RenderCopy(tela,botaoDesafio5x5.textura,NULL,&posicaoBotao2);
        SDL_RenderCopy(tela,botaoDesafio5x5.textura,NULL,&posicaoBotao3);
        SDL_RenderCopy(tela,botaoDesafio10x10.textura,NULL,&posicaoBotao4);
        SDL_RenderCopy(tela,botaoDesafio10x10.textura,NULL,&posicaoBotao5);
        SDL_RenderCopy(tela,botaoDesafio10x10.textura,NULL,&posicaoBotao6);
        SDL_RenderCopy(tela,botaoDesafio10x10.textura,NULL,&posicaoBotao7);
        SDL_RenderCopy(tela,botaoDesafio10x10.textura,NULL,&posicaoBotao8);
        SDL_RenderCopy(tela,botaoDesafio10x10.textura,NULL,&posicaoBotao9);
        SDL_RenderCopy(tela,botaoDesafio15x15.textura,NULL,&posicaoBotao10);
        SDL_RenderCopy(tela,botaoDesafio15x15.textura,NULL,&posicaoBotao11);
        SDL_RenderCopy(tela,botaoDesafio15x15.textura,NULL,&posicaoBotao12);
        SDL_RenderCopy(tela,botaoVoltar.textura,NULL,&botaoVoltar.posicao);

        if(concluido[1] == 1) SDL_RenderCopy(tela,completa.textura,NULL,&concluido1);
        if(concluido[2] == 1) SDL_RenderCopy(tela,completa.textura,NULL,&concluido2);
        if(concluido[3] == 1) SDL_RenderCopy(tela,completa.textura,NULL,&concluido3);
        if(concluido[4] == 1) SDL_RenderCopy(tela,completa.textura,NULL,&concluido4);
        if(concluido[5] == 1) SDL_RenderCopy(tela,completa.textura,NULL,&concluido5);
        if(concluido[6] == 1) SDL_RenderCopy(tela,completa.textura,NULL,&concluido6);
        if(concluido[7] == 1) SDL_RenderCopy(tela,completa.textura,NULL,&concluido7);
        if(concluido[8] == 1) SDL_RenderCopy(tela,completa.textura,NULL,&concluido8);
        if(concluido[9] == 1) SDL_RenderCopy(tela,completa.textura,NULL,&concluido9);
        if(concluido[10] == 1) SDL_RenderCopy(tela,completa.textura,NULL,&concluido10);
        if(concluido[11] == 1) SDL_RenderCopy(tela,completa.textura,NULL,&concluido11);
        if(concluido[12] == 1) SDL_RenderCopy(tela,completa.textura,NULL,&concluido12);


        if(SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao1,NULL)) SDL_RenderCopy(tela,botaoJogar2.textura,NULL,&posicaoBotao1);
        if(SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao2,NULL)) SDL_RenderCopy(tela,botaoJogar2.textura,NULL,&posicaoBotao2);
        if(SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao3,NULL)) SDL_RenderCopy(tela,botaoJogar2.textura,NULL,&posicaoBotao3);
        if(SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao4,NULL)) SDL_RenderCopy(tela,botaoJogar2.textura,NULL,&posicaoBotao4);
        if(SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao5,NULL)) SDL_RenderCopy(tela,botaoJogar2.textura,NULL,&posicaoBotao5);
        if(SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao6,NULL)) SDL_RenderCopy(tela,botaoJogar2.textura,NULL,&posicaoBotao6);
        if(SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao7,NULL)) SDL_RenderCopy(tela,botaoJogar2.textura,NULL,&posicaoBotao7);
        if(SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao8,NULL)) SDL_RenderCopy(tela,botaoJogar2.textura,NULL,&posicaoBotao8);
        if(SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao9,NULL)) SDL_RenderCopy(tela,botaoJogar2.textura,NULL,&posicaoBotao9);
        if(SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao10,NULL)) SDL_RenderCopy(tela,botaoJogar2.textura,NULL,&posicaoBotao10);
        if(SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao11,NULL)) SDL_RenderCopy(tela,botaoJogar2.textura,NULL,&posicaoBotao11);
        if(SDL_EnclosePoints(&posicaoMouse,1,&posicaoBotao12,NULL)) SDL_RenderCopy(tela,botaoJogar2.textura,NULL,&posicaoBotao12);
        if(SDL_EnclosePoints(&posicaoMouse,1,&botaoVoltar.posicao,NULL)) SDL_RenderCopy(tela,botaoVoltar2.textura,NULL,&botaoVoltar.posicao);

        SDL_RenderCopy(tela,texturaTexto2,NULL,&textoRect);




        SDL_RenderPresent(tela);
        SDL_Delay(10);

}
    SDL_RenderClear(tela);
    return 0;
}

int jogada(int matrizDesenho[tamanhoMatriz][tamanhoMatriz])
{

int linha, coluna;

int loop = 1;

while((verificaVitoria(matrizBranca,matrizDesenho) != 1 ) && loop == 1)
{

        posicaoMouse.x = evento.motion.x;
        posicaoMouse.y = evento.motion.y;
        int x = 219, y = 219;

        while(SDL_PollEvent(&evento))
        {

            switch(evento.type)
            {
                case SDL_QUIT:
                    SDL_Quit();
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&botaoVoltar.posicao,NULL))
                    {
                        loop = 0;
                    }

                    for(linha=0;linha<tamanhoMatriz;linha++)
                    {
                        for(coluna=0;coluna<tamanhoMatriz;coluna++)
                        {
                            SDL_Rect posicaoMatriz = {x,y,33,33};
                            if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&posicaoMatriz,NULL))
                            {
                                if(matrizBranca[linha][coluna] == 0)
                                {
                                    matrizBranca[linha][coluna] = 1;
                                  if(matrizBranca[linha][coluna] != matrizDesenho[coluna][linha]) tentativa--;
                                }
                                else
                                {
                                    matrizBranca[linha][coluna] = 0;
                                }
                            }
                            y += 36;
                        }
                        y = 219;
                        x += 36;
                    }
                    break;

            }

        }
                    imprimeTela();
                    SDL_RenderPresent(tela);
                    SDL_Delay(10);

                    if (tentativa == 0) return 1;

    }

    return 0;
}

int imprimeTela()
{
    int x = 269, y = 269;
    int linha, coluna;


    SDL_QueryTexture(texturaTexto,NULL,NULL,&largura,&altura);
    SDL_Rect posicaoTentativa = {0,-10,largura,altura*2};
    SDL_Rect posicao5x5 = {100,100,300,300};
    SDL_Rect posicao10x10 = {100,100,480,480};
    SDL_Rect posicao15x15 = {100,100,660,660};

    SDL_RenderCopy(tela,backgroundPlay.textura,NULL,NULL);
    SDL_RenderCopy(tela,botaoVoltar.textura,NULL,&botaoVoltar.posicao);
    SDL_RenderCopy(tela,texturaTexto,NULL,&posicaoTentativa);

    if(SDL_EnclosePoints(&posicaoMouse,1,&botaoVoltar.posicao,NULL)) SDL_RenderCopy(tela,botaoVoltar2.textura,NULL,&botaoVoltar.posicao);
    if(tamanhoMatriz == 5) SDL_RenderCopy(tela,texturaTabela,NULL,&posicao5x5);
    if(tamanhoMatriz == 10) SDL_RenderCopy(tela,texturaTabela,NULL,&posicao10x10);
    if(tamanhoMatriz == 15) SDL_RenderCopy(tela,texturaTabela,NULL,&posicao15x15);


    x = 160;
    for(linha=0;linha<tentativa;linha++)
    {
        SDL_Rect posicaoCoracao = {x,5,50,50};
        SDL_RenderCopy(tela,coracao.textura,NULL,&posicaoCoracao);
        x += 60;
    }

    x = 219;
    y = 219;

    for(linha=0;linha<tamanhoMatriz;linha++)
    {

         for(coluna=0;coluna<tamanhoMatriz;coluna++)
         {
            SDL_Rect posicaoMatriz = {x,y,33,33};
            if(matrizBranca[linha][coluna] == 0)
            {
                SDL_RenderCopy(tela,vazio.textura,NULL,&posicaoMatriz);
            }
            if(matrizBranca[linha][coluna] == 1)
            {
                SDL_RenderCopy(tela,preenchido.textura,NULL,&posicaoMatriz);
            }
            y += 36;
         }
         y = 219;
         x += 36;
    }



   return 0;

}


int telaCheia(SDL_Texture *desenho)
{
    SDL_Rect offsetImagemGrande = {(WIDTH/2)-250,(HEIGHT/2)-250,500,500};


    SDL_RenderClear(tela);

SDL_Event evento;
    int loop = 1;

    while(loop == 1)
    {

        posicaoMouse.x = evento.motion.x;
        posicaoMouse.y = evento.motion.y;

        SDL_RenderCopy(tela,backgroundMenu.textura,NULL,NULL);
        SDL_RenderCopy(tela,desenho,NULL,&offsetImagemGrande);
        SDL_RenderCopy(tela,botaoVoltar.textura,NULL,&offsetVoltar);

        while(SDL_PollEvent(&evento))
        {
            switch(evento.type)
            {
                case SDL_QUIT:
                    SDL_Quit();
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&offsetVoltar,NULL)) loop = 0;
                    break;
            }
        }

        if(SDL_EnclosePoints(&posicaoMouse,1,&offsetVoltar,NULL))
        {
            SDL_RenderCopy(tela,botaoVoltar2.textura,NULL,&offsetVoltar);
        }

        SDL_RenderPresent(tela);
        SDL_Delay(10);
    }


    SDL_RenderClear(tela);
    return 0;
}

int mostraGaleria()
{
SDL_Rect offsetBotao = {65,310,70,30};
SDL_Rect offsetBotao2 = {265,310,70,30};
SDL_Rect offsetBotao3 = {465,310,70,30};
SDL_Rect offsetBotao4 = {665,310,70,30};
SDL_Rect offsetBotao5 = {865,310,70,30};
SDL_Rect offsetBotao6 = {65,510,70,30};
SDL_Rect offsetBotao7 = {265,510,70,30};
SDL_Rect offsetBotao8 = {465,510,70,30};
SDL_Rect offsetBotao9 = {665,510,70,30};
SDL_Rect offsetBotao10 = {865,510,70,30};
SDL_Rect offsetBotao11 = {65,710,70,30};
SDL_Rect offsetBotao12 = {265,710,70,30};

SDL_QueryTexture(texturaTexto3,NULL,NULL,&largura,&altura);
SDL_Rect textogaleria = {421,20,largura*3,altura*3};

    int loop = 1;

    while(loop == 1)
    {
        posicaoMouse.x = evento.motion.x;
        posicaoMouse.y = evento.motion.y;

        while(SDL_PollEvent(&evento))
        {

            switch(evento.type)
            {
                case SDL_QUIT:
                    loop = 0;
                    break;


                case SDL_MOUSEBUTTONDOWN:

                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao,NULL) && concluido[1] == 1)
                    {
                            telaCheia(foto1.textura);
                    }

                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao2,NULL) && concluido[2] == 1)
                    {
                            telaCheia(foto2.textura);
                    }

                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao3,NULL) && concluido[3] == 1)
                    {
                            telaCheia(foto3.textura);
                    }

                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao4,NULL) && concluido[4] == 1)
                    {
                            telaCheia(foto4.textura);
                    }

                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao5,NULL) && concluido[5] == 1)
                    {
                            telaCheia(foto5.textura);
                    }

                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao6,NULL) && concluido[6] == 1)
                    {
                            telaCheia(foto6.textura);
                    }

                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao7,NULL) && concluido[7] == 1)
                    {
                            telaCheia(foto7.textura);
                    }

                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao8,NULL) && concluido[8] == 1)
                    {
                            telaCheia(foto8.textura);
                    }

                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao9,NULL) && concluido[9] == 1)
                    {
                            telaCheia(foto9.textura);
                    }
                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao10,NULL) && concluido[10] == 1)
                    {
                            telaCheia(foto10.textura);
                    }
                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao11,NULL) && concluido[11] == 1)
                    {
                            telaCheia(foto11.textura);
                    }
                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao12,NULL) && concluido[12] == 1)
                    {
                            telaCheia(foto12.textura);
                    }
                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&botaoVoltar.posicao,NULL))
                    {
                            loop = 0;
                    }
                    break;
            }
        }



        SDL_RenderCopy(tela,backgroundMenu.textura,NULL,NULL);
        SDL_RenderCopy(tela,botaoVisualizar.textura,NULL,&offsetBotao);
        SDL_RenderCopy(tela,botaoVisualizar.textura,NULL,&offsetBotao2);
        SDL_RenderCopy(tela,botaoVisualizar.textura,NULL,&offsetBotao3);
        SDL_RenderCopy(tela,botaoVisualizar.textura,NULL,&offsetBotao4);
        SDL_RenderCopy(tela,botaoVisualizar.textura,NULL,&offsetBotao5);
        SDL_RenderCopy(tela,botaoVisualizar.textura,NULL,&offsetBotao6);
        SDL_RenderCopy(tela,botaoVisualizar.textura,NULL,&offsetBotao7);
        SDL_RenderCopy(tela,botaoVisualizar.textura,NULL,&offsetBotao8);
        SDL_RenderCopy(tela,botaoVisualizar.textura,NULL,&offsetBotao9);
        SDL_RenderCopy(tela,botaoVisualizar.textura,NULL,&offsetBotao10);
        SDL_RenderCopy(tela,botaoVisualizar.textura,NULL,&offsetBotao11);
        SDL_RenderCopy(tela,botaoVisualizar.textura,NULL,&offsetBotao12);
        SDL_RenderCopy(tela,botaoVoltar.textura,NULL,&botaoVoltar.posicao);
        SDL_RenderCopy(tela,texturaTexto3,NULL,&textogaleria);


        if(concluido[1] == 1)
        {
            SDL_RenderCopy(tela,foto1.textura,NULL,&foto1.posicao);
        }
        else
        {
            SDL_RenderCopy(tela,interrogacao.textura,NULL,&foto1.posicao);
        }

        if(concluido[2] == 1)
        {
            SDL_RenderCopy(tela,foto2.textura,NULL,&foto2.posicao);
        }
        else
        {
            SDL_RenderCopy(tela,interrogacao.textura,NULL,&foto2.posicao);
        }

        if(concluido[3] == 1)
        {
            SDL_RenderCopy(tela,foto3.textura,NULL,&foto3.posicao);
        }
        else
        {
            SDL_RenderCopy(tela,interrogacao.textura,NULL,&foto3.posicao);
        }

        if(concluido[4] == 1)
        {
            SDL_RenderCopy(tela,foto4.textura,NULL,&foto4.posicao);
        }
        else
        {
            SDL_RenderCopy(tela,interrogacao.textura,NULL,&foto4.posicao);
        }

        if(concluido[5] == 1)
        {
            SDL_RenderCopy(tela,foto5.textura,NULL,&foto5.posicao);
        }
        else
        {
            SDL_RenderCopy(tela,interrogacao.textura,NULL,&foto5.posicao);
        }

        if(concluido[6] == 1)
        {
            SDL_RenderCopy(tela,foto6.textura,NULL,&foto6.posicao);
        }
        else
        {
            SDL_RenderCopy(tela,interrogacao.textura,NULL,&foto6.posicao);
        }

         if(concluido[7] == 1)
        {
            SDL_RenderCopy(tela,foto7.textura,NULL,&foto7.posicao);
        }
        else
        {
            SDL_RenderCopy(tela,interrogacao.textura,NULL,&foto7.posicao);
        }

        if(concluido[8] == 1)
        {
            SDL_RenderCopy(tela,foto8.textura,NULL,&foto8.posicao);
        }
        else
        {
            SDL_RenderCopy(tela,interrogacao.textura,NULL,&foto8.posicao);
        }

        if(concluido[9] == 1)
        {
            SDL_RenderCopy(tela,foto9.textura,NULL,&foto9.posicao);
        }
        else
        {
            SDL_RenderCopy(tela,interrogacao.textura,NULL,&foto9.posicao);
        }
        if(concluido[10] == 1)
        {
            SDL_RenderCopy(tela,foto10.textura,NULL,&foto10.posicao);
        }
        else
        {
            SDL_RenderCopy(tela,interrogacao.textura,NULL,&foto10.posicao);
        }
        if(concluido[11] == 1)
        {
            SDL_RenderCopy(tela,foto11.textura,NULL,&foto11.posicao);
        }
        else
        {
            SDL_RenderCopy(tela,interrogacao.textura,NULL,&foto11.posicao);
        }
        if(concluido[12] == 1)
        {
            SDL_RenderCopy(tela,foto12.textura,NULL,&foto12.posicao);
        }
        else
        {
            SDL_RenderCopy(tela,interrogacao.textura,NULL,&foto12.posicao);
        }

        if(SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao,NULL))  SDL_RenderCopy(tela,botaoVisualizar2.textura,NULL,&offsetBotao);
        if(SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao2,NULL)) SDL_RenderCopy(tela,botaoVisualizar2.textura,NULL,&offsetBotao2);
        if(SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao3,NULL)) SDL_RenderCopy(tela,botaoVisualizar2.textura,NULL,&offsetBotao3);
        if(SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao4,NULL)) SDL_RenderCopy(tela,botaoVisualizar2.textura,NULL,&offsetBotao4);
        if(SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao5,NULL)) SDL_RenderCopy(tela,botaoVisualizar2.textura,NULL,&offsetBotao5);
        if(SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao6,NULL)) SDL_RenderCopy(tela,botaoVisualizar2.textura,NULL,&offsetBotao6);
        if(SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao7,NULL)) SDL_RenderCopy(tela,botaoVisualizar2.textura,NULL,&offsetBotao7);
        if(SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao8,NULL)) SDL_RenderCopy(tela,botaoVisualizar2.textura,NULL,&offsetBotao8);
        if(SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao9,NULL)) SDL_RenderCopy(tela,botaoVisualizar2.textura,NULL,&offsetBotao9);
        if(SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao10,NULL)) SDL_RenderCopy(tela,botaoVisualizar2.textura,NULL,&offsetBotao10);
        if(SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao11,NULL)) SDL_RenderCopy(tela,botaoVisualizar2.textura,NULL,&offsetBotao11);
        if(SDL_EnclosePoints(&posicaoMouse,1,&offsetBotao12,NULL)) SDL_RenderCopy(tela,botaoVisualizar2.textura,NULL,&offsetBotao12);
        if(SDL_EnclosePoints(&posicaoMouse,1,&botaoVoltar.posicao,NULL)) SDL_RenderCopy(tela,botaoVoltar2.textura,NULL,&botaoVoltar.posicao);

        SDL_RenderPresent(tela);
        SDL_Delay(10);
    }

    return 0;
}

void menuCredito()
{
    SDL_RenderClear(tela);


    int loop = 1;

    while(loop == 1)
    {

        posicaoMouse.x = evento.motion.x;
        posicaoMouse.y = evento.motion.y;

        while(SDL_PollEvent(&evento))
        {
            switch(evento.type)
            {
                case SDL_QUIT:
                    SDL_Quit();
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&botaoVoltar.posicao,NULL)) loop = 0;
                    break;
            }
        }

        SDL_RenderCopy(tela,creditos.textura,NULL,NULL);
        SDL_RenderCopy(tela,botaoVoltar.textura,NULL,&botaoVoltar.posicao);

        if(SDL_EnclosePoints(&posicaoMouse,1,&botaoVoltar.posicao,NULL))
        {
            SDL_RenderCopy(tela,botaoVoltar2.textura,NULL,&botaoVoltar.posicao);
        }

        SDL_RenderPresent(tela);
        SDL_Delay(10);
    }


    SDL_RenderClear(tela);
}

void menuTutorial()
{
    SDL_RenderClear(tela);

    int loop = 1;

    while(loop == 1)
    {

        posicaoMouse.x = evento.motion.x;
        posicaoMouse.y = evento.motion.y;

        while(SDL_PollEvent(&evento))
        {
            switch(evento.type)
            {
                case SDL_QUIT:
                    SDL_Quit();
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(evento.button.button == SDL_BUTTON_LEFT && SDL_EnclosePoints(&posicaoMouse,1,&botaoVoltar.posicao,NULL)) loop = 0;
                    break;
            }
        }

        SDL_RenderCopy(tela,tutorial.textura,NULL,NULL);
        SDL_RenderCopy(tela,botaoVoltar.textura,NULL,&botaoVoltar.posicao);

        if(SDL_EnclosePoints(&posicaoMouse,1,&botaoVoltar.posicao,NULL))
        {
            SDL_RenderCopy(tela,botaoVoltar2.textura,NULL,&botaoVoltar.posicao);
        }

        SDL_RenderPresent(tela);
        SDL_Delay(10);
    }


    SDL_RenderClear(tela);
}

int loading(Imagem *temp)
{
    char pastaImagem[255] = "./Imagens/";
    strcat(pastaImagem,temp->nomeImagem);
    SDL_Surface *imagemTemporaria = IMG_Load(pastaImagem);
    temp->textura = SDL_CreateTextureFromSurface(tela,imagemTemporaria);
    SDL_FreeSurface(imagemTemporaria);
}

int inicializacao()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);      // inicializa video, audio, imagens e texto
    SDL_Init(IMG_INIT_JPG);
    SDL_Init(IMG_INIT_PNG);
    TTF_Init();

    janela = SDL_CreateWindow("SDL PICROSS",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_FULLSCREEN);
    tela = SDL_CreateRenderer(janela,-1,SDL_RENDERER_ACCELERATED);

    fonte = TTF_OpenFont("./Fonte/fonte.ttf",36);
    bgm = Mix_LoadMUS("./Musicas/bgm.mp3");
    vitoria = Mix_LoadMUS("./Musicas/vitoria.mp3");
    //efeito = Mix_LoadWAV("./Musicas/vitoria.wav");




    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);     // configura o audio freq 22050
    Mix_VolumeMusic(MIX_MAX_VOLUME/4);
    Mix_PlayMusic(bgm,-1);                  // toca a musica em loop infinito -1

    SDL_Color cor;
    cor.r = 255;
    cor.g = 0;
    cor.b = 0;

    texto = TTF_RenderText_Solid(fonte,"TENTATIVAS:",cor);
    texturaTexto = SDL_CreateTextureFromSurface(tela,texto);
    SDL_FreeSurface(texto);

    texto = TTF_RenderText_Solid(fonte,"Escolha o Desafio",cor);
    texturaTexto2 = SDL_CreateTextureFromSurface(tela,texto);
    SDL_FreeSurface(texto);

    texto = TTF_RenderText_Solid(fonte,"Galeria",cor);
    texturaTexto3 = SDL_CreateTextureFromSurface(tela,texto);
    SDL_FreeSurface(texto);


    loading(&backgroundMenu);
    loading(&logo);
    loading(&botaoJogar);
    loading(&botaoJogar2);
    loading(&botaoTutorial);
    loading(&botaoTutorial2);
    loading(&botaoGaleria);
    loading(&botaoGaleria2);
    loading(&botaoCreditos);
    loading(&botaoCreditos2);
    loading(&botaoSair);
    loading(&botaoSair2);
    loading(&botaoVoltar);
    loading(&botaoVoltar2);
    loading(&creditos);
    loading(&tutorial);
    loading(&interrogacao);
    loading(&foto1);
    loading(&foto2);
    loading(&foto3);
    loading(&foto4);
    loading(&foto5);
    loading(&foto6);
    loading(&foto7);
    loading(&foto8);
    loading(&foto9);
    loading(&foto10);
    loading(&foto11);
    loading(&foto12);
    loading(&botaoVisualizar);
    loading(&botaoVisualizar2);
    loading(&botaoDesafio5x5);
    loading(&botaoDesafio10x10);
    loading(&botaoDesafio15x15);
    loading(&completa);
    loading(&backgroundPlay);
    loading(&vazio);
    loading(&preenchido);
    loading(&coracao);
    loading(&tabelaGato);
    loading(&tabelaDino);
    loading(&tabelaSmile);
    loading(&tabelaMario);
    loading(&tabelaCoelho);
    loading(&tabelaBoo);
    loading(&tabelaOvo);
    loading(&tabelaPanda);
    loading(&tabelaSnail);
    loading(&tabelaGameBoy);
    loading(&tabelaEstrela);
    loading(&tabelaGomba);


    return 0;

}

int loadSave()
{
    int i;                  // usado para leitura e criaçao do arquivo de save.txt

    gravacao = fopen("./Save/save.txt","r");       // abre oarquivo save.txt em modo texto

    if(gravacao != NULL)                    // se for diferente de nulo é pq o arquivo exixte ai apenas faz a leitura
    {
        for(i=0;i<15;i++)
        {
            fscanf(gravacao,"%d ", &concluido[i]);
        }
    }

    if(gravacao == NULL)                    // se retornar nulo é pq o arquivo nao existe entao abre um novosave.txt em modo de escrita
    {
        gravacao = fopen("./Save/save.txt","w");
        for(i=0;i<15;i++)
        {
            fprintf(gravacao,"%d ", concluido[i]);
        }
    }

    fclose(gravacao);           // fecha a gravaçao

}

void encerraPrograma()
{
    SDL_DestroyTexture(texturaTabela);
    SDL_DestroyTexture(texturaFoto);
    SDL_DestroyTexture(texturaTexto);
    SDL_DestroyTexture(texturaTexto2);
    SDL_DestroyTexture(texturaTexto3);
    SDL_DestroyTexture(backgroundMenu.textura);
    SDL_DestroyTexture(logo.textura);
    SDL_DestroyTexture(botaoJogar.textura);
    SDL_DestroyTexture(botaoJogar2.textura);
    SDL_DestroyTexture(botaoTutorial.textura);
    SDL_DestroyTexture(botaoTutorial2.textura);
    SDL_DestroyTexture(botaoGaleria.textura);
    SDL_DestroyTexture(botaoGaleria2.textura);
    SDL_DestroyTexture(botaoCreditos.textura);
    SDL_DestroyTexture(botaoCreditos.textura);
    SDL_DestroyTexture(botaoSair.textura);
    SDL_DestroyTexture(botaoSair2.textura);
    SDL_DestroyTexture(botaoVoltar.textura);
    SDL_DestroyTexture(botaoVoltar2.textura);
    SDL_DestroyTexture(creditos.textura);
    SDL_DestroyTexture(tutorial.textura);
    SDL_DestroyTexture(interrogacao.textura);
    SDL_DestroyTexture(foto1.textura);
    SDL_DestroyTexture(foto2.textura);
    SDL_DestroyTexture(foto3.textura);
    SDL_DestroyTexture(foto4.textura);
    SDL_DestroyTexture(foto5.textura);
    SDL_DestroyTexture(foto6.textura);
    SDL_DestroyTexture(foto7.textura);
    SDL_DestroyTexture(foto8.textura);
    SDL_DestroyTexture(foto9.textura);
    SDL_DestroyTexture(foto10.textura);
    SDL_DestroyTexture(foto11.textura);
    SDL_DestroyTexture(foto12.textura);
    SDL_DestroyTexture(botaoVisualizar.textura);
    SDL_DestroyTexture(botaoVisualizar2.textura);
    SDL_DestroyTexture(botaoDesafio5x5.textura);
    SDL_DestroyTexture(botaoDesafio10x10.textura);
    SDL_DestroyTexture(botaoDesafio15x15.textura);
    SDL_DestroyTexture(completa.textura);
    SDL_DestroyTexture(vazio.textura);
    SDL_DestroyTexture(preenchido.textura);
    SDL_DestroyTexture(coracao.textura);
    SDL_DestroyTexture(tabelaGato.textura);
    SDL_DestroyTexture(tabelaDino.textura);
    SDL_DestroyTexture(tabelaSmile.textura);
    SDL_DestroyTexture(tabelaMario.textura);
    SDL_DestroyTexture(tabelaCoelho.textura);
    SDL_DestroyTexture(tabelaBoo.textura);
    SDL_DestroyTexture(tabelaOvo.textura);
    SDL_DestroyTexture(tabelaSnail.textura);
    SDL_DestroyTexture(tabelaPanda.textura);
    SDL_DestroyTexture(tabelaGameBoy.textura);
    SDL_DestroyTexture(tabelaEstrela.textura);
    SDL_DestroyTexture(tabelaGomba.textura);
    SDL_DestroyRenderer(tela);          //destroy a rendere janela criada e fecha as demais funçoes
    SDL_DestroyWindow(janela);
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
    TTF_Quit();

}
