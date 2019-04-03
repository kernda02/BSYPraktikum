/*******************************************************************************
* Beispiel:   Testprogramm fuer Linked List
* File:       main.c
* Fach:       BSy
* Autoren:    L. Christen
* Version:    v.fs18
*******************************************************************************/

#include <stdlib.h>

#include "commondefs.h"
#include "mlist.h"
#include "mthread.h"

/*----------------------------------------------------------------------------*/
/* Hauptprogramm                                                              */

int main(void) {
    int i;
    mthread_t* th;
    mlist_t* list = mlNewList();

    // Enqueue 10 items
    for (i = 0; i < 10; i++) {
          th = mtNewThread(i, 1, 10);
          mlEnqueue(list, th);
    }

    // Get nr of nodes
    int count =  mlGetNumNodes(list);

    // Dequeue 10 items
    for (i = 0; i < 10; i++) {
          th = mlDequeue(list);
    }

    // Delete list
    mlDelList(list);

    // Create another list
    list = mlNewList();

    // Sort elements into list
    for (i = 0; i < 10; i++) {
          th = mtNewThread(i, 1, 10);
          mlSortIn(list, th);
    }

    // Get first element
    th = mlReadFirst(list);

    // Iterate over list
    mlSetPtrFirst(list);
    while (mlReadCurrent(list) != NULL) {
        mlSetPtrNext(list);
    }

    exit(0);
}

/*----------------------------------------------------------------------------*/
