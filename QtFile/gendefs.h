/************************************************************************/
/*																		*/
/*		GENDEFS.H      --	Global Definitions for DPCDEMO Program		*/
/*																		*/
/************************************************************************/
/*  Author:	Joshua Pederson												*/
/*  Copyright:	2004 Digilent, Inc.										*/
/************************************************************************/
/*  File Description:													*/
/*																		*/
/*																		*/
/************************************************************************/
/*  Revision History:													*/
/*																		*/
/*	08/20/2004(Josh): created											*/
/*	09/20/2004(Josh): prepared for release								*/
/*																		*/
/************************************************************************/
#ifndef GENDEFS_H
#define GENDEFS_H
#include <windows.h>
#include <stdio.h>
#include "dpcdefs.h"	/* holds error codes and data types for dpcutil	*/
#include "dpcutil.h"	/* holds declaration of DPCUTIL API calls		*/
#include <iostream>
#include <sstream>
#include <string>
#include <memory.h>
#include <time.h>
#define	fFalse	0
#define	fTrue	1
#define	NULL	0 
#define	LOCAL
#define	GLOBAL
#define	BOOL	unsigned int
#define	BYTE	unsigned char
#define	WORD	unsigned short
#define	DWORD	unsigned long


const int	cbBlockSize		= 1000;
const int	cchShortString	= 16;
const float	idVer			= 1.0;

#endif 
/* ------------------------------------------------------------ */
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */

/************************************************************************/
