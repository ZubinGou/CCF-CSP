#include <cstdio>
using namespace std;

int x1, y11, x2, y2;

bool in_risk(int x, int y) {
    return x >= x1 && x <= x2 && y >= y11 && y <= y2;
}

int main() {
    int n, k, t;
    scanf("%d%d%d%d%d%d%d", &n, &k, &t, &x1, &y11, &x2, &y2);
    int x, y, conti;
    bool passed, stayed;
    int count_pass = 0, count_stay = 0;
    for (int i = 0; i < n; i++) {
        passed = stayed = false;
        conti = 0;
        for (int j = 0; j < t; j++) {
            scanf("%d%d", &x, &y);
            if (in_risk(x, y)) {
                conti++;
                passed = true;
                if (conti >= k)
                    stayed = true;
            } else {
                conti = 0;
            }
        }
        if (passed)
            count_pass++;
        if (stayed)
            count_stay++;
    }
    printf("%d\n%d", count_pass, count_stay);
    return 0;
}