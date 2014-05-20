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
#include "dsumCalculateHashes.h"

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