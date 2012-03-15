#ifndef cppfix_h
#define cppfix_h

#include <stdlib.h>

__extension__ typedef int __guard __attribute__((mode (__DI__)));

void * operator new(size_t size);
void operator delete(void * ptr);

int __cxa_guard_acquire(__guard *g);
void __cxa_guard_release (__guard *g);
void __cxa_guard_abort (__guard *);


#endif 