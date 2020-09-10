#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
using vi = vector<ll>;

ll         n, T, a, b;
vector<ii> time_cost;

ll get_extra(ll window, ll easy_left, ll hard_left)
{
    auto temp_extra = min(window / a, easy_left), extra = temp_extra;
    window -= a * temp_extra;

    temp_extra = min(window / b, hard_left), extra += temp_extra;
    window -= b * temp_extra;

    return extra;
}

int solve(void)
{
    ll ans(0), acc_cost(0), taken_prev = 0;
    ll easy_left =
        count_if(all(time_cost), [](ii tc) { return tc.second == a; });
    ll hard_left =
        count_if(all(time_cost), [](ii tc) { return tc.second == b; });

    sort(all(time_cost)); // sorted by starting time
    time_cost.emplace_back(T + 1, a);
    for (auto [t, c] : time_cost)
    {
        ll new_acc_cost = acc_cost + c, cur = 0;
        taken_prev = n - (easy_left + hard_left);

        if (acc_cost < t)
            cur = max(cur,
                      taken_prev + get_extra(max((t - 1) - acc_cost, 0LL),
                                             easy_left,
                                             hard_left));
        if (c == a)
            easy_left--;
        else
            hard_left--;
        acc_cost = new_acc_cost;
        ans      = max(ans, cur);
    }

    return ans;
}

int main(void)
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        cin >> n >> T >> a >> b;
        time_cost.resize(n);
        for (auto &[t, c] : time_cost)
            cin >> c, c = (c ? b : a);
        for (auto &[t, c] : time_cost)
            cin >> t;

        cout << solve() << endl;
    }
    return 0;
}
