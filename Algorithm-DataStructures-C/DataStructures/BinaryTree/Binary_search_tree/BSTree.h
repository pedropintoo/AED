///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024
///
/// Pointers Binary Tree
///

#ifndef _BINARY_SEARCH_Tree_
#define _BINARY_SEARCH_Tree_

#include "PointersQueue.h"

// The Binary Search Tree type

typedef struct _BSTreeHeader BSTree;

// The type for item comparator functions

typedef int (*compFunc)(const void* p1, const void* p2);

// The type for item printer functions

typedef void (*printFunc)(void* p);

// The BSTree constructor/destructor

BSTree* BSTreeCreate(compFunc compF, printFunc printF);

void BSTreeDestroy(BSTree** pHeader);

// BSTree properties and getters

int BSTreeIsEmpty(const BSTree* header);

unsigned int BSTreeGetNumberOfNodes(const BSTree* header);

int BSTreeGetHeight(const BSTree* header);

void* BSTreeGetMin(const BSTree* header);

void* BSTreeGetMax(const BSTree* header);

void* BSTreeSearch(const BSTree* header, const void* item);

int BSTreeContains(const BSTree* header, const void* item);

// Recursive Traversal

void BSTreeTraverseINOrder(BSTree* header, void (*function)(void* p));

// Operations with items

int BSTreeAdd(BSTree* header, void* item);

int BSTreeRemove(BSTree* header, const void* item);

Queue* BSTreeGetItems(const BSTree* header);

// Tree visualization (nice for debugging)

void BSTreeView(const BSTree* header);

// Check some invariants BSTree* header

void BSTreeTestInvariants(const BSTree* header);

#endif  // _BINARY_SEARCH_Tree_
