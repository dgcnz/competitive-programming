#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/string/z_function>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

string solve(string s, int k)
{
    int  n = s.size();
    auto z = z_function(s);
    for (int i = 1; i < n; ++i)
    {
        int j = i + z[i];
        if (j == n or s[j] > s[z[i]])
        {
            s.resize(i);
            break;
        }
    }
    n = s.size();
    string ans(k, ' ');
    for (int i = 0; i < k; ++i)
        ans[i] = s[i % n];
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    cout << solve(s, k) << endl;
    return 0;
}
