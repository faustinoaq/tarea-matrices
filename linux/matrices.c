/*
	Faustino Aguilar, 2015
	Se trata de diseñar y codificar un programa utilizando el
	lenguaje de programación C, el cual, a partir de dos matrices
	debe calcular el salario bruto de determinados empleados
	(se deben indicar los nombres de los empleados cuyos salarios
	serán calculados) y el total en dinero de la planilla de los
	empleados solicitados. El programa maneja dos matrices una
	de nombres de empleados y otra que contiene en una columna
	las horas trabajadas y en la otra columna el salario por hora.
	Puede asumir que el número de la fila que contiene el nombre
	es el mismo que contiene las horas trabajadas y el salario por hora.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5 // Límite de empleados

int main() {
	int n, i, existe;
	float salario[2][5], total_sal=0;
	char empleados[MAX][20], empleado[20], otro='s';
	printf("\n\tPrograma para la gestión de empleados\n\n");
	do {
		printf("Escriba la cantidad de empleados de 1 a %d: ", MAX);
		scanf("%d", &n);
		if (n <= 0 || n > MAX) {
			printf("Error: El rango de empleados es de 1 a %d\n", MAX);
		}
	} while (n <= 0 || n > MAX);
	for (i=0; i < n; i++) {
		printf("\nEscriba el nombre del empleado No. %d: ", i+1);
		scanf("%s", empleados[i]);
		printf("Escriba el salario por hora de %s: ", empleados[i]);
		scanf("%f", &salario[0][i]);
		printf("Escriba las horas trabajadas de %s: ", empleados[i]);
		scanf("%f", &salario[1][i]);
	}
	system("clear");
	printf("\n\tLista de empleados\n");
	printf("\n| Salario por hora | Horas trabajadas | Nombre \n\n");
	for (i=0; i < n; i++) {
		printf("|           $ %.2f |             %.0f | %s \n", salario[0][i], salario[1][i], empleados[i]);
	}
	printf("\n\tCalcular el salario bruto\n");
	do {
		existe=0;
		printf("\nEscriba el nombre de un empleado: ");
		scanf("%s", empleado);
		for (i=0; i < n; i++) {
			if (strcmp(empleados[i], empleado) == 0) {
				printf("Salario Bruto de %s: $ %.2f\n", empleados[i], salario[0][i]*salario[1][i]);
				total_sal = total_sal + (salario[0][i]*salario[1][i]);
				existe=1;
			}
		}
		if (existe == 0) {
			printf("El empleado %s no existe\n", empleado);
		}
		printf("\n¿Desea buscar otro empleado? s/n: ");
		scanf("%s", &otro);
	} while(otro != 'n');
	printf("\nTotal de salarios de empleados buscados: $ %.2f\n", total_sal);
	printf("\n\t¡Gracias por usar el programa!\n\n");
	return 0;
}
