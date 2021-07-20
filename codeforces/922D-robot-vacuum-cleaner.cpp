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

ll score(vector<string> s)
{
    int scnt = 0;
    ll  ans  = 0;
    for (auto &si : s)
    {
        for (auto &sij : si)
        {
            if (sij == 's')
                scnt++;
            else
                ans += scnt;
        }
    }
    return ans;
}

ll solve(vector<string> &s)
{
    auto cmp = [](string &a, string &b)
    { return score({a + b}) > score({b + a}); };
    sort(all(s), cmp);
    return score(s);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> s(n);
    read(all(s));

    cout << solve(s) << endl;
    return 0;
}
