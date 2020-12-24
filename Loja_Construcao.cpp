#include <unistd.h> //sleep(seconds)
#include <stdio.h> // printf
#include <string.h> //memset
#include <stdlib.h> //system
#include <iostream>  //cout

using namespace std;

int exibirProdutos();
int menuPrincipal();

int main()
{
	char nomeCliente[100]; 
	memset(nomeCliente,0,100);
	int idade = 0;
	float altura = 0.0;
	float renda = 0.0;
	int UF = 1;
	
	float taxaTransp  = 0.0;
	float taxaImposto = 0.0;
	
	float total_pedido = 0.0;
	int qtd_produtos_pedido = 0;
	

	int qtd_produtos_geral = 0;
	float total_pedido_geral = 0.0;
	float menor_preco = 9999999.99;
	float maior_preco = 0.0;
	float maior_imposto = 0.0;
	float maior_ValorPedido_imposto = 0.0;
	float maior_transporte = 0.0;
	float maior_ValorPedido_transporte = 0.0;
	float total_salario = 0.0;
	float total_alturas = 0.0;
	int quantidade_cliente = 0;
	int maior_idade_SP = 0;
	int maior_idade_RJ = 0;
	
	
 	
	
	while(true)
	{
		int opcaoMP=0;
		cout<<" --------------------  MODULO PRINCIPAL  ---------------------" <<endl;
		cout<<" -------------------------  --------  ------------------------" <<endl;
		cout<<" OPCAO ---------- MODULOS ----------------------------------  " <<endl;
		cout<<"   1               VENDAS                            	     " <<endl;
		cout<<"   2               ESTATISTICA                         	     " <<endl;
		cout<<"   3               REFRESH                           	     " <<endl;
		cout<<"   4               FLUXO DE CAIXA                     	     " <<endl;
		cout<<"   5               CADASTRO                            	     " <<endl;
		cout<<"   6               ESTOQUE                            	     " <<endl;
		cout<<"   7               RETENCAO                            	     " <<endl;
		cout<<"   8               BIG DATA                                 	 " <<endl;
		cout<<"   ---------------------------------------------------------- " <<endl;
		cout<<"   9            Finalizar                                 	 " <<endl;
		cout<<"   " <<endl;
		cin>>opcaoMP;
		if(opcaoMP<0 || opcaoMP>9)
		{
			cout<<"   " <<endl;
			cout<<"   X            Opcao Invalida! Digite ouma opcao Valida! 	 " <<endl;
			cout<<"   " <<endl;
			sleep(2);
			system("clear");
			continue;
		}
		sleep(1);
		
		switch (opcaoMP)
		{
			case 1:
			{
				quantidade_cliente++;
				cout<<" ----------------------  MODULO VENDAS  ----------------------" <<endl;
				cout<<" -------------------------  --------  ------------------------" <<endl;
				cout<<"                      CADASTRO DO CLIENTE                     " <<endl;
				cout<<" "<<endl;
				cout<<"Digite o seu nome :" <<endl;
				scanf("%s", nomeCliente);
				cout<<"Digite a sua idade :" <<endl;
				scanf("%d", &idade);
				cout<<"Digite a sua altura :" <<endl;
				scanf("%f", &altura);
				total_alturas += altura;
				cout<<"Digite a sua renda :" <<endl;
				scanf("%f", &renda);
				total_salario += renda;
				cout<<"Digite o seu UF ( 1 - SP | 2 - RJ ) :" <<endl;
				scanf("%d", &UF);
				
				if(UF == 1)
				{
					if (idade > maior_idade_SP)
						maior_idade_SP = idade;
				}
				else
				{
					if (idade > maior_idade_RJ)
						maior_idade_RJ = idade;
				}

				int opcaoVendas;
				total_pedido  = 0;
				qtd_produtos_pedido = 0 ;
				do{
					sleep(1);
					system("clear");
					float preco;
					int quantidade;
					cout<<" ----------------------  MODULO VENDAS  ----------------------" <<endl;
					cout<<" -------------------------  --------  ------------------------" <<endl;
					cout<<"                      ESCOLHA DE PRODUTOS                     " <<endl;
					cout<<" "<<endl;
					cout<<" OPCAO --------- NOME ------------------  PRECO (R$) -------  " <<endl;
					cout<<"   1            Prego                      120.00         	 " <<endl;
					cout<<"   2            Balde                       48.00         	 " <<endl;
					cout<<"   3            Parafuso                   210.00         	 " <<endl;
					cout<<"   4            Martelo                     85.00         	 " <<endl;
					cout<<"   5            Escada                     250.00         	 " <<endl;
					cout<<"   ---------------------------------------------------------- " <<endl;
					cout<<"   6            Finalizar Pedido                          	 " <<endl;
					cout<<"   " <<endl;
					cin>>opcaoVendas;
					if(opcaoVendas<0 && opcaoVendas>7)
					{
						cout<<"   " <<endl;
						cout<<"   X            Opcao Invalida! Digite ouma opcao Valida! 	 " <<endl;
						cout<<"   " <<endl;
						sleep(2);
						system("clear");
					}
					if(opcaoVendas == 6)
						 break;
					 
					cout<<"   :)           Digite a quantidade:                     	 " <<endl;
					cout<<"   " <<endl;
					cin>>quantidade;
					switch(opcaoVendas)
					{
						case 1:
						{
							preco = 120.0;
							break;
						}
						case 2:
						{
							preco = 48.0;
							break;
						}
						case 3:
						{
							preco = 210.0;
							break;
						}
						case 4:
						{
							preco = 85.0;
							break;
						}
						case 5:
						{
							preco = 250.0;
							break;
						}
					}
					if(preco < menor_preco)
						menor_preco = preco;
					
					if(preco > maior_preco)
						maior_preco = preco;
					
					total_pedido += (preco * quantidade);
					qtd_produtos_pedido += quantidade;
			
				}while(opcaoVendas!=6);
				
				qtd_produtos_geral += qtd_produtos_pedido;
				total_pedido_geral += total_pedido;
				
				
				int opcaoTransp;
				cout<<" ----------------------  MODULO VENDAS  ----------------------" <<endl;
				cout<<" -------------------------  --------  ------------------------" <<endl;
				cout<<"                    TRANSPORTADORA UTILIZADA                  " <<endl;
				cout<<" "<<endl;
				cout<<" OPCAO --------- NOME ------------------  ------------ ------ " <<endl;
				cout<<"   1            Transportadora(SP)/Cheguei(RJ)                " <<endl;
				cout<<"   2            Trem Brasil (SP e RJ)         	             " <<endl;
				cout<<"   3            Correio (SP e RJ)                         	 " <<endl;
				cout<<"   ---------------------------------------------------------- " <<endl;
				cout<<"   " <<endl;
				cin>>opcaoTransp;

				switch(opcaoTransp)
				{
					case 1:
					{
						if(UF == 1)
							taxaTransp = 0.10;
						else
							taxaTransp = 0.15;
						break;
					}
					case 2:
					{
						if(UF == 1)
							taxaTransp = 0.075;
						else
							taxaTransp = 0.05;
						break;
					}
					case 3:
					{
						if(UF == 1)
							taxaTransp = 0.025;
						else
							taxaTransp = 0.035;
						break;
					}
				}
								
				// DEFINIÇÃO DO IMPOSTO
				if(total_pedido >= 5 && total_pedido <= 1000)
				{
					if(UF == 1)
						taxaImposto = 0.10;
					else
						taxaImposto = 0.12;
				}
				else if (total_pedido <= 2500)
				{
					if(UF == 1)
						taxaImposto = 0.13;
					else
						taxaImposto = 0.16;
				}
				else
				{
					if(UF == 1)
						taxaImposto = 0.18;
					else
						taxaImposto = 0.20;
				}
				
				
				if(total_pedido > maior_ValorPedido_transporte)
				{
					maior_ValorPedido_transporte = total_pedido;
					maior_transporte = (total_pedido * taxaTransp);
				}

				if(total_pedido > maior_ValorPedido_imposto)
				{
					maior_ValorPedido_imposto = total_pedido;
					maior_imposto = (total_pedido * taxaImposto);
				}				
				
				float valorImposto = taxaImposto * total_pedido;
				float valorTransp = taxaTransp * total_pedido;				
				cout<<" ----------------------  MODULO VENDAS  ----------------------" <<endl;
				cout<<" -------------------------  --------  ------------------------" <<endl;
				cout<<"                       RESUMO DO PEDIDO                       " <<endl;
				cout<<" "<<endl;
				cout<<"   ---------------------------------------------------------- " <<endl;
			   printf("     Quantidade de produto       [%d]\n", qtd_produtos_pedido);
			   printf("     Valor de IMPOSTO            [%f]\n", valorImposto);
			   printf("     Valor da Tranportadora      [%f]\n", valorTransp);
			   printf("     TOTAL (x/imposto s/transp)  [%f]\n", total_pedido);
			   printf("     TOTAL PEDIDO                [%f]\n", total_pedido + valorImposto + valorTransp);
				cout<<"   ---------------------------------------------------------- " <<endl;
				cout<<"   " <<endl;
				
				
				cout<<"                       OBRIGADO POR COMPRAR AQUI!!!!          " <<endl;
				sleep(1);
				cout<<"                       OBRIGADO POR COMPRAR AQUI!!!!          " <<endl;
				sleep(2);
				cout<<"                       OBRIGADO POR COMPRAR AQUI!!!!          " <<endl;
				sleep(3);
				system("clear");
				
				


			
				break;
			}
			case 2:
			{
				cout<<" --------------------  MODULO ESTATISTICA  -------------------" <<endl;
				cout<<" -------------------------  --------  ------------------------" <<endl;
				cout<<"                       RESUMO DE VENDAS                       " <<endl;
				cout<<" "<<endl;
				cout<<"   ---------------------------------------------------------- " <<endl;
			   printf("    1 - Quantidade total de produtos vendidos          [%d]\n", qtd_produtos_geral);
			   printf("    2 - Valor médio dos produtos vendidos              [%f]\n", total_pedido_geral/qtd_produtos_geral);
			   printf("    3 - Valor do produto vendido com menor valor       [%f]\n", menor_preco);
			   printf("    4 - Valor do produto vendido com maior valor       [%f]\n", maior_preco);
			   printf("    5 - Valor do pedido com maior valor de transporte  [%f]\n", maior_transporte);
			   printf("    6 - Valor do pedido com maior valor de imposto     [%f]\n", maior_imposto);
			   printf("    7 - Valor da média do salário dos clientes         [%f]\n", total_salario/quantidade_cliente);
			   printf("    8 - Valor da média das alturas dos clientes        [%f]\n", total_alturas/quantidade_cliente);
			   printf("    9 - Maior Idade dos clientes de SP                 [%d]\n", maior_idade_SP);
			   printf("   10 - Maior Idade dos clientes de RJ                 [%d]\n", maior_idade_RJ);
			   printf("                                                         \n");
				cout<<"   ---------------------------------------------------------- " <<endl;
				cout<<"   " <<endl;
				
				
				cout<<"                       IN DATA WE TRUST !!!                   " <<endl;
				sleep(1);
				cout<<"                       IN DATA WE TRUST !!!                   " <<endl;
				sleep(2);
				cout<<"                       IN DATA WE TRUST !!!                   " <<endl;
				sleep(2);
				system("clear");
				
				break;
			}
			case 3:
			{
				system("clear");
				cout<<" ----------------------     REFRESH     ----------------------" <<endl;
				cout<<" -------------------------  --------  ------------------------" <<endl;
				cout<<"                       EXPURGO DE HISTORICO                   " <<endl;
				cout<<" "<<endl;
				cout<<"   ---------------------------------------------------------- " <<endl;
			   printf("    ");
			   printf("#");
			   sleep(1);
			   printf("#");
			   sleep(1);
			   printf("#\n");
			   sleep(1);
			   
				memset(nomeCliente,0,100);
				 idade = 0;
				 altura = 0.0;
				 renda = 0.0;
				 UF = 1;
				
				 taxaTransp  = 0.0;
				 taxaImposto = 0.0;
				
				 total_pedido = 0.0;
				 qtd_produtos_pedido = 0;
				

				 qtd_produtos_geral = 0;
				 total_pedido_geral = 0.0;
				 menor_preco = 9999999.99;
				 maior_preco = 0.0;
				 maior_imposto = 0.0;
				 maior_ValorPedido_imposto = 0.0;
				 maior_transporte = 0.0;
				 maior_ValorPedido_transporte = 0.0;
				 total_salario = 0.0;
				 total_alturas = 0.0;
				 quantidade_cliente = 0;
				 maior_idade_SP = 0;
				 maior_idade_RJ = 0;			   
				
   			    cout<<"   ---------------------------------------------------------- " <<endl;
				cout<<"   " <<endl;
			   sleep(1);
			   
			   
			   system("clear");
				
				break;
			}
			case 9:
			{
				system("clear");
				cout<<" ----------------------   FINALIZANDO   ----------------------" <<endl;
				cout<<" -------------------------  --------  ------------------------" <<endl;
				cout<<"                       --------------------                   " <<endl;
				cout<<" "<<endl;
				cout<<"   ---------------------------------------------------------- " <<endl;
			   printf("    ");
			   printf("#");
			   sleep(1);
			   printf("#");
			   sleep(1);
			   printf("#\n");
			   sleep(1);
			   return 0;
			}
			default:
			{
				break;
			}
		}
	}
	
	return 0;
}