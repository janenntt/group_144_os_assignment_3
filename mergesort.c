/**
 * This file implements parallel mergesort.
 */

#include <stdio.h>
#include <string.h> /* for memcpy */
#include <stdlib.h> /* for malloc */
#include "mergesort.h"

/* this function will be called by mergesort() and also by parallel_mergesort(). */
void merge(int leftstart, int leftend, int rightstart, int rightend){
	
	int left_length = leftend - leftstart + 1;
	int right_length = rightend - rightstart + 1;
	
	int *B = (int *) malloc(sizeof(int) * (left_length + right_length));
	
	int i = leftstart;
	int j = rightstart;
	int k = 0;

	// merge into temp
	while (i <= leftend && j <= rightend) {
			if (A[i] <= A[j]) {
					B[k++] = A[i++];
			} else {
					B[k++] = A[j++];
			}
	}

	while (i <= leftend) B[k++] = A[i++];
	while (j <= rightend) B[k++] = A[j++];

	memcpy(&A[leftstart], B, sizeof(int) * (left_length + right_length));
	free(B);
}

/* this function will be called by parallel_mergesort() as its base case. */
void my_mergesort(int left, int right){

	if (left >= right) return;

	int mid = left + (right-left)/2;

	my_mergesort(left, mid);
	my_mergesort(mid + 1, right);

	merge(left, mid, mid+1, right);

}

/* this function will be called by the testing program. */
void * parallel_mergesort(void *arg){

	struct argument *args = (struct argument *) arg;

	pthread_t thread1, thread2;
	struct argument *arg1;
	struct argument *arg2;

	if (args->level < cutoff) {
		int mid = args->left + (args->right - args->left)/2;

		arg1 = buildArgs(args->left, mid, args->level + 1);
		arg2 = buildArgs(mid + 1, args->right, args->level + 1);

		pthread_create(&thread1, NULL, parallel_mergesort, (void *) arg1);
		pthread_create(&thread2, NULL, parallel_mergesort, (void *) arg2);

		pthread_join(thread1, NULL);
		pthread_join(thread2, NULL);

		merge(args->left, mid, mid + 1, args->right);

		free(arg1);
		free(arg2);

	} else {
		my_mergesort(args->left, args->right);
	}
	return NULL;
}

/* we build the argument for the parallel_mergesort function. */
struct argument * buildArgs(int left, int right, int level){
	struct argument *arg = (struct argument *) malloc(sizeof(struct argument));
	arg->left = left;
	arg->right = right;
	arg->level = level;
	return arg;
}

