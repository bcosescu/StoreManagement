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

#define INPUT_LINE 24
#define INVALID_OPTION -1
#define INVALID_ID INT_MAX
#define INVALID_PASSWORD 0
#define NO_SELECTION -1
#define USERS_FILE "users.txt"
#define CATEGORIES_FILE "categories.txt"
#define PRODUCTS_FILE "products.txt"
#define INVOICES_FILE "invoices.txt"
#define FIELD_DELIM ';'
#define SUB_FIELD_DELIM ','

#define KEY_SPECIAL_BEGIN -32
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

typedef unsigned int HashType;
typedef unsigned int ID;

#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))

#define ID_WIDTH 5
#define NAME_WIDTH 20
#define DESCRIPTION_WIDTH 30
#define QUANTITY_WIDTH 5
#define SEPARATOR_WIDTH 2
#define DATE_WIDTH 8
#define VALUE_WIDTH 10
#define PROD_DESCRIPTION_WIDTH 20
#define PROD_NAME_WIDTH 10
// TODO: reference additional headers your program requires here
