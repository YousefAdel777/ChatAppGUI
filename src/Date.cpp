//
// Created by DELL on 4/21/2025.
//

#include "Date.h"

tm Date::getNow() {
    time_t timeStamp = time(&timeStamp); // time() makes a timestamp for current date
    now = *localtime(&timeStamp); // localtime() returns a pointer to a struct equal to computer's time
    now.tm_year += 1900; // Because it returns number of years since 1900
    ++now.tm_mon; // Because month is zero-based
    return now;
}

tm Date::fromJson(const json &json) {
    tm timeStruct{};
    timeStruct.tm_year = json.at("year").get<int>();
    timeStruct.tm_mon = json.at("month").get<int>();
    timeStruct.tm_mday = json.at("day").get<int>();
    timeStruct.tm_hour = json.at("hour").get<int>();
    timeStruct.tm_min = json.at("minute").get<int>();
    timeStruct.tm_sec = json.at("second").get<int>();
    return timeStruct;
}

json Date::toJson(const tm &time) {
    json json;
    json["time"]["year"] = time.tm_year;
    json["time"]["month"] = time.tm_mon;
    json["time"]["day"] = time.tm_mday;
    json["time"]["hour"] = time.tm_hour;
    json["time"]["minute"] = time.tm_min;
    json["time"]["second"] = time.tm_sec;
    return json;
}
