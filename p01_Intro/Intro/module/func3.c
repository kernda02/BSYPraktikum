/*******************************************************************************
 * Beispiel:   Modulare Programmierung in C (und C++)
 * File:       func3.c
 * Fach:       BSy
 * Autoren:    Luca Christen
 * Version:    v.fs18
 *******************************************************************************/

#include "mydefs.h"
#include "func3.h"

myfloat_t volumen(myfloat_t radius) {
    return (4.0/3.0 * my_pi * radius * radius * radius);
}
