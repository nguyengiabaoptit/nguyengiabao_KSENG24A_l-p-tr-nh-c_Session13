#include <stdio.h>
#define MAX 100

void nhapMang(int arr[], int *n) {
    printf("\nNhap so phan tu: ");
    scanf("%d", n);
    int i; 
    for (i = 0; i < *n; i++) {
        printf("Nhap gia tri phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void inMang(int arr[], int n) {
    printf("\nCac phan tu trong mang: ");
    int i; 
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int themPhanTu(int arr[], int *n, int pos, int value) {
    if (pos < 0 || pos > *n || *n >= MAX) {
        return 0; 
    }
    int i; 
    for (i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
    return 1; 
}

int suaPhanTu(int arr[], int n, int pos, int value) {
    if (pos < 0 || pos >= n) {
        return 0; 
    }
    arr[pos] = value;
    return 1; 
}

int xoaPhanTu(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        return 0; 
    }
    int i; 
    for (i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    return 1; 
}

void sapXep(int arr[], int n, int tangDan) {
	int i; 
    for (i = 0; i < n - 1; i++) {
    	int j; 
        for (j = i + 1; j < n; j++) {
            if ((tangDan && arr[i] > arr[j]) || (!tangDan && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int timTuyenTinh(int arr[], int n, int value) {
	int i; 
    for (i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int timNhiPhan(int arr[], int n, int value) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[MAX], n = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Tim kiem phan tu nhap vao\n");
        printf("8. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr, &n);
                break;

            case 2:
                inMang(arr, n);
                break;

            case 3: {
                int pos, value;
                printf("Nhap vi tri can them: ");
                scanf("%d", &pos);
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                if (themPhanTu(arr, &n, pos, value)) {
                    printf("Them thanh cong!\n");
                } else {
                    printf("Them that bai!\n");
                }
                break;
            }

            case 4: {
                int pos, value;
                printf("Nhap vi tri can sua: ");
                scanf("%d", &pos);
                printf("Nhap gia tri moi: ");
                scanf("%d", &value);
                if (suaPhanTu(arr, n, pos, value)) {
                    printf("Sua thanh cong!\n");
                } else {
                    printf("Sua that bai!\n");
                }
                break;
            }

            case 5: {
                int pos;
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);
                if (xoaPhanTu(arr, &n, pos)) {
                    printf("Xoa thanh cong!\n");
                } else {
                    printf("Xoa that bai!\n");
                }
                break;
            }

            case 6: {
                int subChoice;
                printf("\na. Giam dan\n");
                printf("b. Tang dan\n");
                printf("Lua chon: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) {
                    sapXep(arr, n, 0);
                } else {
                    sapXep(arr, n, 1);
                }
                printf("Sap xep thanh cong!\n");
                break;
            }

            case 7: {
                int subChoice, value;
                printf("\na. Tim kiem tuyen tinh\n");
                printf("b. Tim kiem nhi phan\n");
                printf("Lua chon: ");
                scanf("%d", &subChoice);
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);

                int result;
                if (subChoice == 1) {
                    result = timTuyenTinh(arr, n, value);
                } else {
                    sapXep(arr, n, 1); 
                    result = timNhiPhan(arr, n, value);
                }

                if (result != -1) {
                    printf("Tim thay tai vi tri %d!\n", result);
                } else {
                    printf("Khong tim thay!\n");
                }
                break;
            }

            case 8:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (choice != 8);

    return 0;
}

