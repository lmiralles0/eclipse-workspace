#ifndef GET_ENTRADA_H_
#define GET_ENTRADA_H_

int get_EntradaInt(int* pResultado, char* mensaje, char* mensajeError, int maximo, int minimo, int intentos);
int get_EntradaTexto(char* pArrays, int longitud, char* mensaje, char* mensajeError,int intentos);

#endif /* GET_ENTRADA_H_ */
