#pragma once
#include<sstream>
#include<ctime>
using namespace std;

class Status {
    bool seen;
    tm deliveryTime;
public:

    Status();

    Status(const bool &);

    Status(const bool &, struct tm &);

    void initiateDeliveryTime();

    void setSeen(const bool &);

    bool getSeen() const;

    tm getDeliveryTime() const;
};
