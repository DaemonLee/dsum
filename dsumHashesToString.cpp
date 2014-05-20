#include "dsumHashesToString.h"

std::string hashToString(unsigned long rawHash)
{
	std::stringstream ss;
	std::string newHash;

	ss << std::uppercase << std::hex << rawHash;
	ss >> newHash;
	return newHash;
}