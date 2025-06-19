#include "Group.h"
#include "User.h"
Group::Group() :
ImagePath("default image"),
Description("Rghyapp Group"),
    Type_Permission(1)
{
    chatType = ChatRoomModel::ChatType::GROUP;
}

Group::Group(string name,vector<int> &users, set<MessageModel> &messages, map<int, Roles> &Members_Roles, string ImagePath,
    string Description,bool Type_Permission) :
ChatRoomModel(name,1, users, messages),
ImagePath(ImagePath),
Description(Description),
Type_Permission(Type_Permission),
Members_Roles(Members_Roles)
{
    chatType = ChatRoomModel::ChatType::GROUP;
}

Group::Group(long long Id,string name, vector<int> &users, set<MessageModel> &messages, map<int, Roles> &Members_Roles, string ImagePath,
    string Description,bool Type_Permission) :
ChatRoomModel(Id,1,name, users, messages),
Members_Roles(Members_Roles),
    Type_Permission(Type_Permission),
ImagePath(ImagePath),
Description(Description)
{
    chatType = ChatRoomModel::ChatType::GROUP;
}

void Group::deleteGroup() {
    ChatRoomModels.erase(id);
}


const string & Group::getImagePath() const {
    return ImagePath;
}

const string & Group::getDescription() const {
    return Description;
}

Group::Roles Group::getRoleOf(int Member) const {
    if (Members_Roles.find(Member) == Members_Roles.end()) {
        return NOT_MEMBER;
    }
    return Members_Roles.at(Member);
}

bool Group::isMember(int userId) {
    return getRoleOf(userId) != NOT_MEMBER;
}

map<int, Group::Roles> Group::getRoles() {
    return Members_Roles;
}

void Group::setDescription(string &Description) {
    this->Description = Description;
}

bool Group::getTypePermission()
{
    return Type_Permission;
}

void Group::setTypePermission(bool TypePermission)
{
    this->Type_Permission = TypePermission;
}
void Group::setImagePath(string &ImagePath) {
    this->ImagePath = ImagePath;
}

void Group::Change_Member_Role(int member, Roles Role) {
    Members_Roles[member]= Role;
}

void Group::Change_Member_Role(User& member, Roles Role) {
    Members_Roles[member.getId()]= Role;
}

void Group::Add_Member(int Member) {
    User user = User::getUser(Member).value();
    user.addChatRoom(id);
    user.save();
    if (users.empty()) {
        Members_Roles[Member] = OWNER;
    }
    else {
        Members_Roles[Member] = MEMBER;
    }
    users.push_back(Member);
}

string Group::roleToString(Roles role) {
    switch (role) {
        case OWNER: return "Owner";
        case ADMIN: return "Admin";
        case MEMBER: return "Member";
        case NOT_MEMBER: return "Not Member";
        default: return "Unknown";
    }
}

void Group::Remove_Member(int Member) {
    User user = User::getUser(Member).value();
    users.erase(find(users.begin(), users.end(), Member));
    user.removeChatRoom(id);
    user.save();
    // Members_Roles[id] = NOT_MEMBER;
    Members_Roles.erase(Member);
    bool has_admin = false;
    bool has_owner = false;
    for (auto [id, role] : Members_Roles) {
        if (role == OWNER) {
            has_owner = true;
            has_admin = true;
            break;
        }
        if (role == ADMIN) {
            has_admin = true;
        }
    }
    if (!has_owner) {
        if (has_admin) {
            for (int user : getUsers()) {
                if (Members_Roles[user] == ADMIN) {
                    Members_Roles[user] = OWNER;
                    break;
                }
            }
        }
        else {
            for (int user : getUsers()) {
                Members_Roles[user] = OWNER;
                break;
            }
        }
    }
    auto it = find(users.begin(), users.end(), Member);
    if (it != users.end()) {
        users.erase(it);
    }
    if (user.getId() == User::getCurrentUser()->getId()) {
        User::setCurrentUser(user);
    }
}

Group* Group::createGroup(string name, int adminId, string imagePath, string description, bool type_perm) {
    vector<int> userIds;
    map<int, Roles> roles;
    set<MessageModel> messages;

    roles[adminId] = Roles::ADMIN;

    Group* g = new Group(name, userIds, messages, roles, imagePath, description, type_perm);
    g->Add_Member(adminId);
    g->save();
    User::setCurrentUser(User::getUser(adminId).value());

    return g;
}

json Group::toJson()
{
    json json;
    json["type"] = type;
    json["id"] = id;
    json["name"] = name;
    json["users"] = json::array();
    json["Image_Path"] = ImagePath;
    json["Description"] = Description;
    for (int &user : users) {
        json["users"].push_back(user);
    }
    json["messages"] = json::array();
    for (MessageModel message : messages) {
        json["messages"].push_back(message.toJson());
    }
    json["Member_Roles"] = json::array();
    for(auto member:Members_Roles){
        nlohmann::json x;
        x["id"] = member.first;
        x["Role"] = member.second;
        json["Member_Roles"].push_back(x);
    }
    json["Type_Permission"] = getTypePermission();
    return json;
}

Group* Group::fromJson(const json &json){
    vector<int> users;
    set<MessageModel> messages;
    for (const auto &user : json["users"]) {
        users.push_back(user.get<int>());
    }
    for (const auto &message : json["messages"]) {
        messages.insert(MessageModel::fromJson(message));
    }
    map<int,Roles> roles;
    for(auto x:json["Member_Roles"]){

        switch (  x["Role"].get<int>()) {
            case 0: {
                roles[x["id"].get<int>()] =  NOT_MEMBER;
                break;
            }
            case 1: {
                roles[x["id"].get<int>()] =  MEMBER;
                break;
            }
            case 2:{
                roles[x["id"].get<int>()] =  ADMIN;
                break;
            }
            case 3:{
                roles[x["id"].get<int>()] =  OWNER;
                break;
            }
        }
    }
    return new Group(
        json["id"].get<long long>(),
        json["name"].get<string>(),
        users,
        messages,
        roles,
        json["Image_Path"].get<string>(),
        json["Description"].get<string>(),
        json["Type_Permission"].get<bool>()
        );
}
