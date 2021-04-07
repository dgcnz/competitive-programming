#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

pair<ll, ll> solve(ll n)
{
    ll  three = 3, five = 5;
    int b = 1;
    while (n - five > 0)
        five *= 5, ++b;

    for (int a = 1; n - three > 0; ++a, three *= 3)
    {
        ll x = n - three;

        // first 5^b >= x
        while (b >= 1 and five >= x)
            b--, five /= 5;
        b++, five *= 5;

        if (x == five)
            return {a, b};
    }
    return {-1, -1};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll n;
    cin >> n;

    auto [a, b] = solve(n);
    if (a == -1)
        cout << -1 << endl;
    else
        cout << a << " " << b << endl;
    return 0;
}
