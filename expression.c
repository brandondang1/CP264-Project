/*
 -------------------------------------
 File:    expression.c
 Project: dang6034_a06
 file description
 -------------------------------------
 Author:  Brandon Dang
 Version  2024-02-28
 -------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression.h"

/**
 * Convert infix expression string to postfix expression reprsented by queue data structure.
 * @param infixstr - string of infix expression.
 * @return - postfix expression in queue of QUEUE type.
 **/
QUEUE infix_to_postfix(char *infixstr) {

// your code

	char *p = infixstr;
	QUEUE queue = { 0 };
	STACK stack = { 0 };
	int sign = 1;
	int num = 0;
	while (*p) {

		if (*p == '-' && (p == infixstr || *(p - 1) == '(')) {

			sign = -1;

		} else if (get_type(*p) == 0) { //*p is a digit

			num = *p - '0';

			while ((*(p + 1) >= '0' && *(p + 1) <= '9')) {

				num = num * 10 + *(p + 1) - '0';
				p++;

			}

			enqueue(&queue, new_node(sign * num, 0));
			sign = 1;

		} else if (get_type(*p) == 1) { //*p is an operator character

			while (stack.top
					&& get_priority(stack.top->data) >= get_priority(*p)) {
				enqueue(&queue, pop(&stack));
			}
			push(&stack, new_node(*p, 1));

		} else if (get_type(*p) == 2) { //*p=='('

			push(&stack, new_node(*p, 2));

		} else if (get_type(*p) == 3) { //*p==')'

			while (stack.top && stack.top->type != 2) {

				enqueue(&queue, pop(&stack));

			}
			//printf("%d\n", stack.top->data);

			pop(&stack);

		} //else ignore

		//display(queue.front);
		p++; //moves to next character

	}

	while (stack.top) {

		//printf("%d\n", stack.top->data);

		enqueue(&queue, pop(&stack));

	}

	return queue;

}

/**
 * Evaluate and return the value postfix expression passed by queue.
 * @parame queue - postfix expression in queue of QUEUE type.
 ^ @return - value of postfix expression
 **/
int evaluate_postfix(QUEUE queue) {

// your code

	NODE *p = queue.front;
	STACK stack = { 0 };
	int type = 0;
	while (p) {

		type = p->type;

		if (type == 0) {

			push(&stack, new_node(p->data, 0));

		} else if (type == 1) {

			int operator = p->data;
			NODE *oprand2 = pop(&stack);
			if (operator == '+') {

				stack.top->data = stack.top->data + oprand2->data;

			} else if (operator == '-') {

				stack.top->data = stack.top->data - oprand2->data;

			} else if (operator == '/') {

				stack.top->data = stack.top->data / oprand2->data;

			} else if (operator == '*') {

				stack.top->data = stack.top->data * oprand2->data;

			} else if (operator == '%') {

				stack.top->data = stack.top->data % oprand2->data;

			}

			free(oprand2);

		}

		p = p->next;

	}

	int result = stack.top->data;
	clean_stack(&stack);
	return result;

}

/**
 * Evaluate and return the value of infix expression passed by string infixstr,
 * using infix_to_postfix() and evaluate_postfix() functions.
 * @param infixstr - string of infix expression.
 * @return - value of the infix expression.
 **/
int evaluate_infix(char *infixstr) {

// your code

	int value = evaluate_postfix(infix_to_postfix(infixstr));

	return value;

}
