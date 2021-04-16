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

int solve(vi p)
{
    int h = p.front();
    if (h <= 2)
        return 0;

    vector<int> blocks;
    int         cnt = 0, prev = h + 1;
    for (auto pi : p)
    {
        if (pi == prev - 1)
            cnt++;
        else
            blocks.push_back(cnt), cnt = 1;
        prev = pi;
    }
    if (cnt)
        blocks.push_back(cnt);
    if (p.back() == 1)
        blocks.pop_back();
    if (blocks.empty())
        return 0;

    auto odd = [](int n) { return n % 2; };
    int  ans = count_if(all(blocks), odd);
    // dbg(blocks, ans);
    if (odd(blocks.front()))
        ans--;
    else
        ans++;
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int h, n;
        cin >> h >> n;
        vi p(n);
        read(all(p));
        cout << solve(p) << endl;
    }
    return 0;
}
