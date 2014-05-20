#include <iostream>
#include "dsumCalculateHashes.h"
#include "dsumHashesToString.h"

int main(int argc,char *argv[]) {
	
	switch(argc) {
	case 2:
		std::cout << calculateMD5ToString(argv[1]) << "  " << argv[1] << std::endl;
		break;
	case 3:
		if(std::string(argv[1]) == "md5") {
			std::cout << calculateMD5ToString(argv[2]) << "  " << argv[2] << std::endl;
			break;
		} else if(std::string(argv[1]) == "crc32") {
			std::cout << hashToString(calculateCRC32(argv[2])) << "  " << argv[2] << std::endl;
			break;
		} else {
			std::cout << "dsum doesn't have support for that hashing method yet!" << std::endl;
		}
	default:
		std::cout << "Usage: dsum <hashing method | default: MD5> \"filename\"" << std::endl;
	}
}
