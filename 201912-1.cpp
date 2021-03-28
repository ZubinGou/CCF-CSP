#include <iostream>
#include <vector>

using namespace std;

bool has_seven(int num) {
    while (num) {
        if (num % 10 == 7)
            return true;
        num /= 10;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int i = 0, count = 0, j = 0;
    vector<int> res(4, 0);
    while (count < n) {
        if (++i % 7 == 0 || has_seven(i))
            res[j]++;
        else {
            count++;
        }
        j = (++j) % 4;
    }
    for (auto x : res)
        cout << x << endl;
    return 0;
}