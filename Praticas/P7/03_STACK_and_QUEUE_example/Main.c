//
// Created by pedro on 08-11-2023.
//
#include<stdio.h>
#include<stdlib.h>

#include "PointersQueue.h"
#include "PointersStack.h"

#include "Person.h"
#include "Date.h"


int main(void)
{
#if 1

  // Create the stack
  Stack* stack = StackCreate(10);

  // Add 10 Dates
  StackPush(stack, DateCreate(2004,10,1));
  StackPush(stack, DateCreate(2004,10,2));
  StackPush(stack, DateCreate(2004,10,3));
  StackPush(stack, DateCreate(2004,10,4));
  StackPush(stack, DateCreate(2004,10,5));
  StackPush(stack, DateCreate(2004,10,6));
  StackPush(stack, DateCreate(2004,10,7));
  StackPush(stack, DateCreate(2004,10,8));
  StackPush(stack, DateCreate(2004,10,9));
  StackPush(stack, DateCreate(2004,10,10));
  //StackPush(stack, DateCreate(2004,10,11)); //  Should assert in max size!

  // Destroy 10 Dates
  Date* d;
  d = StackPop(stack); DateDestroy(&d);
  d = StackPop(stack); DateDestroy(&d);
  d = StackPop(stack); DateDestroy(&d);
  d = StackPop(stack); DateDestroy(&d);
  d = StackPop(stack); DateDestroy(&d);
  d = StackPop(stack); DateDestroy(&d);
  d = StackPop(stack); DateDestroy(&d);
  d = StackPop(stack); DateDestroy(&d);
  d = StackPop(stack); DateDestroy(&d);
  d = StackPop(stack); DateDestroy(&d);

  // Destroy the stack;
  StackDestroy(&stack);

#else

  // Create the queue
  Queue* queue = QueueCreate(10);

  // Add 10 persons
  QueueEnqueue(queue, PersonCreate("Pedro","Pinto",2004,10,1));
  QueueEnqueue(queue, PersonCreate("Pedro","Pinto",2004,10,2));
  QueueEnqueue(queue, PersonCreate("Pedro","Pinto",2004,10,3));
  QueueEnqueue(queue, PersonCreate("Pedro","Pinto",2004,10,4));
  QueueEnqueue(queue, PersonCreate("Pedro","Pinto",2004,10,5));
  QueueEnqueue(queue, PersonCreate("Pedro","Pinto",2004,10,6));
  QueueEnqueue(queue, PersonCreate("Pedro","Pinto",2004,10,7));
  QueueEnqueue(queue, PersonCreate("Pedro","Pinto",2004,10,8));
  QueueEnqueue(queue, PersonCreate("Pedro","Pinto",2004,10,9));
  QueueEnqueue(queue, PersonCreate("Pedro","Pinto",2004,10,10));
  //QueueEnqueue(queue, PersonCreate("Pedro","Pinto",2004,10,8)); Should assert in max size!

  // Destroy 10 persons
  Person* p;
  p = QueueDequeue(queue); PersonDestroy(&p);
  p = QueueDequeue(queue); PersonDestroy(&p);
  p = QueueDequeue(queue); PersonDestroy(&p);
  p = QueueDequeue(queue); PersonDestroy(&p);
  p = QueueDequeue(queue); PersonDestroy(&p);
  p = QueueDequeue(queue); PersonDestroy(&p);
  p = QueueDequeue(queue); PersonDestroy(&p);
  p = QueueDequeue(queue); PersonDestroy(&p);
  p = QueueDequeue(queue); PersonDestroy(&p);
  p = QueueDequeue(queue); PersonDestroy(&p);

  // Destroy the queue;
  QueueDestroy(&queue);

#endif

  return EXIT_SUCCESS;
}