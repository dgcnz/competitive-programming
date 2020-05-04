#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t, n, minc, maxc, cur_streak, past, xi;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cur_streak = 0;
        minc       = INT_MAX;
        maxc       = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            cin >> xi;
            if (i == 0 or (xi - past) <= 2)
                ++cur_streak;
            else if (xi - past > 2)
            {
                minc       = min(minc, cur_streak);
                maxc       = max(maxc, cur_streak);
                cur_streak = 1;
            }
            past = xi;
        }
        minc = min(minc, cur_streak);
        maxc = max(maxc, cur_streak);
        cout << minc << " " << maxc << endl;
    }
    return 0;
}
