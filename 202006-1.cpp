#include <iostream>
const int MAX_N = 1e4 + 50;

using namespace std;
int x[MAX_N], y[MAX_N];
char s[MAX_N];

int get_sign(int x) {
    return x > 0 ? 1 : -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> s[i];
    }

    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        int sign = get_sign(a + b * x[0] + c * y[0]);
        int i;
        for (i = 1; i < n; i++) {
            if (s[i] == s[i-1]) {
                if (sign != get_sign(a + b * x[i] + c * y[i])) 
                    break;
            }
            if (s[i] != s[i-1]) {
                if (sign == get_sign(a + b * x[i] + c * y[i])) 
                    break;
                else {
                    sign = -sign;
                }
            }
        }
        if (i == n)
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }
    return 0;
}