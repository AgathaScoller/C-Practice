#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define HISTORICO_ARQUIVO "historico-operacoes.txt"

void registrar_operacao(const char *tipo, double entrada1, double entrada2, double resultado) {
    FILE *f = fopen(HISTORICO_ARQUIVO, "a");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fprintf(f, "%-30s %15.6f %15.6f %15.6f\n", tipo, entrada1, entrada2, resultado);
    fclose(f);
}

double entrada_unica(const char *mensagem) {
    double valor;
    int ok;
    do {
        printf("%s", mensagem);
        ok = scanf("%lf", &valor);
        while(getchar() != '\n'); // limpa o buffer
        if (!ok) printf("Erro: Por favor, digite um número válido.\n");
    } while (!ok);
    return valor;
}

void duas_entradas(double *a, double *b) {
    *a = entrada_unica("Digite o primeiro número: ");
    *b = entrada_unica("Digite o segundo número: ");
}

void calculadora() {
    int opcao;
    int fim = 0;

    while (!fim) {
        printf("\n--- CALCULADORA CIENTÍFICA C ---\n");
        printf("1. Soma\n2. Subtração\n3. Multiplicação\n4. Divisão\n");
        printf("5. Raiz Quadrada\n6. Potência\n7. Logaritmo Natural\n8. Seno\n9. Cosseno\n0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        while(getchar() != '\n'); // limpa o buffer

        double a, b, resultado;
        switch (opcao) {
            case 1:
                duas_entradas(&a, &b);
                resultado = a + b;
                printf("Resultado: %.6f\n", resultado);
                registrar_operacao("Soma", a, b, resultado);
                break;
            case 2:
                duas_entradas(&a, &b);
                resultado = a - b;
                printf("Resultado: %.6f\n", resultado);
                registrar_operacao("Subtracao", a, b, resultado);
                break;
            case 3:
                duas_entradas(&a, &b);
                resultado = a * b;
                printf("Resultado: %.6f\n", resultado);
                registrar_operacao("Multiplicacao", a, b, resultado);
                break;
            case 4:
                duas_entradas(&a, &b);
                if (b == 0) {
                    printf("Erro: Divisão por zero.\n");
                } else {
                    resultado = a / b;
                    printf("Resultado: %.6f\n", resultado);
                    registrar_operacao("Divisao", a, b, resultado);
                }
                break;
            case 5:
                a = entrada_unica("Digite o número: ");
                if (a < 0) {
                    printf("Erro: Número negativo.\n");
                } else {
                    resultado = sqrt(a);
                    printf("Resultado: %.6f\n", resultado);
                    registrar_operacao("Raiz Quadrada", a, 0.0, resultado);
                }
                break;
            case 6:
                duas_entradas(&a, &b);
                resultado = pow(a, b);
                printf("Resultado: %.6f\n", resultado);
                registrar_operacao("Potencia", a, b, resultado);
                break;
            case 7:
                a = entrada_unica("Digite o número: ");
                if (a <= 0) {
                    printf("Erro: Valor <= 0.\n");
                } else {
                    resultado = log(a);
                    printf("Resultado: %.6f\n", resultado);
                    registrar_operacao("Logaritmo Natural", a, 0.0, resultado);
                }
                break;
            case 8:
                a = entrada_unica("Digite o ângulo (radianos): ");
                resultado = sin(a);
                printf("Resultado: %.6f\n", resultado);
                registrar_operacao("Seno", a, 0.0, resultado);
                break;
            case 9:
                a = entrada_unica("Digite o ângulo (radianos): ");
                resultado = cos(a);
                printf("Resultado: %.6f\n", resultado);
                registrar_operacao("Cosseno", a, 0.0, resultado);
                break;
            case 0:
                fim = 1;
                printf("Calculadora encerrada.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    }
}

int main() {
    calculadora();
    return 0;
}
