#ifndef PRIVACY_H
#define PRIVACY_H
#include <vector>
#include <set>
#include "User.h"
using namespace std;

class Privacy
{
    //Some one made it to him
    optional<User> optUser;
    User user;

public:
    Privacy (int id);

    bool isBlockedBy(int id);
    bool infoIsHiddenBy(int id);
    bool seenIsHiddenBy(int id);
    bool lastSeenIsHiddenBy(int id);
};

#endif //PRIVACY_H