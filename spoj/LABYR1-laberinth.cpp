#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

const int CRMAX = 1e3 + 11;

const vi dr({0, 0, 1, -1});
const vi dc({1, -1, 0, 0});

int  cols, rows, diameter, row_, col_;
char lab[CRMAX][CRMAX];
bool vis[CRMAX][CRMAX];

void clear_vis(void)
{
    for (int row = 0; row < rows; ++row)
        memset(vis[row], false, sizeof(vis[row][0]) * cols);
}

inline bool in_range(int row, int col)
{
    return row >= 0 and row < rows and col >= 0 and col < cols;
}

inline bool is_free_block(int row, int col) { return lab[row][col] == '.'; }

void dfs(int row, int col, int depth)
{
    if (depth > diameter)
    {
        diameter = depth;
        row_     = row;
        col_     = col;
    }
    vis[row][col] = true;
    for (int i = 0; i < 4; ++i)
    {
        if (in_range(row + dr[i], col + dc[i]) and
            not vis[row + dr[i]][col + dc[i]] and
            is_free_block(row + dr[i], col + dc[i]))
            dfs(row + dr[i], col + dc[i], depth + 1);
    }
}

int solve(void)
{
    diameter = INT_MIN;
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            if (lab[row][col] == '.')
            {
                clear_vis();
                dfs(row, col, 0);
                clear_vis();
                dfs(row_, col_, 0);
                return diameter;
            }
        }
    }
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;
    while (t--)
    {
        cin >> cols >> rows;
        for (int row = 0; row < rows; ++row)
            cin >> lab[row];

        cout << "Maximum rope length is " << solve() << '.' << endl;
    }
    return 0;
}
