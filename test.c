#include <stdio.h>
#define TEST
typedef long TYP;
TYP licz_silnia(TYP podstawa) {
    TYP silnia = 1;
    TYP i;
    for (i = 1; i <= podstawa; ++i) {
        silnia *= i;
    }
    return silnia;
}
#ifdef TEST
void nd(int licznik) { printf("Test nr %i nie działa\n", licznik); }
// tutaj należy umieszczać kolejne testy
void test_1_licz_silnia(int licznik) {
    if (licz_silnia(0) != 1) nd(licznik);
}
void test_2_licz_silnia(int licznik) {
    if (licz_silnia(1) != 1) nd(licznik);
}
void test_3_licz_silnia(int licznik) {
    if (licz_silnia(2) != 2) nd(licznik);
}
void test_4_licz_silnia(int licznik) {
    if (licz_silnia(5) != 120) nd(licznik);
}
void test_5_licz_silnia(int licznik) {
    if (licz_silnia(15) != 1307674368000) nd(licznik);
}
void run_test_pool() {
    int licznik = 0;
// tutaj wywołujemy testy
    test_1_licz_silnia(++licznik);
    test_2_licz_silnia(++licznik);
    test_3_licz_silnia(++licznik);
    test_4_licz_silnia(++licznik);
    test_5_licz_silnia(++licznik);
}
#endif
int main() {
#ifndef TEST
    TYP podstawa;
    // uruchom program
    printf("Program liczy silnie dla podanej liczby całkowitej.\n");
    printf("Podaj liczbę do obliczenia silni z zakresu 0-15: ");
    scanf(" %ld", &podstawa);
    if (podstawa >= 0 && podstawa <= 15) {
        printf("Silnia(%ld) = %ld", podstawa, licz_silnia(podstawa));
    } else {
        printf("Podana liczba jest spoza zakresu!\n");
    }
#else
    // uruchom testy
    run_test_pool();
#endif
    return 0;
}