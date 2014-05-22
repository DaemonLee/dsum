dsum
====

dsum is an early prototype for a universal hash integrity checker with an automatic file name parser for commonly checked things. 

INFO
====

Currently supports MD5, CRC32, SHA1, SHA224, SHA256, SHA384, SHA512 as well as MD4, MDC2 and RIPEMD160 algorithms.

Classic make (make gcc if you want to use the GCC) ; sudo make install. sudo make uninstall to remove.

Usage is simple, dsum \<Optional hashing method | defaults to MD5\> filename

Licensed under Apache 2.0 so feel free to fork. (Maybe you can make it not garbage. *wink*)

TODO
====

Ability to accept multiple files.

Add the file name parser, currently planned: Videos with CRC data defauling to CRC32 with an auto "Everything checks out" alert. 

Option to embed CRC32 data into the filename of the video.

Pretty the code and docs up.

Coloured output would be nice.

Fix mixed case with OpenSSL related stuff.