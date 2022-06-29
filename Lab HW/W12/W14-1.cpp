#include <iostream>
#include <string>
#define vo 26

using namespace std;

class TrieNode
{
public:
    bool isword = false;
    TrieNode *childs[vo];
    TrieNode()
    {
        for(int i = 0; i < vo; i++){
            childs[i] = NULL;
        }
    }


};

class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string s)
    {
        TrieNode *visit = root;
        for(auto &c : s)
        {
            if(!(visit -> childs[c-'a']))
            {
                visit -> childs[c-'a'] = new TrieNode();
            }

            visit = visit -> childs[c-'a'];
        }
        visit -> isword = true;
    }

    bool search(string s)
    {
        TrieNode *visit = root;
        for(auto &c : s)
        {
            if(visit -> childs[c - 'a'] != NULL)
            {
                visit = visit -> childs[c - 'a'];
            }
            else return false;
        }
        return visit -> isword;
    }

private:
    TrieNode *root;
};

int main()
{
    Trie *trie = new Trie();
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        trie -> insert(str);
    }
    for(int j = 0; j < m; j++)
    {
        string str2;
        cin >> str2;
        if(trie -> search(str2))
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}
