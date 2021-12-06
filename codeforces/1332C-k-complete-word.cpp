#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int iceil(int a, int b) { return (a + b - 1) / b; }

int solve(string s, int k)
{
    int n = s.size(), nblocks = n / k;

    int ans = 0;
    for (int i = 0; i < iceil(k, 2); ++i)
    {
        vi  cnt(26, 0);
        int num = 0;
        for (int j = 0; j < nblocks; ++j)
        {
            int c1 = s[j * k + i] - 'a', c2 = s[j * k + k - i - 1] - 'a';
            cnt[c1]++;
            num++;
            if (not(k % 2 and i == k / 2))
                cnt[c2]++, num++;
        }

        auto it = max_element(all(cnt));
        ans += num - *it;
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
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        cout << solve(s, k) << endl;
        ;
    }
    return 0;
}
