---
layout: post
mathjax: true
title: PHONELST - Phone List
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---



{% if page.time_complexity != "None" %}
Time complexity: ${{ page.time_complexity }}$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: ${{ page.memory_complexity }}$
{% endif %}

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
```cpp
{% raw %}
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
const int ALPH = 26;
const int TRIEMAX = 20;
struct Node
{
    bool finish, visited;
    array<Node *, ALPH> children;
    Node(void)
    {
        visited = finish = false;
        fill(children.begin(), children.end(), nullptr);
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
        for (int i = 0, n = (int)s.size(); i < n; ++i)
        {
            int j = s[i] - '0';
            if (not cur->children[j])
                cur->children[j] = new Node();
            if (cur->finish)
                return false;
            cur->visited = true;
            cur = cur->children[j];
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
        int n;
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

{% endraw %}
```
</details>

