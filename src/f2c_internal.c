#include <stdio.h>
#include "t3pio.h"
#include "t3pio_internal.h"
#include <mpi.h>

int t3piointernal_(int* f_comm, int* f_info, const char* dir, int* global_size, int* max_stripes, int* factor,
                   const char* file)
{
  return t3pio_internal(f_comm, f_info, dir, global_size, max_stripes, factor, file);
}

int T3PIOINTERNAL(int* f_comm, int* f_info, const char* dir, int* global_size, int* max_stripes, int* factor,
                   const char* file)
{
  return t3pio_internal(f_comm, f_info, dir, global_size, max_stripes, factor, file);
}

int t3piointernal(int* f_comm, int* f_info, const char* dir, int* global_size, int* max_stripes, int* factor,
                   const char* file)
{
  return t3pio_internal(f_comm, f_info, dir, global_size, max_stripes, factor, file);
}

int t3pio_internal(int* f_comm, int* f_info, const char* dir, int* global_size, int* max_stripes, int* factor,
                   const char* file)
{
  
  MPI_Comm comm = MPI_Comm_f2c(*f_comm);
  MPI_Info info = MPI_Info_f2c(*f_info);

  int      ierr = t3pio_set_info(comm, info, dir,
                                 T3PIO_GLOBAL_SIZE, *global_size,
                                 T3PIO_MAX_STRIPES, *max_stripes,
                                 T3PIO_FACTOR,      *factor,
                                 T3PIO_FILE,        file);
  *f_info = MPI_Info_c2f(info);

  return   ierr;
}

