#ifndef STRINGX_H_
#define STRINGX_H_

#include "boolx.h"

typedef char* str;

boolx comparex(const str string1, const str string2);
boolx is_substrx(const str string, const str substr);
int lenx(const str string);
int calcx(const str string, const str old, const str new);
void replacex(const str string, const str old, const str new, str result);

#endif