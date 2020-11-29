#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int const MAX = 4e6;
    int       a = 1, b = 1, i = 3;
    long long ans = 0;

    while (a + b <= MAX)
    {
        a += b;
        if (i % 3 == 0)
            ans += a;
        swap(a, b);
        ++i;
    }
    cout << ans << endl;
    return 0;
}
