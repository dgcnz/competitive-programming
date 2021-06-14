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

string solve(vector<ll> h)
{
    int n = h.size();
    for (int i = 0; i < n - 1; ++i)
    {
        if (h[i] < i)
            return "NO";
        h[i + 1] += (h[i] - i);
        h[i] = i;
    }
    return (h[n - 1] >= n - 1 ? "YES" : "NO");
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> h(n);
        read(all(h));
        cout << solve(h) << endl;
    }
    return 0;
}
