#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
	setlocale(LC_ALL, "portuguese");
	float vendas = 0.0, gastos = 0.0, valor;
	int opcao;
	do {
		printf("\n==== Menu Principal ====\n");
		printf("\n1. Registrar Venda");
		printf("\n2. Registrar Gasto");
		printf("\n3. Ver Balanco Diario");
		printf("\n4. Sair\n");
        printf("\n========================\n");
		printf("\nEscolha uma opcao: ");
		if (scanf("%d", &opcao) != 1) {
			printf("Opcao invalida!\n");
			while(getchar() != '\n');
			continue;
		}
		switch(opcao) {
			case 1:
				printf("Digite o valor da venda: R$");
				if (scanf("%f", &valor) == 1 && valor > 0) {
					vendas += valor;
					printf("Venda registrada!\n");
				} else {
					printf("Valor invalido!\n");
					while(getchar() != '\n');
				}
				break;
			case 2:
				printf("Digite o valor do gasto: R$");
				if (scanf("%f", &valor) == 1 && valor > 0) {
					gastos += valor;
					printf("Gasto registrado!\n");
				} else {
					printf("Valor invalido!\n");
					while(getchar() != '\n');
				}
				break;
			case 3:
				printf("\n--- Balanco Diario ---\n");
				printf("Total de Vendas: R$ %.2f\n", vendas);
				printf("Total de Gastos: R$ %.2f\n", gastos);
				printf("Balanco Final: R$ %.2f\n", vendas - gastos);
				if (vendas - gastos >= 0)
					printf("Situacao: Lucro\n");
				else
					printf("Situacao: Prejuizo\n");
				break;
			case 4:
				printf("Saindo...\n");
				break;
			default:
				printf("Opcao invalida!\n");
		}
	} while(opcao != 4);
	return 0;
}
