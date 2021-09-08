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
    int t;
    cin >> t;
    while (t--)
    {
        int    n;
        string s;
        cin >> n >> s;

        vector<int> twos;
        for (int i = 0; i < n; ++i)
            if (s[i] == '2')
                twos.push_back(i);

        if (twos.size() == 1 or twos.size() == 2)
            cout << "NO" << endl;
        else
        {

            vector<string> ans(n, string(n, '='));
            for (int i = 0; i < n; ++i)
                ans[i][i] = 'X';

            for (int i = 0, m = twos.size(); i < m; ++i)
            {
                int u = twos[i], v = twos[(i + 1) % m];
                ans[u][v] = '+';
                ans[v][u] = '-';
            }
            cout << "YES" << endl;
            write(all(ans)), cout << endl;
        }
    }
    return 0;
}
