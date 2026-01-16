#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocaçao de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro()  //Função responsavel por cadastrar os usuários no sistema
{
	   //inicio criação vatiáveis/string
	   char arquivo[40];
       char cpf[40];
	   char nome[40];
	   char sobrenome[40];
	   char cargo[40];
	   //final criação vatiáveis/string
	       printf("Digite o CPF do usuário a ser cadastrado: "); //coletando informação do usuário
	       scanf("%s", cpf); //%s refere-se a string
	   
	   strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	   
	   FILE *file;  // cria o arquivo
	   file = fopen(arquivo, "w"); //  cria o arquivo e o "w" significa escrever
	   fprintf(file,cpf);  // salva o valor da variavel 
	   fclose(file);  // fecha o arquivo 
	   
	   file = fopen(arquivo, "a");  // atualiza o arquivo
	   fprintf(file,",");  //coloca virgula
	   fclose(file);  //fecha o arquivo
	   
	       printf("Digite o nome a ser cadastrado: ");
	       scanf("%s",nome); //%s refere-se a string
	   
	   file = fopen(arquivo, "a");  // atualiza o arquivo
	   fprintf(file,nome); // salva o valor da variavel 
	   fclose(file);  // fecha o arquivo 
	   
	   file = fopen(arquivo, "a");  // atualiza o arquivo
	   fprintf(file,",");  //coloca virgula
	   fclose(file);  //fecha o arquivo
	   
	       printf("Digite o sobrenome a ser cadastrado: ");
	       scanf("%s",sobrenome); //%s refere-se a string
	   
	   file = fopen(arquivo, "a");
	   fprintf(file,sobrenome); // salva o valor da variavel 
	   fclose(file);   //fecha o arquivo
	   
	   file = fopen(arquivo, "a");
	   fprintf(file,",");  //coloca virgula
	   fclose(file);  //fecha o arquivo
	   
	       printf("Digite o cargo a ser cadastrado: ");
	       scanf("%s",cargo); //%s refere-se a string
	   
	   file = fopen(arquivo, "a");
	   fprintf(file,cargo); // salva o valor da variavel 
	   fclose(file);  //fecha o arquivo
	   
	   system("pause"); //pausa a tela
	   	
}

int consulta()
{
	   setlocale(LC_ALL, "Portuguese"); //Definendo a Linguagem 
	   //inicio criação vatiáveis/string
       char cpf[40];
       char conteudo[200];
       //final criação vatiáveis/string
       
           printf("Digite o CPF do usuário a ser consultado: ");
           scanf("%s",cpf); //%s refere-se a string
       
           FILE *file;
           file = fopen(cpf,"r");
       
       if(file== NULL)
       {
       	    printf("Não foi possivel abrir o arquivo, não localizado!.\n");
       	   
	   }
        
       while(fgets(conteudo, 200, file) != NULL)
	   {
	   	    printf("\nEssas são as informações do usuário: ");
	   	    printf("%s", conteudo);
	   	    printf("\n\n");

		} 
		
		system("pause"); //pausa a tela

}
int deletar()
{
	//inicio criação vatiáveis/string
    char cpf[40];
    //final criação vatiáveis/string
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s",cpf); //%s refere-se a string
    
    remove(cpf); //deletar o cfp
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("O usuário não se encontra no sistema!.\n");
    	system("pause");  //pausa a tela
	}
    
}

int main()
{
    int opcao=0; //Definindo as variáveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
	    system("cls");
	    setlocale(LC_ALL, "Portuguese"); //Definendo a Linguagem 
	
    	printf("--- CARTÓRIO DA EBAC ---\n\n"); //inicio do menu 
	    printf("Escolha a Opção Desejada Do Menu:\n\n");
	    printf("\t1 - Registrar Nomes-\n");
     	printf("\t2 - Consultar Nomes-\n");
    	printf("\t3 - Deletar Nomes-\n\n\n");
    	printf("Opção: ");  //fim do menu 
     
        scanf("%d", &opcao); //Armazenando a escolha do usuário
    
        system("cls");  //responsavel por limpar a tela
        
        
        switch(opcao)  //inicio da seleção do menu
        {
        	case 1:
            registro(); //chamada de função
        	break;
        	
        	case 2:
        	consulta();
        	break;
        	
        	case 3:
        	deletar();	    	
			break;
			
			default:
			printf("Essa opção não esta disponivel!\n");
     	    system("pause");
			break;	
			//Fim da seleção do menu
		}
    
    	
   }
}

