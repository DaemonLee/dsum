dsum
====

dsum is an early prototype for a universal hash integrity checker with an automatic file name parser for commonly checked things. 

INFO
====

Classic make ; make install. make uninstall to remove.

Usage is simple, dsum \<Optional hashing method, defaults to MD5\> filename

Licensed under Apache 2.0 so feel free to fork. (Maybe you can make it not garbage. *wink*)

TODO
====

Add the file name parser, currently planned: Videos with CRC data defauling to CRC32 with an auto "Everything checks out" alert. Option to embed CRC32 data into the filename of the video.

Add more hashing methods.

Pretty the code and docs up.

Coloured output would be nice.
