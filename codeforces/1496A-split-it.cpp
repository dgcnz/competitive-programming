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

bool is_palindrome(string s) { return s == string(s.rbegin(), s.rend()); }

bool solve(string s, int k)
{
    return 2 * k != (int)s.size() and
           (k == 0 or is_palindrome(string(s.begin(), s.begin() + k) +
                                    string(s.end() - k, s.end())));
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int    n, k;
        string s;
        cin >> n >> k >> s;
        cout << (solve(s, k) ? "YES" : "NO") << endl;
    }
    return 0;
}
