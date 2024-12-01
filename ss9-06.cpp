#include <stdio.h>

void displayMenu() {
    printf("\nMENU\n");
    printf("1. Enter the size and values of the matrix\n");
    printf("2. Print the values of the matrix\n");
    printf("3. Print odd values and calculate their sum\n");
    printf("4. Print border elements and calculate their product\n");
    printf("5. Print main diagonal elements\n");
    printf("6. Print secondary diagonal elements\n");
    printf("7. Print the row with the highest sum of elements\n");
    printf("8. Exit\n");
}

void inputMatrix(int matrix[100][100], int *rows, int *cols) {
    printf("Enter the number of rows: ");
    scanf("%d", rows);
    printf("Enter the number of columns: ");
    scanf("%d", cols);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[100][100], int rows, int cols) {
    printf("\nCurrent matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printOddAndSum(int matrix[100][100], int rows, int cols) {
    int sumOdd = 0;
    printf("\nOdd elements: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] % 2 != 0) {
                printf("%d ", matrix[i][j]);
                sumOdd += matrix[i][j];
            }
        }
    }
    printf("\nSum of odd elements: %d\n", sumOdd);
}

void printBorderAndProduct(int matrix[100][100], int rows, int cols) {
    int product = 1;
    printf("\nBorder elements: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                printf("%d ", matrix[i][j]);
                product *= matrix[i][j];
            }
        }
    }
    printf("\nProduct of border elements: %d\n", product);
}

void printMainDiagonal(int matrix[100][100], int rows, int cols) {
    printf("\nMain diagonal elements: ");
    for (int i = 0; i < rows && i < cols; i++) {
        printf("%d ", matrix[i][i]);
    }
    printf("\n");
}

void printSecondaryDiagonal(int matrix[100][100], int rows, int cols) {
    printf("\nSecondary diagonal elements: ");
    for (int i = 0; i < rows && i < cols; i++) {
        printf("%d ", matrix[i][cols - 1 - i]);
    }
    printf("\n");
}

void printRowWithMaxSum(int matrix[100][100], int rows, int cols) {
    int maxSum = -1, maxRow = -1;
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxRow = i;
        }
    }
    printf("\nRow with the highest sum of elements: %d\n", maxRow + 1);
}

int main() {
    int matrix[100][100];
    int rows, cols;
    int choice;

    while (1) {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputMatrix(matrix, &rows, &cols);
                break;
            case 2:
                printMatrix(matrix, rows, cols);
                break;
            case 3:
                printOddAndSum(matrix, rows, cols);
                break;
            case 4:
                printBorderAndProduct(matrix, rows, cols);
                break;
            case 5:
                printMainDiagonal(matrix, rows, cols);
                break;
            case 6:
                printSecondaryDiagonal(matrix, rows, cols);
                break;
            case 7:
                printRowWithMaxSum(matrix, rows, cols);
                break;
            case 8:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

