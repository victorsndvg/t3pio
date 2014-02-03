#include <mpi.h>
#include <stdio.h>
#include <string.h>
#include "t3pio.h"
#include "t3pio_internal.h"

int t3piointernal_(int* f_comm, int* f_info, const char* dir, int* global_size, int* max_stripes,
                   int* mStripeSz, int* factor, const char* file, int* maxWritersPer, int* nWriters,
                   int* nNodes)
{
  return t3pio_internal(f_comm, f_info, dir, global_size, max_stripes, mStripeSz, factor, file,
                        maxWritersPer, nWriters, nNodes);
}
int T3PIOINTERNAL(int* f_comm, int* f_info, const char* dir, int* global_size, int* max_stripes,
                   int* mStripeSz, int* factor, const char* file, int* maxWritersPer, int* nWriters,
                   int* nNodes)
{
  return t3pio_internal(f_comm, f_info, dir, global_size, max_stripes, mStripeSz, factor, file,
                        maxWritersPer, nWriters, nNodes);
}

int t3piointernal(int* f_comm, int* f_info, const char* dir, int* global_size, int* max_stripes,
                   int* mStripeSz, int* factor, const char* file, int* maxWritersPer, int* nWriters,
                   int* nNodes)
{
  return t3pio_internal(f_comm, f_info, dir, global_size, max_stripes, mStripeSz, factor, file,
                        maxWritersPer, nWriters, nNodes);
}

int t3pio_internal(int* f_comm, int* f_info, const char* dir, int* global_size, int* max_stripes,
                   int* mStripeSz, int* factor, const char* file, int* maxWritersPer, int* nWriters,
                   int* nNodes)
{
  int      ierr, myProc;
  MPI_Comm comm = MPI_Comm_f2c(*f_comm);
  MPI_Info info = MPI_Info_f2c(*f_info);

  ierr = t3pio_set_info(comm, info, dir,
			T3PIO_GLOBAL_SIZE, 	   *global_size,
			T3PIO_MAX_STRIPES, 	   *max_stripes,
			T3PIO_FACTOR,      	   *factor,
			T3PIO_MAX_WRITER_PER_NODE, *maxWritersPer,
                        T3PIO_MAX_WRITERS,         *nWriters,
                        T3PIO_MAX_STRIPE_SIZE,     *mStripeSz,
			T3PIO_NUM_NODES,           nNodes,
			T3PIO_FILE,        	   file);
  *f_info = MPI_Info_c2f(info);

  return   ierr;
}



void t3piointernalversion_(char* v, int *len)
{
  t3pio_version_internal(v, len);
}
void t3piointernalversion(char* v, int *len)
{
  t3pio_version_internal(v, len);
}
void T3PIOINTERNALVERSION(char* v, int *len)
{
  t3pio_version_internal(v, len);
}

void  t3pio_version_internal(char *v, int *len)
{
  const char* myVersion = t3pio_version();
  int slen              = strlen(myVersion);
  int vlen              = *len;
  slen = (slen < vlen) ? slen : vlen;
  memcpy(v, myVersion, slen);
  if (vlen > slen)
    memset(&v[slen],' ', vlen - slen); 
}
