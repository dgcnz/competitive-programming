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

ll solve(vi a)
{
    set<int, greater<int>> unique;
    for (auto ai : a)
        if (ai % 2 == 0)
            unique.insert(ai);

    ll ans = 0;
    while (!unique.empty())
    {
        auto it = unique.begin();
        if ((*it / 2) % 2 == 0)
            unique.insert(*it / 2);
        ++ans;
        unique.erase(it);
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
        int n;
        cin >> n;
        vi a(n);
        read(all(a));

        cout << solve(a) << endl;
    }
    return 0;
}
