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

vi solve(vi h, int m)
{
    int        n = h.size();
    vector<ii> sh(n);
    for (int i = 0; i < n; ++i)
        sh[i] = {h[i], i};
    sort(all(sh), greater<ii>());

    vi   ans(n);
    auto ix = [m](int i) {
        bool fwd = (i / m) % 2;
        if (fwd)
            return i % m;
        else
            return (m - 1 - (i % m));
    };
    for (int i = 0; i < n; ++i)
    {
        auto [h, j] = sh[i];
        ans[j]      = ix(i);
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m >> x;
        vi h(n);
        read(all(h));
        auto ans = solve(h, m);
        cout << "YES" << endl;
        transform(all(ans), begin(ans), [](int y) { return y + 1; });
        write(all(ans), " "), cout << endl;
    }
    return 0;
}
