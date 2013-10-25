GPP=g++
GCC=gcc
FLAGS= -fshow-column -O2 `wx-config --cppflags`
LIBS=  -s  `wx-config --libs` 
OBJS=release.lnx/Application.o release.lnx/eventos.o release.lnx/eventos_ayuda.o release.lnx/eventos_confirmar_bin.o release.lnx/eventos_equiva.o release.lnx/eventos_negacion.o release.lnx/sentencia.o release.lnx/wxventanas.o release.lnx/eventos_selector.o release.lnx/wxsudoku.o release.lnx/eventos_sudoku.o 

all: release.lnx anallogica clean

clean:
	rm -rf release.lnx

anallogica: ${OBJS}
	${GPP} ${OBJS} ${LIBS} -o $@

release.lnx:
	mkdir release.lnx

release.lnx/Application.o: src/Application.cpp src/Application.h src/eventos.h src/wxventanas.h src/sentencia.h src/eventos_equiva.h
	${GPP} ${FLAGS} -c src/Application.cpp -o $@

release.lnx/eventos.o: src/eventos.cpp src/eventos.h src/wxventanas.h src/sentencia.h src/eventos_equiva.h src/eventos_negacion.h logana.xpm src/eventos_ayuda.h src/eventos_confirmar_bin.h src/eventos_selector.h src/eventos_sudoku.h src/wxsudoku.h
	${GPP} ${FLAGS} -c src/eventos.cpp -o $@

release.lnx/eventos_ayuda.o: src/eventos_ayuda.cpp src/eventos_ayuda.h src/wxventanas.h
	${GPP} ${FLAGS} -c src/eventos_ayuda.cpp -o $@

release.lnx/eventos_confirmar_bin.o: src/eventos_confirmar_bin.cpp src/eventos_confirmar_bin.h src/wxventanas.h
	${GPP} ${FLAGS} -c src/eventos_confirmar_bin.cpp -o $@

release.lnx/eventos_equiva.o: src/eventos_equiva.cpp src/eventos_equiva.h src/wxventanas.h src/eventos.h src/sentencia.h
	${GPP} ${FLAGS} -c src/eventos_equiva.cpp -o $@

release.lnx/eventos_negacion.o: src/eventos_negacion.cpp src/eventos_negacion.h src/wxventanas.h src/sentencia.h
	${GPP} ${FLAGS} -c src/eventos_negacion.cpp -o $@

release.lnx/sentencia.o: src/sentencia.cpp src/sentencia.h
	${GPP} ${FLAGS} -c src/sentencia.cpp -o $@

release.lnx/wxventanas.o: src/wxventanas.cpp src/wxventanas.h
	${GPP} ${FLAGS} -c src/wxventanas.cpp -o $@

release.lnx/eventos_selector.o: src/eventos_selector.cpp src/eventos_selector.h src/wxventanas.h
	${GPP} ${FLAGS} -c src/eventos_selector.cpp -o $@

release.lnx/wxsudoku.o: src/wxsudoku.cpp src/wxsudoku.h
	${GPP} ${FLAGS} -c src/wxsudoku.cpp -o $@

release.lnx/eventos_sudoku.o: src/eventos_sudoku.cpp src/eventos_sudoku.h src/wxsudoku.h
	${GPP} ${FLAGS} -c src/eventos_sudoku.cpp -o $@

