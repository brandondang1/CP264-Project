/*
 -------------------------------------
 File:    queue.c
 Project: dang6034_a06
 file description
 -------------------------------------
 Author:  Brandon Dang
 Version  2024-02-28
 -------------------------------------
 */

#include <stdio.h>
#include "queue.h"

/**
 * Enqueue a node into a queue
 * @param *qp - pointer to the queue
 * @param NODE *np - pointer to the node.
 **/
void enqueue(QUEUE *qp, NODE *np) {

// your code

	if (qp->length == 0) {

		qp->front = np;

	} else {

		qp->rear->next = np;

	}

	qp->rear = np;
	qp->length++;

}

/**
 * Dequeue and return the pointer of the removed node.
 * @param *qp - pointer to the queue
 **/
NODE* dequeue(QUEUE *qp) {

// your code

	if (qp->length == 0) {

		return NULL;

	}

	NODE *point = qp->front;
	qp->front = qp->front->next;
	qp->length--;

	return point;
}

/**
 * Clean the linked list queue
 * @param *qp - pointer to queue
 **/
void queue_clean(QUEUE *qp) {
	clean(&(qp->front));
	qp->front = NULL;
	qp->rear = NULL;
	qp->length = 0;
}
