#include <stdio.h>
#include "tablaMercado.h"
#include "funcsNominaPollosII.h"

#define FACTORBASE (1.20)


int main(int argc, char const *argv[]) {
	
	int i = 0; // Para los ciclos

// DATOS DE ENTRADA

	int edadPromedio;
	double kilosAlimento;
	double pesoPromedio;
	double gananciaDiaria; // Debe estar en Kilos para que funcione de acuerdo a lo que se indica en tabla
	double conversion;
	double kilosPollo;

// DATOS CALCULADOS

	double factor;
	double diferenciaGananciaDiaria;
	double diferenciaConversion;

// VARIABLES DE LA ESTRUCTURA MERCADO (DEFINIDA EN EL HEADER tablaMercado.h)

	mercado miResultado; // Se recorre el arreglo y se busca y se almacena en esta variable la estructura correspondiente a nuestros resultados

	mercado tabla[15]; // Arreglo de estructuras en donde esta guardada la tabla mercado

	llenaTablaMercado(tabla); // Funcion que carga la tabla mercado en el arreglo de estructuras que se le pase como parametro debe ser un arreglo de dimension 15

// CICLO QUE IMPRIME EL CONTENIDO DE LA TABLA MERCADO

	/*

	for (i = 0; i < 15; i++) {
		printf("edadPromedio: %d\ngananciaDiaria: %.2f\nconversion: %.2f\n\n",tabla[i].edadPromedio,tabla[i].gananciaDiaria,tabla[i].conversion);
	}

	*/

// RECOLECCION DE DATOS DE ENTRADA

	printf("\nPARAMETROS OBTENIDOS EN LA PARVADA\n\n");

	printf("\to Edad Promedio/Venta [Entero]: ");
	scanf("%d",&edadPromedio);

	printf("\to Peso Promedio [Gramos]: ");
	scanf("%lf",&pesoPromedio);

	printf("\to Kilogramos de Alimento: ");
	scanf("%lf",&kilosAlimento);

	printf("\to Kilogramos de Pollo: ");
	scanf("%lf",&kilosPollo);

// CALCULO CONVERSION Y GANANCIA DIARIA

	conversion = kilosAlimento/kilosPollo;
	gananciaDiaria = pesoPromedio/edadPromedio;

	printf("\n\to Conversion: %f",conversion);
	printf("\n\to Ganancia Diaria: %f\n",gananciaDiaria);

// OBTENCION DE LOS PARAMETROS POR TABLA MERCADO A PARTIR DE LA EDAD PROMEDIO/VENTA

	/* Este bucle reccore el arreglo de estructuras donde esta almacenada nuestra tabla de mercado comparando la edad promedio/venta
	   que se ingreso al inicio con las edades de venta de la tabla en cuanto coincidan se obtienen los valores correspondientes y se
	   almacenan en la estructuraa miResultado. */

	for (i = 0; i < 15; i++) {
		if (tabla[i].edadPromedio == edadPromedio){
			miResultado = tabla[i];
			break;
		}
	}

// CALCULO DE LOS BONOS POR CONVERSION Y GANANCIA DIARIA

	diferenciaGananciaDiaria = gananciaDiaria - miResultado.gananciaDiaria;
	diferenciaConversion = miResultado.conversion - conversion;

// IMPRESION DE PARAMETROS POR TABLA


	printf("\nPARAMETROS POR TABLA");
	printf("\n\n\t> Edad Promedio/Venta: %d\n\t> Ganancia Diaria: %.2f\n\t> Conversion: %.4f\n\n",
		miResultado.edadPromedio,miResultado.gananciaDiaria,miResultado.conversion);

// IMPRESION DE DIFERENCIAS

	printf("DIFERENCIAS A FAVOR/EN CONTRA");
	printf("\n\n\t* Ganancia Diaria: %f [GRAMOS]\tPuntos: %f\n\t* Conversion: %f []\tPuntos: %f\n\n",
		diferenciaGananciaDiaria,diferenciaGananciaDiaria,diferenciaConversion,diferenciaConversion/0.01);

	// Aqui se calcula cuanto sube o baja el factor dependiendo de la ganancia diaria y de la conversion

	double factorGananciaDiaria;
	double factorConversion;

	// Edad de venta es promedio ponderado

	factorGananciaDiaria = diferenciaGananciaDiaria*0.03; // Aqui si son los puntos 
	factorConversion = (diferenciaConversion/0.01)*0.02; // Hay que dividir en

	printf("CALCULO DE LOS FACTORES DE GANANCIA DIARIA Y CONVERSION\n\n");
	printf("\t~ Factor Base: 1.20\n\t~ Factor Ganancia Diaria: %f\n\t~ Factor Conversion: %f\n\n",factorGananciaDiaria,factorConversion);

	factor = FACTORBASE + factorGananciaDiaria + factorConversion;

	printf("\t~ Factor Total: %f\n\n",factor);

	printf("PAGO DE LA PARVADA\n\n");
	printf("\t-> Factor Base * Kilogramos de Pollo = 1.2 * %.2f = %.2f\n",kilosPollo,kilosPollo*1.20);
	printf("\t-> Factor Ganancia Diaria * Kilogramos de Pollo = %.4f * %.2f = %.2f\n",factorGananciaDiaria,kilosPollo,kilosPollo*factorGananciaDiaria);
	printf("\t-> Factor Conversion * Kilogramos de Pollo = %.4f * %.2f = %.2f\n\n",factorConversion,kilosPollo,kilosPollo*factorConversion);

	printf("\t-> Ganancia Final = %.2f\n",kilosPollo*factor);

	getchar();
	getchar();

	return 0;
}