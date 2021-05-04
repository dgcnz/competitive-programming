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
using i5 = array<int, 5>;

int solve(vector<i5> people)
{
    int       n               = people.size();
    int const INF             = 2e9;
    auto      strength_select = [](i5 p, int mask) {
        int ans = INF;
        for (int i = 0; i < 5; ++i)
            if ((mask & (1 << i)))
                ans = min(ans, p[i]);
        return ans == INF ? 0 : ans;
    };

    int ans = 0;
    for (int m0 = 0; m0 < (1 << 5); ++m0)
    {
        int s0 = 0;
        for (int i = 0; i < n; ++i)
            s0 = max(s0, strength_select(people[i], m0));
        for (int m1 = 0; m1 < (1 << 5); ++m1)
        {
            if (m0 & m1)
                continue;

            int s1 = 0;
            for (int i = 0; i < n; ++i)
                s1 = max(s1, strength_select(people[i], m1));

            for (int m2 = 0; m2 < (1 << 5); ++m2)
            {
                if (m0 & m2 or m1 & m2 or (m0 | m1 | m2) != (1 << 5) - 1)
                    continue;

                int s2 = 0;
                for (int i = 0; i < n; ++i)
                    s2 = max(s2, strength_select(people[i], m2));

                ans = max(ans, min({s0, s1, s2}));
            }
        }
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<i5> people(n);
    for (auto &[a, b, c, d, e] : people)
        cin >> a >> b >> c >> d >> e;

    cout << solve(people) << endl;
    return 0;
}
