#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 256

int validateInput(int *value) {
    double input;
    if (scanf("%lf", &input) == 1 && modf(input, &input) == 0) {
        *value = (int)input;
        return 1;
    } else {
        printf("Invalid input. Please enter an integer.\n"); // отформотированная строка + запись в файл
        while (getchar() != '\n');  // Очистка буфера ввода
        return 0;
    }
}

void randomizeArray(double *arr, int length) {
    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        arr[i] = rand() / (RAND_MAX + 1.0) * 100.0;
    }
}

double findMaxValue(const double *arr, int length) {
    if (length == 0) {
        printf("Array is empty!\n");
        return 0.0;
    }

    const double *ptr = arr;
    double maxValue = *ptr;
    for (int i = 1; i < length; ++i) {
        ++ptr;
        if (*ptr > maxValue) {
            maxValue = *ptr;
        }
    }
    return maxValue;
}

double findMinValue(const double *arr, int length) {
    if (length == 0) {
        fprintf(stderr, "Array is empty!\n");
        return 0.0;
    }

    const double *ptr = arr;
    double minValue = *ptr;
    for (int i = 1; i < length; ++i) {
        ++ptr;
        if (*ptr < minValue) {
            minValue = *ptr;
        }
    }
    return minValue;
}

void printArray(const double *arr, int length) {
    const double *ptr = arr;
    for (int i = 0; i < length; ++i) {
        printf("%.2f ", *ptr);
        ++ptr;
    }
    printf("\n");
}

void writeToFile(const double *arr, int length, double max, double min, const char *filename, int cleartxt) {
    FILE *fout = fopen(filename, cleartxt ? "w" : "a");

    const double *ptr = arr;
    for (int i = 0; i < length; ++i) {
        fprintf(fout, "%.2f ", *ptr);
        ++ptr;
    }

    fprintf(fout, "\nmax: %.2f\n", max);
    fprintf(fout, "min: %.2f\n", min);
    fprintf(fout, "sum: %.2f\n", min + max);

    fclose(fout);
}

int main() {
    int writeToTextFile = 0;
    int cleartxt = 0;
    char write[MAX_FILENAME_LENGTH];
    printf("Do you want to write the result to the text.txt file (press y or clear all press c)\n");
    scanf("%s", write);

    for (int i = 0; write[i]; ++i) {
        write[i] = (char)tolower(write[i]);
    }

    if (write[0] == 'y') {
        writeToTextFile = 1;
    } else if (write[0] == 'c') {
        writeToTextFile = 1;
        cleartxt = 1;
    }

    int len;
    int validInput = 0;
    while (!validInput) {
        printf("Enter a positive integer n: ");
        validInput = validateInput(&len) && len > 0;
    }

    double *mainArr = (double *)malloc(len * sizeof(double));

    if (mainArr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    };

    randomizeArray(mainArr, len);
    printArray(mainArr, len);

    double max = findMaxValue(mainArr, len);
    double min = findMinValue(mainArr, len);
    printf("\nMAX: %.2f\n", max);
    printf("MIN: %.2f\n", min);
    printf("sum: %.2f\n", min + max);

    if (writeToTextFile) {
        writeToFile(mainArr, len, max, min, "text.txt", cleartxt);
    }

    free(mainArr);

    return 0;
}
