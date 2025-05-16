#pragma once
#include<sstream>
#include<ctime>
#include <unordered_set>
#include "json.hpp"
using namespace std;
using namespace nlohmann;
class Status {
    tm deliveryTime;
    unordered_set<int>seenBy;
    bool seen;
    int n;
    unordered_set<int>deletedFor;
public:

    Status(int n = 1);

    Status(int n,bool seen,unordered_set<int> &seenBy,unordered_set<int>&deletedFor,struct tm &);

    Status(int n,bool seen,unordered_set<int> &deletedFor,struct tm &);

    void setDeletedFor(int id);
    void initiateDeliveryTime();

    void setSeen(int id);

    bool CheckDeletedFor(int id);

    bool getSeen() const;

    static Status fromJson(const json &json);
    json toJson();

    tm getDeliveryTime() const;
};
