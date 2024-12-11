#include <stdio.h>

void taoMaTran(int cow, int row, int maTran[100][100]) {
    printf("Nhap cac phan tu cua ma tran:\n");
    int i;
    for (i = 0; i < cow; i++) {
    	int j;
        for (j = 0; j < row; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &maTran[i][j]);
        }
    }
}
void inMaTran(int cow, int row, int maTran[100][100]) {
	int i;
    for (i = 0; i < cow; i++) {
    	int j;
        for (j = 0; j < row; j++) {
            printf("%d ", maTran[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int cow, row;
    int maTran[100][100]; 

    printf("Nhap so hang: ");
    scanf("%d", &cow);
    printf("Nhap so cot: ");
    scanf("%d", &row);

    taoMaTran(cow, row, maTran);

    inMaTran(cow, row, maTran);

    return 0;
}

