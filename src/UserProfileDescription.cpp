#ifndef USERPROFILEDESCRIPTION_CPP
#define USERPROFILEDESCRIPTION_CPP
#include "UserProfileDescription.h"

#include <utility>

UserProfileDescription::UserProfileDescription():
Id(++Id_Generator),Name("User"+to_string(Id)),ImagePath("defaultPhoto"),
About("I use Rghyapp"),Phone("Not avaliable"),VisiabilityOption(0)
{}

UserProfileDescription::UserProfileDescription(
	long long Id
	, string ImagePath
	, string About
	, string Name
	, string Phone
	, vector<string> SocialMediaLinks
	, bool VisiabilityOption
) : Id(Id),ImagePath(std::move(ImagePath)),About(std::move(About)),Name(std::move(Name)),Phone(std::move(Phone)),
	SocialMediaLinks(std::move(SocialMediaLinks)),VisiabilityOption(VisiabilityOption)
{}

// UserProfileDescription::UserProfileDescription(
// 	string ImagePath,
// 	string About,
// 	string Name,
// 	string Phone,
// 	vector<string> SocialMediaLink,
// 	bool VisiabilityOption
// ) : Id(++Id_Generator), ImagePath(ImagePath), About(std::move(About)), Name(Name),Phone(Phone), SocialMediaLinks(std::move(SocialMediaLink)), VisiabilityOption(VisiabilityOption) {}

UserProfileDescription::UserProfileDescription(
	string ImagePath,
	string About,
	vector<string> SocialMediaLink,
	bool VisiabilityOption
) : Id(++Id_Generator), About(std::move(About)), ImagePath(std::move(ImagePath)), VisiabilityOption(VisiabilityOption), SocialMediaLinks(std::move(SocialMediaLink)) {}



long long UserProfileDescription::getId() const {
	return Id;
}

const string& UserProfileDescription::getImagePath() const
{
	return ImagePath;
}

const string& UserProfileDescription::getAbout() const
{
	return About;
}

const string& UserProfileDescription::getName() const
{
	return Name;
}

const string& UserProfileDescription::getPhone() const
{
	return Phone;
}

vector<std::string> UserProfileDescription::getSocialMediaLinks()
{
	return SocialMediaLinks;
}

bool UserProfileDescription::getVisibilityOption() const
{
	return VisiabilityOption;
}

void UserProfileDescription::setImagePath(string& ImagePath)
{
	this->ImagePath = ImagePath;
}

void UserProfileDescription::setAbout(string& About)
{
	this->About = About;
}

void UserProfileDescription::setName(string& Name)
{
	this->Name = Name;
}

void UserProfileDescription::setPhone(string& Phone)
{
	this->Phone = Phone;
}

void UserProfileDescription::setSocialMediaLinks(vector<string> SocialMediaLinks)
{
	this->SocialMediaLinks = SocialMediaLinks;
}

void UserProfileDescription::setVisibilityOption(bool VisiabilityOption)
{
	this->VisiabilityOption = VisiabilityOption;
}

json UserProfileDescription::toJson() {
	json json;
	json["id"] = Id;
	json["imagePath"] = ImagePath;
	json["About"] = About;
	json["Name"] = Name;
	json["Phone"] = Phone;
	json["SocialMediaLinks"] = SocialMediaLinks;
	json["VisibilityOption"] = VisiabilityOption;
	return json;
}

UserProfileDescription UserProfileDescription::fromJson(json json) {
	return {
		json["id"].get<long long>(),
		json["imagePath"].get<string>(),
		json["About"].get<string>(),
		json["Name"].get<string>(),
		json["Phone"].get<string>(),
		json["SocialMediaLinks"].get<vector<string>>(),
		json["VisibilityOption"].get<bool>()
	};
}

#endif