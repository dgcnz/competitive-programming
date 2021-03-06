#include <bits/stdc++.h>

using namespace std;
using vi  = vector<int>;
using mii = map<int, int>;

const int NMAX = 1e5 + 11;

int  n, m;
bool visited[NMAX];
vi   g[NMAX];

void reconstruct_path(int s, int e, const mii &came_from)
{
    vi  ans;
    int cur = s;
    ans.push_back(s);

    do
    {
        cur = came_from.at(cur);
        ans.push_back(cur);
    } while (cur != e);

    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (auto computer : ans)
        cout << computer << " ";
    cout << endl;
}

void bfs(int start, int target)
{
    mii        came_from;
    queue<int> q;
    q.push(start);

    while (not q.empty())
    {
        int u = q.front();
        q.pop();

        if (u == target)
        {
            reconstruct_path(u, start, came_from);
            return;
        }

        for (auto v : g[u])
        {
            if (not visited[v])
            {
                q.push(v);
                came_from[v] = u;
                visited[v]   = true;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main(void)
{
    int u, v;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(1, n);
    return 0;
}
