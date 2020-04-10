#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;
using tiii = tuple<int, int, int>;
using pic  = pair<int, char>;

const int NMAX = 1e3 + 11;

int  n;
tiii tasks[NMAX];

string reconstruct(vector<pic> ans)
{
    if (ans.empty())
        return "IMPOSSIBLE";

    string s;
    sort(ans.begin(), ans.end());
    for (auto p : ans)
        s += p.second;

    return s;
}

string solve(void)
{
    int         si, ei, id;
    vector<pic> ans;

    int jamie_free, cameron_free;
    jamie_free = cameron_free = 0;

    for (int i = 0; i < n; ++i)
    {
        tiii task = tasks[i];
        si        = get<0>(task);
        ei        = get<1>(task);
        id        = get<2>(task);

        if (cameron_free <= si)
        {
            ans.push_back(make_pair(id, 'C'));
            cameron_free = ei;
        }
        else if (jamie_free <= si)
        {
            ans.push_back(make_pair(id, 'J'));
            jamie_free = ei;
        }
        else
            return reconstruct(vector<pic>());
    }

    return reconstruct(ans);
}

int main(void)
{
    int t, si, ei;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc)
    {
        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            cin >> si >> ei;
            tasks[i] = make_tuple(si, ei, i);
        }

        sort(tasks, tasks + n);

        cout << "Case #" << tc << ": " << solve() << endl;
    }
}
