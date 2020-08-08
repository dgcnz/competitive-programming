#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void)
{
    ll n;
    cin >> n;

    ll d0 = 1;
    for (int i = 1, m = sqrt(n); i <= m; ++i)
    {
        if (n % i == 0)
        {
            d0 = i;
        }
    }

    cout << d0 + n / d0 - 2 << endl;
    return 0;
}
