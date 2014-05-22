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
#include <string>
#include "calculateHashes.hpp"
#include "filenameParser.hpp"


int main(int argc,char *argv[]) {
	std::string selectedAlgorithm;
	std::string filename;
	
	if(argc >= 3) {
		selectedAlgorithm = std::string(argv[1]);
		std::transform(selectedAlgorithm.begin(), selectedAlgorithm.end(), selectedAlgorithm.begin(), ::toupper);

		filename = std::string(argv[2]);
	} else if(argc == 2) {
		
	}

	switch(argc) {
	case 2:
		std::cout << calculateHash(argv[1], (char *)"MD5") << "  " << argv[1] << std::endl;
		break;
	case 3:
		if(selectedAlgorithm != "CRC32") {
			std::cout << calculateHash(argv[2], argv[1]) << "  " << argv[2] << std::endl;
			break;
		} else if(selectedAlgorithm == "CRC32") {
			std::cout << calculateCRC32(argv[2]) << "  " << argv[2] << std::endl;
			break;
		} else {
			std::cout << "dsum doesn't have support for that hashing method yet!" << std::endl;
			break;
		}
	default:
		std::cout << "Usage: dsum <hashing method | default: MD5> \"filename\"" << std::endl;
	}
}