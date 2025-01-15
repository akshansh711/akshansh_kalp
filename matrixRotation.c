#include <stdio.h>
#include <stdlib.h>

void takeInput(int m, int n, int arr[m][n]) {
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void rotate90(int m,int n,int arr[m][n]) {
    int res[n][m];
    int temp = m-1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[j][temp] = arr[i][j];
        }
        temp = temp-1;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }
}

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void reverseColumn(int m, int arr[m][10], int col, int start, int end) {
    while (start < end) {
        int temp = arr[start][col];
        arr[start][col] = arr[end][col];
        arr[end][col] = temp;
        start++;
        end--;
    }
}

void rotateLeft(int n, int arr[], int steps) {
    steps = steps % n;
    reverse(arr, 0, n - 1);
    reverse(arr, n - steps, n - 1);
    reverse(arr, 0, n - steps - 1);
}

void rowLeft(int m, int n, int arr[m][n]) {
    int steps;
    printf("Enter steps: ");
    scanf("%d", &steps);

    for (int i = 0; i < m; i++) {
        rotateLeft(n, arr[i], steps);
    }
    printf("Matrix after left rotation:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void rotateRight(int n, int arr[], int steps) {
    steps = steps % n;
    reverse(arr, 0, n - 1);
    reverse(arr, 0, steps - 1);
    reverse(arr, steps, n - 1);
}

void rowRight(int m, int n, int arr[m][n]) {
    int steps;
    printf("Enter steps: ");
    scanf("%d", &steps);

    for (int i = 0; i < m; i++) {
        rotateRight(n, arr[i], steps);
    }

    printf("Matrix after right rotation:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void columnUp(int m, int n, int arr[m][n]) {
    int steps;
    printf("Enter steps: ");
    scanf("%d", &steps);
    steps = steps % m;

    for (int col = 0; col < n; col++) {
        reverseColumn(m, arr, col, 0, m - 1);
        reverseColumn(m, arr, col, 0, m - steps - 1);
        reverseColumn(m, arr, col, m - steps, m - 1);
    }

    printf("Matrix after column up rotation:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void columnDown(int m, int n, int arr[m][n]) {
    int steps;
    printf("Enter steps: ");
    scanf("%d", &steps);
    steps = steps % m;

    for (int col = 0; col < n; col++) {
        reverseColumn(m, arr, col, 0, m - 1);
        reverseColumn(m, arr, col, 0, steps - 1);
        reverseColumn(m, arr, col, steps, m - 1);
    }

    printf("Matrix after column down rotation:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int options = -1;
    int m, n;
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);
    int arr[m][10];  // Assume max columns <= 10 for general use

    while (options != 6) {
        printf("\nMenu:\n");
        printf("0 - Take Input\n");
        printf("1 - Row Left Rotation\n");
        printf("2 - Row Right Rotation\n");
        printf("3 - Column Up Rotation\n");
        printf("4 - Column Down Rotation\n");
        printf("5 - for rotating 90\n");
        printf("6 - for exiting\n");
        printf("Choose an option: ");
        scanf("%d", &options);

        switch (options) {
            case 0:
                takeInput(m, n, arr);
                break;
            case 1:
                rowLeft(m, n, arr);
                break;
            case 2:
                rowRight(m, n, arr);
                break;
            case 3:
                columnUp(m, n, arr);
                break;
            case 4:
                columnDown(m, n, arr);
                break;
            case 5:
                rotate90(m,n,arr);
            case 6:
                return 0;
            default:
                printf("Invalid input! Please choose a valid option.\n");
        }
    }
    return 0;
}
