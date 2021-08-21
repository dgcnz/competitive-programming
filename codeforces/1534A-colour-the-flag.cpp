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
        int n, m;
        cin >> n >> m;
        vector<string> board(n);
        read(all(board));

        vector<string> ans1(board), ans2(board);
        bool           valid1 = true, valid2 = true;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if ((i + j) % 2)
                {
                    if (ans1[i][j] == 'W')
                        valid1 = false;
                    ans1[i][j] = 'R';
                    if (ans2[i][j] == 'R')
                        valid2 = false;
                    ans2[i][j] = 'W';
                }
                else
                {
                    if (ans1[i][j] == 'R')
                        valid1 = false;
                    ans1[i][j] = 'W';
                    if (ans2[i][j] == 'W')
                        valid2 = false;
                    ans2[i][j] = 'R';
                }
            }
        }
        if (valid1)
        {
            cout << "YES" << endl;
            write(all(ans1), "\n"), cout << endl;
        }
        else if (valid2)
        {
            cout << "YES" << endl;
            write(all(ans2), "\n"), cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
