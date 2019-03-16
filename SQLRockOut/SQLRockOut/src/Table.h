//
//  Table.h
//  SQLRockOut
//
//  Created by Artyom Panfutov on 16/03/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//

#ifndef Table_h
#define Table_h
#include <stdlib.h>
#include "Pager.h"

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
void cursor_advance(Cursor* cursor);

#endif /* Table_h */
