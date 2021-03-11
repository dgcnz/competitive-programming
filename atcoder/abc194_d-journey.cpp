/** @file
 * @date                2021-03-11
 * @url                 https://atcoder.jp/contests/abc194/tasks/abc194_d
 * @tags                math, probability
 * @status              AC
 * @score               4
 * @difficulty          3
 * @editorial           no
 * @reading_time        2
 * @thinking_time       40
 * @coding_time         10
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Let's define a few random variables.
 *
 * - $X_k$: time for the $k$-th distinct vertex to be first sampled.
 * - $Y_m$: 1 if one of m selected vertices is sampled, 0 otherwise.
 * - $Z_m$: number of trials for first $Y_m = 1$. (Number of trials to sample
 * one of m selected vertices).
 *
 * We want to find $E[X_n]$, the expected number of trials to sample $n$
 * distinct vertices, which is enough to minimally connect the graph. We
 * consider vertex 1 to be already sampled/visited.
 *
 * We can think of the time for sampling the $k$-th distinct vertex as the time
 * for sampling $k-1$ distinct vertices plus the time needed to sample one of
 * the remaining $n - (k - 1)$ non-sampled vertices.
 *
 * $$ E[X_k] = E[X_{k - 1}] + E[Z_{n - (k - 1)}]$$
 *
 * $E[Z_m]$ has a known closed formula ($Y_m$ is a Bernoulli trial, check
 * [this](https://www.cut-the-knot.org/Probability/LengthToFirstSuccess.shtml)
 * for more information) which is $\frac{1}{P(Y_m = 1)}$.
 *
 * Since sampling any vertex follows a Uniform distribution, we know that:
 *
 * $$P(Y_m) = \frac{m}{n}$$
 *
 * We can now simplify $E[X_k]$:
 *
 * $$E[X_k] = E[X_{k - 1}] + \frac{n}{n - (k - 1)}$$
 *
 * With a base case of $E[X_1] = 0$ we can linearly compute $E[X_n]$ in
 * $O(n)$.
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

double solve(int n)
{
    vector<double> E(n + 1);
    E[1] = 0;
    for (int k = 2; k <= n; ++k)
        E[k] = E[k - 1] + n / double(n - k + 1);
    return E[n];
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;
    cout << fixed << setprecision(12) << solve(n) << endl;
    return 0;
}
