#include <set>
#include <cstdio>
using namespace std;
struct Item
{
    int val;
    int freq;
    bool operator < (const Item b) const {
        if (freq != b.freq) {
            return freq > b.freq;
        } else {
            return val < b.val;
        }
    }
    Item(int v, int f){val=v;freq=f;}
};
int times[50001];
int main()
{
    int n, k, val;
    int size;
    scanf("%d %d", &n, &k);
    set<Item> rec;
    set<Item>::iterator it;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &val);
        size = rec.size() > k ? k : rec.size();
        if (size) {
            printf("%d:", val);
            it = rec.begin();
            for(int j = 0; j < size; ++j) {
                printf(" %d", it->val);
                it++;
            }
            printf("\n");
        }
        it = rec.find(Item(val,times[val]));
        if (it != rec.end()) { 
            rec.erase(it);
        }
        times[val]++;
        rec.insert(Item(val,times[val]));
    }
    return 0;
}
