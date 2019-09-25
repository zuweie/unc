/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-09-14 10:14:04
 * @LastEditTime: 2019-09-23 08:07:02
 * @LastEditors: Please set LastEditors
 */
#include "_graph.h"
#include "_con.h"
#include "__mem_pool.h"

static vertex_t* _create_vertex(graph_t* graph, type_value_t vertex) 
{
    vertex_t* v = allocate(pool(0), sizeof(vertex_t));
    v->vertex = vertex;
    init_set(&v->adjacency, graph->compare_adjnode);
    return v;
}

static adjacency_node_t* _create_adjacency_node(vertex_t* to, float weight) 
{
    adjacency_node_t* node = allocate(pool(0), sizeof(adjacency_node_t));
    node->to = to;
    node->weight = weight;
    return node;
}

int init_graph(graph_t* graph, int(*compare_vertex)(type_value_t, type_value_t), int(*compare_adjnode)(type_value_t, type_value_t)) 
{
    init_set(&graph->vertexes, compare_vertex);
    graph->compare_adjnode = compare_adjnode;
    graph->compare_vertex  = compare_vertex;
    return 0;
} 

int graph_add_vertex(graph_t* graph, type_value_t vertex) 
{
    vertex_t* v = _create_vertex(graph, vertex);
    // 值插屁股
    return set_insert(&v->adjacency, pointer_type(v));
}

int graph_add_edge(graph_t* graph, type_value_t from, type_value_t to, float weight)
{
    it_t it_from = con_find(&graph->vertexes, from);
    it_t it_to   = con_find(&graph->vertexes, to);
    
    if (it_valid(it_from) && it_valid(it_to)) {
        
        vertex_t* v_from = type_pointer(it_derefer(it_from));
        vertex_t* v_to   = type_pointer(it_derefer(it_to));

        return set_insert(&v_from->adjacency, pointer_type(v_to));
    }
    return -1;
}

int graph_del_vertex(graph_t* graph, type_value_t vertex)
{
    
    type_value_t r_vertext;
    if (con_rm_find(&graph->vertexes, vertex, &r_vertext) != -1) {
        vertex_t* pv = type_pointer(r_vertext);

        type_value_t r_adj;

        while( con_rm_last(&pv->adjacency, &r_adj) != -1 ) {
            deallocate(pool(0), type_pointer(r_adj));
        }

        deallocate(pool(0), pv);
        return 0;
    }
    return -1;
}

int graph_del_edge(graph_t* graph, type_value_t from, type_value_t to)
{
    it_t it_from = con_find(&graph->vertexes, from);
    it_t it_to   = con_find(&graph->vertexes, to);

    if (it_valid(it_from) && it_valid(it_to)) {

        vertex_t* v_from = type_pointer(it_derefer(it_from));
        vertex_t* v_to   = type_pointer(it_derefer(it_to));

        type_value_t r_adj;
        if (con_rm_find(&v_from->adjacency, pointer_type(v_to), &r_adj) != -1) {
            deallocate(pool(0), type_pointer(r_adj));
            return 0;
        }
    }
    return -1;
}

void graph_set_vertex_data(iterator_t it, void* data) 
{
    vertex_t* vertex = type_pointer(it_derefer(it));
    vertex->data = data;
    return;
}

void* graph_get_vertex_data(iterator_t it) 
{
    vertex_t* vertex = type_pointer(it_derefer(it));
    return vertex->data;
}
