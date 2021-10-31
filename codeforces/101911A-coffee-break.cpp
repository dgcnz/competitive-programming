#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
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
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> a(n);
    read(all(a));

    map<int, int> id;
    for (int i = 0; i < n; ++i)
        id[a[i]] = i;

    set<int> b(all(a));

    vector<int> ans(n);
    int         day = 1;
    while (not b.empty())
    {
        auto it = b.begin();
        while (it != b.end())
        {
            int x = *it;
            b.erase(it);
            ans[id[x]] = day;
            it         = b.upper_bound(d + x);
        }
        day++;
    }
    cout << day - 1 << endl;
    write(all(ans), " "), cout << endl;
    return 0;
}
