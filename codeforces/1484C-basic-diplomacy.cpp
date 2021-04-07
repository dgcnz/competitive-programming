#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

vi solve(vector<vi> friends, vector<vi> rev_friends)
{
    int         n = rev_friends.size(), m = friends.size();
    auto        cmp  = [](vi &v1, vi &v2) { return v1.size() < v2.size(); };
    auto        it   = max_element(all(rev_friends), cmp);
    int         fmax = distance(begin(rev_friends), it), maxcnt = it->size();
    vector<int> ans(m, -1);

    for (auto i : rev_friends[fmax])
        ans[i] = fmax;

    for (int i = 0; i < m; ++i)
    {
        if (ans[i] == -1)
            ans[i] = friends[i].front();
        else if ((friends[i].size() > 1 and maxcnt > (m + 1) / 2))
        {
            maxcnt--;
            ans[i] = friends[i].front() == fmax ? friends[i].back()
                                                : friends[i].front();
        }
    }

    vector<int> cnt(n, 0);
    for (int i = 0; i < m; ++i)
        cnt[ans[i]]++;

    return (*max_element(all(cnt)) <= (m + 1) / 2 ? ans : vi(m, -1));
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vi> friends(m), rev_friends(n);
        for (int i = 0; i < m; ++i)
        {
            int ki;
            cin >> ki;
            while (ki--)
            {
                int f;
                cin >> f, f--;
                friends[i].push_back(f);
                rev_friends[f].push_back(i);
            }
        }

        auto ans = solve(friends, rev_friends);
        if (ans.front() == -1)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for (auto x : ans)
                cout << x + 1 << " ";
            cout << endl;
        }
    }
    return 0;
}
