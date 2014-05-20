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