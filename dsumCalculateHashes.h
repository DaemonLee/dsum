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