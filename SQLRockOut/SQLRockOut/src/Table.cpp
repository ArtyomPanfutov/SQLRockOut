//
//  Table.cpp
//  SQLRockOut
//
//  Created by Artyom Panfutov on 16/03/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//

#include <stdio.h>
#include "BTree.h"
#include "Table.h"

Cursor* table_start(Table* table)
{
    Cursor* cursor = table_find(table, 0);
    
    void*    node      = get_page(table->pager, cursor->page_num);
    uint32_t num_cells = *leaf_node_num_cells(node);
    
    cursor->end_of_table = (num_cells == 0);
    return cursor;
}

void cursor_advance(Cursor* cursor)
{
    uint32_t page_num = cursor->page_num;
    void* node = get_page(cursor->table->pager, page_num);
    
    cursor->cell_num += 1;
    
    if (cursor->cell_num >= (*leaf_node_num_cells(node)))
    {
        /* Advance to next leaf node */
        uint32_t next_page_num = *leaf_node_next_leaf(node);
        if (next_page_num == 0)
        {
            /* This was rightmost leaf */
            cursor->end_of_table = true;
        }
        else
        {
            cursor->page_num = next_page_num;
            cursor->cell_num = 0;
        }
    }
}
