#include <cstdio>
#include <algorithm>
struct Money
{
    int knut;
    int sickle;
    int galleon;
};

bool bigger(Money a, Money b)
{
    if (a.galleon != b.galleon) {
        return a.galleon > b.galleon;
    } else {
        if (a.sickle != b.sickle) {
            return a.sickle > b.sickle;
        } else {
            return a.knut > b.knut;
        }
    }
}

int main()
{
    Money bill;
    Money pay;
    scanf("%d.%d.%d", &bill.galleon, &bill.sickle, &bill.knut);
    scanf("%d.%d.%d", &pay.galleon, &pay.sickle, &pay.knut);
    if (bigger(bill, pay)) {
        printf("-");
        std::swap(bill, pay);
    }
    Money back;
    back.knut = pay.knut - bill.knut;
    back.sickle = pay.sickle - bill.sickle;
    back.galleon = pay.galleon - bill.galleon;
    if (back.knut < 0) {
        back.sickle -= 1;
        back.knut += 29;
    }
    if (back.sickle < 0) {
        back.galleon -= 1;
        back.sickle += 17;
    }
    printf("%d.%d.%d\n", back.galleon, back.sickle, back.knut);
    return 0;
}
