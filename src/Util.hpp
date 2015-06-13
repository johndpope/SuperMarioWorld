/*
*	Util class: Contains all the methods that can be used anywhere
*/

#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>
#include <SFML/System.hpp>
#include <SFML\Graphics.hpp>

class DisplayableObject;
struct InfoForDisplay;

class Util
{
	public:
		static bool isInteger(std::string& _str);
		static std::vector<std::string> Split(std::string _str, char _sep);
		static bool Util::StringEndsWith(std::string _full, std::string _ending);
};

class CompareInfoForDisplay {
	public:
		bool operator()(InfoForDisplay const& _a, InfoForDisplay const& _b);
};

#endif