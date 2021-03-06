#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;

int solve(int k, vector<ii> tab)
{
    sort(all(tab));

    vector<int> choices;

    queue<int> queued[2];
    for (auto [t, sign] : tab)
    {
        if (sign == 2)
            choices.push_back(t);
        else
        {
            queued[sign].push(t);
            if (not queued[0].empty() and not queued[1].empty())
            {
                choices.push_back(queued[0].front() + queued[1].front());
                queued[0].pop(), queued[1].pop();
            }
        }
    }
    sort(all(choices));
    if (isz(choices) < k)
        return -1;
    else
        return accumulate(choices.begin(), choices.begin() + k, 0);
}

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector<ii> tab;
    for (int i = 0; i < n; ++i)
    {
        int ti, ai, bi;
        cin >> ti >> ai >> bi;
        if (not ai and not bi)
            continue;
        else
            tab.push_back({ti, (ai and bi ? 2 : ai)});
    }

    cout << solve(k, tab) << endl;

    return 0;
}
