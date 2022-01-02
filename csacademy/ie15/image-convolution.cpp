#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/string/z_function>
#include <cplib/utils/io>
#include <cplib/utils/multidimensional>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

char const DUMMY = 'x';
bool       eq(char si, char sj)
{
    if (si == DUMMY or sj == DUMMY)
        return false;
    return si == sj or si == '?' or sj == '?';
}

ll solve(vector<string> m, vector<string> p)
{
    int R = m.size(), C = m.back().size();
    int A = p.size(), B = p.back().size();

    ll   ans = 0;
    auto dp  = create_multidimensional(R + 1, C + 1, A + 1, false);
    for (int j = 0; j <= C; ++j)
        fill(all(dp[R][j]), true);

    for (int i = R - 1; i >= 0; --i)
    {
        vector<vi> pi(A);
        for (int k = 0; k < A; ++k)
        {
            pi[k] = z_function(p[k] + DUMMY + m[i], eq);
            pi[k] = vi(pi[k].begin() + B + 1, pi[k].end());
        }
        for (int j = C - 1; j >= 0; --j)
        {
            for (int k = A - 1; k >= 0; --k)
            {
                // dbg(i, j, k, pi[k][j] == B, dp[i + 1][j][k + 1]);
                dp[i][j][k] = (pi[k][j] == B) and dp[i + 1][j][k + 1];
            }
            ans += dp[i][j][0];
        }
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<string> m(R);
        read(all(m));

        int A, B;
        cin >> A >> B;
        vector<string> p(A);
        read(all(p));

        cout << solve(m, p) << endl;
    }
    return 0;
}
