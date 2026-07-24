#define MEMORY_ARENA
#ifdef MEMORY_ARENA



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>



#define MEMORY_ARENA_ERROR 0
#define MEMORY_ARENA_OK 1



int MEMORY_ARENA__INIT(const size_t DEFAULT_ALLOCATION_SIZE);


void* MEMORY_ARENA_ALLOC(size_t SIZE);


void FREE_MEMORY_ARENA(void);



#endif
