#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    string         s;
    vector<string> ans;
    cin >> s;

    sort(s.begin(), s.end());
    do
    {
        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << ans.size() << endl;
    for (auto a : ans)
        cout << a << endl;

    return 0;
}
