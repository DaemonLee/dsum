/*	dsum - A universal hash integrity checker with an automatic file name parser for commonly checked things.
	Copyright 2014 Daemon Lee Schmidt

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

    	http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include "dsumCalculateHashes.hpp"
#include "dsumHashesToString.hpp"


int main(int argc,char *argv[]) {

	std::string selectedMethod;
	
	if(argc >= 2) {
		selectedMethod = std::string(argv[1]);
		std::transform(selectedMethod.begin(), selectedMethod.end(), selectedMethod.begin(), ::toupper);
	}

	switch(argc) {
	case 2:
		std::cout << calculateMD5ToString(argv[1]) << "  " << argv[1] << std::endl;
		break;
	case 3:
		if(selectedMethod == "MD5") {
			std::cout << calculateMD5ToString(argv[2]) << "  " << argv[2] << std::endl;
			break;
		} else if(std::string(argv[1]) == "CRC32" || "CRC") {
			std::cout << hashToString(calculateCRC32(argv[2])) << "  " << argv[2] << std::endl;
			break;
		} else {
			std::cout << "dsum doesn't have support for that hashing method yet!" << std::endl;
		}
	default:
		std::cout << "Usage: dsum <hashing method | default: MD5> \"filename\"" << std::endl;
	}
}
