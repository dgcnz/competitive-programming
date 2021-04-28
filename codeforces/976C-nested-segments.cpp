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

ii solve(vector<tuple<int, int, int>> segments)
{

    int n = segments.size();

    auto cmp = [](iii a, iii b) {
        if (get<0>(a) == get<0>(b))
            return get<1>(a) > get<1>(b);
        return get<0>(a) < get<0>(b);
    };
    sort(all(segments), cmp);
    // vector<ii> maxr(n);
    // maxr[0] = {get<1>(segments[0]), get<2>(segments[0])};
    for (int ix = 1; ix < n; ++ix)
    {
        auto [l, r, i] = segments[ix];
        // auto [r2, j]   = maxr[ix - 1];
        auto [l2, r2, j] = segments[ix - 1];

        if (r <= r2)
            return {i, j};
        // maxr[i] = max(maxr[i - 1], {r, i});
    }
    return {-2, -2};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<tuple<int, int, int>> segments(n);
    for (int i = 0; i < n; ++i)
    {
        auto &[l, r, ix] = segments[i];
        cin >> l >> r;
        ix = i;
    }
    auto [i, j] = solve(segments);
    cout << i + 1 << " " << j + 1 << endl;
    return 0;
}
