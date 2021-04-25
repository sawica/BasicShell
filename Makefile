OBJ = main.o arguments.o execute.o history.o builtinsfunc.o
all: BasicShell
BasicShell: $(OBJ)
	gcc $(OBJ) -o BasicShell
$(OBJ): clean
clean:
	rm -f *.o BasicShell
