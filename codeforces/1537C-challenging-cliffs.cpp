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
using ll  = long long;
using ii  = pair<int, int>;
using iii = tuple<int, int, int>;
using vi  = vector<int>;

vector<int> solve(vector<int> h)
{
    int       n   = h.size();
    int const INF = 2e9;
    sort(all(h));

    ii ans = {INF, 0};
    for (int i = 1; i < n; ++i)
    {
        ii cur = {abs(h[i - 1] - h[i]), i};
        ans    = min(ans, cur);
    }

    auto [d, ix] = ans;
    vi x;
    x.reserve(n);
    x.push_back(h[ix - 1]);
    for (int i = ix + 1; i < n; ++i)
        x.push_back(h[i]);
    for (int i = 0; i < ix - 1; ++i)
        x.push_back(h[i]);
    x.push_back(h[ix]);
    return x;
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
        vector<int> h(n);
        read(all(h));
        auto ans = solve(h);
        write(all(ans), " "), cout << endl;
    }
    return 0;
}
