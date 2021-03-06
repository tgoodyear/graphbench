/* 
 * GraphBench is a benchmark suite for 
 *		microarchitectural simulation of streaming graph workloads
 * 
 * Copyright (C) 2014  Georgia Tech Research Institute
 * Jason Poovey (jason.poovey@gtri.gatech.edu)
 * David Ediger (david.ediger@gtri.gatech.edu)
 * Eric Hein (eric.hein@gtri.gatech.edu)
 * Tom Conte (tom@conte.us)

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#if !defined(STINGER_DEFS_H_)
#define STINGER_DEFS_H_

#ifdef __cplusplus
#define restrict
extern "C" {
#endif

/** @file */

/**
* @defgroup STINGER_DEFINE Graph Definitions
*
* @{
*/

/** Maximum number of vertices in STINGER */
#if !defined(STINGER_MAX_LVERTICES)
/* much smaller for quick testing */
#define STINGER_MAX_LVERTICES (1L<<20)
#endif
/** Edges per edge block */
#define STINGER_EDGEBLOCKSIZE 14
/** Number of edge types */
#define STINGER_NUMETYPES 5
/** Number of vertex types (with names) */
#define STINGER_NUMVTYPES 128

/** \def STINGER_MAX_LVERTICES
*   \brief Maximum number of vertices that STINGER can support
*/
/** \def STINGER_EDGEBLOCKSIZE
*   \brief Number of edges stored in an edge block
*/
/** \def STINGER_NUMETYPES
*   \brief Number of edge types allowed.  Edge type values are 0 to STINGER_NUMETYPES - 1.
*/


/** @} */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <inttypes.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <assert.h>

#include <libgen.h>
#include <getopt.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#if defined(_OPENMP)
#define OMP(x) _Pragma(x)
#else
#define OMP(x)
#endif

#if defined(__GNUC__)
#define FNATTR_MALLOC __attribute__((malloc))
#define UNLIKELY(x) __builtin_expect((x),0)
#define LIKELY(x) __builtin_expect((x),1)
#else
#define FNATTR_MALLOC
#define UNLIKELY(x) x
#define LIKELY(x) x
#endif

#define STINGERASSERTS()		    \
  do {					    \
    assert (G);				    \
    assert (from >= 0);			    \
    assert (to >= 0);			    \
    assert (from < STINGER_MAX_LVERTICES);  \
    assert (to < STINGER_MAX_LVERTICES);    \
  } while (0)

#ifdef __cplusplus
}
#undef restrict
#endif

#endif /* STINGER_DEFS_H_ */
