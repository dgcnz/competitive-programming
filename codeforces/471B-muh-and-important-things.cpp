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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    map<int, vi> num;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        num[x].push_back(i + 1);
    }

    int        cnt = 0;
    vector<vi> ans(3);
    for (auto [k, v] : num)
    {
        if (v.size() == 1)
            for (int ix = 0; ix < 3; ++ix)
                ans[ix].push_back(v.back());
        else
        {
            ans[0].insert(ans[0].end(), all(v));
            next_permutation(all(v));
            ans[1].insert(ans[1].end(), all(v));
            next_permutation(all(v));
            ans[2].insert(ans[2].end(), all(v));

            swap(ans[0], ans[1]);
            cnt += v.size();
        }
    }
    if (cnt >= 3)
    {
        cout << "YES" << endl;
        for (auto x : ans)
            write(all(x), " "), cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
