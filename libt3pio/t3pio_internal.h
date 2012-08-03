#ifndef T3PIO_INTERNAL_H
#define T3PIO_INTERNAL_H

#include <mpi.h>
typedef struct
{
  int globalSz;
  int maxStripes;
  int factor;
  int numNodes;
  int numIO;
  int numStripes;
  int nodeMem;
  int stripeSz;
  char* dir;
  char* fn;
} T3Pio_t;

void t3pio_init(T3Pio_t* t3);
int t3pio_numComputerNodes(MPI_Comm comm, int nProc);
int t3pio_maxStripes(MPI_Comm comm,       int myProc, const char* dir);
int t3pio_readStripes(MPI_Comm comm,      int myProc, const char* fn);
int t3pio_nodeMemory(MPI_Comm comm,       int myProc);

int t3pio_internal(int* f_comm, int* f_info, const char* dir, int* global_size, int* max_stripes, int* factor,
                   const char* file);


#endif /* T3PIO_INTERNAL_H */
