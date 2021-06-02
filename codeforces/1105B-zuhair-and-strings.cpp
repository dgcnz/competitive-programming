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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    map<char, int> freq;
    int            cnt  = 0;
    char           prev = s.front();
    for (auto c : s)
    {
        if (c != prev)
            cnt = 1;
        else
            cnt++;
        if (cnt == k)
        {
            cnt = 0;
            freq[c]++;
        }
        prev = c;
    }
    int ans = 0;
    for (auto [c, m] : freq)
        ans = max(ans, m);
    cout << ans << endl;
    return 0;
}
