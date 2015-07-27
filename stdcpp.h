#ifndef CRYPTOPP_STDCPP_H
#define CRYPTOPP_STDCPP_H

#if _MSC_VER >= 1500
#define _DO_NOT_DECLARE_INTERLOCKED_INTRINSICS_IN_MEMORY
#include <intrin.h>
#endif

#include <stddef.h>
#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

// http://marshall.calepin.co/c-and-xcode-46.html. LLVM places unique_ptr in std:: when using
//   using -stdlib=libc++ (and not std::tr1::) regardless of C++03/C++11. We detect can detect
//   it with _LIBCPP_VERSION, but its not accurate because Apple's built-in Clang behaves
//   differently than a LLVM downloaded and compiled CLang. So we fall back to Clang's
//   __has_include (http://clang.llvm.org/docs/LanguageExtensions.html#id3).
#if (__cplusplus >= 201103L) && !defined(__clang__)
#    include <memory>
#elif defined(__clang__)
#   if (__has_include(<tr1/memory>))
#      include <tr1/memory>
#   endif
#elif (__cplusplus < 201103L)
#   include <tr1/memory>
#else
#   include <memory>
#endif

#include <map>
#include <vector>
#include <string>
#include <exception>
#include <typeinfo>
#include <algorithm>
#include <functional>

#ifdef CRYPTOPP_INCLUDE_VECTOR_CC
// workaround needed on Sun Studio 12u1 Sun C++ 5.10 SunOS_i386 128229-02 2009/09/21
#include <vector.cc>
#endif

// for alloca
// #ifdef __sun
// #include <alloca.h>
// #elif defined(__MINGW32__) || defined(__BORLANDC__)
// #include <malloc.h>
// #endif

// Rijdael uses alloca. Just include it for everyone....
#include <alloca.h>

#if defined(__MINGW32__) || defined(__BORLANDC__)
# include <malloc.h>
#endif

#ifdef _MSC_VER
#pragma warning(disable: 4231)	// re-disable this
#ifdef _CRTAPI1
#define CRYPTOPP_MSVCRT6
#endif
#endif

#endif
