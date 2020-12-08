/** @file
 * @date                2020-12-07
 * @url                 https://codeforces.com/gym/100971/problem/K
 * @tags                strings, implementation
 * @status              AC
 * @score               2
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       10
 * @coding_time         15
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Assume that $s$ is not already a palindrome (if it is, then just remove the
 * middle character, as it will remain a palindrome).
 *
 * If $s$ can be turned into a palindrome by the removal of a character at
 * position $k$, then it has the form:
 *
 * $$s_1 s_2 ... s_{k - 1} s_k s_{k + 1} ... s_{k + 1} s_{k - 1} ... s_2 s_1 $$
 *
 * We can observe that such string has a matching suffix and prefix up to
 * position $k$, but it is uncertain if $s_k$ or $s_{n - k}$ should be removed.
 *
 * However, we know that if we remove one of those characters, then the
 * remaining characters must necessarily match.
 *
 * So we just try both options and see if one matches, if not, it's impossible
 * because there would necessarily be at least 2 characters to remove in order
 * to make the string palindromic.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

bool test(const string &s, int l, int r)
{
    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        ++l, --r;
    }
    return true;
}

int solve(string s)
{
    int n = isz(s);

    int l = 0, r = n - 1;
    while (l < r)
    {
        if (s[l] != s[r])
        {
            if (test(s, l + 1, r)) // l should be removed
                return l;
            else if (test(s, l, r - 1)) // r should be removed
                return r;
            else
                return -1;
        }
        else
            ++l, --r;
    }
    return n / 2;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    string s;

    cin >> s;
    if (auto ans = solve(s); ans != -1)
    {
        cout << "YES" << endl;
        cout << ans + 1 << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
