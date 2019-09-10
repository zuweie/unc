/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-09-03 15:07:40
 * @LastEditTime: 2019-09-10 13:44:27
 * @LastEditors: Please set LastEditors
 */

#ifndef _LIST_H_
#define _LIST_H_
#include "_type_value.h"
#include "_container.h"

#define list_head(list) (&((list)->_sentinel))
#define list_tail(list) (&((list)->_sentinel))
#define list_first(list) (list_head(list)->next)
#define list_last(list)  (list_tail(list)->prev)

#define list_init(list) do{             \
    list->size = 0;                     \
    list_first(list) = list_head(list); \
    list_last(list) = list_tail(list); \
}while(0)

typedef struct _list_node list_node_t;
struct _list_node
{
    /* 数据节点的data，要放在首段，否则会出现灾难性后果 */
    type_value_t data;
    list_node_t* prev;
    list_node_t* next;
};

typedef struct _list 
{
    container_t container;
    list_node_t _sentinel;
    unsigned int _size;
} list_t;

extern void init_list(list_t*);

#endif
