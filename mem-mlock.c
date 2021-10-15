#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

void * alloc_workbuf(size_t size)
{
    void *ptr;
    int retval;
 /* 
  * alloc memory aligned to a page, to prevent two mlock() in the
  * same page.
  */
    retval = posix_memalign(&ptr, (size_t) sysconf(_SC_PAGESIZE), size);

 /* return NULL on failure */
    if (retval)
    return NULL;

 /* lock this buffer into RAM */
    if (mlock(ptr, size)) {
        free(ptr);
    return NULL;
 }
 return ptr;
}

void  free_workbuf(void *ptr, size_t size)
{
 /* unlock the address range */
    munlock(ptr, size);

 /* free the memory */
    free(ptr);
}