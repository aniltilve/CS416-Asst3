/*
  Copyright (C) 2012 Joseph J. Pfeiffer, Jr., Ph.D. <pfeiffer@cs.nmsu.edu>

  This program can be distributed under the terms of the GNU GPLv3.
  See the file COPYING.

  There are a couple of symbols that need to be #defined before
  #including all the headers.
*/

#ifndef _PARAMS_H_
#define _PARAMS_H_

// The FUSE API has been changed a number of times.  So, our code
// needs to define the version of the API that we assume.  As of this
// writing, the most current API version is 26
#define FUSE_USE_VERSION 26

// need this to get pwrite().  I have to use setvbuf() instead of
// setlinebuf() later in consequence.
#define _XOPEN_SOURCE 500

//size of disk
#define DISK 16777216

//inode structure
struct inode{
	int owner;
	int type;
	int lastModified;
	int lastAccess;
	int permissions;
	int size;
	int blockPtr;
};

//superblock structure
struct superBlock{
	int fsSize;
	int freeBlocks;
	//TODO: list of free blocks
	int indexFreeBlock;
	int inodeListSize;
	int freeInodes;
	//TODO: list of inodes
	int indexFreeInode;
};

// maintain bbfs state in here
#include <limits.h>
#include <stdio.h>
struct sfs_state {
    FILE *logfile;
    char *diskfile;
};
#define SFS_DATA ((struct sfs_state *) fuse_get_context()->private_data)

#endif
