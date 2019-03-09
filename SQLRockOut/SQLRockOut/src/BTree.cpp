//
//  BTree.cpp
//  SQLRockOut
//
//  Created by Artyom Panfutov on 02/03/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "BTree.h"


uint32_t* leaf_node_num_cells(void* node)
{
    return (uint32_t *)(char *)node + LEAF_NODE_NUM_CELLS_OFFSET;
}

void* leaf_node_cell(void* node, uint32_t cell_num)
{
    return (char *)node + LEAF_NODE_HEADER_SIZE + cell_num;
}

uint32_t* leaf_node_key(void* node, uint32_t cell_num)
{
    return (uint32_t *)leaf_node_cell(node, cell_num);
}

void* leaf_node_value(void* node, uint32_t cell_num)
{
    return (char *)leaf_node_cell(node, cell_num) + LEAF_NODE_KEY_SIZE;
}

void initialize_leaf_node(void* node)
{
    *leaf_node_num_cells(node) = 0;
}

void leaf_node_insert(Cursor* cursor, uint32_t key, Row* value)
{
    void* node = get_page(cursor->table->pager, cursor->page_num);
    
    uint32_t num_cells = *leaf_node_num_cells(node);
    if (num_cells >= LEAF_NODE_MAX_CELLS)
    {
        // Node full
        printf("Need to implement splitting a leaf node. \n");
        exit(EXIT_FAILURE);
    }
    
    if (cursor->cell_num < num_cells)
    {
        // Make room for new cell
        for (uint32_t i = num_cells; i > cursor->cell_num; i--)
        {
            memcpy(leaf_node_cell(node, i), leaf_node_cell(node, i - 1), LEAF_NODE_CELL_SIZE);
        }
    }
    
    *(leaf_node_num_cells(node)) += 1;
    *(leaf_node_key(node, cursor->cell_num)) = key;
    serialize_row(value, (char *)leaf_node_value(node, cursor->cell_num));
}
