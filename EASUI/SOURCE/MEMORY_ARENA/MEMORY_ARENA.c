#include "MEMORY_ARENA_PRIVATE.h"
#include "../../EASUI.h"


#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>



size_t LAST_INDEX;



typedef struct MEMORY_ARENA__BLOCK
{

        size_t BLOCK_SIZE;
        size_t OCCUPIED_SIZE;
        struct MEMORY_ARENA__BLOCK* LAST_BLOCK;
        char* SPACE;

}
MEMORY_ARENA__BLOCK;




MEMORY_ARENA__BLOCK STARTING_BLOCK;
MEMORY_ARENA__BLOCK* CURRENT_BLOCK = NULL;




size_t DEFAULT_BLOCK_SIZE;
char USING_STARTING_BLOCK = FALSE;




int ALLOCATE_NEW_BLOCK(const size_t SIZE);




int MEMORY_ARENA__INIT(const size_t DEFAULT_ALLOCATION_SIZE)
{

        if (DEFAULT_ALLOCATION_SIZE == 0)
        {

                return MEMORY_ARENA_ERROR;

        }


        DEFAULT_BLOCK_SIZE = DEFAULT_ALLOCATION_SIZE;


        CURRENT_BLOCK = &STARTING_BLOCK;


        ALLOCATE_NEW_BLOCK(DEFAULT_BLOCK_SIZE);


        return MEMORY_ARENA_OK;

}


void* MEMORY_ARENA_ALLOC(const size_t SIZE)
{

        if ((CURRENT_BLOCK->OCCUPIED_SIZE) + SIZE > CURRENT_BLOCK->BLOCK_SIZE)
        {

                const char ALLOCATE_NEW_BLOCK__STATUS = ALLOCATE_NEW_BLOCK(SIZE);


                if (ALLOCATE_NEW_BLOCK__STATUS == MEMORY_ARENA_ERROR)
                {

                        return NULL;

                }

        }


        CURRENT_BLOCK->OCCUPIED_SIZE += SIZE;


        return &(CURRENT_BLOCK->SPACE[CURRENT_BLOCK->OCCUPIED_SIZE - SIZE]);

}


void FREE_MEMORY_ARENA()
{

        for (MEMORY_ARENA__BLOCK* BLOCK = CURRENT_BLOCK; BLOCK != NULL && BLOCK != &STARTING_BLOCK;)
        {

                MEMORY_ARENA__BLOCK* TEMP_LAST_BLOCK = BLOCK->LAST_BLOCK;


                free(BLOCK->SPACE);
                free(BLOCK);


                BLOCK = TEMP_LAST_BLOCK;
        }


        free(STARTING_BLOCK.SPACE);


        CURRENT_BLOCK = NULL;
}


int ALLOCATE_NEW_BLOCK(const size_t BLOCK_SIZE)
{

        MEMORY_ARENA__BLOCK* NEW_BLOCK = NULL;


        if (CURRENT_BLOCK == NULL)
        {

                return MEMORY_ARENA_ERROR;

        }


        size_t FINAL_BLOCK_SIZE = DEFAULT_BLOCK_SIZE;


        if (BLOCK_SIZE > DEFAULT_BLOCK_SIZE)
        {

                FINAL_BLOCK_SIZE = BLOCK_SIZE;

        }


        CURRENT_BLOCK->LAST_BLOCK = NULL;


        if (!USING_STARTING_BLOCK)
        {



                // [ALLOCATE MEMORY FOR THE NEW BLOCK]
                {

                        NEW_BLOCK = malloc(sizeof(MEMORY_ARENA__BLOCK));


                        if (NEW_BLOCK == NULL)
                        {

                                return MEMORY_ARENA_ERROR;

                        }

                }


                NEW_BLOCK->LAST_BLOCK = CURRENT_BLOCK;


                CURRENT_BLOCK = NEW_BLOCK;

        }


        // [ALLOCATE MEMORY FOR BLOCK SPACE]
        {

                CURRENT_BLOCK->SPACE = malloc(FINAL_BLOCK_SIZE );


                if (CURRENT_BLOCK->SPACE == NULL)
                {

                        return MEMORY_ARENA_ERROR;

                }

        }


        CURRENT_BLOCK->OCCUPIED_SIZE = 0;


        CURRENT_BLOCK->BLOCK_SIZE = FINAL_BLOCK_SIZE;


        USING_STARTING_BLOCK = FALSE;


        return MEMORY_ARENA_OK;

}


// #include "MEMORY_ARENA_PRIVATE.h"
// #include <stddef.h>
// #include <stdlib.h>



// MARENA PROGRAM_ARENA;



// // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! AI WRITEN !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// void INIT_MEMORY_ARENA(size_t DEFAULT_SIZE)
// {

//         PROGRAM_ARENA.HEAD = NULL;
//         PROGRAM_ARENA.DEFAULT_SIZE = DEFAULT_SIZE;

// }


// // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! AI WRITEN !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// void* MEMORY_ARENA_ALLOC(size_t SIZE)
// {

//         size_t ALIGNMENT = 8;
//         size_t ALIGNED_OFFSET = 0;



//         if (PROGRAM_ARENA.HEAD != NULL)
//         {

//                 ALIGNED_OFFSET = (PROGRAM_ARENA.HEAD->OFFSET + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1);

//         }

//         // 2. If no block exists, or the allocation does not fit, create a new block
//         if (PROGRAM_ARENA.HEAD == NULL || (ALIGNED_OFFSET + SIZE > PROGRAM_ARENA.HEAD->CAPACITY)) {

//                 // Choose between the default block size or the massive requested size
//                 size_t BLOCK_SIZE = PROGRAM_ARENA.DEFAULT_SIZE;


//                 if (SIZE > BLOCK_SIZE)
//                 {
//                         BLOCK_SIZE = SIZE;
//                 }

//                 // Allocate block metadata and the memory payload together in one shot
//                 const size_t MALLOC_SIZE = sizeof(MARENA_BLOCK) + BLOCK_SIZE;

//                 MARENA_BLOCK* NEW_BLOCK = (MARENA_BLOCK*)malloc(MALLOC_SIZE);

//                 if (!NEW_BLOCK) return NULL;

//                 // Make all to zero
//                 for (size_t INDEX = 0; INDEX < sizeof(MARENA_BLOCK) + BLOCK_SIZE; INDEX ++)
//                 {

//                         ((char*)NEW_BLOCK)[INDEX] = 0;

//                 }

//                 NEW_BLOCK->CAPACITY = BLOCK_SIZE;
//                 NEW_BLOCK->OFFSET = 0;

//                 // Push new block to the head of the global chain
//                 NEW_BLOCK->NEXT = PROGRAM_ARENA.HEAD;
//                 PROGRAM_ARENA.HEAD = NEW_BLOCK;

//                 ALIGNED_OFFSET = 0;

//         }



//         void* ALLOCATED_PTR = &PROGRAM_ARENA.HEAD->DATA[ALIGNED_OFFSET];

//         PROGRAM_ARENA.HEAD->OFFSET = ALIGNED_OFFSET + SIZE;


//         return ALLOCATED_PTR;

// }


// // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! AI WRITEN !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// void FREE_MEMORY_ARENA(void)
// {
//         MARENA_BLOCK* CURRENT_NODE = PROGRAM_ARENA.HEAD;

//         while (CURRENT_NODE != NULL)
//         {

//                 // Cast the void* back to MARENA_BLOCK* to step to the next link
//                 MARENA_BLOCK* NEXT_NODE = (MARENA_BLOCK*)CURRENT_NODE->NEXT;

//                 free(CURRENT_NODE);

//                 CURRENT_NODE = NEXT_NODE;

//         }


//         PROGRAM_ARENA.HEAD = NULL;
// }
