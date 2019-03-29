//
//  DevelopTable.h
//  SQLRockOut
//
//  Created by Artyom Panfutov on 23/02/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//



#ifndef DevelopTable_h
#define DevelopTable_h
#include "Pager.h"
#include "Constant.h"
#include "Btree.h"
#include <stdlib.h>

/*
 Moved into table.h
 struct Table_t
{
    Pager* pager;
    uint32_t root_page_num;
};
typedef struct Table_t Table;

struct Cursor_t
{
    Table*   table;
    uint32_t page_num;
    uint32_t cell_num;
    bool     end_of_table;
};
typedef struct Cursor_t Cursor;

Cursor* table_start(Table* table);
void cursor_advance(Cursor* cursor);*/

//void serialize_row(Row* source, char* destination);
//void deserialize_row(char* source, Row* destination);
void* cursor_value(Cursor* cursor);
Table* db_open(const char* filename);
void db_close(Table* table);

#endif /* DevelopTable_h */
