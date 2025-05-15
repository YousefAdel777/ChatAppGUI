//
// Created by M.Ramadan on 4/16/25.
//

#ifndef USERPROFILEDESCRIPTION_H
#define USERPROFILEDESCRIPTION_H
#include <string>
#include <vector>
#include <json.hpp>
using namespace nlohmann;

// #include "User.h"
using namespace std;
class UserProfileDescription {
private:
	long long Id;
	string ImagePath;
	string About;
	string Name;
	string Phone;
	vector<string>SocialMediaLinks;
	bool VisiabilityOption;
public :
    inline static long long Id_Generator = 0;

	UserProfileDescription();
	UserProfileDescription(long long Id, string ImagePath, string About, string Name, string Phone, vector<string>SocialMediaLink, bool VisiabilityOption);
	UserProfileDescription(string ImagePath,string About,vector<string>SocialMediaLink,bool VisiabilityOption);

    // Getters
    [[nodiscard]] long long getId() const;
    [[nodiscard]] const string& getImagePath() const;
    [[nodiscard]] const string& getAbout() const;
    [[nodiscard]] const string& getName() const;
    [[nodiscard]] const string& getPhone() const;
    vector<string> getSocialMediaLinks();
    [[nodiscard]] bool getVisibilityOption() const;

    // Setters
    void setImagePath(string& path);
    void setAbout(string& text);
    void setName(string& newName);
    void setPhone(string& newPhone);
    void setSocialMediaLinks(vector<string> links);
    void setVisibilityOption(bool option);
	json toJson();
	static UserProfileDescription fromJson(json json);

};
#endif
