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

bool solve(int n)
{
    string x = to_string(n);
    if (is_palindrome(x))
        return true;
    int m = x.size(), zeros = 0;
    while (m - zeros >= 1 and x[m - zeros - 1] == '0')
        zeros++;

    x = string(zeros, '0') + x;
    return is_palindrome(x);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    cout << (solve(n) ? "Yes" : "No") << endl;
    return 0;
}
