// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <iostream>

#define INPUT_LINE 20
#define INVALID_OPTION -1
#define INVALID_ID MAXINT
#define INVALID_PASSWORD 0
#define USERS_FILE "users.txt"
#define CATEGORIES_FILE "categories.txt"
#define FIELD_DELIM ";"

#define KEY_SPECIAL_BEGIN -32
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

typedef unsigned int HashType;
typedef unsigned int ID;

#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))
// TODO: reference additional headers your program requires here