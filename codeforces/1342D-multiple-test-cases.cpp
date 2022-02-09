#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/divide_conquer/binary_search>
#include <cplib/math/misc>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#include <cplib/utils/number_iterator>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> m(n), c(k);
    read(all(m));
    read(all(c));
    decrement(all(m));

    vector<int> cnt(k, 0);
    for (auto mi : m)
        cnt[mi]++;

    int n_groups = 0;
    for (int i = k - 1; i >= 0; --i)
    {
        if (i < k - 1)
            cnt[i] += cnt[i + 1];
        n_groups = max(n_groups, integer::ceil(cnt[i], c[i]));
    }

    sort(all(m), greater<int>());
    vector<vector<int>> groups(n_groups);
    for (int i = 0; i < n; ++i)
        groups[i % n_groups].push_back(m[i] + 1);

    cout << groups.size() << endl;
    for (auto group : groups)
    {
        cout << group.size() << " ";
        write(all(group), " "), cout << endl;
    }

    return 0;
}
