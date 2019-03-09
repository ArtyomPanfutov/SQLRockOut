//
//  BTree.cpp
//  SQLRockOut
//
//  Created by Artyom Panfutov on 02/03/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
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
