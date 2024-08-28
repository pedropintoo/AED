//
// Algoritmos e Estruturas de Dados --- 2023/2024
//

// Complete the functions (marked by ...)
// so that it passes all tests in Tests.

#include "PersonSet.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BSTree.h"

// NOTE THAT:
// - Field capacity was eliminated.
// - Field size was eliminated, because size==BSTreeGetNumberOfNodes(...).

// Definition of the structure
struct _PersonSet_ {
  BSTree *persons;  // points to a BSTree of Person pointers
};

// Comparison function to be used in generic BSTree.
// Comparison is based on Person ID
static int cmpP(const void *a, const void *b) {
  Person *p1 = (Person *)a;
  Person *p2 = (Person *)b;
  int d = p1->id - p2->id;
  return (d > 0) - (d < 0);
}

// Print function to be used in generic BSTree.
static void printP(void *p) { PersonPrintf((Person *)p, ""); }

// Create a PersonSet.
PersonSet *PersonSetCreate() {
  // You must allocate space for the struct and create an empty persons tree!
  // COMPLETE
  PersonSet* personSet = (PersonSet*) malloc(sizeof(PersonSet));
  if(personSet == NULL) {
    perror("PersonSetCreate Fail");
    return NULL;
  }

  personSet->persons = BSTreeCreate(cmpP,printP);

  if(personSet->persons == NULL) {
    free(personSet);
    // perror("PersonSetCreate Fail"); // (não é necessário) BSTreeCreate deve gerir o erro!
    return NULL;
  }

  BSTreeTestInvariants(personSet->persons);
  return personSet;
}

// Destroy PersonSet *pps
void PersonSetDestroy(PersonSet **pps) {
  assert(*pps != NULL);
  // COMPLETE

  BSTreeDestroy(&((*pps)->persons));

  free(*pps);
  *pps = NULL;

}

int PersonSetSize(const PersonSet *ps) {
  return BSTreeGetNumberOfNodes(ps->persons);
}

int PersonSetIsEmpty(const PersonSet *ps) { return BSTreeIsEmpty(ps->persons); }

// Print function to use in PersonSetPrint
static void printlnP(void *p) { PersonPrintf((Person *)p, ";\n"); }

void PersonSetPrint(const PersonSet *ps) {
  printf("{\n");
  BSTreeTraverseINOrder(ps->persons, printlnP);
  printf("}(size=%d)\n", PersonSetSize(ps));
}

// Find node in BSTree ps->persons of person with given id.
// Return a pointer to the stored Person instance.
// Or NULL, if it does not belong to the BSTree.
// (INTERNAL function.)
static Person *search(const PersonSet *ps, int id) {
  Person dummyPerson;
  dummyPerson.id = id;
  return BSTreeSearch(ps->persons, &dummyPerson);
}

// Add person *p to *ps.
// Do nothing if *ps already contains a person with the same id.
void PersonSetAdd(PersonSet *ps, Person *p) {
  // COMPLETE
  // ...
  BSTreeAdd(ps->persons, p);
  
  BSTreeTestInvariants(ps->persons);
}

// Pop one person out of *ps.
Person *PersonSetPop(PersonSet *ps) {
  assert(!PersonSetIsEmpty(ps));
  // It is easiest to pop and return the first person in the set!
  // COMPLETE
  // ...
  Person* dummyPerson = (Person *) BSTreeGetMin(ps->persons);
  assert(BSTreeRemove(ps->persons, dummyPerson));

  BSTreeTestInvariants(ps->persons);
  return dummyPerson;

}

// Remove the person with given id from *ps, and return it.
// If no such person is found, return NULL and leave set untouched.
Person *PersonSetRemove(PersonSet *ps, int id) {
  // You may call search here!
  // COMPLETE
  // ...
  Person* dummyPerson = search(ps,id);
  if (dummyPerson == NULL) return NULL;
  
  BSTreeRemove(ps->persons, dummyPerson);

  BSTreeTestInvariants(ps->persons);
  return dummyPerson;
}

// Get the person with given id of *ps.
// return NULL if it is not in the set.
Person *PersonSetGet(const PersonSet *ps, int id) {
  // You may call search here!
  // COMPLETE
  // ...
  return search(ps, id);
}

// Return true (!= 0) if set contains person with given id, false otherwise.
int PersonSetContains(const PersonSet *ps, int id) {
  return search(ps, id) != NULL;
}

// Return a NEW PersonSet with the union of *ps1 and *ps2.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetUnion(const PersonSet *ps1, const PersonSet *ps2) {
  PersonSet *ps = PersonSetCreate();

  // COMPLETE
  // ...
  Queue* q1 = BSTreeGetItems(ps1->persons);
  while(!QueueIsEmpty(q1)) {
    PersonSetAdd(ps, QueueDequeue(q1));
  }

  Queue* q2 = BSTreeGetItems(ps2->persons);
  while(!QueueIsEmpty(q2)) {
    PersonSetAdd(ps, QueueDequeue(q2));
  }

  BSTreeTestInvariants(ps->persons);
  return ps;
}

// Return a NEW PersonSet with the intersection of *ps1 and *ps2.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetIntersection(const PersonSet *ps1, const PersonSet *ps2) {
  PersonSet *ps = PersonSetCreate();

  // COMPLETE
  // ...  
  BSTree* smallestBSTree;
  BSTree* largestBSTree;

  if (PersonSetSize(ps1) < PersonSetSize(ps2)) {
    smallestBSTree = ps1->persons;
    largestBSTree = ps2->persons;
  } else {
    smallestBSTree = ps2->persons;
    largestBSTree = ps1->persons;
  }

  Queue* smallestQueue = BSTreeGetItems(smallestBSTree);

  while(!QueueIsEmpty(smallestQueue)) {
    Person* current = QueueDequeue(smallestQueue);
    if (BSTreeContains(largestBSTree,current)) PersonSetAdd(ps, current);
  }
  QueueDestroy(&smallestQueue);

  BSTreeTestInvariants(ps->persons);
  return ps;
}

// Return a NEW PersonSet with the set difference of *ps1 and *ps2.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetDifference(const PersonSet *ps1, const PersonSet *ps2) {
  PersonSet *ps = PersonSetCreate();

  // COMPLETE
  // ...
  Queue* q1 = BSTreeGetItems(ps1->persons);
  while(!QueueIsEmpty(q1)) {
    Person* current = QueueDequeue(q1);
    if (!BSTreeContains(ps2->persons,current)) PersonSetAdd(ps, current);
  }

  BSTreeTestInvariants(ps->persons);
  return ps;
}

// Return true iff *ps1 is a subset of *ps2.
int PersonSetIsSubset(const PersonSet *ps1, const PersonSet *ps2) {
  // COMPLETE
  // ...
  if (PersonSetSize(ps1) > PersonSetSize(ps2)) return 0;

  Queue* q1 = BSTreeGetItems(ps1->persons);
  while(!QueueIsEmpty(q1)) {
    Person* current = QueueDequeue(q1);
    if (!BSTreeContains(ps2->persons, current)) return 0;
  }

  return 1;
}

// Return true if the two sets contain exactly the same elements.
int PersonSetEquals(const PersonSet *ps1, const PersonSet *ps2) {
  return PersonSetSize(ps1) == PersonSetSize(ps2) &&
         PersonSetIsSubset(ps1, ps2);
}
