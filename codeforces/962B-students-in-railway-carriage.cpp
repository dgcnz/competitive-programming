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

int solve(string s, int a, int b)
{
    vi  blocks;
    int cnt = 0, total = a + b;
    for (auto c : s)
    {
        if (c == '.')
            cnt++;
        else
        {
            if (cnt)
                blocks.push_back(cnt);
            cnt = 0;
        }
    }
    if (cnt)
        blocks.push_back(cnt);

    ii choices = {a, b};
    for (auto len : blocks)
    {
        if (choices.first < choices.second)
            swap(choices.first, choices.second);
        choices.first -= (len + 1) / 2;
        choices.second -= len / 2;
        choices.first  = max(0, choices.first);
        choices.second = max(0, choices.second);
    }
    return total - (choices.first + choices.second);
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    cout << solve(s, a, b) << endl;
    return 0;
}
