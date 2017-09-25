COMPILER=gcc
FILEPATH=linux/matrices
# FILEPATH=windows/matrices

compile_run:
	# Linux
	$(COMPILER) $(FILEPATH).c -o $(FILEPATH)
	./$(FILEPATH)
	# Windows
	# $(COMPILER) $(FILEPATH).c -o $(FILEPATH).exe
	# $(FILEPATH).exe

# Predeterminado:
# Configurado para compilar en Linux
