/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-09-20 18:51:11
 * @LastEditTime: 2019-09-21 02:44:01
 * @LastEditors: Please set LastEditors
 */
#ifndef _CON_H_
#define _CON_H_
#include "__container.h"

#define con_con(con) (((con_t*)(con))->_container)
#define con_cmp(con) (((con_t*)(con))->_compare)

#define con_first(con) container_first(con_con(con))
#define con_last(con) container_last(con_con(con))
#define con_head(con) container_head(con_con(con))
#define con_tail(con) container_tail(con_con(con))

#define con_search(con, offset, find) container_search(con_con(con), offset, find, con_cmp(con))
#define con_find(con, find) con_search(con, con_first(con), find)

#define con_ins(con, it, data) container_insert(con_con(con), it, data)
#define con_ins_find(con, find, data) container_insert_find(con_con(con), find, data, con_cmp(con))
#define con_ins_first(con, data) container_insert_first(con_con(con), data)
#define con_ins_tail(con, data) container_insert_tail(con_con(con), data)

#define con_rm(con, it, rdata) container_remove(con_con(con), it, rdata)
#define con_rm_find(con, find, rdata) container_remove_find(con_con(con), find, rdata, con_cmp(con))
#define con_rm_first(con, rdata) container_remove_first(con_con(con), rdata)
#define con_rm_last(con, rdata) container_remove_last(con_con(con), rdata)

#define con_has(con, find) container_has(con_con(con), find, con_cmp(con))
#define con_size(con) container_size(con_con(con))

typedef struct _con {
    container_t* _container;
    int (*_compare)(type_value_t, type_value_t);

} con_t;

#endif