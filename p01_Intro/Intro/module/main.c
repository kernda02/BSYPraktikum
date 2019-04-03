/*******************************************************************************
* Beispiel:   Modulare Programmierung in C (und C++),
* File:       main.c
* Fach:       BSy
* Autoren:    J.Zeman, M. Thaler
* Version:    v.fs18
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mydefs.h"   /* Headerdatei mit eigenen Typen und Konstante */
#include "func1.h"    /* Headerdatei fuer Modul func1.c   */
#include "func2.h"    /* Headerdatei fuer Modul func2.c   */
#include "func3.h"    /* Headerdatei fuer Modul func3.c   */


/*----------------------------------------------------------------------------*/
/* Funktionsprototypen: (lokale Funktionen in diesem Modul)                   */

void eingabe(myfloat_t *x);

/*----------------------------------------------------------------------------*/
/* Hauptprogramm                                                              */

int main(void) {
  myfloat_t R, F, U, V;

    eingabe(&R);
    printf("\n\n Kreisberechnung");
    printf(" (berechnet mit pi = %11.10f)\n", M_PI);  /* aus math.h */
    U = umfang(R);
    F = flaeche(R);
    V = volumen(R);
    printf("\n Radius =\t%f \n Umfang =\t%f \n Flaeche =\t%f\n Volumen =\t%f\n",
           R , U, F, V);
    getchar(); getchar();                       /* dummy input -> warte hier */
    exit(0);
}

/*----------------------------------------------------------------------------*/
/* lokale Funktion                                                            */

void eingabe(myfloat_t *x) {
    printf("\n Kreisberechnung: Radius = ? ");
    scanf("%lf", x);
}

/*----------------------------------------------------------------------------*/
