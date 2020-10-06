// IDEA:
//      mask[i]: 1 if topic i was covered, 0 otherwise
//
//      BACKWARD DP
//
//      dp(i, mask) : minimum cost to cover the topics on mask using only the
//      first i books
//
//      dp(i, mask) = min(dp(i - 1, mask), dp(i - 1, mask & ~book_mask(i)) +
//      time(i)) // DOESNT WORK
//
//
//      dp(i, mask) = min(
//                  dp(i - 1, mask),
//                  {dp(i - 1, mask2) + time(i) | mask2 <- [0, 2^nbooks], if
//                                          (mask2 | book_mask(i)) == mask})
//
//      To understand why that doesn't work, try to think of what happens when
//      two or more books cover topics in common:
//
//      dp(i - 1, mask & ~book_mask(i)) assumes that the contribution of the
//      book i was unique, meaning that the only previous state we're
//      considering is the one that contains no topics included on the book i.
//
//      However, this is clearly false, since the optimal solution could be one
//      that includes books that overlap on their topics covered
//
//      A simple counter-example could be:
//
//      1       topicA  topicB              // book 1
//      10000   topicA                      // book 2
//      1               topicB  topicC      // book 3
//
//      First, the only way in which we cover topic 3 is if we choose book 3,
//      and if we use the aforementioned dp formulation, then we would only
//      consider book 1 (since book 2 has topics in common), resulting in a
//      sub-optimal solution
//
//      So, how do we fix it?
//      One possible way would be to consider all the posible submasks of the
//      current book_mask, but that would be too expensive
//
//
//      dp(i, mask) = min(
//                  dp(i - 1, mask),
//                  {dp(i - 1, mask2) + time(i) | mask2 <- P(mask)}
//
//      Here comes Forward DP (https://codeforces.com/blog/entry/43256)
//      Instead of computing the current state based on all the previous states
//      that contribute to it, we will build the next states by considering all
//      the contributions from the current state
//
//      However, the dimensions of the dp table will exceed the memory, but we
//      can observe that to compute a layer of dp states, we only need the
//      previous one, ie. dp(i, mask) is only dependent on dp(i - 1, ???).
//
//      So that's it, we'll only maintain the current and previous layer on
//      a 2 * 2^nbooks 2darray.

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int const NMAX = 1e2 + 1;

int              nbooks, ntopics, btime[NMAX], bmask[NMAX], dp[2][1 << 20];
map<string, int> id;

int solve(void)
{
    memset(dp, 62, sizeof dp); // just a big number
    dp[0][0] = 0;
    int prv = 0, cur = 1;
    for (int i = 1; i <= nbooks; ++i)
    {
        // To compute a dp state at layer i, I only need the previous level
        for (int mask = 0; mask < (1LL << ntopics); ++mask)
            dp[cur][mask] = dp[prv][mask];

        // Forward DP: making contributions to next state from previous state,
        // once I reach that state, the answer is already computed
        for (int mask = 0; mask < (1LL << ntopics); ++mask)
        {
            int &fans = dp[cur][mask | bmask[i]];
            fans      = min(fans, dp[prv][mask] + btime[i]);
        }
        swap(cur, prv);
    }
    return dp[prv][(1LL << ntopics) - 1];
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    string line;
    while (getline(cin, line))
    {
        if (line.empty())
            break;
        istringstream is(line);
        string        topic;
        int           mask = 0, i = ++nbooks;
        is >> btime[i];
        while (is >> topic)
        {
            if (id.find(topic) == id.end())
                id[topic] = ntopics++;
            int idt = id.at(topic);
            mask |= (1LL << idt);
        }
        bmask[i] = mask;
    }

    cout << solve() << endl;

    return 0;
}
