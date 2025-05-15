#include "Privacy.h"

Privacy::Privacy(int id)
{
    optUser = user.getUser(id);
    if (optUser.has_value())
        user = optUser.value();
}

bool Privacy::isBlockedBy(int id)
{
    return user.getBlocked().find(id) != user.getBlocked().end();
}

bool Privacy::infoIsHiddenBy(int id)
{
    return user.getInfoVisibility().find(id) != user.getInfoVisibility().end();
}

bool Privacy::seenIsHiddenBy(int id)
{
    return user.getSeenVisibility().find(id) != user.getSeenVisibility().end();
}

bool Privacy::lastSeenIsHiddenBy(int id)
{
    return user.getLastSeenVisibility().find(id) != user.getLastSeenVisibility().end();
}