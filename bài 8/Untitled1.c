#include <stdio.h>

int timUCLN(int num1, int num2) {
    while (num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

int main() {
    int a, b;

    printf("Nhap so thu nhat: ");
    scanf("%d", &a);
    printf("Nhap so thu hai: ");
    scanf("%d", &b);

    int ucln = timUCLN(a, b);

    printf("UCLN cua %d và %d là: %d\n", a, b, ucln);

    return 0;
}

