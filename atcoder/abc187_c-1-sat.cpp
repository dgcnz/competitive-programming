/** @file
 * @date                2021-01-02
 * @url                 https://atcoder.jp/contests/abc187/tasks/abc187_c
 * @tags                implementation
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       4
 * @coding_time         10
 * @time_complexity     O(n)
 * @memory_complexity   O(n \log{n})
 * @idea
 * Check for existence of $x$ and $!x$.
 * @endidea
 */

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

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    string           x;
    bool             satisfiable = true;
    map<string, int> is_positive;

    for (int i = 0; i < n; ++i)
    {
        string s;
        int    sign = +1;
        char   ch   = (std::cin >> std::ws).peek();
        if (ch == '!')
        {
            cin >> ch;
            sign = -1;
        }
        cin >> s;
        if (is_positive.find(s) == is_positive.end())
            is_positive[s] = sign;
        else if (is_positive[s] != sign)
        {
            satisfiable = false;
            x           = s;
        }
    }

    cout << (satisfiable ? "satisfiable" : x) << endl;
    return 0;
}
