/** @file
 * @date                2020-11-26
 * @url                 https://projecteuler.net/problem=4
 * @tags                math
 * @status              AC
 * @score               2
 * @difficulty          2
 * @editorial           yes
 * @reading_time        2
 * @thinking_time       15
 * @coding_time         5
 * @idea
 * Source: [article](https://www.xarg.org/puzzle/project-euler/problem-4/).
 *
 * The key observation is to notice that one of the numbers must be a
 * multiple of 11.
 *
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

bool is_palindrome(int x)
{
    string a = to_string(x);
    string b = a;
    reverse(all(b));
    return a == b;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int ans = 0;
    for (int a = 990; a > 99; a -= 11)
    {
        for (int b = 999; b > 99; b--)
        {
            int x = a * b;
            if (x <= ans)
                break;
            else if (x > ans and is_palindrome(x))
            {
                ans = x;
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
