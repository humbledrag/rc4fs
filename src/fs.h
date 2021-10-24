#ifndef RC4FS_FS_H
#define RC4FS_FS_H

#define FUSE_USE_VERSION 31

#include <fuse.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

char *ARGV_REAL_PATH;

/*
 * struct fuse_operations {
 * int (*getattr) (const char *, struct stat *);
 * int (*readlink) (const char *, char *, size_t);
 * int (*getdir) (const char *, fuse_dirh_t, fuse_dirfil_t);
 * int (*mknod) (const char *, mode_t, dev_t);
 * int (*mkdir) (const char *, mode_t);
 * int (*unlink) (const char *);
 * int (*rmdir) (const char *);
 * int (*symlink) (const char *, const char *);
 * int (*rename) (const char *, const char *);
 * int (*link) (const char *, const char *);
 * int (*chmod) (const char *, mode_t);
 * int (*chown) (const char *, uid_t, gid_t);
 * int (*truncate) (const char *, off_t);
 * int (*utime) (const char *, struct utimbuf *);
 * int (*open) (const char *, struct fuse_file_info *);
 * int (*read) (const char *, char *, size_t, off_t,
 * 	     struct fuse_file_info *);
 * int (*write) (const char *, const char *, size_t, off_t,
 * 	      struct fuse_file_info *);
 * int (*statfs) (const char *, struct statvfs *);
 * int (*flush) (const char *, struct fuse_file_info *);
 * int (*release) (const char *, struct fuse_file_info *);
 * int (*fsync) (const char *, int, struct fuse_file_info *);
 * int (*setxattr) (const char *, const char *, const char *, size_t, int);
 * int (*getxattr) (const char *, const char *, char *, size_t);
 * int (*listxattr) (const char *, char *, size_t);
 * int (*removexattr) (const char *, const char *);
 * int (*opendir) (const char *, struct fuse_file_info *);
 * int (*readdir) (const char *, void *, fuse_fill_dir_t, off_t,
 * 		struct fuse_file_info *);
 * int (*releasedir) (const char *, struct fuse_file_info *);
 * int (*fsyncdir) (const char *, int, struct fuse_file_info *);
 * void *(*init) (struct fuse_conn_info *conn);
 * void (*destroy) (void *);
 * int (*access) (const char *, int);
 * int (*create) (const char *, mode_t, struct fuse_file_info *);
 * int (*ftruncate) (const char *, off_t, struct fuse_file_info *);
 * int (*fgetattr) (const char *, struct stat *, struct fuse_file_info *);
 * int (*lock) (const char *, struct fuse_file_info *, int cmd,
 * 	     struct flock *);
 * int (*utimens) (const char *, const struct timespec tv[2]);
 * int (*bmap) (const char *, size_t blocksize, uint64_t *idx);
 * int (*ioctl) (const char *, int cmd, void *arg,
 * 	      struct fuse_file_info *, unsigned int flags, void *data);
 * int (*poll) (const char *, struct fuse_file_info *,
 * 	     struct fuse_pollhandle *ph, unsigned *reventsp);
 * int (*write_buf) (const char *, struct fuse_bufvec *buf, off_t off,
 * 		  struct fuse_file_info *);
 * int (*read_buf) (const char *, struct fuse_bufvec **bufp,
 * 		 size_t size, off_t off, struct fuse_file_info *);
 * int (*flock) (const char *, struct fuse_file_info *, int op);
 * int (*fallocate) (const char *, int, off_t, off_t,
 * 		  struct fuse_file_info *);
 * };
 */

int fs_getattr(const char *, struct stat *, struct fuse_file_info *);
int fs_readdir(const char *, void *, fuse_fill_dir_t, off_t, struct fuse_file_info *);
int fs_open(const char *, struct fuse_file_info *);
int fs_read (const char *, size_t, off_t, struct fuse_file_info *);
int fs_write(const char *, const char *, size_t, off_t, struct fuse_file_info *);
int fs_getxattr(const char *, const char *, char *, size_t);

struct fuse_operations fs_ops;

#endif
