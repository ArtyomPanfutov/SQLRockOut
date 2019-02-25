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

void serialize_row(Row* source, char* destination)
{
    memcpy(destination + ID_OFFSET, &(source->id),        ID_SIZE);
    memcpy(destination + USERNAME_OFFSET, &(source->username),  USERNAME_SIZE);
    memcpy(destination + EMAIL_OFFSET,    &(source->email),     EMAIL_SIZE);
}

void deserialize_row(char* source, Row* destination)
{
    memcpy(&(destination->id),       source + ID_OFFSET,       ID_SIZE);
    memcpy(&(destination->username), source + USERNAME_OFFSET, USERNAME_SIZE);
    memcpy(&(destination->email),    source + EMAIL_OFFSET,    EMAIL_SIZE);
}

void* row_slot(Table* table, uint32_t row_num)
{
    uint32_t page_num = row_num / ROWS_PER_PAGE;
    void* page = get_page(table->pager, page_num);
    
    uint32_t row_offset  = row_num % ROWS_PER_PAGE;
    uint32_t byte_offset = row_offset * ROW_SIZE;
    return (char *)page + byte_offset;
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

