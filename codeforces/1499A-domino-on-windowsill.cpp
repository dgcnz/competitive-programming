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

bool solve(int n, int k1, int k2, int w, int b)
{
    int offset = abs(k1 - k2);
    w -= (offset / 2);
    b -= (offset / 2);
    w -= min(k1, k2);
    b -= (n - max(k1, k2));
    return w <= 0 and b <= 0;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k1, k2, w, b;
        cin >> n >> k1 >> k2 >> w >> b;
        cout << (solve(n, k1, k2, w, b) ? "YES" : "NO") << endl;
    }
    return 0;
}
