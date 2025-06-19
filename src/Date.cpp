//
// Created by DELL on 4/21/2025.
//

#include "Date.h"
#include <ctime>

tm Date::getNow() {
    time_t timeStamp = time(&timeStamp); // time() makes a timestamp for current date
    now = *localtime(&timeStamp); // localtime() returns a pointer to a struct equal to computer's time
    now.tm_year += 1900; // Because it returns number of years since 1900
    ++now.tm_mon; // Because month is zero-based
    return now;
}

string Date::format(tm *time) {
    time_t now = std::time(nullptr);
    tm* currentTm = localtime(&now);

    time_t inputTime = mktime(time);
    tm startOfToday = *currentTm;
    startOfToday.tm_hour = 0;
    startOfToday.tm_min = 0;
    startOfToday.tm_sec = 0;
    time_t todayStart = mktime(&startOfToday);
    double diffInSeconds = difftime(now, inputTime);
    int daysDiff = diffInSeconds / (60 * 60 * 24);
    char buffer[100];

    if (inputTime >= todayStart) {
        strftime(buffer, sizeof(buffer), "Today, %I:%M %p", time);
    } else if (daysDiff < 7) {
        strftime(buffer, sizeof(buffer), "%A, %I:%M %p", time);
    } else {
        strftime(buffer, sizeof(buffer), "%B %d, %Y, %I:%M %p", time);
    }

    return string(buffer);
}


tm Date::fromJson(const json &json) {
    tm timeStruct{};
    timeStruct.tm_year = json["time"]["year"].get<int>();
    timeStruct.tm_mon = json["time"]["month"].get<int>();
    timeStruct.tm_mday = json["time"]["day"].get<int>();
    timeStruct.tm_hour = json["time"]["hour"].get<int>();
    timeStruct.tm_min = json["time"]["minute"].get<int>();
    timeStruct.tm_sec = json["time"]["second"].get<int>();
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
