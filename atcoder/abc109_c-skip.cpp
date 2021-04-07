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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    ll  X;
    cin >> n >> X;

    ll g = 0;
    for (int i = 0; i < n; ++i)
    {
        ll xi;
        cin >> xi;
        g = gcd(g, X - xi);
    }
    cout << g << endl;
    return 0;
}
