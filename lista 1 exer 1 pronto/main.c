#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

typedef struct {
    int id;
    char nome[50];
    int quant;
    float custo;
}   Produto;

int aux=0, cont=0, ig=00, aux2=0;

FILE *pont_arq;

main()
{
    setlocale (LC_ALL, "portuguese");

    int cont, q;

    //CRIANDO O ARQUIVO E TESTANDO SE A ABERTURA FOI CORRETA

    pont_arq = fopen("bancoDeDados.bin","ab");

    if (pont_arq == NULL){
        printf("ERRO AO CRIAR O ARQUIVO!!!\n");
    }
    else
    {
        contID();
        Sleep(600);

        system ("cls");
    }

    while(cont != 3)
    {
        printf("|||||||||||||||||||||||MENU|||||||||||||||||||||||\n");
        printf("|||                                            |||\n");
        printf("|||         01-Cadastrar/Remover Produtos      |||\n");
        printf("|||         02-Consultar                       |||\n");
        printf("|||         03-Sair do Programa                |||\n");
        printf("|||                                            |||\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("Digite a opção:");
        scanf("%d", &cont);

        switch(cont)
        {
            case 01:
                //CHAMA A FUNÇÃO CADASTRAR PRODUTOS
                system ("cls");
                aux=0;
                cont = 0;
                editar ();
                break;

            case 02:
                //CHAMA A FUNÇÂO CONSULTA
                system ("cls");
                cont = 0;
                aux2 = 0;
                consulta();
                break;

            case 03:
                system ("cls");
                printf("Voce quer mesmo fechar o programa?\n");
                printf("[01-Sim]\n[02-Não]:");
                scanf("%d", &cont);
                if (cont == 01)
                {
                    cont = 03;
                    system ("cls");
                }
                else
                {
                    system ("cls");
                    cont = 0;
                }
                break;
            default:
                printf("\n\nErro na leitura!!!\n\n");
                Sleep (700);
                system ("cls");
                break;
        }
    }

    return 0;
}

consulta()
{

    while(aux2 != 03)
    {


    system ("cls");

    printf("|||||||||||||||||||||||MENU|||||||||||||||||||||||\n");
    printf("|||                                            |||\n");
    printf("|||          01-Consultar por nome             |||\n");
    printf("|||          02-Relatorio Geral                |||\n");
    printf("|||          03-Voltar                         |||\n");
    printf("|||                                            |||\n");
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("Digite a opção:");
    scanf("%d", &aux2);

    switch (aux2)
    {
        case 01:

            system("cls");
            aux2 = 0;
            cnome();
            break;

        case 02:
            //CHAMA FUNÇÂO REMOVER

            system("cls");
            aux2=0;
            rgeral();
            break;

        case 03:
            //VOLTA PARA MENU
            system("cls");
            aux2=03;
            break;

    }


    }

}

cnome()
{
    char consu[50];
    int control=0, alterar=0, nom=0, qtd=0, val=0;
    long int pos;

    pont_arq = fopen("bancoDeDados.bin","r+b");

    if (pont_arq == NULL)
    {
        printf("ERRO AO CRIAR O ARQUIVO!!!\n");
    }
    Produto cl;

    printf("Digite o nome do produto: ");
    scanf("%s", &consu);

    rewind(pont_arq);
    while(fread(&cl, sizeof(Produto), 1,  pont_arq))
    {

    pos = ftell(pont_arq)-sizeof(Produto);
    if(strcmp(cl.nome, consu) == 0)
    {

        printf("\n\nNOME: %s | ID: %d  | QUANTIDADE: %d  |  VALOR: %.2f  ", cl.nome, cl.id, cl.quant, cl.custo);
        printf("\n\nDESEJA ALTERAR ALGUM REGISTRO:");
        printf("\n[01-Sim]\n[02-Não]");
        printf("\n------------: ");
        scanf("%d", &alterar);

            if (alterar == 01)
            {
                    fseek(pont_arq, pos, SEEK_SET);


                    printf("\nALTERAR NOME:\n");
                    printf("\n01 -- SIM\n02 -- NÂO");
                    printf("\n------------: ");
                    scanf("%d", &nom);
                        if(nom == 01)
                        {
                        printf("\nDIGITE O NOME: ");
                        fflush(stdin);
                        gets(cl.nome);

                        fwrite(&cl, sizeof(Produto), 1, pont_arq);
                        }
                    printf("\nALTERAR QUANTIDADE:\n");
                    printf("\n01 -- SIM\n02 -- NÂO");
                    printf("\n------------: ");
                    scanf("%d", &qtd);
                        if(qtd == 01)
                        {

                            printf("DIGITE A QUANTIDADE: ");
                            scanf("%d", &cl.quant);

                            fwrite(&cl, sizeof(Produto), 1, pont_arq);
                        }
                    printf("\nALTERAR VALOR:\n");
                    printf("\n01 -- SIM\n02 -- NÂO");
                    printf("\n------------: ");
                    scanf("%d", &val);
                        if(val == 01)
                        {

                            printf("DIGITE O VALOR (00,0): ");
                            scanf("%f", &cl.custo);

                            fwrite(&cl, sizeof(Produto), 1, pont_arq);
                        }
            }
            else
            {
                consulta();
            }
        control = 1;
        fclose(pont_arq);
        break;
        }
    }
        if(control==0)
        {
            printf("\n\nNOME NÂO ENCONTRADO!!!");
            Sleep(1000);
        }
}

rgeral()
{

    pont_arq = fopen("bancoDeDados.bin","rb");

    if (pont_arq == NULL)
    {
        printf("ERRO AO CRIAR O ARQUIVO!!!\n");
    }

    Produto cl;
    printf("|||||||Registro de todos os produtos|||||||");
    while(fread(&cl, sizeof(Produto), 1,  pont_arq))
    {
        if (cl.id != -1)
        {
        printf("\nNOME: %s | ID: %d  | QUANTIDADE: %d  |  VALOR: %.2f  ", cl.nome, cl.id, cl.quant, cl.custo);
        }
    }
    getch();
    fclose(pont_arq);

}

remover()
{
    long int pos, control=0;

    char remov[50];

     pont_arq = fopen("bancoDeDados.bin","r+b");

    if (pont_arq == NULL)
    {
        printf("ERRO AO CRIAR O ARQUIVO\n");
    }

    Produto cl;


    printf("\n\nDigite o nome do produto para remover: ") ;
    scanf("%s", &remov);

    rewind(pont_arq);
    while(fread(&cl, sizeof(Produto), 1,  pont_arq))
    {

        pos = ftell(pont_arq)-sizeof(Produto);
        if(strcmp(cl.nome,remov) == 0)
        {
        fseek(pont_arq, pos, SEEK_SET);
        printf("\nNome: %s | ID: %d  | Quantidade: %d  |  Valor: %.2f  ", cl.nome, cl.id, cl.quant, cl.custo);
        Produto cx;
        cx.id = -1;
        fwrite(&cx, sizeof(Produto), 1, pont_arq);
        control = 1;
        break;
        }

        }
        if(control==0)
        {
            printf("\n\nNOME NÂO ENCONTRADO");
            Sleep(1000);
        }

    fclose(pont_arq);
}

ler ()
{
    pont_arq = fopen("bancoDeDados.bin","rb");

    if (pont_arq == NULL)
    {
        printf("ERRO AO CRIAR O ARQUIVO\n");
    }

    Produto cl;

    while(fread(&cl, sizeof(Produto), 1,  pont_arq))
    {
        if(cl.id != -1)
        {
        printf("\nNOME: %s | ID: %d  | QUANTIDADE: %d  |  VALOR: %.2f  ", cl.nome, cl.id, cl.quant, cl.custo);
        }
    }
    fclose(pont_arq);

}

contID()
{
    pont_arq = fopen("bancoDeDados.bin","rb");
    if (pont_arq == NULL)
    {
        printf("ERRO AO CRIAR O ARQUIVO\n");
    }
    Produto cl;
    while(fread(&cl, sizeof(Produto), 1,  pont_arq))
    {

    ig=ig+01;

    }
    fclose(pont_arq);
}

void cadastrar ()
{

    int c=0;

    pont_arq = fopen("bancoDeDados.bin","ab");

    if (pont_arq == NULL)
    {
        printf("ERRO AO CRIAR O ARQUIVO\n");
    }

    Produto cl;

    ig=ig+1;
    aux=0;
    cont=0;

    cl.id = ig;

    printf("|||||||||Cadastro do produto|||||||||\n");
    printf("Digite o nome: ");
    fflush(stdin);
    gets(cl.nome);
    printf("Digite a quantidade: ");
    scanf("%d", &cl.quant);
    printf("Digite o valor(00,0): ");
    scanf("%f", &cl.custo);

    system("cls");
    fwrite(&cl, sizeof(Produto), 1, pont_arq);

    fclose(pont_arq);

    system("cls");
}

editar ()
{

    aux=0;

    while(aux != 3)
    {
        system ("cls");

        printf("|||||||||||||||||||||||MENU|||||||||||||||||||||||\n");
        printf("|||                                            |||\n");
        printf("|||             01-Cadastrar                   |||\n");
        printf("|||             02-Remover                     |||\n");
        printf("|||             03-Voltar                      |||\n");
        printf("|||                                            |||\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("\nDigite a opção:");
        scanf("%d", &aux);

        switch (aux)
        {

            case 01:

            system("cls");
            aux = 0;
            cadastrar();
            break;

            case 02:
            //CHAMA FUNÇÂO REMOVER
            ler();
            remover ();
            system("cls");
            aux=0;
            break;

            case 03:
            //VOLTA PARA MENU
            system("cls");
            aux=03;
            break;
        }

    }
}
