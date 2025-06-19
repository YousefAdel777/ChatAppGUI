//
// Created by DELL on 4/21/2025.
//

#ifndef DATE_H
#define DATE_H
#include <json.hpp>
#include<ctime>
using namespace std;
using json = nlohmann::json;

class Date {
    inline static tm now;

public:
    static tm getNow();

    static tm fromJson(const json &);

    static json toJson(const tm &);

    static string format(tm *);

};

#endif //DATE_H
