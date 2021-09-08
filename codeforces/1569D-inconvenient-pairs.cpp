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

inline ll C2(ll n) { return (n * (n - 1)) / 2; }

ll solve(vi hor, vi ver, vector<ii> people)
{
    auto cmp_ver = [](ii a, ii b) { return a < b; };
    auto cmp_hor = [](ii a, ii b)
    {
        swap(a.first, a.second), swap(b.first, b.second);
        return a < b;
    };

    sort(all(people), cmp_ver);
    ll ans = 0;
    int n = ver.size(), m = hor.size(), k = people.size();
    for (int i = 1, l = 0; i < m; ++i)
    {
        int up = hor[i - 1], down = hor[i];

        while (l < k and people[l].first == up)
            ++l;

        int           r = l;
        map<int, int> cnt;
        int           total = 0;
        while (r < k and people[r].first < down)
        {
            ++cnt[people[r].second];
            ++total;
            ++r;
        }

        ll cur = C2(total);
        for (auto [_, val] : cnt)
            cur -= C2(val);

        ans += cur;
        l = r;
    }

    sort(all(people), cmp_hor);

    for (int i = 1, l = 0; i < n; ++i)
    {
        int up = ver[i - 1], down = ver[i];

        while (l < k and people[l].second == up)
            ++l;

        int           r = l;
        map<int, int> cnt;
        int           total = 0;
        while (r < k and people[r].second < down)
        {
            ++cnt[people[r].first];
            ++total;
            ++r;
        }

        ll cur = C2(total);
        for (auto [_, val] : cnt)
            cur -= C2(val);

        ans += cur;
        l = r;
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
        int n, m, k;
        cin >> n >> m >> k;
        vi ver(n), hor(m);
        read(all(ver));
        read(all(hor));
        vector<ii> people(k);
        for (auto &[r, c] : people)
            cin >> r >> c;

        cout << solve(ver, hor, people) << endl;
    }
    return 0;
}
