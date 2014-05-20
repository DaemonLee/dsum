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

#ifndef DSUMCALCULATEHASHES_H
#define DSUMCALCULATEHASHES_H

#include <iostream>
#include <openssl/md5.h>
#include <zlib.h>


#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 65536
#endif

std::string calculateMD5ToString(char *filename);

unsigned long calculateCRC32(char *filename);