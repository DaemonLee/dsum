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
#include "calculateHashes.hpp"

std::string calculateMD5(char *filename)
{

	//Declare some stuff we're going to need
	unsigned char md5Buffer[MD5_DIGEST_LENGTH];
	MD5_CTX mdContext;
	unsigned char data[BUFFER_SIZE];
	int bytes;
	std::stringstream hash;

	//Open a file
	FILE *inFile = fopen (filename, "rb");

	//Check if the file opened succesfully
	if(inFile == nullptr) {
		std::cout << filename << " can't be opened." << std::endl;
		hash << "NULL";
		return hash.str();
	}

	
	//Generate the MD5 hash
	MD5_Init (&mdContext);
	while ((bytes = fread (data, 1, BUFFER_SIZE, inFile)) != 0) {
		MD5_Update(&mdContext, data, bytes);
	}
	MD5_Final(md5Buffer,&mdContext);

	//Close the file
	fclose(inFile);

	//Convert it to a readable format
	for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
		hash << std::hex << std::setw(2) << std::setfill('0') << (int)md5Buffer[i];
	}

	return hash.str();
}

std::string calculateSHA1(char *filename) {

	//Declare some stuff we're going to need
	unsigned char sha1Buffer[SHA_DIGEST_LENGTH];
	SHA_CTX mdContext;
	unsigned char data[BUFFER_SIZE];
	int bytes;
	std::stringstream hash;

	//Open a file
	FILE *inFile = fopen (filename, "rb");

	//Check if the file opened succesfully
	if (inFile == nullptr) {
		std::cout << filename << " can't be opened." << std::endl;
		hash << "NULL";
		return hash.str();
	}

	
	//Generate the SHA1 hash
	SHA1_Init(&mdContext);
	while((bytes = fread (data, 1, BUFFER_SIZE, inFile)) != 0) {
		SHA1_Update (&mdContext, data, bytes);
	}
	SHA1_Final(sha1Buffer,&mdContext);

	//Close the file
	fclose(inFile);

	//Convert it to a readable format
	for(int i = 0; i < SHA_DIGEST_LENGTH; i++) {
		hash << std::hex << std::setw(2) << std::setfill('0') << (int)sha1Buffer[i];
	}

	return hash.str();
}


std::string calculateCRC32(char *filename)
{

	//Declare some stuff we're going to need
	unsigned int length = 1;
	int bytes;
	unsigned char buffer[BUFFER_SIZE];
	unsigned long crc = crc32(0L, Z_NULL, 0);
	std::stringstream hash;

	//Open a file
	FILE *inFile = fopen(filename, "rb");

	//Check if the file opened succesfully
	if(inFile == nullptr) {
		std::cout << filename << " can't be opened." << std::endl;
		hash << "NULL";
		return hash.str();
	}

	//Generate the CRC32 hash
	while((bytes = fread (buffer, 1, length, inFile)) != 0) {
		crc = crc32(crc, buffer, length);
	}

	//Close the file
	fclose(inFile);

	//Convert it to a readable format
	hash << std::uppercase << std::hex << crc;

	return hash.str();
}