#include <cstdio>
struct Node 
{
    int val;
    int next;
};
Node vmem[100000];
int main()
{
    int s_addr, n, k;
    scanf("%d %d %d", &s_addr, &n, &k);
    for(int i = 0; i < n; ++i) { // build
        int addr, val, next;
        scanf("%d %d %d", &addr, &val, &next);
        vmem[addr].val = val;
        vmem[addr].next = next;
    }
    int head = s_addr;
    int thead = head;
    int old;
    if(s_addr == -1) //首地址为-1
    {  
        printf("-1\n");
        return 0;
    }  
    if (k) {
        int cnt = 0;
        for(int i = s_addr; i!= -1; i = vmem[i].next)
            cnt++;
        for(int i = 0; i < (cnt/k); ++i) { // n/k
            for(int j = 0; j < k-1; ++j) {
                int tmp = vmem[vmem[head].next].next; //next->next
                vmem[vmem[head].next].next = thead;
                thead = vmem[head].next;
                vmem[head].next = tmp;
            }
            if (i == 0)
                s_addr = thead;
            else
                vmem[old].next = thead;

            old = head;
            head = vmem[head].next;
            thead = head;
        }
    }

    for(int i = s_addr; i!= -1; i = vmem[i].next) {
        if (vmem[i].next != -1)
            printf("%05d %d %05d\n", i , vmem[i].val, vmem[i].next);
        else
            printf("%05d %d -1\n", i , vmem[i].val);
    }
    return 0;
}
