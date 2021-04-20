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

ll solve(vector<ii> candidates, int m)
{
    vector<vi> skill_candidates(m);
    for (auto [s, r] : candidates)
        skill_candidates[s].push_back(r);
    for (auto &c : skill_candidates)
        sort(all(c), greater<int>());
    auto by_size = [](auto &v1, auto &v2) { return v1.size() > v2.size(); };
    sort(all(skill_candidates), by_size);

    int        mx_size = skill_candidates.front().size();
    vector<ll> sum(m, 0);
    ll         ans = 0;
    for (int k = 1; k <= mx_size; ++k)
    {
        int i   = 0;
        ll  cur = 0;
        while (i < m and (int) skill_candidates[i].size() >= k)
        {
            sum[i] += skill_candidates[i][k - 1];
            if (sum[i] > 0)
                cur += sum[i];
            i += 1;
        }
        ans = max(ans, cur);
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<ii> candidates(n);
    for (auto &[s, r] : candidates)
        cin >> s >> r, s--;

    cout << solve(candidates, m) << endl;
    return 0;
}
