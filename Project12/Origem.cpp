#include<stdio.h>//biblioteca
#include<stdlib.h>//biblioteca
#include<conio.h>//biblioteca
#include<string.h>//biblioteca
#include<locale.h>//biblioteca


int main() {

	setlocale(LC_ALL, "Portuguese");//libera uso de caracteres especiais

	FILE* arquivo;//ponteiro

	char frase[50];//variavel

	char nome[15];//variavel

	char* leitura;//ponteiro



	printf("Digite o nome do arquivo: ");//usuario escolhe o nome do arquivo
    scanf_s("%s", &nome);

	strcat_s(nome, " .txt"); // concatenei o nome do arquivo junto da palavra .txt para criar o arquivo.

	if ((arquivo = fopen_s(nome, "a")) != NULL) { //verificando se o arquivo não está nulo
		for (int i = 1; i <= 5; i++) { //laço que escreve 5 frases
			printf("\nDigite a %i° frase: ", i);//apresenta para usuario escrever 5 frases
			fflush(stdin);//limpeza de teclado
			fgets(frase, 50, stdin); // fgets já limita a 50 caracteres
			_strupr_s(frase); // torna a escrita para maiusculo
			fputs(frase, arquivo); // escreve a frase no arquivo
		}
	}

	fclose(arquivo);
	arquivo = fopen_s(nome, "r");//abrindo arquivo para leitura
	for (int i = 1; i <= 5; i++) {//laço para ler as 5 frases
		leitura = fgets(frase, 50, arquivo);//lendo
		printf("%s \n", frase);//mostra frase
	}
}

