//
//  BTree.h
//  SQLRockOut
//
//  Created by Artyom Panfutov on 02/03/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//

#ifndef BTree_h
#define BTree_h
#include <stdlib.h>
#include "DevelopTable.h"

enum NodeType_t
{
    NODE_INTERNAL,
    NODE_LEAF
};
typedef enum NodeType_t NodeType;

/*
 * Common Node Header Layout
 */
const uint32_t NODE_TYPE_SIZE   = sizeof(uint8_t);
const uint32_t NODE_TYPE_OFFSET = 0;
const uint32_t IS_ROOT_SIZE     = sizeof(uint8_t);
const uint32_t IS_ROOT_OFFSET   = NODE_TYPE_SIZE;
const uint32_t PARENT_POINTER_SIZE    = sizeof(uint32_t);
const uint32_t PARENT_POINTER_OFFSET  = IS_ROOT_OFFSET + IS_ROOT_SIZE;
const uint8_t COMMON_NODE_HEADER_SIZE = NODE_TYPE_SIZE + IS_ROOT_SIZE + PARENT_POINTER_SIZE;

/*
 * Leaf Node Header Layout
 */
const uint32_t LEAF_NODE_NUM_CELLS_SIZE   = sizeof(uint32_t);
const uint32_t LEAF_NODE_NUM_CELLS_OFFSET = COMMON_NODE_HEADER_SIZE;
const uint32_t LEAF_NODE_HEADER_SIZE      = COMMON_NODE_HEADER_SIZE + LEAF_NODE_NUM_CELLS_SIZE;

/*
 * Leaf Node Body Layout
 */
const uint32_t LEAF_NODE_KEY_SIZE     = sizeof(uint32_t);
const uint32_t LEAF_NODE_KEY_OFFSET   = 0;
const uint32_t LEAF_NODE_VALUE_SIZE   = ROW_SIZE;
const uint32_t LEAF_NODE_VALUE_OFFSET = LEAF_NODE_KEY_OFFSET + LEAF_NODE_KEY_OFFSET;
const uint32_t LEAF_NODE_CELL_SIZE    = LEAF_NODE_KEY_SIZE + LEAF_NODE_VALUE_SIZE;
const uint32_t LEAF_NODE_SPACE_FOR_CELLS = PAGE_SIZE - LEAF_NODE_HEADER_SIZE;
const uint32_t LEAF_NODE_MAX_CELLS       = LEAF_NODE_SPACE_FOR_CELLS / LEAF_NODE_CELL_SIZE;

/**************************************************************
 *                         PROTOTYPES                         *
 **************************************************************/

uint32_t* leaf_node_num_cells(void* node);
void*     leaf_node_cell(void* node, uint32_t cell_num);
uint32_t* leaf_node_key(void* node, uint32_t cell_num);
void*     leaf_node_value(void* node, uint32_t cell_num);
void      initialize_leaf_node(void* node);
void      leaf_node_insert(Cursor* cursor, uint32_t key, Row* value);
Cursor*   table_find(Table* table, uint32_t key);
Cursor*   leaf_node_find(Table* table, uint32_t page_num, uint32_t key);
NodeType  get_node_type(void* node);
void      set_node_type(void* node, NodeType type);
/**************************************************************/
#endif /* BTree_h */
