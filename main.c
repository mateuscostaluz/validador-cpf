#include <stdio.h>
#include <stdlib.h>

// nao utilizado, mas serve para retornar a quantidade de digitos de um numero qualquer
// retorna a quantidade de dígitos do CPF
int tamanhoCpf(int cpf, int x) {
    if(cpf == 0) {
        return x;
    }
    cpf = cpf / 10;
    x++;
    return tamanhoCpf(cpf, x);
}

// nao utilizado, mas serve para distribuir um numero qualquer em um vetor
// distribui o CPF em um vetor para validacao
void distribuirCpf(int cpf, int vetorCpf[], int tam, int x) {
    int base = 1;
	// int base = pow(10, tam); -- requer implementacao da biblioteca <math.h>
    for(int i = 0; i < tam; i++) {
        base *= 10;
    }
    int digito = cpf / base;
    vetorCpf[x] = digito;
    int testeCpf = cpf - (base * digito);
    x++;
    if(base == 1) {
        return;
    }
    return distribuirCpf(testeCpf, vetorCpf, tam - 1, x);
}

void validarCpf(char cpf[]) {
    int j = 0;
    int total = 0;
    for(int i = 10; i >= 2; i--) {
        total = total + cpf[j] * i;
        j++;
    }
    int validacao1 = total % 11;
    if(validacao1 < 2) {
        validacao1 = 0;
    }
    else {
        validacao1 = 11 - validacao1;
    }
    j = 0;
    total = 0;
    for(int i = 11; i >= 2; i--) {
        total = total + cpf[j] * i;
        j++;
    }
    int validacao2 = total % 11;
    if(validacao2 < 2) {
        validacao2 = 0;
    }
    else {
        validacao2 = 11 - validacao2;
    }
    if(validacao1 == cpf[9] && validacao2 == cpf[10]) {
        printf("CPF valido.");
    }
    else {
        printf("CPF invalido.");
    }
}

int main() {
    char cpf[11];
    int testeIgual = 0;
    printf("Informe o CPF a ser validado, sem pontos ou tracos: ");
    scanf("%s", &cpf); // recebe o CPF como string (vetor char) por conta do limite do tipo int
    int i = 0;
    for(; i < 11; i++) {
        cpf[i] = cpf[i] - 48; // converte o numero digitado para numero ao inves de letra, conforme tabela ASCII
        // printf("[%d]", cpf[i]); // para verificar a conversao
        testeIgual += cpf[i];
    }
    if(testeIgual / 11 == cpf[i - 1] && testeIgual % 11 == 0) { //testa se todos os numeros sao iguais
        printf("CPF invalido.");
    }
    else{
        validarCpf(cpf);
    }
    return 0;
}
