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

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void write(InputIterator first, InputIterator last, const char *delim = "\n")
{
    copy(first, last, ostream_iterator<T>(cout, delim));
}

const int ALPH    = 26;
const int TRIEMAX = 20;

struct Node
{
    bool                finish, visited;
    array<Node *, ALPH> children;
    Node(void)
    {
        visited = finish = false;
        fill(all(children), nullptr);
    }
    ~Node()
    {
        finish = visited = false;
        for (auto child : children)
            delete child;
    }
};

struct Trie
{
    Node *root;
    Trie() { root = new Node(); }
    ~Trie()
    {
        delete root;
        root = nullptr;
    }
    bool insert(string s)
    {
        auto cur = root;
        for (int i = 0, n = isz(s); i < n; ++i)
        {
            int j = s[i] - '0';
            if (not cur->children[j])
                cur->children[j] = new Node();
            if (cur->finish)
                return false;
            cur->visited = true;
            cur          = cur->children[j];
        }
        if (cur->visited)
            return false;
        return cur->visited = cur->finish = true;
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        Trie tree;

        int  n;
        bool flag = true;
        cin >> n;
        while (n--)
        {
            string num;
            cin >> num;
            if (flag and not tree.insert(num))
                flag = false;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}
