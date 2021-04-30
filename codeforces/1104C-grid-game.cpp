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
    string s;
    cin >> s;

    vector<ii> pos0 = {{1, 1}, {3, 1}};
    vector<ii> pos1 = {{4, 3}, {4, 1}};
    for (auto c : s)
    {
        if (c == '0')
        {
            cout << pos0.front().first << " " << pos0.front().second << endl;
            swap(pos0.front(), pos0.back());
        }
        else
        {
            cout << pos1.front().first << " " << pos1.front().second << endl;
            swap(pos1.front(), pos1.back());
        }
    }

    return 0;
}
