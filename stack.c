/*
 -------------------------------------
 File:    stack.c
 Project: dang6034_a06
 file description
 -------------------------------------
 Author:  Brandon Dang
 Version  2024-02-28
 -------------------------------------
 */

#include <stdio.h>
#include "stack.h"

/**
 * Push a node into a linked list stack
 * @param STACK *sp - pointer to the stack
 * @param NODE *np - pointer to the node.
 **/
void push(STACK *sp, NODE *np) {

// your code

	NODE *hold = sp->top;
	sp->top = np;
	sp->top->next = hold;
	sp->length++;

}

/**
 * Pop and return the pointer of the removed top node
 * @param STACK *sp - pointer to the stack
 **/
NODE* pop(STACK *sp) {

// your code

	if (sp->top == NULL) {

		return NULL;

	} else {

		NODE *top = sp->top;
		sp->top = sp->top->next;
		top->next = NULL;
		sp->length--;

		return top;
	}

}

/**
 * clean the linked list stack
 * @param - sp - pointer to the stack
 **/
void clean_stack(STACK *sp) {
	clean(&(sp->top));
	sp->top = NULL;
	sp->length = 0;
}
