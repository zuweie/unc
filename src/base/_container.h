/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-09-07 23:21:46
 * @LastEditTime: 2019-09-15 03:58:01
 * @LastEditors: Please set LastEditors
 */
#ifndef _CONTAINER_H_
#define _CONTAINER_H_


#include "_type_value.h"
#include "_iterator.h"

#define container_first(container) (((container_t*)(container))->first(container))
#define container_last(container) (((container_t*)(container))->last(container))
#define container_head(container) iterator_prev(container_first(container))
#define container_tail(container) iterator_next(container_last(container))
#define container_find(container, data, compare) (((container_t*)(container))->find(container, data, compare))
#define container_insert(container, iter, data) (((container_t*)(container))->insert(container, iter, data))
#define container_remove(container, iter, data) (((container_t*)(container))->remove(container, iter, data))
#define container_size(container) ((container_t*)(container))->size()

#define initialize_container(container, __first, __last, __find, __insert, __remove, __size) do { \
    ((container_t*)container)->first = (__first);                                         \
    ((container_t*)container)->last = (__last);                                           \
    ((container_t*)container)->find = (__find);                                           \
    ((container_t*)container)->insert = (__insert);                                       \
    ((container_t*)container)->remove = (__remove);                                       \
    ((container_t*)container)->size = (__size);                                           \
} while (0)

typedef struct _container container_t;
typedef struct _iterator iterator_t;
struct _container {
    iterator_t (*first) (container_t* container);   
    iterator_t (*last) (container_t * container);   
    iterator_t (*find) (container_t* container, type_value_t data, int (*compare)(type_value_t, type_value_t)); 
    int (*insert) (container_t* container, iterator_t iter, type_value_t data); 
    int (*remove) (container_t* container, iterator_t iter, type_value_t* rdata); 
    unsigned int (*size) (container_t*);
};

#endif