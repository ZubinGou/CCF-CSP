#include <stdio.h>

const int MAX_N = 1e6 + 50;
int ax[MAX_N], ay[MAX_N];
int bx[MAX_N], by[MAX_N];

int main() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < a; i++) 
        scanf("%d%d", &ax[i], &ay[i]);
    for (int i = 0; i < b; i++)
        scanf("%d%d", &bx[i], &by[i]);
    
    int i = 0, j = 0;
    long long res = 0;
    while (i < a && j < b) {
        if (ax[i] == bx[j]) {
            res += ay[i] * by[j];
            i++;
            j++;
        }
        else if (ax[i] > bx[j])
            j++;
        else
            i++;
    }
    printf("%lld\n", res);
    return 0;
}