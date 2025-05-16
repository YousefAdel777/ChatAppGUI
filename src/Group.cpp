//
// Created by dell on 4/20/2025.
//

#include "Group.h"

Group::Group() :
ImagePath("default image"),
Description("Rghyapp Group"),
settings(GroupSettings())
{}

Group::Group(string &name,vector<int> &users, set<MessageModel> &messages, map<int, Roles> &Members_Roles, string &ImagePath,
    string &Description, GroupSettings &settings) :
ChatRoomModel(name, users, messages),
ImagePath(ImagePath),
Description(Description),
settings(settings),
Members_Roles(Members_Roles)
{}

Group::Group(long long Id, string &name, vector<int> &users, set<MessageModel> &messages, map<int, Roles> &Members_Roles, string &ImagePath,
    string &Description, GroupSettings &settings) :
ChatRoomModel(Id,name, users, messages),
Members_Roles(Members_Roles),
settings(settings),
ImagePath(ImagePath),
Description(Description)
{}

const string & Group::getImagePath() const {
    return ImagePath;
}

const string & Group::getDescription() const {
    return Description;
}

Roles Group::getRoleOf(int Member) const {
    if (Members_Roles.find(Member) == Members_Roles.end()) {
        return Roles::NOT_MEMBER;
    }
    return Members_Roles.at(Member);
}

void Group::setDescription(string &Description) {
    this->Description = Description;
}

Group::GroupSettings & Group::getSettings() {
    return settings;
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
    //todo
    users.push_back(Member);

}
void Group::Remove_Member(int Member) {
    users.erase(find(users.begin(), users.end(), Member));
}
