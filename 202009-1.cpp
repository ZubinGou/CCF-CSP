#include <stdio.h>
#include <algorithm>

#define MAX_N 250
using namespace std;

pair<int, int> p[MAX_N];

int main()
{
    int n, x, y, a, b;

    scanf("%d%d%d", &n, &x, &y);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        p[i] = make_pair((x-a) * (x-a) + (y-b) * (y - b), i + 1);

    }
    sort(p, p + n);
    printf("%d\n%d\n%d\n", p[0].second, p[1].second, p[2].second);
    return 0;
}