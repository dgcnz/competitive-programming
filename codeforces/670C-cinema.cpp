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

int solve(vi a, vi b, vi c)
{
    map<int, int> cnt;
    for (auto ai : a)
        cnt[ai]++;

    int        m = b.size();
    vector<ii> ans(m);
    for (int i = 0; i < m; ++i)
        ans[i] = {cnt[b[i]], cnt[c[i]]};

    return distance(ans.begin(), max_element(all(ans))) + 1;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &ai : a)
        cin >> ai;

    int m;
    cin >> m;
    vector<int> b(m), c(m);
    for (auto &bi : b)
        cin >> bi;
    for (auto &ci : c)
        cin >> ci;

    cout << solve(a, b, c) << endl;
    return 0;
}
