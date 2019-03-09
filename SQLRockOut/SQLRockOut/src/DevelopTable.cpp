//
//  DevelopTable.cpp
//  SQLRockOut
//
//  Created by Artyom Panfutov on 23/02/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include "Constant.h"
#include "DevelopTable.h"
#include "BTree.h"

Cursor* table_start(Table* table)
{
    Cursor* cursor = (Cursor*)malloc(sizeof(Cursor));
    cursor->table  = table;

    cursor->page_num = table->root_page_num;
    cursor->cell_num = 0;
    
    void* root_node = get_page(table->pager, table->root_page_num);
    uint32_t num_cells   = *leaf_node_num_cells(root_node);
    cursor->end_of_table = (num_cells == 0);
    
    return cursor;
}

Cursor* table_end(Table* table)
{
    Cursor* cursor       = (Cursor*)malloc(sizeof(Cursor));
    cursor->table        = table;
    cursor->page_num     = table->root_page_num;
    
    void* root_node      = get_page(table->pager, table->root_page_num);
    uint32_t num_cells   = *leaf_node_num_cells(root_node);
    cursor->cell_num     = num_cells;
    cursor->end_of_table = true;
    
    return cursor;
}

void cursor_advance(Cursor* cursor)
{
    cursor->row_num += 1;
    if (cursor->row_num >= cursor->table->num_rows)
    {
        cursor->end_of_table = true;
    }
}


void serialize_row(Row* source, char* destination)
{
    memcpy(destination + ID_OFFSET,       &(source->id),        ID_SIZE);
    memcpy(destination + USERNAME_OFFSET, &(source->username),  USERNAME_SIZE);
    memcpy(destination + EMAIL_OFFSET,    &(source->email),     EMAIL_SIZE);
}

void deserialize_row(char* source, Row* destination)
{
    memcpy(&(destination->id),       source + ID_OFFSET,       ID_SIZE);
    memcpy(&(destination->username), source + USERNAME_OFFSET, USERNAME_SIZE);
    memcpy(&(destination->email),    source + EMAIL_OFFSET,    EMAIL_SIZE);
}

void* cursor_value(Cursor* cursor)
{
    uint32_t page_num = cursor->page_num;
    void* page = get_page(cursor->table->pager, page_num);
    
    return leaf_node_value(page, cursor->cell_num);
}

Table* db_open(const char* filename)
{
    Pager* pager = pager_open(filename);
    uint32_t num_rows = pager->file_length / ROW_SIZE;
    Table* table = (Table *)malloc(sizeof(Table));
    table->pager = pager;
    table->num_rows = num_rows;
    
    return table;
}

void db_close(Table* table)
{
    Pager* pager = table->pager;
    
    for (uint32_t i = 0; i < pager->num_pages; i++)
    {
        if (pager->pages[i] == NULL)
        {
            continue;
        }
        pager_flush(pager, i);
        free(pager->pages[i]);
        pager->pages[i] = NULL;
    }
    
    int result = close(pager->file_descriptor);
    if (result == -1)
    {
        printf("Error closing db file.\n");
        exit(EXIT_FAILURE);
    }
    
    for (uint32_t i = 0; i < TABLE_MAX_PAGES; i++)
    {
        void* page = pager->pages[i];
        if (page)
        {
            free(page);
            pager->pages[i] = NULL;
        }
    }
    free(pager);
}

