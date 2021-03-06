/*
 * File: data_structure.h
 * Author: Paul Vorobyev (pv149)
 * Date: 02/08/2018
 *
 * All primitive data structures and associated methods used 
 * in the scheduler are defined here.
 */

#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#define _GNU_SOURCE

/* Struct definitions */

// Queue

typedef struct linked_node {
    void * data;
    struct linked_node * next;
    struct linked_node * prev;
} node;

typedef struct queue_structure {
    node * head;
    node * rear;
    int size;
} queue;

// Hashtable

typedef int (*hash_fn)(int, int); // hashes id

typedef struct hash_table_structure {
    queue ** elements;
    int size;
    hash_fn hash;
} hash_table;

// Min Heap

typedef int (*cmp_fn)( void *, void * );

typedef struct heap_node {
    void *data;
} h_node;

typedef struct min_heap_structure {
    cmp_fn cmp;
    h_node *arr;
    int size;
    int capacity;
} m_heap;

// Arraylist

typedef struct arraylist_structure_ {
    void **array;
    int size;
    int capacity;
} array_list;

/* Method definitions */

// Queue

queue * queue_init();
void queue_enqueue(void * element, queue * q);
void * queue_dequeue(queue * q);
void * peek(queue * q);
int isEmpty(queue * q);

// Hashtable

hash_table * hash_init();
void hash_insert(hash_table * h, void * t, int id);
void * hash_find(hash_table * h, int id);
void hash_delete(hash_table *h, int id);

// Min Heap

m_heap *m_heap_init(cmp_fn cmp);
int m_heap_is_empty(m_heap *h);
void m_heap_insert(m_heap *h, void *data);
void *m_heap_delete(m_heap *h);

#endif

// Arraylist

array_list *array_list_init(int initial_size);
int array_list_is_empty(array_list *a);
void array_list_add(array_list *a, void *item);
void *array_list_get(array_list *a, int index);

