OBJ = main.o algsVector.o process.o algsCube.o elements.o menu.o arrayIO.o measurement.o 
program: $(OBJ)
		gcc -o program $(OBJ) -lm
$(OBJ): algorithms.h process.h elements.h menu.h arrayIO.h measurement.h


run:
	./program

clear:
	rm -rf program *.o 
