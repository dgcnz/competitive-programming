#include <bits/stdc++.h>

using namespace std;

int const HMAX = 200 + 11;
int const DMAX = 10;
int const INF  = 1e9;

int c[DMAX][DMAX], a[HMAX][HMAX], dist[DMAX][DMAX];

void floyd_warshall(void)
{
    for (int i = 0; i < DMAX; i++)
    {
        for (int j = 0; j < DMAX; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else if (c[i][j])
                dist[i][j] = c[i][j];
            else
                dist[i][j] = INF;
        }
    }
    for (int k = 0; k < DMAX; k++)
    {
        for (int i = 0; i < DMAX; i++)
        {
            for (int j = 0; j < DMAX; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(void)
{
    int h, w, ai;

    cin >> h >> w;
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            cin >> c[i][j];

    floyd_warshall();
    int ans = 0;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cin >> ai;
            if (ai == -1 or ai == 1)
                continue;
            ans += dist[ai][1];
        }
    }

    cout << ans << endl;

    return 0;
}
