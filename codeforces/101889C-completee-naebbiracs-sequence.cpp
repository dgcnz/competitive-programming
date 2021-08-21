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

string solve(vi s, int k)
{
    int         n = s.size();
    vector<int> cnt(k, 0);
    for (auto si : s)
        cnt[si]++;
    for (int i = 1; i <= n; ++i)
    {
        vector<int> neg, pos;
        bool        ok = [&] {
            for (int x = 0; x < k; ++x)
            {
                if (abs(cnt[x] - i) > 1)
                    return false;
                else if (cnt[x] > i)
                    neg.push_back(x);
                else if (cnt[x] < i)
                    pos.push_back(x);
            }
            return true;
        }();

        if (ok and neg.size() <= 1 and pos.size() <= 1)
        {
            string ans;
            if (neg.size())
                ans += "-" + to_string(neg.front() + 1);
            if (neg.size() and pos.size())
                ans += " ";
            if (pos.size())
                ans += "+" + to_string(pos.front() + 1);
            return ans;
        }
    }
    return "*";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int k, n;
    cin >> k >> n;

    vi s(n);
    read(all(s));
    decrement(all(s));
    cout << solve(s, k) << endl;

    return 0;
}
