#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(ll n)
{
    while (n % 2 == 0)
        n /= 2;

    return n;
}

int main(void)
{
    ll n;

    cin >> n;

    cout << solve(n) << endl;

    return 0;
}
