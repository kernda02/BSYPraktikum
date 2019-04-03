//******************************************************************************
// File:    mlist.c
// Purpose: implementation mlist (a single linked list with header dummy)
// Author:  M. Thaler, 2012, (based on former work by J. Zeman and M. Thaler)
// Version: v.fs18
//******************************************************************************

#include <stdlib.h>

#include "commondefs.h"
#include "mthread.h"
#include "mlist.h"

//******************************************************************************
// macro to allocate new tnode_t

#define mlNewTNode() (tnode_t*)malloc(sizeof(tnode_t))

//******************************************************************************

static tnode_t* mlNewNode(mthread_t* tcb, tnode_t* next)
{
  tnode_t* node = mlNewTNode();
  node->tcb = tcb;
  node->next = next;
  return node;
}

//******************************************************************************

mlist_t* mlNewList()
{
  mlist_t* list = (mlist_t *)malloc(sizeof(mlist_t));
  list->head = mlNewNode(NULL, NULL);
  list->tail = list->head;
  list->numNodes = 0;
  list->iter = NULL;
  return list;
}

void mlDelList(mlist_t* list)
{
  tnode_t* current = list->head;
  while (current != NULL) {
    tnode_t* delete = current;
    current = delete->next;
    if (delete->tcb != NULL)
        mtDelThread(delete->tcb);
    free(delete);
  }
  free(list);
}

void mlEnqueue(mlist_t* list, mthread_t* tcb)
{
  tnode_t* node = mlNewNode(tcb, NULL);
  list->tail->next = node;
  list->tail = node;
  list->numNodes++;
}

mthread_t* mlDequeue(mlist_t* list)
{
  if (list->numNodes == 0) {
    return NULL;
  }

  tnode_t* first = list->head->next;
  free(list->head);
  list->head = first;
  list->numNodes--;

  mthread_t* tcb = first->tcb;
  first->tcb = NULL;
  return tcb;
}

void mlSortIn(mlist_t* list, mthread_t* tcb)
{
  tnode_t* prev = list->head;
  tnode_t* current = prev->next;

  while (current != NULL) {
    if (mtGetReadyTime(tcb) < mtGetReadyTime(current->tcb)) {
      tnode_t* node = mlNewNode(tcb, NULL);
      node->next = current;
      prev->next = node;
      list->numNodes++;
      return;
    }

    prev = current;
    current = current->next;
  }

  mlEnqueue(list, tcb);
}

mthread_t* mlReadFirst(mlist_t* list)
{
  if (list->numNodes > 0) {
    return list->head->next->tcb;
  } else {
    return NULL;
  }
}

unsigned int mlGetNumNodes(mlist_t* list)
{
  return list->numNodes;
}

void mlSetPtrFirst(mlist_t* list)
{
  list->iter = list->head->next;
}

void mlSetPtrNext(mlist_t* list)
{
  if (list->iter != NULL) {
    list->iter = list->iter->next;
  }
}

mthread_t* mlReadCurrent(mlist_t* list)
{
  if (list->iter != NULL) {
    return list->iter->tcb;
  } else {
    return NULL;
  }
}

//******************************************************************************

