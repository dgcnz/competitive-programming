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
    int    n;
    string s;
    cin >> n >> s;

    int ones = 0, zeros = 0;
    for (auto c : s)
    {
        if (c == '1')
            ones++;
        else
            zeros++;
    }

    if (ones)
        cout << 1;
    while (zeros--)
        cout << 0;
    return 0;
}
