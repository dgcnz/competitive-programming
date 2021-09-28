#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    while (n--)
    {
        ll p, q, b;
        cin >> p >> q >> b;
        ll g = gcd(p, q);
        p /= g;
        q /= g;

        while (auto g = gcd(q, b))
        {
            if (g == 1)
                break;
            while (q % g == 0)
                q /= g;
        }
        if (q == 1)
            cout << "Finite" << endl;
        else
            cout << "Infinite" << endl;
    }
    return 0;
}
