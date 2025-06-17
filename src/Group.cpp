#include "Group.h"
#include "User.h"
Group::Group() :
ImagePath("default image"),
Description("Rghyapp Group"),
    Type_Permission(1)
{}

Group::Group(string name,vector<int> &users, set<MessageModel> &messages, map<int, Roles> &Members_Roles, string ImagePath,
    string Description,bool Type_Permission) :
ChatRoomModel(name,1, users, messages),
ImagePath(ImagePath),
Description(Description),
Type_Permission(Type_Permission),
Members_Roles(Members_Roles)
{}

Group::Group(long long Id,string name, vector<int> &users, set<MessageModel> &messages, map<int, Roles> &Members_Roles, string ImagePath,
    string Description,bool Type_Permission) :
ChatRoomModel(Id,1,name, users, messages),
Members_Roles(Members_Roles),
    Type_Permission(Type_Permission),
ImagePath(ImagePath),
Description(Description)
{}

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
    user.getChatRooms().push(id);
    user.save();
    users.push_back(Member);
}

void Group::Remove_Member(int Member) {
    users.erase(find(users.begin(), users.end(), Member));
}

const Group& Group::createGroup(string name, int adminId, string imagePath, string description, bool type_perm) {
    vector<int> userIds;
    map<int, Roles> roles;
    set<MessageModel> messages;

    userIds.push_back(adminId);
    roles[adminId] = Roles::ADMIN;

    Group g(name, userIds, messages, roles, imagePath, description, type_perm);
    g.save();
    return g;
}

json Group::toJson()
{
    json json;
    json["type"] = 1;
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

Group Group::fromJson(const json &json){
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
    return Group(
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
