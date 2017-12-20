#include <stdio.h>
#include "tablaMercado.h"
#include "funcsNominaPollosII.h"

#define FACTORBASE (1.20)


int main(int argc, char const *argv[]) {
	
	int i = 0;

	int edadPromedio;
	double gananciaDiaria;
	double conversion;
	double kilosPollo;
	double factor;

	double bonusGananciaDiaria;
	double bonusConversion;

	mercado miResultado; // Se recorre el arreglo y se busca y se almacena en esta variable la estructura correspondiente a nuestros resultados

	mercado tabla[15];

	llenaTablaMercado(tablaMercado);

	/*

	for (i = 0; i < 15; i++) {
		printf("edadPromedio: %d\ngananciaDiaria: %.2f\nconversion: %.2f\n\n",tabla[i].edadPromedio,tabla[i].gananciaDiaria,tabla[i].conversion);
	}

	*/

	printf("\nDATOS DE LA PARVADA\n\n");

	printf("Ingresa Edad Promedio: ");
	scanf("%d",&edadPromedio);

	printf("Ingresa Ganancia Diaria: ");
	scanf("%lf",&gananciaDiaria);

	printf("Ingresa Conversion: ");
	scanf("%lf",&conversion);

	printf("Ingresa Kilogramos de Pollo: ");
	scanf("%lf",&kilosPollo);

//	printf("edadPromedio: %d\ngananciaDiaria: %.2f\nconversion: %.2f\nkilosPollo: %.2f\n",edadPromedio,gananciaDiaria,conversion,kilosPollo);

	// Identificacion de los parámetros a comparar con base en la edad promedio obtenida

	for (i = 0; i < 15; i++) {
		if (tabla[i].edadPromedio == edadPromedio){
			miResultado = tabla[i];
			break;
		}
	}

	// Calculo de los Bonus positivos o negativos de ganancia diaria y conversion

	bonusGananciaDiaria = gananciaDiaria - miResultado.gananciaDiaria;
	bonusConversion = miResultado.conversion - conversion;


	printf("\nRESULTADOS DE TABLA SEGUN MI EDAD PROMEDIO\n\n");
	printf("Edad Promedio: %d\nGanancia Diaria: %.2f\nConversion: %.4f\n\n",miResultado.edadPromedio,miResultado.gananciaDiaria,miResultado.conversion);
	printf("BONUS\n\n");
	printf("Bonus Ganancia Diaria: %.2f\nBonus Conversion: %.2f\n\n",bonusGananciaDiaria,bonusConversion);

	// Aqui se calcula cuanto sube o baja el factor dependiendo de la ganancia diaria y de la conversion

	double factorGananciaDiaria;
	double factorConversion;

	factorGananciaDiaria = (bonusGananciaDiaria/0.01)*0.025;
	factorConversion = (bonusConversion/0.01)*0.020;

	printf("CALCULO DE LOS FACTORES DE GANANCIA DIARIA Y CONVERSION\n\n");
	printf("Factor Ganancia Diaria: %.4f\nFactor Conversion: %.4f\n\n",factorGananciaDiaria,factorConversion);

	factor = FACTORBASE + factorGananciaDiaria + factorConversion;

	printf("PAGO DE LA PARVADA\n\n");
	printf("Factor Base * Kilogramos de Pollo = 1.2 * %.2f = %.2f\n",kilosPollo,kilosPollo*1.20);
	printf("Factor Ganancia Diaria * Kilogramos de Pollo = %.4f * %.2f = %.2f\n",factorGananciaDiaria,kilosPollo,kilosPollo*factorGananciaDiaria);
	printf("Factor Conversion * Kilogramos de Pollo = %.4f * %.2f = %.2f\n\n",factorConversion,kilosPollo,kilosPollo*factorConversion);

	printf("Ganancia Final = %.2f\n",kilosPollo*factor);


	return 0;
}