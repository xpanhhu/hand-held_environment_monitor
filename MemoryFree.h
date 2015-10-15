// MemoryFree library based on code posted here:
// http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1213583720/15
// Extended by Matthew Murdoch to include walking of the free list.

#ifndef	MEMORY_FREE_H
#define MEMORY_FREE_H

#ifdef __cplusplus
extern "C" {
#endif

int freeMemory();

#ifdef  __cplusplus
}
#endif

#define MEMORY_CHECK_ENABLE //check free memory
#if (defined MEMORY_CHECK_ENABLE) && (defined CONSOLE_ENABLED)
#define FREE_MEMORY()\
  Console.println(freeMemory())
#else
#define FREE_MEMORY()
#endif

#endif
