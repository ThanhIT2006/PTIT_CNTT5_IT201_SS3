#include <stdio.h>
#include <stdlib.h>

int tinhTongCheoChinh(int* arr, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += arr[i * n + i];  
    }
    return tong;
}

int tinhTongCheoPhu(int* arr, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += arr[i * n + (n - 1 - i)]; 
    }
    return tong;
}

int main() {
    int rows, cols;

    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0) {
        printf("So hang hoac cot khong hop le\n");
        return 0;
    }

    int* arr = (int*)malloc(rows * cols * sizeof(int));
    if (!arr) {
        printf("Khong the cap phat bo nho\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhap arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i * cols + j]);
        }
    }

    if (rows == cols) {
        int tongChinh = tinhTongCheoChinh(arr, rows);
        int tongPhu = tinhTongCheoPhu(arr, rows);
        printf("Tong duong cheo chinh = %d\n", tongChinh);
        printf("Tong duong cheo phu = %d\n", tongPhu);
    } else {
        printf("Khong ton tai duong cheo chinh\n");
        printf("Khong ton tai duong cheo phu\n");
    }

    free(arr);
    return 0;
}
