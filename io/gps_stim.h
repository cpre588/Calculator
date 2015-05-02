//////////////////////////////////////////////////////////////////////
// C++ header file generated by SCRC V2.1
// Design: gps_stim
// File:   gps_stim.h
// Time:   Sat May  2 16:28:51 2015
//////////////////////////////////////////////////////////////////////

#include <specc.h>
#include <longlong.h>
#include <bit.h>

// named user-defined type declarations //////////////////////////////

struct _IO_FILE;
struct _IO_FILE_plus;
struct _IO_jump_t;
struct _IO_marker;
struct __gconv_info;
struct __gconv_loaded_object;
struct __gconv_step;
struct __gconv_step_data;
struct __gconv_trans_data;
struct alt_processed;
struct alt_send_data;
struct fuel_processed;
struct fuel_send_data;
struct gps_processed;
struct gps_send_data_t;

// named enumerator type definitions /////////////////////////////////

#line 205 "/usr/include/libio.h"
enum __codecvt_result { __codecvt_ok=0,
    __codecvt_partial=1,
    __codecvt_error=2,
    __codecvt_noconv=3
};

// unnamed enumerator type definitions ///////////////////////////////

#line 39 "/usr/include/gconv.h"
enum { __GCONV_OK=0,
    __GCONV_NOCONV=1,
    __GCONV_NODB=2,
    __GCONV_NOMEM=3,

    __GCONV_EMPTY_INPUT=4,
    __GCONV_FULL_OUTPUT=5,
    __GCONV_ILLEGAL_INPUT=6,
    __GCONV_INCOMPLETE_INPUT=7,

    __GCONV_ILLEGAL_DESCRIPTOR=8,
    __GCONV_INTERNAL_ERROR=9
};

#line 57 "/usr/include/gconv.h"
enum { __GCONV_IS_LAST=1,
    __GCONV_IGNORE_ERRORS=2
};

// struct/union type definitions /////////////////////////////////////

#line 64 "/usr/include/bits/types.h"
typedef struct { long int __val[2]; }
    __quad_t;

#line 269 "/usr/include/libio.h"
struct _IO_FILE { int _flags;




    char *_IO_read_ptr;
    char *_IO_read_end;
    char *_IO_read_base;
    char *_IO_write_base;
    char *_IO_write_ptr;
    char *_IO_write_end;
    char *_IO_buf_base;
    char *_IO_buf_end;

    char *_IO_save_base;
    char *_IO_backup_base;
    char *_IO_save_end;

    struct _IO_marker *_markers;

    struct _IO_FILE *_chain;

    int _fileno;



    int _flags2;

    long int _old_offset;



    unsigned short int _cur_column;
    char _vtable_offset;
    char _shortbuf[1];



    void *_lock;

#line 316 "/usr/include/libio.h"
    __quad_t _offset;

#line 325 "/usr/include/libio.h"
    void *__pad1;
    void *__pad2;
    void *__pad3;
    void *__pad4;
    unsigned int __pad5;

    int _mode;

    char _unused2[40];
};

#line 184 "/usr/include/libio.h"
struct _IO_marker { struct _IO_marker *_next;
    struct _IO_FILE *_sbuf;



    int _pos;
};

#line 78 "/usr/include/wchar.h"
typedef struct { int __count;




    union { unsigned int __wch; char __wchb[4]; } __value; }
    __mbstate_t;

#line 147 "/usr/include/gconv.h"
struct __gconv_step_data { unsigned char *__outbuf;
    unsigned char *__outbufend;



    int __flags;



    int __invocation_counter;



    int __internal_use;

    __mbstate_t *__statep;
    __mbstate_t __state;



    struct __gconv_trans_data *__trans;
};

#line 174 "/usr/include/gconv.h"
struct __gconv_info { unsigned int __nsteps;
    struct __gconv_step *__steps;
    struct __gconv_step_data __data[1];
};

#line 117 "/usr/include/gconv.h"
struct __gconv_step { struct __gconv_loaded_object *__shlib_handle;
    const char *__modname;

    int __counter;

    char *__from_name;
    char *__to_name;

    int (*__fct)(struct __gconv_step *, struct __gconv_step_data *, const unsigned char **, const unsigned char *, unsigned char **, unsigned int *, int, int);
    unsigned int (*__btowc_fct)(struct __gconv_step *, unsigned char);
    int (*__init_fct)(struct __gconv_step *);
    void (*__end_fct)(struct __gconv_step *);



    int __min_needed_from;
    int __max_needed_from;
    int __min_needed_to;
    int __max_needed_to;


    int __stateful;

    void *__data;
};

#line 106 "/usr/include/gconv.h"
struct __gconv_trans_data { int (*__trans_fct)(struct __gconv_step *, struct __gconv_step_data *, void *, const unsigned char *, const unsigned char **, const unsigned char *, unsigned char **, unsigned int *);
    int (*__trans_context_fct)(void *, const unsigned char *, const unsigned char *, unsigned char *, unsigned char *);
    void (*__trans_end_fct)(void *);
    void *__data;
    struct __gconv_trans_data *__next;
};

#line 19 "../include/types.h"
struct alt_processed { double delta_alt;
    char dir;
};

#line 14 "../include/types.h"
struct alt_send_data { unsigned int time;
    double alt;
};

#line 29 "../include/types.h"
struct fuel_processed { double time_left;
    double fuel_left;
};

#line 24 "../include/types.h"
struct fuel_send_data { unsigned int time;
    double vol;
};

#line 8 "../include/types.h"
struct gps_processed { double speed;
    char dir1;
    char dir2;
};

#line 2 "../include/types.h"
struct gps_send_data_t { unsigned int ts;
    double lat; double lon;
    char ns; char ew;
};

#line 68 "/usr/include/bits/types.h"
typedef struct { unsigned long int __val[2]; }
    __u_quad_t;

#line 147 "/usr/include/bits/types.h"
typedef struct { int __val[2]; } __fsid_t;

#line 28 "/usr/include/_G_config.h"
typedef struct { long int __pos;
    __mbstate_t __state; }
    _G_fpos_t;


typedef struct { __quad_t __pos;
    __mbstate_t __state; }
    _G_fpos64_t;

#line 47 "/usr/include/_G_config.h"
typedef union { struct __gconv_info __cd;




    struct { struct __gconv_info __cd; struct __gconv_step_data __data; } __combined; }
    _G_iconv_t;

// type synonym definitions //////////////////////////////////////////

#line 5 "../include/types.h"
typedef struct gps_send_data_t gps_send_data;

#line 55 "/usr/include/_G_config.h"
typedef int _G_int16_t;
typedef int _G_int32_t;
typedef unsigned int _G_uint16_t;
typedef unsigned int _G_uint32_t;

#line 34 "/usr/include/bits/types.h"
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef char __int8_t;
typedef unsigned char __uint8_t;
typedef short int __int16_t;
typedef unsigned short int __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;

#line 138 "/usr/include/bits/types.h"
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;

typedef unsigned int __mode_t;
typedef unsigned int __nlink_t;
typedef long int __off_t;

typedef int __pid_t;

typedef long int __clock_t;
typedef unsigned long int __rlim_t;

typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef long int __swblk_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void *__timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;



typedef unsigned long int __fsblkcnt_t;



typedef unsigned long int __fsfilcnt_t;


typedef int __ssize_t;




typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


typedef int __intptr_t;


typedef unsigned int __socklen_t;

#line 70 "/usr/include/gconv.h"
typedef int (*__gconv_fct)(struct __gconv_step *, struct __gconv_step_data *, const unsigned char **, const unsigned char *, unsigned char **, unsigned int *, int, int);




typedef unsigned int (*__gconv_btowc_fct)(struct __gconv_step *, unsigned char);


typedef int (*__gconv_init_fct)(struct __gconv_step *);
typedef void (*__gconv_end_fct)(struct __gconv_step *);



typedef int (*__gconv_trans_fct)(struct __gconv_step *, struct __gconv_step_data *, void *, const unsigned char *, const unsigned char **, const unsigned char *, unsigned char **, unsigned int *);

#line 91 "/usr/include/gconv.h"
typedef int (*__gconv_trans_context_fct)(void *, const unsigned char *, const unsigned char *, unsigned char *, unsigned char *);




typedef int (*__gconv_trans_query_fct)(const char *, const char ***, unsigned int *);



typedef int (*__gconv_trans_init_fct)(void **, const char *);
typedef void (*__gconv_trans_end_fct)(void *);

#line 177 "/usr/include/gconv.h"
typedef struct __gconv_info *__gconv_t;

#line 177 "/usr/include/libio.h"
typedef void _IO_lock_t;

#line 338 "/usr/include/libio.h"
typedef struct _IO_FILE _IO_FILE;

#line 361 "/usr/include/libio.h"
typedef int __io_read_fn(void *, char *, unsigned int);

#line 369 "/usr/include/libio.h"
typedef int __io_write_fn(void *, const char *, unsigned int);

#line 378 "/usr/include/libio.h"
typedef int __io_seek_fn(void *, __quad_t *, int);


typedef int __io_close_fn(void *);

#line 46 "/usr/include/stdio.h"
typedef struct _IO_FILE FILE;

#line 62 "/usr/include/stdio.h"
typedef struct _IO_FILE __FILE;

#line 43 "/usr/lib/gcc/i386-redhat-linux/4.1.2/include/stdarg.h"
typedef void *__gnuc_va_list;

#line 214 "/usr/lib/gcc/i386-redhat-linux/4.1.2/include/stddef.h"
typedef unsigned int size_t;

#line 355 "/usr/lib/gcc/i386-redhat-linux/4.1.2/include/stddef.h"
typedef unsigned int wint_t;

// class declarations ////////////////////////////////////////////////

#line 417 "gps_stim.h"
class i_sender;
class GPS_stim;

// interface class definitions ///////////////////////////////////////

#line 24 "/usr/local/scrc/import/i_sender.sc"
class i_sender
{
private:
public:

#line 429 "gps_stim.h"
    virtual ~i_sender(void){};

#line 26 "/usr/local/scrc/import/i_sender.sc"
    virtual void send(const void *, unsigned long int) = 0;
private:
};

// behavior and channel class definitions ////////////////////////////

#line 6 "gps_stim.sc"
class GPS_stim : public _specc::behavior
{
private:

#line 6 "gps_stim.sc"
    i_sender (&gps_raw); const char *(&file_name);
public:

#line 448 "gps_stim.h"
    GPS_stim(i_sender (&gps_raw), const char *(&file_name));
    virtual ~GPS_stim(void);
    void main(void);
private:
};

// variable and function declarations ////////////////////////////////

#line 27 "/usr/include/bits/sys_errlist.h"
extern int sys_nerr;
extern const char *const sys_errlist[];

#line 343 "/usr/include/libio.h"
extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;

#line 413 "/usr/include/libio.h"
extern "C" int __underflow(struct _IO_FILE *);
extern "C" int __uflow(struct _IO_FILE *);
extern "C" int __overflow(struct _IO_FILE *, int);
extern "C" unsigned int __wunderflow(struct _IO_FILE *);
extern "C" unsigned int __wuflow(struct _IO_FILE *);
extern "C" unsigned int __woverflow(struct _IO_FILE *, unsigned int);

#line 451 "/usr/include/libio.h"
extern "C" int _IO_getc(struct _IO_FILE *);
extern "C" int _IO_putc(int, struct _IO_FILE *);
extern "C" int _IO_feof(struct _IO_FILE *);
extern "C" int _IO_ferror(struct _IO_FILE *);

extern "C" int _IO_peekc_locked(struct _IO_FILE *);

#line 462 "/usr/include/libio.h"
extern "C" void _IO_flockfile(struct _IO_FILE *);
extern "C" void _IO_funlockfile(struct _IO_FILE *);
extern "C" int _IO_ftrylockfile(struct _IO_FILE *);

#line 481 "/usr/include/libio.h"
extern "C" int _IO_vfscanf(struct _IO_FILE *, const char *, void *, int *);

extern "C" int _IO_vfprintf(struct _IO_FILE *, const char *, void *);

extern "C" int _IO_padn(struct _IO_FILE *, int, int);
extern "C" unsigned int _IO_sgetn(struct _IO_FILE *, void *, unsigned int);

extern "C" __quad_t _IO_seekoff(struct _IO_FILE *, __quad_t, int, int);
extern "C" __quad_t _IO_seekpos(struct _IO_FILE *, __quad_t, int);

extern "C" void _IO_free_backup_area(struct _IO_FILE *);

#line 142 "/usr/include/stdio.h"
extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;

#line 154 "/usr/include/stdio.h"
extern "C" int remove(const char *);

extern "C" int rename(const char *, const char *);

#line 171 "/usr/include/stdio.h"
extern "C" struct _IO_FILE *tmpfile(void);

#line 185 "/usr/include/stdio.h"
extern "C" char *tmpnam(char *);

#line 191 "/usr/include/stdio.h"
extern "C" char *tmpnam_r(char *);

#line 203 "/usr/include/stdio.h"
extern "C" char *tempnam(const char *, const char *);

#line 213 "/usr/include/stdio.h"
extern "C" int fclose(struct _IO_FILE *);




extern "C" int fflush(struct _IO_FILE *);

#line 228 "/usr/include/stdio.h"
extern "C" int fflush_unlocked(struct _IO_FILE *);

#line 248 "/usr/include/stdio.h"
extern "C" struct _IO_FILE *fopen(const char *, const char *);

#line 254 "/usr/include/stdio.h"
extern "C" struct _IO_FILE *freopen(const char *, const char *, struct _IO_FILE *);

#line 280 "/usr/include/stdio.h"
extern "C" struct _IO_FILE *fdopen(int, const char *);

#line 303 "/usr/include/stdio.h"
extern "C" void setbuf(struct _IO_FILE *, char *);



extern "C" int setvbuf(struct _IO_FILE *, char *, int, unsigned int);

#line 314 "/usr/include/stdio.h"
extern "C" void setbuffer(struct _IO_FILE *, char *, unsigned int);



extern "C" void setlinebuf(struct _IO_FILE *);

#line 327 "/usr/include/stdio.h"
extern "C" int fprintf(struct _IO_FILE *, const char *, ...);

#line 333 "/usr/include/stdio.h"
extern "C" int printf(const char *, ...);

extern "C" int sprintf(char *, const char *, ...);

#line 342 "/usr/include/stdio.h"
extern "C" int vfprintf(struct _IO_FILE *, const char *, void *);

#line 348 "/usr/include/stdio.h"
extern "C" int vprintf(const char *, void *);

extern "C" int vsprintf(char *, const char *, void *);

#line 357 "/usr/include/stdio.h"
extern "C" int snprintf(char *, unsigned int, const char *, ...);



extern "C" int vsnprintf(char *, unsigned int, const char *, void *);

#line 399 "/usr/include/stdio.h"
extern "C" int fscanf(struct _IO_FILE *, const char *, ...);

#line 405 "/usr/include/stdio.h"
extern "C" int scanf(const char *, ...);

extern "C" int sscanf(const char *, const char *, ...);

#line 441 "/usr/include/stdio.h"
extern "C" int fgetc(struct _IO_FILE *);
extern "C" int getc(struct _IO_FILE *);

#line 448 "/usr/include/stdio.h"
extern "C" int getchar(void);

#line 460 "/usr/include/stdio.h"
extern "C" int getc_unlocked(struct _IO_FILE *);
extern "C" int getchar_unlocked(void);

#line 471 "/usr/include/stdio.h"
extern "C" int fgetc_unlocked(struct _IO_FILE *);

#line 483 "/usr/include/stdio.h"
extern "C" int fputc(int, struct _IO_FILE *);
extern "C" int putc(int, struct _IO_FILE *);

#line 490 "/usr/include/stdio.h"
extern "C" int putchar(int);

#line 504 "/usr/include/stdio.h"
extern "C" int fputc_unlocked(int, struct _IO_FILE *);

#line 512 "/usr/include/stdio.h"
extern "C" int putc_unlocked(int, struct _IO_FILE *);
extern "C" int putchar_unlocked(int);

#line 520 "/usr/include/stdio.h"
extern "C" int getw(struct _IO_FILE *);


extern "C" int putw(int, struct _IO_FILE *);

#line 532 "/usr/include/stdio.h"
extern "C" char *fgets(char *, int, struct _IO_FILE *);

#line 540 "/usr/include/stdio.h"
extern "C" char *gets(char *);

#line 590 "/usr/include/stdio.h"
extern "C" int fputs(const char *, struct _IO_FILE *);

#line 596 "/usr/include/stdio.h"
extern "C" int puts(const char *);

#line 603 "/usr/include/stdio.h"
extern "C" int ungetc(int, struct _IO_FILE *);

#line 610 "/usr/include/stdio.h"
extern "C" unsigned int fread(void *, unsigned int, unsigned int, struct _IO_FILE *);

#line 616 "/usr/include/stdio.h"
extern "C" unsigned int fwrite(const void *, unsigned int, unsigned int, struct _IO_FILE *);

#line 638 "/usr/include/stdio.h"
extern "C" unsigned int fread_unlocked(void *, unsigned int, unsigned int, struct _IO_FILE *);

extern "C" unsigned int fwrite_unlocked(const void *, unsigned int, unsigned int, struct _IO_FILE *);

#line 650 "/usr/include/stdio.h"
extern "C" int fseek(struct _IO_FILE *, long int, int);




extern "C" long int ftell(struct _IO_FILE *);




extern "C" void rewind(struct _IO_FILE *);

#line 674 "/usr/include/stdio.h"
extern "C" int fseeko(struct _IO_FILE *, long int, int);




extern "C" long int ftello(struct _IO_FILE *);

#line 699 "/usr/include/stdio.h"
extern "C" int fgetpos(struct _IO_FILE *, _G_fpos_t *);




extern "C" int fsetpos(struct _IO_FILE *, const _G_fpos_t *);

#line 727 "/usr/include/stdio.h"
extern "C" void clearerr(struct _IO_FILE *);

extern "C" int feof(struct _IO_FILE *);

extern "C" int ferror(struct _IO_FILE *);




extern "C" void clearerr_unlocked(struct _IO_FILE *);
extern "C" int feof_unlocked(struct _IO_FILE *);
extern "C" int ferror_unlocked(struct _IO_FILE *);

#line 747 "/usr/include/stdio.h"
extern "C" void perror(const char *);

#line 759 "/usr/include/stdio.h"
extern "C" int fileno(struct _IO_FILE *);




extern "C" int fileno_unlocked(struct _IO_FILE *);

#line 774 "/usr/include/stdio.h"
extern "C" struct _IO_FILE *popen(const char *, const char *);

#line 780 "/usr/include/stdio.h"
extern "C" int pclose(struct _IO_FILE *);

#line 786 "/usr/include/stdio.h"
extern "C" char *ctermid(char *);

#line 814 "/usr/include/stdio.h"
extern "C" void flockfile(struct _IO_FILE *);



extern "C" int ftrylockfile(struct _IO_FILE *);


extern "C" void funlockfile(struct _IO_FILE *);

//////////////////////////////////////////////////////////////////////
// End of file gps_stim.h
//////////////////////////////////////////////////////////////////////