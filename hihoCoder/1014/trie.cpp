#include <iostream>
#include <string>
using namespace std;
class Trie_node
{
public:
    int cnt;
    Trie_node *next[26];
public:
    Trie_node()
    {
        cnt = 0;
        for(int i = 0; i < 26; ++i)
            next[i] = NULL;
    }
};


Trie_node *tree = new Trie_node();

void insert(string str)
{
    Trie_node *p = tree;
    int len = str.size();;
    for(int i = 0; i < len; ++i)
    {
        char cur = str[i] - 'a';
        if(p->next[cur] == NULL)
            p->next[cur] = new Trie_node();
            
        p = p->next[cur];
        p->cnt++;
    }
}

int search(string str)
{
    Trie_node *p = tree;
    int len = str.size();
    for(int i = 0; i < len; ++i)
    {
        char cur = str[i] - 'a';
        if(p->next[cur] != NULL)
            p = p->next[cur];
        else
            return 0;
    }
    return p->cnt;
}

int main()
{
    
    int m,n;
    cin >> n;
    while(n--)
    {
        string tmp;
        cin >> tmp;
        insert(tmp);
    }
    cin >> m;
    while(m--)
    {
        string tmp;
        cin >> tmp;
        cout << search(tmp) << endl;
    }
    return 0;
}
