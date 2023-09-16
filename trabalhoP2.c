#include <stdio.h>
#include <string.h>
#include <locale.h>

int NT = 0;
int NC = 0;

void trocar(char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
    NT++;
}

int particionar(char *arr[], int bottom, int upper) {
    char *pivot = arr[upper];
    int y = bottom - 1;

    for (int x = bottom; x <= upper - 1; x++) {
        NC++;
        if (strcmp(arr[x], pivot) < 0) {
            y++;
            trocar(&arr[y], &arr[x]);
        }
    }
    trocar(&arr[y + 1], &arr[upper]);
    return y + 1;
}

void quicksort(char *arr[], int bottom, int upper) {
    if (bottom < upper) {
        int pi = particionar(arr, bottom, upper);

        quicksort(arr, bottom, pi - 1);
        quicksort(arr, pi + 1, upper);
    }
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limão", "manga", "abacate", "kiwi",
        "cereja", "morango", "pêssego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    printf("Vetor ordenado:\n");
    for (int y = 0; y < n; y++) {
        printf("%s\n", arr[y]);
    }

    printf("\nNúmero de trocas: %d\n", NT);
    printf("Número de comparações: %d\n", NC);

    char *mediana = arr[n / 2];
    printf("\nMediana: %s\n", mediana);

    FILE *saida = fopen("saidadedados.txt", "w");
    if (saida == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        return 1;
    }

    fprintf(saida, "Vetor ordenado:\n");
    for (int y = 0; y < n; y++) {
        fprintf(saida, "%s\n", arr[y]);
    }

    fprintf(saida, "\nNúmero de trocas: %d\n", NT);
    fprintf(saida, "Número de comparações: %d\n", NC);
    fprintf(saida, "\nMediana: %s\n", mediana);

    fclose(saida);

    return 0;
}

