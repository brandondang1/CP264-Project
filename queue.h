/*
 -------------------------------------
 File:    queue.h
 Project: dang6034_a06
 file description
 -------------------------------------
 Author:  Brandon Dang
 Version  2024-02-28
 -------------------------------------
 */

#ifndef QUEUE_H
#define QUEUE_H
#include "common.h"

/**
 * Define a structure QUEUE containing length and pointers of front and rare node.
 * int length - maintains the length of queue,
 * NODE *front - pointer to the front node of linked list queue
 * NODE *rear - points to the rare node of linked list queue
 **/
typedef struct queue {
	int length;
	NODE *front;
	NODE *rear;
} QUEUE;

/**
 * Enqueue a node into a queue
 * @param *qp - pointer to the queue
 * @param NODE *np - pointer to the node.
 **/
void enqueue(QUEUE *qp, NODE *np);

/**
 * Dequeue and return the pointer of the removed node.
 * @param *qp - pointer to the queue
 **/
NODE* dequeue(QUEUE *qp);

/**
 * Clean the linked list queue
 * @param *qp - pointer to queue
 **/
void queue_clean(QUEUE *qp);

#endif
