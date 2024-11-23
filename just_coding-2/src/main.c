#include <stdio.h>
#include "./calc_sum.h"
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int result = calc_sum(a, b);
    printf("%d\n", result);
}