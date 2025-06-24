#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    printf("Nhap so luong phan tu ban dau (n): ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Nhap so luong phan tu can them (m): ");
    scanf("%d", &m);

    if (m < 0 || n + m >= 1000) {
        printf("So luong phan tu can them khong hop le hoac vuot qua gioi han\n");
        free(arr);
        return 0;
    }

    if (m > 0) {
        int* newArr = (int*)realloc(arr, (n + m) * sizeof(int));
        if (newArr == NULL) {
            printf("Khong the cap phat lai bo nho\n");
            free(arr);
            return 1;
        }
        arr = newArr;

        for (int i = 0; i < m; i++) {
            printf("Nhap phan tu moi thu %d: ", i + 1);
            scanf("%d", &arr[n + i]);
        }
    }

    printf("[ ");
    for (int i = 0; i < n + m; i++) {
        printf("%d", arr[i]);
        if (i < n + m - 1) printf(", ");
    }
    printf(" ]\n");

    free(arr);

    return 0;
}
