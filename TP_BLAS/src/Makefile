# une bibliotheque statique (libmnblas.a)
# une bibliotheque dynamique (libmnblasdyn.so)

all: libmnblas.a libmnblasdyn.so test_copy test_swap test_dot test_gemv

LIB_DIR=../lib
INC_DIR=../include
OPTIM=-O2 -fopenmp
FICHIERS_TEST=test_copy test_swap test_dot test_gemv

OPTIONS=-O2 -Wall -fPIC $(OPTIM) -I$(INC_DIR)
# Bibliothèque statique

libmnblas.a: copy.o swap.o dot.o complexe.o
	rm -f libmnblas.a $(LIB_DIR)/libmnblas.a
	ar -r libmnblas.a copy.o swap.o dot.o complexe.o
	cp libmnblas.a $(LIB_DIR)

# Bibliothèque dynamique

libmnblasdyn.so:copy.o swap.o dot.o complexe.o
	rm -f libmnblasdyn.so $(LIB_DIR)/libmnblasdyn.so
	gcc -shared -o libmnblasdyn.so copy.o swap.o dot.o complexe.o
	cp libmnblasdyn.so $(LIB_DIR)

complexe.o: $(INC_DIR)/complexe.h complexe.c
	gcc $(OPTIONS) -c complexe.c

# BLAS 1

copy.o : copy.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS) -c copy.c

swap.o : swap.c $(INC_DIR)/mnblas.h
	gcc  $(OPTIONS) -c swap.c

dot.o : dot.c $(INC_DIR)/mnblas.h
	gcc  $(OPTIONS) -c dot.c

test_copy.o : test_copy.c $(INC_DIR)/mnblas.h
	gcc  $(OPTIONS) -c test_copy.c

test_swap.o : test_swap.c $(INC_DIR)/mnblas.h
	gcc  $(OPTIONS) -c test_swap.c

test_dot.o : test_dot.c $(INC_DIR)/mnblas.h
	gcc  $(OPTIONS) -c test_dot.c

test_copy: test_copy.o copy.o
	gcc $(OPTIM) -o test_copy test_copy.o copy.o -L$(LIB_DIR) -lmnblas -lm

test_swap: test_swap.o swap.o
	gcc $(OPTIM) -o test_swap test_swap.o swap.o -L$(LIB_DIR) -lmnblas -lm

test_dot: test_dot.o dot.o
	gcc $(OPTIM) -o test_dot test_dot.o dot.o -L$(LIB_DIR) -lmnblas -lm

# BLAS 2

gemv.o : gemv.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS) -c gemv.c

test_gemv.o : test_gemv.c $(INC_DIR)/mnblas.h
	gcc $(OPTIONS) -c test_gemv.c

test_gemv: test_gemv.o gemv.o
	gcc $(OPTIM) -o test_gemv test_gemv.o gemv.o -L$(LIB_DIR) -lmnblas -lm

# BLAS 3

clean:
	rm -f *.o *.a *.so *~ $(FICHIERS_TEST) $(INC_DIR)/*~ $(LIB_DIR)/libmnblasdyn.so  $(LIB_DIR)/libmnblas.a ../lib/libmnblas.a ../lib/libmnblasdyn.so



