// koala-db.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

// TODO: Reference additional headers your program requires here.
#ifdef __unix__

constexpr auto OS_WINDOWS = false;
// ??? linux dependencies must be added here

#elif defined(_WIN32) || defined(WIN32) 

constexpr auto OS_WINDOWS = true;
#include<winsock2.h>
#pragma comment(lib, "ws2_32.lib")

#endif
