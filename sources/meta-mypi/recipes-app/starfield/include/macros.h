#pragma once

#define STR(x) STR_1(x)
#define STR_1(x) #x

//include macro for the specific CPU
#define INCLUDE_FILE(file) STR(../include/SYS_CPU/file)

