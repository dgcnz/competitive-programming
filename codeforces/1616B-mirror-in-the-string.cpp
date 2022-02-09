#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/divide_conquer/binary_search>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#include <cplib/utils/number_iterator>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

string solve(string s)
{
    int  n        = s.size();
    auto make_ans = [&](int i)
    {
        string a(s.begin(), s.begin() + i + 1);
        string b(a.rbegin(), a.rend());
        return a + b;
    };

    int i = 1;
    while (i < n and s[i] <= s[i - 1])
        ++i;

    string ans = make_ans(0);
    ans        = min(ans, make_ans(i - 1));
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        cout << solve(s) << '\n';
    }
    return 0;
}
