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
#include "dsumCalculateHashes.hpp"

std::string calculateMD5ToString(char *filename)
{
	unsigned char md5Buffer[MD5_DIGEST_LENGTH];
	int i;
	FILE *inFile = fopen (filename, "rb");
	MD5_CTX mdContext;
	int bytes;
	unsigned char data[BUFFER_SIZE];
	char hexBuffer[32];
	std::string hash;
	if (inFile == nullptr) {
		printf ("%s can't be opened.\n", filename);
		hash = "";
		return hash;
	}
	MD5_Init (&mdContext);
	while ((bytes = fread (data, 1, BUFFER_SIZE, inFile)) != 0) {
		MD5_Update (&mdContext, data, bytes);
	}
	MD5_Final (md5Buffer,&mdContext);
	for(i = 0; i < MD5_DIGEST_LENGTH; i++) {
		sprintf(hexBuffer, "%02x", md5Buffer[i]);
		hash.append(hexBuffer);
	}
	fclose (inFile);
	return hash;
}
unsigned long calculateCRC32(char *filename)
{
	FILE *inFile = fopen (filename, "r");
	unsigned int length = 1;
	int bytes;
	unsigned char buffer[BUFFER_SIZE];
	uLong crc = crc32(0L, Z_NULL, 0);

	while ((bytes = fread (buffer, 1, length, inFile)) != 0) {
		crc = crc32(crc, buffer, length);
	}
	
	fclose (inFile);

	return crc;
}