#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<stdbool.h>

	
	typedef struct lista{
		char nome[40];
		char sigla[10];
		float valorCompra;
		float valorVenda;
		int codigo;
		struct lista* prox;   
   }Lista;

     //Declaração de funções.
   Lista* inserir_papel(Lista* primeiro);
   void listar_papeis(Lista* primeiro);
   Lista* excluir_papel(Lista* primeiro);
   void alterar_papel(Lista* primeiro);
   Lista* verifica_compra (Lista *primeiro);
   Lista* verifica_venda (Lista *primeiro);



   int main(){
	   			Lista *primeiro= NULL;
                int quant, cont , i;
				int opcao, opcao1,opcao2,opcao3;



	while(opcao!=0)
	{
			
	          	printf("------------------------------------\n");
	          	printf("         SEJA BEM VINDO\n");
	          	printf("------------------------------------\n");
			  	printf(" 0-SAIR\n");
			  	printf(" 1-NEGOCIAR PAPEIS \n");
				printf(" 2-CADASTRO DE PAPEIS \n");
				printf(" 3-ALTERAR CADASTRO DE PAPEIS \n");
				printf(" 4-EXCLUIR CADASTRO DE PAPEIS \n");
				printf("------------------------------------\n");
	          	printf("        QUAL DESEJA ACESSAR?\n");
	          	printf("------------------------------------\n");
			  	scanf("%i", &opcao);

	switch(opcao)
		{
			case 1: //Papeis Disponiveis
    					
				system("cls");
				printf("------------------------------------\n");
 				listar_papeis(primeiro);
				printf("------------------------------------\n");
				printf("0- Voltar\n");
				printf("1- Comprar\n");
				printf("2- Vender\n");
				scanf("%i", &opcao1);
				
		switch(opcao1)
		{
				
			case 1: 
					printf("------------------------------------\n");
					primeiro=verifica_compra(primeiro);
					printf("------------------------------------\n");
					system("pause");
				
			
			break;//opcao1-case 1
			case 2: 
					printf("------------------------------------\n");
					primeiro =verifica_venda(primeiro);
					printf("------------------------------------\n");
					system("pause");
			break;//opcao2-case 2
	system("pause");
		}
	
						   
			break; //Papeis Disponiveis
		
			case 2:	
			 	fflush(stdin);
				printf("------------------------------------\n");
				printf("             CADASTRO\n");
				printf("------------------------------------\n");
				primeiro = inserir_papel(primeiro);
				printf("------------------------------------\n");
				getch();

			break;	

			case 3:
				fflush(stdin);
				printf("------------------------------------\n");
				printf("             ALTERAR CADASTRO\n");
				printf("------------------------------------\n");
				alterar_papel(primeiro);
				printf("------------------------------------\n");
				getch();
			break;	

			case 4:
				fflush(stdin);
				printf("------------------------------------\n");
				printf("             EXCLUIR CADASTRO\n");
				printf("------------------------------------\n");
				primeiro= excluir_papel(primeiro);
				printf("------------------------------------\n");
				getch();
			break;
		
		}

	}

}

Lista* inserir_papel (Lista *primeiro){ 
     Lista papel;
     Lista *atual= primeiro;
     bool jaExiste= false;
     
     //Lendo as informações.
		printf("  Nome : ");
		fflush (stdin); fgets(papel.nome, 40, stdin); printf ("\n");
		printf("  Sigla : ");
		fflush (stdin); fgets(papel.sigla, 20, stdin); printf ("\n");
		printf("  Valor de compra : ");
		scanf(" %f",&papel.valorCompra);printf ("\n");	
		fflush(stdin);	
		printf("  Valor de venda : ");
		scanf(" %f" ,&papel.valorVenda);printf ("\n");
		fflush(stdin);
		printf("  Codigo : ");
		scanf(" %i",&papel.codigo);printf ("\n");
		fflush(stdin);

		
     //Verificando se o cadastro já existe.
     for(atual=primeiro; atual!=NULL; atual=atual->prox){
        if(atual->codigo==papel.codigo){
            jaExiste=true; 
            break;
        }    
     }

     if(!jaExiste && (strlen(papel.nome)!=1 && strlen(papel.sigla)!=1))
	 {
         //Alocando os espaços e guardando as informações.
         Lista* NovoPapel=(Lista*) malloc (sizeof(Lista));       
         strcpy(NovoPapel->nome, papel.nome);
         strcpy(NovoPapel->sigla, papel.sigla);
         NovoPapel->valorCompra=papel.valorCompra;
		 NovoPapel->valorVenda= papel.valorVenda;
		 NovoPapel->codigo= papel.codigo;
         NovoPapel->prox= primeiro;
         printf("\n  Cadastro realizado com sucesso.");
         return NovoPapel;    
     }else
	 {
         printf("\n  Cadastro invalido.");
         return primeiro;
     }
}

void listar_papeis (Lista* primeiro){
     Lista* atual;//Ponteiro para percorrer a lista sem perder a referência do primeiro elemento da lista.
     
     //Imprimindo  lista, e suas repectivas informações.
     for(atual= primeiro ; atual!= NULL; atual= atual->prox)
	 {
		printf("------------------------------------\n");
        printf("\n  Nome: %s",atual->nome);
        printf("\n  Sigla: %s ",atual->sigla);
		printf("\n  Valor de compra: %.2f", atual->valorCompra);
		printf("\n  Valor de venda; %.2f", atual->valorVenda);
		printf("\n  Codigo: %i ",atual->codigo);
        printf("\n\n");
		printf("------------------------------------\n");
     }
     if(primeiro==NULL)
        printf("  Nenhum papel cadastrado.\n");
     printf(" PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.\n");
}



Lista* verifica_compra (Lista *primeiro){
	Lista papel;
	Lista *atual= primeiro;
	int quantCompra = 0;
	int verificaCodigo;
		printf("Digite o codigo da acao que deseja comprar\n");
		scanf("%i",&verificaCodigo);
	//Verificando se o cadastro já existe.
     for(atual=primeiro; atual!=NULL; atual=atual->prox)
	 {
        if(atual->codigo == verificaCodigo)
		{
			printf("Quantos papeis de codigo %i deseja comprar?\n",atual->codigo);
			scanf("%i",&quantCompra);
			printf("Compra realizada com sucesso\n");
            break;
        }else{
			printf("   Papel inexistente\n");//break impede essa linha mas vou deixar
		}    
     }
}

Lista* verifica_venda (Lista *primeiro){
	Lista papel;
	Lista *atual= primeiro;
	int quantVenda = 0;
	int verificaCodigo;
		printf("Digite o codigo da acao que deseja comprar\n");
		scanf("%i",&verificaCodigo);
	//Verificando se o cadastro já existe.
     for(atual=primeiro; atual!=NULL; atual=atual->prox)
	 {
        if(atual->codigo == verificaCodigo)
		{
			printf("Quantos papeis de codigo %i deseja vender?\n",atual->codigo);
			scanf("%i",&quantVenda);
			printf("Venda realizada com sucesso\n");
            break;
        }else{
			printf("  Papel inexistente\n");//break impede essa linha mas vou deixar
		}    
     }
}

void alterar_papel(Lista* primeiro){     
     char nome_substituto[40], sigla_substituto[20];
     float novoValorCompra=0,novoValorVenda=0;
	 int codigo=0;  
     Lista* atual=primeiro;
     
     //Requisitando e lendo o código do Papel a ser alterado.
     printf("  Codigo do Papel a ser alterado: ");
     fflush(stdin);
     scanf("%i",&codigo);
     
     //Procurando na lista.
     while(atual!= NULL && atual->codigo!=codigo){
        atual= atual->prox;
     }
     
     //Alterando os dados 
     if(atual!=NULL){
        printf("\n  Novo nome: ");
        fflush (stdin); fgets(nome_substituto, 40, stdin); 
        strcpy(atual->nome,nome_substituto);
        printf("\n  Nova sigla: ");
        fflush (stdin); fgets(sigla_substituto, 40, stdin); printf ("\n");
        strcpy(atual->sigla,sigla_substituto);
		fflush (stdin); printf("\n Novo valor de compra");
		scanf("%f",novoValorCompra);
		fflush(stdin);novoValorCompra = atual->valorCompra;
		fflush (stdin); printf("\n Novo valor de venda");
		scanf("%f",novoValorVenda);
		fflush(stdin);novoValorVenda = atual->valorVenda;	
        printf("  Dados alterados com sucesso.\n");
     }else{
        printf("\n  Papel nao encontrado.");
     }
     printf("\n\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}

Lista* excluir_papel(Lista *primeiro){
     
     Lista *anterior= NULL;//Ponteiro para saber o elemento anterior ao elemento atual da lista.
     Lista *atual= primeiro;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
     int codigo=0;
     
     //Requisitando e lendo o código a ser excluído.
     printf("  Codigo do Papel a ser excluido: ");
     fflush(stdin);
     scanf("%i",&codigo);
     
     //Procurando na lista.
     while(atual!= NULL && atual->codigo!=codigo){
        anterior= atual;
        atual= atual->prox;
     }
     
     //Mensagem caso não seja encontrado.
     if(atual==NULL){
        printf("\n  Papel nao encontrado."); 
        printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
        return primeiro;
     }
     
     //Excluindo o primeiro da lista.   
     if(anterior==NULL){
        printf("\n  Conteudo excluido com sucesso."); 
        primeiro= atual->prox;
     //Excluindo  do meio da lista.
     }else{
        printf("\n  Conteudo excluido com sucesso.");
        anterior->prox= atual->prox;
     }
     
     //Desalocando o espaço da memória.
     free(atual);
     printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
     return primeiro;     
}
