#ifndef 16_MYLIBRARY_GLOBAL_H
#define 16_MYLIBRARY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(16_MYLIBRARY_LIBRARY)
#  define 16_MYLIBRARYSHARED_EXPORT Q_DECL_EXPORT
#else
#  define 16_MYLIBRARYSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // 16_MYLIBRARY_GLOBAL_H
