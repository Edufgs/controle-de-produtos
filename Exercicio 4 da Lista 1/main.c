#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>//BIBLIOTECA DO SLEEP(LOADING) OU O DE BAIXO
#include <windows.h>//BIBLIOTECA DO SLEEP(LOADING) PARA WINDOWS

FILE *antigo, *novo, *ajuda;
int i;
int main()
{
    setlocale(LC_ALL, "Portuguese");//IMPRIMIR OS ACENTOS
    antigo=fopen("Zinho.CAD","r");//ABRE O ARQUIVO ZINHO.CAD
    //VERIFICAR SE FOI ABERTO
    if(!antigo)
    {
        printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
        printf("\n||||          O arquivo 'Zinho.CAD' nao foi aberto!!!!        ||||");
        printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        return;
    }
    Menu();//CHAMA A FUNÇÃO MENU
}
//IMPRIMIR ARQUIVO ZINHO.CAD
imprimir()
{
    char vet[72]={};
    fclose(antigo);//FECHANDO O ARQUIVO
        antigo=fopen("Zinho.CAD","r");//ABRE NOVANETE O ARQUIVO ZINHO.CAD
        //VERIFICAR SE FOI ABERTO
        if(!antigo)
        {
            printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
            printf("\n||||         O arquivo 'Zinho.CAD' nao foi aberto!!!!         ||||");
            printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            return;
        }

    printf("\n");
    while(!feof(antigo))
    {
        fgets(vet, 72, antigo);
        printf("%s", vet);
    }
    printf("\n");
    Sleep(1000);
    Menu();
}

Menu()//FUNÇÃO MENU
{
    printf("\n||||||||||||||||||||||||||||||MENU||||||||||||||||||||||||||||||");
    printf("\n||||              O que voce deseja fazer?                  ||||");
    printf("\n||||                                                        ||||");
    printf("\n||||    01-Imprimir cadastro de cliente?                    ||||");
    printf("\n||||    02-Criar um novo arquivo com pessoas de 50 anos?    ||||");
    printf("\n||||    03-Fechar programa?                                 ||||");
    printf("\n||||                                                        ||||");
    printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\nDigite a opção:");
    scanf("%d", &i);
    system("cls");

    switch(i)
    {
        case 1:
            imprimir();
            break;
        case 2:
            Criar();
            break;
        case 3:
            fechar();
            break;
        default:
            printf("\n||||||||||||||||||||||||||||ATENÇÃO|||||||||||||||||||||||||||||");
            printf("\n||||                                                        ||||");
            printf("\n||||         Erro na leitura, Digite novamente!!            ||||");
            printf("\n||||                                                        ||||");
            printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            Sleep(1000);
            Menu();
    }
}
fechar()
{
    printf("Fechando Programa");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    printf("\n||||||||||||||||||||||||||||ATENÇÃO|||||||||||||||||||||||||||||");
    printf("\n||||                                                        ||||");
    printf("\n||||                  Programa Fechado!!!                   ||||");
    printf("\n||||                                                        ||||");
    printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");

    fclose(novo);
    fclose(antigo);
    return;
}
//CRIAR E SEPARAR PARA O ZINHO.M50
Criar()
{
    //LOADING
    printf("C");
    Sleep(100);
    printf("R");
    Sleep(100);
    printf("I");
    Sleep(100);
    printf("A");
    Sleep(100);
    printf("N");
    Sleep(100);
    printf("D");
    Sleep(100);
    printf("O");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);

    char ed[75]={},vet[500];
    int ano,teste=1961;
    char aju[65]={};
    //CRIANDO UM NOVO ARQUIVO
    novo=fopen("Zinho.M50","wb");

    fclose(antigo);//FECHANDO O ARQUIVO
        antigo=fopen("Zinho.CAD","r");//ABRE NOVANETE O ARQUIVO ZINHO.CAD
        //VERIFICAR SE FOI ABERTO
        if(!antigo)
        {
            printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
            printf("\n||||          O arquivo 'Zinho.CAD' nao foi aberto!!!         ||||");
            printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            return;
        }

    //LER O ARQUIVO ZINHO.CAD
    while(!feof(antigo))
    {
        fgets(ed,74,antigo);
        fscanf(antigo,"%d",&ano);
        fscanf(antigo,"\n");
        //POSIÇÃO 65 ESTA O SEXO
        if(ano==teste && ed[65]=='M')
        {
            ajuda=fopen("Ajuda.CAD","w");//ABRINDO ARQUIVO DE AJUDA
            for(i=0;i<=64;i++)
            {
                fprintf(ajuda,"%c",ed[i]);
            }
            fclose(ajuda);//FECHANDO PARA ABRIR EM FORMA DE LER
            ajuda=fopen("Ajuda.CAD","r");
            fgets(aju,64,ajuda);
            fprintf(novo,"\n%s",aju);
            fclose(ajuda);
        }

    }
    printf("\n||||||||||||||||||||||||||||ATENÇÃO|||||||||||||||||||||||||||||");
    printf("\n||||                                                        ||||");
    printf("\n||||                   Criação comcluida                    ||||");
    printf("\n||||                                                        ||||");
    printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    Sleep(1000);
    Menu2();
}

Menu2()//MENU PARA DEPOIS QUE TIVER COMCLUIDO A SEPARAÇÃO
{
    printf("\n||||||||||||||||||||||||||||||MENU||||||||||||||||||||||||||||||");
    printf("\n||||              O que voce deseja fazer?                  ||||");
    printf("\n||||                                                        ||||");
    printf("\n||||    01-Imprimir o novo cadastro de pessoas com 50 anos? ||||");
    printf("\n||||    02-Imprimir cadastro de cliente?                    ||||");
    printf("\n||||    03-Fechar programa?                                 ||||");
    printf("\n||||                                                        ||||");
    printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\nDigite a opção:");
    scanf("%d",&i);
    system("cls");
    switch(i)
    {
        case 1:
            imprimir2();
            break;
        case 2:
            imprimir3();
            break;
        case 3:
            fechar();
            break;
        default:
            printf("\n||||||||||||||||||||||||||||ATENÇÃO|||||||||||||||||||||||||||||");
            printf("\n||||                                                        ||||");
            printf("\n||||         Erro na leitura, Digite novamente!!            ||||");
            printf("\n||||                                                        ||||");
            printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            Sleep(1000);
            Menu2();
    }

}

imprimir2()//IMPRIMIR O NOVO ARQUIVO
{
    char vet[72]={};
    fclose(novo);//FECHANDO O ARQUIVO
        novo=fopen("Zinho.M50","r");//ABRE NOVANETE O ARQUIVO ZINHO.M50
        //VERIFICAR SE FOI ABERTO
        if(!novo)
        {
            printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
            printf("\n||||         O arquivo 'Zinho.M50' nao foi aberto!!!!         ||||");
            printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            return;
        }

    printf("\n");
    while(!feof(novo))
    {
        fgets(vet, 72, novo);
        printf("%s", vet);
    }
    printf("\n");
    Sleep(1000);
    Menu2();
}

imprimir3()//IMPRIMIR O ARQUIVO DE CADASTRO "ZINHO.CAD"
{
    char vet[72]={};
    fclose(antigo);//FECHANDO O ARQUIVO
        antigo=fopen("Zinho.CAD","r");//ABRE NOVANETE O ARQUIVO ZINHO.CAD
        //VERIFICAR SE FOI ABERTO
        if(!antigo)
        {
            printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("\n||||        O arquivo 'Zinho.CAD' nao foi aberto!!!!          ||||");
            printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            return;
        }

    printf("\n");
    while(!feof(antigo))
    {
        fgets(vet, 72, antigo);
        printf("%s", vet);
    }
    printf("\n");
    Sleep(1000);
    Menu2();
}
