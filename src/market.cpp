#include <iostream>
#include "market.h"
#include <ctime>

Market::Market(double cheese_val, double ham_val, double bread_val, double bank_val, int limit) {
    cheese_value = cheese_val;
    ham_value = ham_val;
    bread_value = bread_val;
    bank = bank_val;
    market_limit = limit;
    profit = 0;
}

void Market::bring_goods(int cheese_number, int ham_number, int bread_number) {
    if (market_limit < cheese + cheese_number + ham + ham_number + bread + bread_number) {
        std::cout << "failed to deliver the goods: out of warehouse limit" << "\n";
    }
    else if (bank < cheese_value * cheese_number + ham_value * ham_number + bread_value * bread_number) {
        std::cout << "failed to deliver the goods: out of money limit" << "\n";
        }
    else {
        std::cout << cheese_number << " units of cheese, " << ham_number << " units of ham and " <<
                  bread_number << " units of bread were brought to the warehouse" << "\n";
        plus_minus_bank = bank;
        cheese += cheese_number;
        ham += ham_number;
        bread += bread_number;
        if (cheese_number != 0) bank -= cheese_value * cheese_number;
        if (ham_number != 0) bank -= ham_value * ham_number;
        if (bread_number != 0) bank -= bread_value * bread_number;
        plus_minus_bank -= bank;
        profit -= plus_minus_bank;
    }
}

void Market::purchase_of_goods(int cheese_pur, int ham_pur, int bread_pur) {
    cheese_pur_if = cheese_pur;
    ham_pur_if = ham_pur;
    bread_pur_if = bread_pur;
    if (cheese == 0 || ham == 0 || bread == 0) if_zero();
    if (cheese < cheese_pur_if || ham < ham_pur_if || bread < bread_pur_if) if_less();
    cheese_pur = cheese_pur_if;
    ham_pur = ham_pur_if;
    bread_pur = bread_pur_if;
    std::cout << cheese_pur_if << " units of cheese, " << ham_pur << " units of ham and " <<
    bread_pur << " units of bread were sold" << "\n";
    plus_minus_bank = bank;
    cheese -= cheese_pur;
    if (cheese_pur != 0) bank += (cheese_value * 1.5 * cheese_pur);
    ham -= ham_pur;
    if (ham_pur != 0) bank += (ham_value * 1.5 * ham_pur);
    bread -= bread_pur;
    if (bread_pur != 0) bank += (bread_value * 1.5 * bread_pur);
    profit += bank;
    profit -= plus_minus_bank;
}

void Market::profit_count() {
    std::cout << "profit is " << profit << "\n";
}

int Market::random() {
    srand(time(NULL));
    int r = rand() % 2;
    return r;
}

void Market::if_less() {
    if (cheese < cheese_pur_if) {
        std::cout << "more cheese is requested than is in warehouse";
        if (random() == 1) {
            std::cout << ", but buyer agree to buy " << cheese << " units of cheese instead of " <<
            cheese_pur_if << "\n";
            cheese_pur_if = cheese;
        }
        else {
            std::cout << " and buyer doesn't agree to buy " << cheese << " units of cheese instead of "
            << cheese_pur_if << "\n";
            cheese_pur_if = 0;
        }
    }
    if (ham < ham_pur_if) {
        std::cout << "more ham is requested than is in warehouse";
        if (random() == 1) {
            std::cout << ", but buyer agree to buy " << ham << " units of ham instead of " << ham_pur_if << "\n";
            ham_pur_if = ham;
        }
        else {
            std::cout << " and buyer doesn't agree to buy " << ham << " units of ham instead of "
            << ham_pur_if << "\n";
            ham_pur_if = 0;
        }
    }
    if (bread < bread_pur_if) {
        std::cout << "more bread is requested than is in warehouse";
        if (random() == 1) {
            std::cout << ", but buyer agree to buy " << bread << " units of bread instead of "
            << bread_pur_if << "\n";
            bread_pur_if = bread;
        }
        else {
            std::cout << " and buyer doesn't agree to buy " << bread << " units of bread instead of "
            << bread_pur_if << "\n";
            bread_pur_if = 0;
        }
    }
}

void Market::if_zero() {
    if (cheese == 0) {
        std::cout << "there are 0 units of cheese in the warehouse";
        cheese_pur_if = 0;
    }
    if (ham == 0) {
        std::cout << "there are 0 units of ham in the warehouse";
        ham_pur_if = 0;
    }
    if (bread == 0) {
        std::cout << "there are 0 units of bread in the warehouse";
        bread_pur_if = 0;
    }
    std::cout << "\n";
}