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

pair<int, vector<ii>> solve(int n)
{
    int        m = (n + 2) / 2;
    vector<ii> points;
    for (int i = 0; i < m; ++i)
        points.emplace_back(i, 0);
    for (int i = 1; i < m; ++i)
        points.emplace_back(m - 1, i);
    points.resize(n);
    return {m, points};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    auto [m, ans] = solve(n);
    cout << m << endl;
    for (auto [r, c] : ans)
        cout << r + 1 << " " << c + 1 << endl;
    return 0;
}
