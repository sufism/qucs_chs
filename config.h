/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */


/* __BEGIN_DECLS should be used at the beginning of your declarations,
   so that C++ compilers don't mangle their names.  Use __END_DECLS at
   the end of C declarations. */
/* #undef __BEGIN_DECLS */
/* #undef __END_DECLS */
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS
# define __END_DECLS
#endif

#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif

typedef double nr_double_t;
typedef int nr_int32_t;
typedef short nr_int16_t;
#define NR_DOUBLE_SIZE 8
#pragma warning(disable:4996)

/* Where the binary files go. */
#define BINARYDIR "/usr/local/bin/"

/* Where the data files go. */
#define BITMAPDIR "/usr/local/share/qucs/bitmaps/"

/* Define if debug output should be supported. */
#define DEBUG 1

/* Where the documentation files go. */
#define DOCDIR "/usr/local/share/qucs/docs/"

/* Define to 1 if you have the <ieeefp.h> header file. */
/* #undef HAVE_IEEEFP_H */

/* Define to 1 if you have the <inttypes.h> header file. */
/* #undef HAVE_INTTYPES_H */

/* Define to 1 if you have the <memory.h> header file. */
/* #undef HAVE_MEMORY_H */

/* Define to 1 if you have the <QtCore/QtCore> header file. */
/* #undef HAVE_QTCORE_QTCORE */

/* Define to 1 if you have the <QtGui/QtGui> header file. */
/* #undef HAVE_QTGUI_QTGUI */

/* Define to 1 if you have the <QtXml/QtXml> header file. */
/* #undef HAVE_QTXML_QTXML */

/* Define to 1 if you have the <stdint.h> header file. */
/* #undef HAVE_STDINT_H */

/* Define to 1 if you have the <stdlib.h> header file. */
/* #undef HAVE_STDLIB_H */

/* Define to 1 if you have the <strings.h> header file. */
/* #undef HAVE_STRINGS_H */

/* Define to 1 if you have the <string.h> header file. */
/* #undef HAVE_STRING_H */

/* Define to 1 if you have the <sys/stat.h> header file. */
/* #undef HAVE_SYS_STAT_H */

/* Define to 1 if you have the <sys/types.h> header file. */
/* #undef HAVE_SYS_TYPES_H */

/* Define to 1 if you have the <unistd.h> header file. */
/* #undef HAVE_UNISTD_H */

/* Where the language files go. */
#define LANGUAGEDIR "/usr/local/share/qucs/lang/"

/* Where the component library files go. */
#define LIBRARYDIR "/usr/local/share/qucs/library/"

/* Define if debug code should be suppressed. */
/* #undef NDEBUG */

/* Where the octave script files go. */
#define OCTAVEDIR "/usr/local/share/qucs/octave/"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "qucs-bugs@lists.sourceforge.net"

/* Define to the full name of this package. */
#define PACKAGE_NAME "qucs"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "qucs 0.0.17"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "qucs"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "0.0.17"

/* Define to 1 if you have the ANSI C header files. */
/* #undef STDC_HEADERS */

/* Define to 1 if the X Window System is missing or not being used. */
/* #undef X_DISPLAY_MISSING */
