//
// Created by M.Ramadan on 4/16/25.
//
#include <iostream>
using namespace std;

#include "Status.h"
Status::Status(int n): n(n) {
    seen = false;
    initiateDeliveryTime();
};

Status::Status(int n,bool seen,unordered_set<int>&seenBy,unordered_set<int>&deletedFor, struct tm &deliveryTime):
    n(n),seenBy(seenBy),seen(seen),deletedFor(deletedFor),deliveryTime(deliveryTime) {
};

Status::Status(int n,bool seen,unordered_set<int>&deletedFor, struct tm &deliveryTime):
    n(n),seen(seen),deletedFor(deletedFor),deliveryTime(deliveryTime) {
    };
void Status::initiateDeliveryTime() {
    time_t timeStamp = time(&timeStamp); // time() makes a timestamp for current date
    deliveryTime = *localtime(&timeStamp); // localtime() returns a pointer to a struct equal to computer's time
}

void Status::setSeen(int id) {
    if(!seen)
        seenBy.insert(id),seen = seenBy.size()==n;
}

bool Status::getSeen() const {
    return seen;
}

bool Status::CheckDeletedFor(int id){
    return deletedFor.find(id)!=deletedFor.end();
}

void Status::setDeletedFor(int id){
    deletedFor.insert(id);
}

struct tm Status::getDeliveryTime() const {
    return deliveryTime;
}

json Status::toJson() {
    json json;
    json["size"] = n;
    json["seen"] = seen;
    json["SeenBy"] = json::array();
    json["DeletedFor"] = json::array();
    if(!seen){
        for(auto &x:seenBy)
            json["SeenBy"].push_back(x);
    }
    for(auto &x:deletedFor)
        json["DeletedFor"].push_back(x);
    json["time"] = std::mktime(&deliveryTime);
    return json;
}

Status Status::fromJson(const json &json) {
    auto time = json["time"].get<time_t>();
    unordered_set<int>tmp,tmp1;
    for(auto &x : json["SeenBy"])
        tmp.insert(x.get<int>());
    for(auto &x:json["DeletedFor"])
        tmp1.insert(x.get<int>());
    return Status(
        json["size"].get<int>(),
         json["seen"].get<bool>(),
        tmp,
        tmp1,
        *std::localtime(&time)
        );
}
