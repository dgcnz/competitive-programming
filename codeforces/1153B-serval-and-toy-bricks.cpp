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

vector<vi> solve(vi a, vi b, vector<vi> c, [[maybe_unused]] int h)
{
    int        m = a.size(), n = b.size();
    vector<vi> ans(n, vi(m));
    for (int j = 0; j < n; ++j)
        for (int i = 0; i < m; ++i)
            ans[j][i] = c[j][i] ? min(a[i], b[j]) : 0;
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m, h;
    cin >> n >> m >> h;

    vi a(m), b(n);
    read(all(a)), read(all(b));

    vector<vi> c(n, vi(m));
    for (auto &ci : c)
        read(all(ci));

    auto ans = solve(a, b, c, h);
    for (auto &row : ans)
        write(all(row), " "), cout << endl;
    return 0;
}
