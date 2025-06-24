#include <stdio.h>
#include <stdlib.h>

int timMax(int* arr, int rows, int cols) {
    int max = arr[0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int val = arr[i * cols + j];
            if (val > max)
                max = val;
        }
    }
    return max;
}

int timMin(int* arr, int rows, int cols) {
    int min = arr[0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int val = arr[i * cols + j];
            if (val < min)
                min = val;
        }
    }
    return min;
}

int main() {
    int rows, cols;

    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    if (rows <= 0 && cols <= 0) {
        printf("So cot va so hang khong hop le\n");
        return 0;
    } else if (cols <= 0) {
        printf("So cot khong hop le\n");
        return 0;
    } else if (rows <= 0) {
        printf("So hang khong hop le\n");
        return 0;
    }

    int* arr = (int*)malloc(rows * cols * sizeof(int));
    if (!arr) {
        printf("Khong the cap phat bo nho\n");
        return 0;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhap arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i * cols + j]);
        }
    }

    int max = timMax(arr, rows, cols);
    int min = timMin(arr, rows, cols);

    printf("max = %d\n", max);
    printf("min = %d\n", min);

    free(arr);

    return 0;
}
