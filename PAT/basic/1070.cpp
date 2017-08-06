#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
priority_queue<double,vector<double>,greater<double> >q;

int main()
{
    double total = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        double len;
        cin >> len;
        q.push(len);
    }
    while(q.size() != 1) { // like Haffman Coding
        double top1 = q.top();
        q.pop();
        double top2 = q.top();
        q.pop();
        total = (top1+top2) / 2;
        q.push(total);
    }
    cout << int(total) << endl;
    return 0;
}
