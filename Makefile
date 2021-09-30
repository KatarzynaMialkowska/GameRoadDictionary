
.SUFFIXES: .cxx .o .x .hxx
NAME1 = gameA

CXX1 = $(NAME1).cxx

EXEC1 = $(NAME1).x

CO=g++
FLAGS= -std=c++11


.PHONY: all
all: $(EXEC1)


$(EXEC1):
	$(CO) -o $@ $(CXX1) $(FLAGS) 



A: $(EXEC1)

.PHONY: zadanieA
zadanieA: A

	./$(EXEC1)<dictionary.txt

.PHONY: clean
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}