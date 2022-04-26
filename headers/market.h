#pragma once

class Market {
private:
    int cheese = 0;
    double cheese_value;
    int ham = 0;
    double ham_value;
    int bread = 0;
    double bread_value;
    int cheese_pur_if;
    int ham_pur_if;
    int bread_pur_if;
    double bank;
    double profit;
    double plus_minus_bank;
    int market_limit;
public:
    Market(double, double, double, double, int);
    void bring_goods(int, int, int);
    void purchase_of_goods (int, int, int);
    void profit_count();
    int random();
    void if_less();
    void if_zero();
};
