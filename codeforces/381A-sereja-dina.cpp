#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    deque<int>  cards(n);
    vector<int> ans(2, 0);

    for (auto &x : cards)
        cin >> x;

    for (int i = 0; i < n; ++i)
    {
        if (cards.front() < cards.back())
        {
            ans[i % 2] += cards.back();
            cards.pop_back();
        }
        else
        {
            ans[i % 2] += cards.front();
            cards.pop_front();
        }
    }

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
