#
# The following environment variables should be predefined:
#
# OPS_INSTALL_PATH
# OPS_COMPILER (gnu,intel,etc)
#

#
# set paths for header files and libraries
#
OPS_INSTALL_PATH := $(OPS_INSTALL_PATH)/c
OPS_INC		= -I$(OPS_INSTALL_PATH)/include
OPS_LIB		= -L$(OPS_INSTALL_PATH)/lib
CUDA_LIB = -L$(CUDA_INSTALL_PATH)/lib64
CUDA_INC = -I$(CUDA_INSTALL_PATH)/include
OPENCL_INC = -I$(OPENCL_INSTALL_PATH)/include
OPENCL_LIB = -L$(OPENCL_INSTALL_PATH)/lib64 -lOpenCL

ifeq ($(OPS_COMPILER),gnu)
  CPP		= g++
ifdef DEBUG
  CPPFLAGS	= -O0 -g -DUNIX -Wall
else
  CPPFLAGS	= -O3 -fPIC -DUNIX -Wall
endif
  OMPFLAGS	= -fopenmp
  MPICPP	= $(MPI_INSTALL_PATH)/bin/mpiCC
  MPIFLAGS	= $(CCFLAGS)
else
ifeq ($(OPS_COMPILER),intel)
  CPP		= icpc
ifdef DEBUG
  CCFLAGS	= -O0 -g -no-prec-div -fp-model strict -fp-model source -prec-div -prec-sqrt -DMPICH_IGNORE_CXX_SEEK -DOPS_DEBUG
else
  CCFLAGS	= -O3 -ipo -no-prec-div -fp-model strict -fp-model source -prec-div -prec-sqrt -xHost -parallel #-DCOMM_PERF #-DDEBUG
  #CCFLAGS       = -qopenmp -O3  -no-prec-div -restrict -fno-alias -xHost -fma -fp-model fast=2 #-fp-model strict -fp-model source -prec-div -prec-sqrt
  #-DMPICH_IGNORE_CXX_SEEK#-vec-report
endif
  CPPFLAGS	= $(CCFLAGS)
  OMPFLAGS	= -qopenmp -openmp-report2
  MPICC		= $(MPI_INSTALL_PATH)/bin/mpicc -std=c99
  MPICPP	= $(MPI_INSTALL_PATH)/bin/mpicxx
  MPIFLAGS	= $(CCFLAGS)
else
ifeq ($(OPS_COMPILER),mic)
  CPP           = icpc
ifdef DEBUG
  CCFLAGS       = -O0 -g -mmic -DMPICH_IGNORE_CXX_SEEK#-vec-report
else1
  #CCFLAGS      = -O3 -ipo -no-prec-div -restrict -fno-alias -fp-model strict -fp-model source -prec-div -prec-sqrt -DMPICH_IGNORE_CXX_SEEK#-vec-report
  #CCFLAGS      = -O3 -ipo -no-prec-div -restrict -fno-alias -mmic -vec-report -finline -inline-forceinline -DSIMD_VEC=32 -DMPICH_IGNORE_CXX_SEEK#-vec-report
  CCFLAGS       = -O3 -ipo -no-prec-div -restrict -fno-alias -mmic -qopt-report -DSIMD_VEC=32 -DMPICH_IGNORE_CXX_SEEK -finline#-vec-report
endif
  CPPFLAGS      = $(CCFLAGS)
  OMPFLAGS      = -openmp -openmp-report2
  MPICPP        = $(MPI_INSTALL_PATH)/bin/mpicxx
  MPIFLAGS      = $(CCFLAGS)
  OPENCL_LIB    = -L$(OPENCL_INSTALL_PATH)/lib64 -lintelocl -lOpenCL #for offload opencl execution on the phi
else
ifeq ($(OPS_COMPILER),pgi)
  CPP 		= pgc++
  CUDA_ALIGN_FLAG := -D__x86_64 -D__align__\(n\)=__attribute__\(\(aligned\(n\)\)\) -D__location__\(a\)=__annotate__\(a\) -DCUDARTAPI=
ifdef DEBUG
  CCFLAGS 	= -O2 -g -Minline -Kieee -Minform=inform -Minfo=all
else
  #CCFLAGS 	= -O2 -Kieee -fastsse -gopt -Mipa=fast -Mlist -Minline #-Minform=severe -Minfo=all
  CCFLAGS 	= -O2 -Kieee -nofma -Minline #-fastsse -gopt -Mipa=fast -mp=nonuma -Kieee -Minline
endif
  CPPFLAGS 	= $(CCFLAGS) -ldl
  OMPFLAGS 	= -mp=nonuma
  MPICPP 	= $(MPI_INSTALL_PATH)/bin/mpic++
  MPICC 	= $(MPI_INSTALL_PATH)/bin/mpicc
  MPIFLAGS 	= $(CPPFLAGS) -ldl
else
ifeq ($(OPS_COMPILER),cray)
  CPP       = CC
    CUDA_ALIGN_FLAG := -D__x86_64 -D__align__\(n\)=__attribute__\(\(aligned\(n\)\)\) -D__location__\(a\)=__annotate__\(a\) -DCUDARTAPI=
ifdef DEBUG
  CCFLAGS   = -O2
else
  CCFLAGS   = -O3
endif
  CPPFLAGS  = $(CCFLAGS)
  OMPFLAGS  =
  MPICPP    = CC
  MPICC     = cc
  MPIFLAGS  = $(CPPFLAGS)
else
ifeq ($(OPS_COMPILER),xlp8)
  CPP       = mpicc
  CUDA_ALIGN_FLAG :=
ifdef DEBUG
  CCFLAGS   = -O2 -g
else
  CCFLAGS   = -qarch=pwr8 -qtune=pwr8:smt2 -O5 -qhot -qaltivec=le -qlist  -qreport #-qsmp=omp -qthreaded 
endif
  CPPFLAGS  = $(CCFLAGS)
  OMPFLAGS  = -qsmp=omp  -qthreaded
  MPICPP    = mpicxx
  MPICC     = mpicc
  MPIFLAGS  = $(CPPFLAGS)
else
print:
	@echo "unrecognised value for OPS_COMPILER"
endif
endif
endif
endif
endif
endif



ifdef HDF5_INSTALL_PATH
  HDF5_INC              := -I$(HDF5_INSTALL_PATH)/include
  HDF5_LIB              := -L$(HDF5_INSTALL_PATH)/lib -lhdf5_hl -lhdf5 -lz
  CC = $(MPICC)
  CPP = $(MPICPP)
  OPS_INC += $(HDF5_INC)
ifdef CHECKPOINTING
  HDF5_INC              := $(HDF5_INC) -DCHECKPOINTING
endif
endif


NVCC  := $(CUDA_INSTALL_PATH)/bin/nvcc
# flags for nvcc
# set NV_ARCH to select the correct one
ifndef NV_ARCH
  MESSAGE=select an NVIDA device to compile in CUDA, e.g. make NV_ARCH=KEPLER
  NV_ARCH=Kepler
endif
ifeq ($(NV_ARCH),Fermi)
	CODE_GEN_CUDA=-gencode arch=compute_20,code=sm_21
else
ifeq ($(NV_ARCH),Kepler)
	CODE_GEN_CUDA=-gencode arch=compute_35,code=sm_35
endif
endif


ifdef DEBUG
  NVCC_FLAGS = -O0 -g -G
else
  NVCC_FLAGS = -O3 -restrict --fmad false
endif

#switch on FMA instructions in OpenCL
OCL_FLAGS=#-DOCL_FMA_SWITCH_ON


#
# master to make all versions
#

HEADERS=initialise_chunk_kernel.h generate_chunk_kernel.h ideal_gas_kernel.h \
                update_halo_kernel.h field_summary_kernel.h viscosity_kernel.h \
                PdV_kernel.h revert_kernel.h accelerate_kernel.h flux_calc_kernel.h \
                reset_field_kernel.h advec_cell_kernel.h advec_mom_kernel.h
OPS_FILES_PLAIN=clover_leaf.cpp start.cpp build_field.cpp read_input.cpp initialise_chunk.cpp \
                initialise.cpp generate.cpp ideal_gas.cpp \
                update_halo.cpp field_summary.cpp time_step.cpp viscosity.cpp \
                calc_dt.cpp PdV.cpp revert.cpp accelerate.cpp flux_calc.cpp \
                advection.cpp advec_cell.cpp advec_mom.cpp reset_field.cpp
OPS_FILES_GEN=clover_leaf_ops.cpp start.cpp build_field.cpp read_input.cpp initialise_chunk_ops.cpp \
	        initialise.cpp generate_ops.cpp ideal_gas_ops.cpp \
                update_halo_ops.cpp field_summary_ops.cpp time_step.cpp viscosity_ops.cpp \
                calc_dt_ops.cpp PdV_ops.cpp revert_ops.cpp accelerate_ops.cpp flux_calc_ops.cpp \
                advection.cpp advec_cell_ops.cpp advec_mom_ops.cpp reset_field_ops.cpp

TARGETS = clean cloverleaf_dev_seq cloverleaf_dev_mpi cloverleaf_mpi cloverleaf_mpi_openmp cloverleaf_openmp cloverleaf_seq cloverleaf_mpi_inline cloverleaf_tiled cloverleaf_cuda cloverleaf_mpi_cuda cloverleaf_opencl cloverleaf_mpi_opencl

ifeq ($(OPS_COMPILER),pgi)
TARGETS += cloverleaf_openacc cloverleaf_mpi_openacc
else
TARGETS += openacc_error
endif

all: clean $(TARGETS)

cloverleaf_dev_seq: Makefile $(HEADERS) $(OPS_FILES_PLAIN) $(OPS_INSTALL_PATH)/lib/libops_seq.a
		$(MPICPP) $(CPPFLAGS) $(OPS_INC) $(OPS_LIB) $(OPS_FILES_PLAIN) -lops_seq $(HDF5_LIB) -o cloverleaf_dev_seq


cloverleaf_dev_mpi: Makefile $(OPS_FILES_PLAIN) \
                $(HEADERS) $(OPS_INSTALL_PATH)/lib/libops_mpi.a
	        $(MPICPP) $(MPIFLAGS) -DOPS_MPI $(OPS_INC) $(OPS_LIB) $(OPS_FILES_PLAIN) -lops_mpi $(HDF5_LIB) -o cloverleaf_dev_mpi

#
# mpi version
#

SEQ_KERNELS = clover_leaf_seq_kernels.cpp

cloverleaf_mpi: Makefile $(OPS_FILES_GEN) \
                $(HEADERS) $(OPS_INSTALL_PATH)/lib/libops_mpi.a
	        $(MPICPP) $(MPIFLAGS) -DOPS_MPI $(OPS_INC) $(OPS_LIB) $(OPS_FILES_GEN) -I. ./MPI/$(SEQ_KERNELS) -lops_mpi $(HDF5_LIB) -o cloverleaf_mpi

#
# OpenMP version
#
OMP_KERNELS = clover_leaf_omp_kernels.cpp

cloverleaf_mpi_openmp: Makefile $(OPS_FILES_GEN) \
                $(HEADERS) $(OPS_INSTALL_PATH)/lib/libops_mpi.a
	        $(MPICPP) $(MPIFLAGS) $(OMPFLAGS) -DOPS_MPI $(OPS_INC) $(OPS_LIB) $(OPS_FILES_GEN) -I. ./MPI_OpenMP/$(OMP_KERNELS) -lops_mpi $(HDF5_LIB) -o cloverleaf_mpi_openmp


cloverleaf_openmp: $(OPS_FILES_GEN) \
                $(HEADERS)
	        $(MPICPP) $(OMPFLAGS) $(MPIFLAGS) $(OPS_INC) $(OPS_LIB) $(OPS_FILES_GEN) -I. ./MPI_OpenMP/$(OMP_KERNELS) -lops_seq $(HDF5_LIB) -o cloverleaf_openmp

#
# Sequential version
#
cloverleaf_seq: $(OPS_FILES_GEN) \
                $(HEADERS)
		$(MPICPP) $(MPIFLAGS) $(OPS_INC) $(OPS_LIB) $(OPS_FILES_GEN) -I. ./MPI/$(SEQ_KERNELS) -lops_seq $(HDF5_LIB) -o cloverleaf_seq 

#
# Tiled version
#
cloverleaf_tiled: $(OPS_FILES_GEN) \
                $(HEADERS)
		$(MPICPP) $(MPIFLAGS) $(OMPFLAGS) -D$(OPS_COMPILER) $(OPS_INC) $(OPS_LIB) $(OPS_FILES_GEN) -I. ./Tiled/$(SEQ_KERNELS) -lops_seq $(HDF5_LIB) -o cloverleaf_tiled
 
#
# CUDA version
#

cloverleaf_cuda: ./CUDA/cloverleaf_kernels_cu.o $(OPS_FILES_GEN) \
		$(HEADERS)
		$(MPICPP) $(OMPFLAGS) $(CPPFLAGS) $(CUDA_INC) $(OPS_INC) $(OPS_LIB) $(CUDA_LIB) $(OPS_FILES_GEN) ./CUDA/cloverleaf_kernels_cu.o -lcudart -lops_cuda $(HDF5_LIB) -o cloverleaf_cuda

cloverleaf_mpi_cuda: ./CUDA/cloverleaf_kernels_mpi_cu.o $(OPS_FILES_GEN) \
		$(HEADERS)
		$(MPICPP) $(OMPFLAGS) $(CPPFLAGS) -DOPS_MPI $(CUDA_INC) $(OPS_INC) $(OPS_LIB) $(CUDA_LIB) $(OPS_FILES_GEN) ./CUDA/cloverleaf_kernels_mpi_cu.o -lcudart -lops_mpi_cuda $(HDF5_LIB) -o cloverleaf_mpi_cuda

./CUDA/cloverleaf_kernels_cu.o:	./CUDA/clover_leaf_kernels.cu \
				Makefile
				$(NVCC) $(VAR) $(INC) $(NVCC_FLAGS) $(CODE_GEN_CUDA) $(OPS_INC) -I. \
				-c -o ./CUDA/cloverleaf_kernels_cu.o ./CUDA/clover_leaf_kernels.cu

./CUDA/cloverleaf_kernels_mpi_cu.o:	./CUDA/clover_leaf_kernels.cu \
				Makefile
				$(NVCC) $(VAR) $(INC) $(NVCC_FLAGS) -DOPS_MPI $(CODE_GEN_CUDA) $(OPS_INC) -I. -DMPICH_IGNORE_CXX_SEEK -I$(MPI_INSTALL_PATH)/include \
				-c -o ./CUDA/cloverleaf_kernels_mpi_cu.o ./CUDA/clover_leaf_kernels.cu

mpiinline_obj_list = $(shell find MPI_inline/ -name "*.cpp" | sed s/\\.cpp/\\.o/g | tr "\n" " ")
mpiinline_c_obj_list = $(shell find MPI_inline/ -name "*_c.c" | sed s/\\.c/\\.o/g | tr "\n" " ")


./MPI_inline/clover_leaf_kernels.o: ./MPI_inline/clover_leaf_kernels.cpp ./MPI_inline/clover_leaf_common.h Makefile
				$(MPICPP) $(MPIFLAGS) $(OMPFLAGS) -DOPS_MPI $(OPS_INC) $(HDF5_INC)  \
 			       -I. MPI_inline/clover_leaf_kernels.cpp -c -o MPI_inline/clover_leaf_kernels.o

./MPI_inline/%.o: ./MPI_inline/%.cpp ./MPI_inline/%_c.c ./MPI_inline/clover_leaf_common.h Makefile
				@echo "Compiling kernel" $*
				$(MPICC) $(MPIFLAGS) $(OMPFLAGS) -DOPS_MPI  $(OPS_INC) $(HDF5_INC) \
			        -I. MPI_inline/$*_c.c -c -o MPI_inline/$*_c.o
				$(MPICPP) $(MPIFLAGS) $(OMPFLAGS) -DOPS_MPI $(OPS_INC) $(HDF5_INC) \
				-I. MPI_inline/$*.cpp -c -o MPI_inline/$*.o

cloverleaf_mpi_inline: $(mpiinline_obj_list) clover_leaf_ops.cpp start.cpp build_field.cpp read_input.cpp initialise_chunk_ops.cpp \
	        initialise.cpp generate.cpp ideal_gas_ops.cpp \
                update_halo_ops.cpp field_summary_ops.cpp time_step.cpp viscosity_ops.cpp \
                calc_dt_ops.cpp PdV_ops.cpp revert_ops.cpp accelerate_ops.cpp flux_calc_ops.cpp \
                advection.cpp advec_cell_ops.cpp advec_mom_ops.cpp reset_field_ops.cpp \
                initialise_chunk_kernel.h generate_chunk_kernel.h ideal_gas_kernel.h \
                update_halo_kernel.h field_summary_kernel.h viscosity_kernel.h \
                PdV_kernel.h revert_kernel.h accelerate_kernel.h flux_calc_kernel.h \
                reset_field_kernel.h advec_cell_kernel.h advec_mom_kernel.h Makefile $(OPS_INSTALL_PATH)/lib/libops_mpi.a
	        $(MPICPP) $(MPIFLAGS) $(OMPFLAGS) $(OPS_INC) $(HDF5_INC) $(OPS_LIB)  -DOPS_MPI \
		clover_leaf_ops.cpp start.cpp build_field.cpp \
                read_input.cpp initialise_chunk_ops.cpp initialise.cpp generate.cpp \
                ideal_gas_ops.cpp update_halo_ops.cpp field_summary_ops.cpp time_step.cpp \
                viscosity_ops.cpp calc_dt_ops.cpp PdV_ops.cpp revert_ops.cpp accelerate_ops.cpp \
                flux_calc_ops.cpp advection.cpp reset_field_ops.cpp advec_cell_ops.cpp \
		advec_mom_ops.cpp -I. $(mpiinline_obj_list) $(mpiinline_c_obj_list) -lops_mpi $(HDF5_LIB) -o cloverleaf_mpi_inline

openacc_obj_list = $(shell find OpenACC/ -name "*.cpp" | sed s/\\.cpp/\\.o/g | tr "\n" " ")
openacc_c_obj_list = $(shell find OpenACC/ -name "*_c.c" | sed s/\\.c/\\.o/g | tr "\n" " ")


./OpenACC/clover_leaf_kernels.o: ./OpenACC/clover_leaf_kernels.cpp ./OpenACC/clover_leaf_common.h Makefile
	$(MPICPP) -acc -ta=tesla:cc35  $(MPIFLAGS) -DOPS_MPI $(CUDA_ALIGN_FLAG) $(OPS_INC) $(CUDA_INC) \
        -I. OpenACC/clover_leaf_kernels.cpp -c -o OpenACC/clover_leaf_kernels.o

./OpenACC/%.o: ./OpenACC/%.cpp ./OpenACC/%_c.c ./OpenACC/clover_leaf_common.h Makefile
	@echo "Compiling kernel" $*
	$(MPICC) -acc -ta=tesla:cc35 -ta=tesla:maxregcount:64 $(MPIFLAGS) -DOPS_MPI $(CUDA_ALIGN_FLAG) $(OPS_INC) $(CUDA_INC) \
	-I. OpenACC/$*_c.c -c -o OpenACC/$*_c.o
	$(MPICPP) -acc -ta=tesla:cc35  $(MPIFLAGS) -DOPS_MPI $(CUDA_ALIGN_FLAG) $(OPS_INC) $(CUDA_INC) \
	-I. OpenACC/$*.cpp OpenACC/$*_c.o -c -o OpenACC/$*.o

cloverleaf_openacc: $(openacc_obj_list) $(OPS_FILES_GEN) \
                $(HEADERS)
	        $(MPICPP) -acc -ta=tesla:cc35 $(MPIFLAGS) $(CUDA_ALIGN_FLAG) $(OPS_INC) $(OPS_LIB) $(CUDA_INC) $(CUDA_LIB) \
		$(OPS_FILES_GEN) -I. $(openacc_obj_list) $(openacc_c_obj_list) -lcudart -lops_mpi_cuda $(HDF5_LIB) -o cloverleaf_openacc

cloverleaf_mpi_openacc: $(openacc_obj_list) $(OPS_FILES_GEN) \
                $(HEADERS)
	        $(MPICPP) -acc -ta=tesla:cc35 $(MPIFLAGS) -DOPS_MPI $(OPS_INC) $(OPS_LIB) $(CUDA_INC) $(CUDA_LIB) \
	        $(OPS_FILES_GEN) -I. $(openacc_obj_list) $(openacc_c_obj_list) -lcudart -lops_mpi_cuda $(HDF5_LIB) -o cloverleaf_mpi_openacc


cloverleaf_opencl: ./OpenCL/cloverleaf_opencl_kernels.o $(OPS_FILES_GEN) \
                $(HEADERS) Makefile
	        $(MPICPP) $(MPIFLAGS) $(OCL_FLAGS) $(OPS_INC) $(OPS_LIB) $(OPENCL_LIB) $(OPS_FILES_GEN) ./OpenCL/cloverleaf_opencl_kernels.o -I. ./OpenCL/$(SEQ_KERNELS) -lops_opencl $(HDF5_LIB) -o cloverleaf_opencl

./OpenCL/cloverleaf_opencl_kernels.o: ./OpenCL/clover_leaf_opencl_kernels.cpp Makefile
		$(MPICPP) $(CPPFLAGS) $(OCL_FLAGS) $(VAR) $(OPENCL_INC) $(INC) $(OPS_INC) -I. \
                -c -o ./OpenCL/cloverleaf_opencl_kernels.o ./OpenCL/clover_leaf_opencl_kernels.cpp


cloverleaf_mpi_opencl: ./OpenCL/cloverleaf_mpi_opencl_kernels.o $(OPS_FILES_GEN) \
                $(HEADERS) Makefile $(OPS_INSTALL_PATH)/lib/libops_opencl.a
		$(MPICPP) $(MPIFLAGS) -DOPS_MPI $(OCL_FLAGS) $(OPS_INC) $(OPS_LIB) $(OPENCL_LIB) $(OPS_FILES_GEN) ./OpenCL/cloverleaf_mpi_opencl_kernels.o -I. ./OpenCL/$(SEQ_KERNELS) -lops_mpi_opencl $(HDF5_LIB) -o cloverleaf_mpi_opencl

./OpenCL/cloverleaf_mpi_opencl_kernels.o: ./OpenCL/clover_leaf_opencl_kernels.cpp Makefile
	        $(MPICPP) $(MPIFLAGS) $(VAR) $(OPENCL_INC) $(INC) $(OPS_INC) -I. -DOPS_MPI \
                -c -o ./OpenCL/cloverleaf_mpi_opencl_kernels.o ./OpenCL/clover_leaf_opencl_kernels.cpp


#
# cleanup
#

clean:
	rm -f cloverleaf_dev_seq cloverleaf_dev_mpi cloverleaf_mpi cloverleaf_seq cloverleaf_tiled cloverleaf_mpi_inlined cloverleaf_openmp cloverleaf_mpi_openmp cloverleaf_cuda cloverleaf_mpi_cuda cloverleaf_openacc cloverleaf_mpi_openacc ./CUDA/*.o ./OpenACC/*.o *.o cloverleaf_opencl cloverleaf_mpi_opencl ./OpenCL/*.o ./MPI_inline/*.o *.o *.lst 
