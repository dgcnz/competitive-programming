#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll  = long long;
using ii  = pair<int, int>;
using vi  = vector<int>;
using pll = pair<ll, ll>;

pll solve(vector<ll> a)
{
    int n = a.size();

    set<int> adj_diff[2];
    for (int i = 1; i < n; ++i)
    {
        int diff = a[i] - a[i - 1];
        adj_diff[diff >= 0].insert(diff);
    }

    if (adj_diff[0].size() > 1 or adj_diff[1].size() > 1)
        return {-1, -1};

    if (adj_diff[1].size() == 0 or adj_diff[0].size() == 0)
        return {0, 0};

    ll c = *adj_diff[1].begin();
    ll m = abs(*adj_diff[0].begin() - c);

    if (c == 0 or m <= *max_element(all(a)))
        return {-1, -1};

    return {m, c};
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
        vector<ll> a(n);
        for (auto &ai : a)
            cin >> ai;

        auto [m, c] = solve(a);
        cout << m;
        if (m > 0)
            cout << " " << c;
        cout << endl;
    }
    return 0;
}
