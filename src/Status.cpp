//
// Created by M.Ramadan on 4/16/25.
//

#include "Status.h"

Status::Status(const bool &seen = false): seen(seen) {
};

Status::Status(const bool &seen, struct tm &deliveryTime): seen(seen), deliveryTime(deliveryTime) {
};

Status::Status() {};


void Status::initiateDeliveryTime() {
    time_t timeStamp = time(&timeStamp); // time() makes a timestamp for current date
    deliveryTime = *localtime(&timeStamp); // localtime() returns a pointer to a struct equal to computer's time
    deliveryTime.tm_year += 1900; // Because it returns number of years since 1900
    ++deliveryTime.tm_mon; // Because month is zero-based
}

void Status::setSeen(const bool &seen) {
    this->seen = seen;
}

bool Status::getSeen() const {
    return seen;
}

struct tm Status::getDeliveryTime() const {
    return deliveryTime;
}