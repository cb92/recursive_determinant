
#Makefile to compile and link Determinant program

# *****************************************************
# Variables to control Makefile operation

CXX = g++
VARNAME = value 

# ****************************************************

det: detMain.o determinant.o utils.o
	$(CXX) -o det detMain.o determinant.o utils.o

detMain.o: detMain.cpp determinant.hpp utils.hpp
	$(CXX) -c detMain.cpp

determinant.o: determinant.cpp determinant.hpp
	$(CXX) -c determinant.cpp

utils.o:  utils.cpp utils.hpp
	$(CXX) -c utils.cpp

clean :
	-rm *.o $(objects) det