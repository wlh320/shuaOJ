// same as B-1090
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
map<int, vector<int>> note;
map<int, bool> shown;

bool isValid(const vector<int> & box)
{
    for (int i = 0; i < box.size(); i++) {
        for (int j = 0; j < note[box[i]].size(); j++) {
            if (shown[note[box[i]][j]]) {
                return false;
            }
        }
    }
    return true;
}


int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        note[x].push_back(y);
        note[y].push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int j, nn;
        scanf("%d", &nn);
        vector<int> box;
        shown.clear();
        for (j = 0; j < nn; j++) {
            int x;
            scanf("%d", &x);
            box.push_back(x);
            shown[x] = true;
        }
        if (isValid(box)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}

