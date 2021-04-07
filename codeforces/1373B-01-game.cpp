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

bool solve(string s)
{
    int  n       = s.size();
    auto is_zero = [](char c) { return c == '0'; };
    int  zeros   = count_if(all(s), is_zero);
    int  moves   = min(zeros, n - zeros);

    return moves % 2;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;

    string ans[2] = {"NET", "DA"};
    while (t--)
    {
        string s;
        cin >> s;
        cout << ans[solve(s)] << endl;
    }
    return 0;
}
