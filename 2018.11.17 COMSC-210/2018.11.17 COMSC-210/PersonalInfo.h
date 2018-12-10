#ifndef PERSONAL_INFO_H
#define PERSONAL_INFO_H
#include <string>


class PersonalInfo
{
private:
	std::string firstName;
	std::string lastName;
	std::string companyName;
	std::string address;
	std::string city;
	std::string county;
	std::string state;
	std::string zip;
	long long unsigned phone1;
	long long unsigned phone2;
	std::string email;
	std::string web;
public:
	long long unsigned getValue()
	{
		return phone1;
	}
	std::string getFirstName()
	{
		return firstName;
	}
};
#endif // !PERSONAL_INFO_H
