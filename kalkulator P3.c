#include <stdio.h>
int cariFPB(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int cariKPK(int a, int b) {
    return (a * b) / cariFPB(a, b);
}
int faktorial(int n) {
    int hasil = 1;
    for (int i = 1; i <= n; i++) {
        hasil *= i;
    }
    return hasil;
}
int main() {
    float angka1, angka2;
    char operator;
    char lanjutkan;
    do {
        printf("\nMasukkan operasi (contoh: '3 + 5' untuk KABATAKU, '5 !' untuk Faktorial, '12 f 8' untuk FPB, '12 k 8'untuk KPK): ");
        scanf("%f %c", &angka1, &operator);
        if (operator == '!') {
            if (angka1 == (int)angka1 && angka1 >= 0) {
                int hasil = faktorial((int)angka1);
                printf("Hasil faktorial dari %.0f adalah %d\n", angka1, hasil);
            } else {
                printf("Faktorial hanya bisa untuk bilangan bulat positif!\n");
            }
        } else {
            scanf("%f", &angka2);
            if (operator == '+') {
                printf("Hasil: %.2f\n", angka1 + angka2);
            } else if (operator == '-') {
                printf("Hasil: %.2f\n", angka1 - angka2);
            } else if (operator == '*') {
                printf("Hasil: %.2f\n", angka1 * angka2);
            } else if (operator == '/') {
                if (angka2 != 0) {
                    printf("Hasil: %.2f\n", angka1 / angka2);
                } else {
                    printf("Error: Pembagian dengan nol tidak diperbolehkan!\n");
                }
            } else if (operator == 'f') {
                if (angka1 == (int)angka1 && angka2 == (int)angka2) {
                    int hasil = cariFPB((int)angka1, (int)angka2);
                    printf("FPB dari %.0f dan %.0f adalah %d\n", angka1, angka2, hasil);
                } else {
                    printf("FPB hanya untuk bilangan bulat!\n");
                }
            } else if (operator == 'k') {
                if (angka1 == (int)angka1 && angka2 == (int)angka2) {
                    int hasil = cariKPK((int)angka1, (int)angka2);
                    printf("KPK dari %.0f dan %.0f adalah %d\n", angka1, angka2, hasil);
                } else {
                    printf("KPK hanya untuk bilangan bulat!\n");
                }
            } else {
                printf("Operator tidak ada!\n");
            }
        }

        printf("Apakah anda ingin melanjutkan? (y/n): ");
        scanf(" %c", &lanjutkan);
    } while (lanjutkan == 'y' || lanjutkan == 'Y');

    return 0;
}
