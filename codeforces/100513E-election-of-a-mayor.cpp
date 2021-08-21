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

int veredict(int m, int r)
{
    if (m > r)
        return 0; // WIN
    if (m < r)
        return 1; // LOSE
    else
        return 2; // TIE
}

pair<bool, vector<ii>> solve(vector<ii> mr)
{
    int         n = mr.size();
    vector<int> res(3, 0);
    for (auto [m, r] : mr)
        res[veredict(m, r)]++;

    vector<ii> ans;
    int        k = max(0, res[1] + res[2] - res[0] + 1), cnt = 0, m = 0, r = 0;

    for (int i = 0; i < n; ++i)
    {
        if (k == 0)
            break;
        // if (veredict(mr[i].first, mr[i].second) == 2)
        // {
        //     cnt = 0, m = 0, r = 0;
        //     continue;
        // }
        cnt++;
        m += mr[i].first;
        r += mr[i].second;
        if (cnt == 2)
        {
            if (veredict(mr[i - 1].first, mr[i - 1].second) == 0 and
                veredict(mr[i].first, mr[i].second) == 0)
            {
                m   = mr[i].first;
                r   = mr[i].second;
                cnt = 1;
                continue;
            }

            if ((veredict(mr[i - 1].first, mr[i - 1].second) == 0 or
                 veredict(mr[i].first, mr[i].second) == 0) and
                m <= r)
            {
                m   = mr[i].first;
                r   = mr[i].second;
                cnt = 1;
                continue;
            }
            else
            {
                k--;
                ans.emplace_back(i - 1, i);
                m = r = cnt = 0;
            }
        }
    }

    return {!k, ans};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<ii> mr(n);
    for (auto &[m, r] : mr)
        cin >> m >> r;
    if (auto [ok, ans] = solve(mr); ok)
    {
        cout << ans.size() << endl;
        for (auto [i, j] : ans)
            cout << i + 1 << " " << j + 1 << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
