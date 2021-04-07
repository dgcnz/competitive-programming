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

pair<string, string> solve(string s)
{
    auto is_zero = [](char c) { return c == '0'; };
    int  zeros   = count_if(all(s), is_zero);

    if (s.front() == '0' or s.back() == '0' or zeros % 2)
        return {"", ""};

    int    n = s.size(), open_ones = (n - zeros - 2) / 2, open_zero = 0;
    string a(n, ' '), b(n, ' ');
    a.front() = b.front() = '(';
    a.back() = b.back() = ')';
    for (int i = 1; i < n - 1; ++i)
    {
        if (s[i] == '1')
            a[i] = b[i] = open_ones > 0 ? '(' : ')', open_ones--;
        else
        {
            a[i]      = open_zero ? '(' : ')';
            b[i]      = open_zero ? ')' : '(';
            open_zero = 1 - open_zero;
        }
    }
    return {a, b};
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int    n;
        string s;
        cin >> n >> s;
        if (auto [a, b] = solve(s); not a.empty())
        {
            cout << "YES" << endl;
            cout << a << endl;
            cout << b << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
