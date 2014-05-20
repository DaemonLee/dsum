/*	dsum - A universal hash integrity checker with an automatic file name parser for commonly checked things.
	Copyright (C) 2014  Daemon Lee Schmidt

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
