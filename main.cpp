#include "market.h"

int main() {
    Market Magaz(50, 80, 30, 10000, 100);
    Magaz.bring_goods(50, 50, 50);
    Magaz.profit_count();
    Magaz.purchase_of_goods(60, 20, 38);
    Magaz.profit_count();
    Magaz.bring_goods(0, 27, 35);
    Magaz.profit_count();
    Magaz.purchase_of_goods(13, 20, 30);
    Magaz.profit_count();
    return 0;
}
