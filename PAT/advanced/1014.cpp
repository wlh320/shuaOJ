// 队列模拟, 还是用优先队列来找到最先出队之人
#include <cstdio>
#include <queue>
using namespace std;
#define TIME_START 8*60
#define TIME_END 17*60
struct Cus
{
    int end; // end time
    int proc; // process time
    int line; // queue number
    bool sorry;
    bool operator < (const Cus &b) const {
        if (end == b.end) {
            return line > b.line;
        } else {
            return end > b.end;
        }
    }
};
Cus cus[1024];
int lastOut[32];
int main()
{
    int nQ, nCap, nCus, nQry;
    priority_queue<Cus> q; // 优先队列
    scanf("%d %d %d %d", &nQ, &nCap, &nCus, &nQry);
    for(int i = 0; i < nCus; ++i) {
        scanf("%d", &cus[i].proc);
    }
    for(int i = 0; i < nQ; ++i) {
        lastOut[i] = TIME_START;
    }
    for(int i = 0; i < nQ*nCap; ++i) { // N*M个人首先入队
        if (i >= nCus) break;
        cus[i].line = i % nQ;
        if (lastOut[i%nQ] >= TIME_END) { 
            // 忘了考虑前N*M个人就已经超17:00的情况了T_T
            cus[i].sorry = true;
        }
        cus[i].end = lastOut[i % nQ] + cus[i].proc;
        lastOut[i % nQ] = cus[i].end;
        q.push(cus[i]);
    }
    for(int i = nQ*nCap; i < nCus; ++i) {
        Cus tmp = q.top(); q.pop();
        if (lastOut[tmp.line] >= TIME_END) {
            cus[i].sorry = true;
        }
        cus[i].line = tmp.line;
        cus[i].end = lastOut[tmp.line] + cus[i].proc;
        lastOut[tmp.line] = cus[i].end;
        q.push(cus[i]);
    }
    int no;
    while(nQry--) { // query    
        scanf("%d", &no); no--;
        if (cus[no].sorry) {
            printf("Sorry\n");
        } else {
            printf("%02d:%02d\n", cus[no].end / 60, cus[no].end % 60);
        }
    }
    return 0;
}
