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

ll ceil(ll a, ll b) { return (a + b - 1) / b; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    int n;
    ll  b(0), w(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int ai;
        cin >> ai;
        b += i % 2 == 0 ? ceil(ai, 2) : ai / 2;
        w += i % 2 == 1 ? ceil(ai, 2) : ai / 2;
    }
    cout << min(b, w) << endl;
    return 0;
}
