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

    string ans(10, '0');

    set<int> open;
    for (int i = 0; i < 10; ++i)
        open.insert(i);

    for (auto c : s)
    {
        if (c == 'L')
        {
            auto room = *open.begin();
            ans[room] = '1';
            open.erase(open.begin());
        }
        else if (c == 'R')
        {
            auto room = *prev(open.end());
            ans[room] = '1';
            open.erase(prev(open.end()));
        }
        else
        {
            auto room = c - '0';
            ans[room] = '0';
            open.insert(room);
        }
    }
    cout << ans << endl;
    return 0;
}
