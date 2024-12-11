#include <stdio.h>

void addALLItem(int arr[100][100], int n, int m) {
	int i;
    for (i = 0; i < n; i++) {
    	int j;
        for (j = 0; j < m; j++) {
            printf("Phan tu thu arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void showItems(int arr[100][100], int n, int m) {
    printf("Ma tran:\n");
    int i;
    for (i = 0; i < n; i++) {
    	int j;
        for (j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void printCorners(int arr[100][100], int n, int m) {
    printf("Cac phan tu o goc:\n");
    printf("%d %d\n", arr[0][0], arr[0][m - 1]);
    printf("%d %d\n", arr[n - 1][0], arr[n - 1][m - 1]);
}

void printEdges(int arr[100][100], int n, int m) {
    printf("Cac phan tu tren duong bien:\n");
    int i;
    for (i = 0; i < n; i++) {
    	int j;
        for (j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                printf("%d ", arr[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void printDiagonals(int arr[100][100], int n, int m) {
    printf("Cac phan tu tren duong cheo chinh va cheo phu:\n");
    int i;
    for (i = 0; i < n; i++) {
    	int j;
        for (j = 0; j < m; j++) {
            if (i == j || i + j == n - 1) {
                printf("%d ", arr[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int laSoNguyenTo(int n) {
    if (n < 2) return 0;
    int i;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void printPrimes(int arr[100][100], int n, int m) {
    printf("Cac phan tu la so nguyen to:\n");
    int i;
    for (i = 0; i < n; i++) {
    	int j;
        for (j = 0; j < m; j++) {
            if (laSoNguyenTo(arr[i][j])) {
                printf("%d ", arr[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    int arr[100][100];
    int n, m;
    int choose;

    printf("Nhap so hang n: ");
    scanf("%d", &n);
    printf("Nhap so cot m: ");
    scanf("%d", &m);

    do {
        printf("\nMENU:\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu o goc theo ma tran\n");
        printf("4. In ra cac phan tu tren duong bien theo ma tran\n");
        printf("5. In ra cac phan tu tren duong cheo chinh va cheo phu theo ma tran\n");
        printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
        printf("7. Thoat\n");
        printf("Moi ban chon: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                addALLItem(arr, n, m);
                break;

            case 2:
                showItems(arr, n, m);
                break;

            case 3:
                printCorners(arr, n, m);
                break;

            case 4:
                printEdges(arr, n, m);
                break;

            case 5:
                printDiagonals(arr, n, m);
                break;

            case 6:
                printPrimes(arr, n, m);
                break;

            case 7:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choose != 7);

    return 0;
}

