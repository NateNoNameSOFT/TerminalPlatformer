#ifndef COMMON_H_
#define COMMON_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define CLEAR "\e[1;1H\e[2J"
#define QUIT_FROM_KEYPRESS                                                     \
  (int)7777 // number to send to handle_exit when recived q keypress

#define MAP_DATA_PRINT_SIZE 2940 // Height: 28 (Read note bellow), Width: 105
#define MAP_DATA_WIDTH 105
#define MAP_DATA_HEIGHT                                                        \
  28 // PLEASE NOTE that the terminal heigh is really 25 but from some currently
     // unknow reason its only printing to 22

extern pthread_t input_thread_id;
extern char debug_map_data[BUFSIZ];

extern _Atomic int32_t map_pos_offset;

#ifdef DEBON
/*
    if DEBON is defined you can use the
    DEBUG macro to display debug info
    from the console

    fmt = what you want to display
*/
#define DEBUG(fmt, ...) printf(fmt, __VA_ARGS__)
#else
/*
    does nothing if DEBON is not defined
*/
#define DEBUG(fmt, ...)                                                        \
  do {                                                                         \
  } while (0)
#endif // DEBON

/*
    print an error message to the console and
    the current line and file then exit.

    fmt = what you want to display to the console
*/
#define ERROR(fmt)                                                             \
  do {                                                                         \
    fprintf(stderr, fmt);                                                      \
    printf("\nFILE: %s, LINE %d\n", __FILE__, __LINE__);                       \
    exit(EXIT_FAILURE);                                                        \
  } while (0)

/*
    xmalloc allows for cleaner code, with out
    tons of malloc fail checks making your code
    messy, for things that need helpful error
    messages, use normal malloc.

    size: amount of memory to allocate
*/
void *xmalloc(size_t multiplier, size_t size);

#endif
