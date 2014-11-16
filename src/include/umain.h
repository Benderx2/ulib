#ifndef __UMAIN_H
#define __UMAIN_H
#define VER_MAJOR 0
#define VER_MIDDLE 1
#define VER_MINOR 1
typedef struct _ulib_struct {
	int version_major;
	int version_middle;
	int version_minor;
	// Error code set by functions (future use)
	int ulib_errno;
} ulib_struct;
ulib_struct* init_ulib(void);
#endif
