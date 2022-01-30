#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

string solve(string a)
{

    int  n           = a.size();
    auto make_int    = [](char c) { return int(c - '0'); };
    auto make_answer = [&](int i)
    {
        string ans;
        if (i != 0)
            ans += string(a.begin(), a.begin() + i);
        ans += to_string(make_int(a[i]) + make_int(a[i + 1]));
        if (i != n - 2)
            ans += string(a.begin() + i + 2, a.end());
        return ans;
    };
    for (int i = n - 2; i >= 0; --i)
    {
        int x = make_int(a[i]), y = make_int(a[i + 1]);
        if (x + y >= 10)
            return make_answer(i);
    }
    return make_answer(0);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        cout << solve(a) << endl;
    }
    return 0;
}
