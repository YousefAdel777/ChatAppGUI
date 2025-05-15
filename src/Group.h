//
// Created by dell on 4/20/2025.
//

#ifndef GROUP_H
#define GROUP_H
#include "ChatRoom.h"
#include <string>
using namespace std;
enum class Roles {
    NOT_MEMBER,
    ADMIN,
    USER,
    OWNER
};
class Group : ChatRoom {
    string ImagePath;
    string Description;
    class GroupSettings {
        bool Type_Permission;
        bool Add_Permission;
        int Max_Members;
        bool Media_Allowed;
    public:
        GroupSettings() {
            Type_Permission = false;
            Add_Permission = false;
            Max_Members = 1;
            Media_Allowed = false;
        }
        GroupSettings(bool Type_Permission, bool Add_Permission, int Max_Members, bool Media_Allowed) :
        Type_Permission(Type_Permission), Add_Permission(Add_Permission),Max_Members(Max_Members),Media_Allowed(Media_Allowed)
        {}
        bool get_Type_Permission() const {
            return Type_Permission;
        }
        bool get_Add_Permission() const {
            return Add_Permission;
        }
        int get_Max_Members() const {
            return Max_Members;
        }
        bool get_Media_Allowed() const {
            return Media_Allowed;
        }
        void set_Type_Permission(bool Type_Permission) {
            this->Type_Permission = Type_Permission;
        }
        void set_Add_Permission(bool Add_Permission) {
            this->Add_Permission = Add_Permission;
        }
        void set_Max_Members(int Max_Members) {
            this->Max_Members = Max_Members;
        }
        void set_Media_Allowed(bool Media_Allowed) {
            this->Media_Allowed = Media_Allowed;
        }
    } settings;
    map<int,Roles> Members_Roles;
public:
    Group();
    Group(
        string &name,
        vector<User> &users,
        vector<Message> &messages,
        map<int,Roles> &MemberRoles,
        string &ImagePath,
        string &Description,
        GroupSettings &settings
    );
    Group(
        long long Id,
        string &name,
        vector<User> &users,
        vector<Message> &messages,
        map<int,Roles> &MemberRoles,
        string &ImagePath,
        string &Description
        ,GroupSettings &settings
    );
    const string& getImagePath() const;
    const string& getDescription() const;
    Roles getRoleOf(int Member) const;
    void setImagePath(string &ImagePath);
    void setDescription(string &Description);
    GroupSettings& getSettings();
    void Change_Member_Role(int member,Roles Role);
    void Change_Member_Role(User& member,Roles Role);
    void Add_Member(User& member);
    void Add_Member(int Member);
    void Remove_Member(User& member);
    void Remove_Member(int Member);

};



#endif //GROUP_H
