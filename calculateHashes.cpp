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

std::string calculateHash(char *filename, char *algorithm) {
	//Declare some stuff we're going to need
	EVP_MD_CTX *mdctx;
	mdctx = EVP_MD_CTX_create();
	const EVP_MD *md;
	unsigned char md_value[EVP_MAX_MD_SIZE];
	unsigned int md_len, i;
	int bytesRead;
	std::stringstream hash;

	//All the algorithms!
	OpenSSL_add_all_algorithms();

	//Get and check if the algorithm is supported
	md = EVP_get_digestbyname(algorithm);
	if(md == nullptr) {
		std::cout << algorithm << " is an unknown hashing method!" << std::endl;
		exit(1);
	}

	//Open a file
	FILE *inFile = fopen (filename, "rb");

	//Check if the file opened succesfully
	if(inFile == nullptr) {
		std::cout << filename << " can't be opened." << std::endl;
		hash << "NULL";
		exit(1);
		//return hash.str(); //Maybe switch to exit();
	}

	//Generate the hash
	EVP_DigestInit_ex(mdctx, md, NULL);
	while ((bytesRead = fread (md_value, 1, EVP_MAX_MD_SIZE, inFile)) != 0) {
		EVP_DigestUpdate(mdctx, md_value, bytesRead);
	}
	EVP_DigestFinal_ex(mdctx, md_value, &md_len);

	//Close the file and clean up
	EVP_MD_CTX_destroy(mdctx);
	fclose(inFile);

	//Convert it to a readable format
	for(int i = 0; i < md_len; i++) {
		hash  << std::hex << std::setw(2) << std::setfill('0') << (int)md_value[i];
	}

	return hash.str();
}