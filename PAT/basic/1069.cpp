#include <string>
#include <map>
#include <iostream>
using namespace std;
map<string, int> user;
int main()
{
    int n,itvl,begin;
    bool going = true;
    cin >> n >> itvl >> begin;
    int no = 1;
    while(n--) {
        string name;
        cin >> name;
        if (no >= begin && (no-begin)%itvl == 0) {
            going = false;
            map<string, int>::iterator it;
            it = user.find(name);
            if (it == user.end()) {
                cout << name << endl;
                user[name] = 1;
            } else {
                no--;
            }
        }
        no++;
    }
    if (going) {
        cout << "Keep going..." << endl;
    }
    return 0;
}
