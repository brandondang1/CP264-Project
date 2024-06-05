/*
 -------------------------------------
 File:    stack.h
 Project: dang6034_a06
 file description
 -------------------------------------
 Author:  Brandon Dang
 Version  2024-02-28
 -------------------------------------
 */

#ifndef STACK_H
#define STACK_H
#include "common.h"

/**
 * Define a structure STACK containing the length and pointer of the top node.
 * int length - maintains the length of stack.
 * NODE *top - pointer to the top node of linked list stack
 **/
typedef struct stack {
	int length;
	NODE *top;
} STACK;

/**
 * Push a node into a linked list stack
 * @param STACK *sp - pointer to the stack
 * @param NODE *np - pointer to the node.
 **/
void push(STACK *sp, NODE *np);

/**
 * Pop and return the pointer of the removed top node
 * @param STACK *sp - pointer to the stack
 **/
NODE* pop(STACK *sp);

/**
 * clean the linked list stack
 * @param - sp - pointer to the stack
 **/
void clean_stack(STACK *sp);

#endif
