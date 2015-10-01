#pragma once
#include "stdincl.h"

bool IsEqual(const char* s1, const char* s2);
Vector2f ParseVector2f(const char* s);
Vector3f ParseVector3f(const char* s);
bool StringStartsWith(const char* prefix, const char* word);
int Max(int a, int b);
int Min(int a, int b);
uint Max(uint a, uint b);
uint Min(uint a, uint b);