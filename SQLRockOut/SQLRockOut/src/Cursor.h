//
//  Cursor.h
//  SQLRockOut
//
//  Created by Artyom Panfutov on 02/03/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//

#ifndef Cursor_h
#define Cursor_h
#include <stdlib.h>
#include "DevelopTable.h"

struct Cursor_t
{
    Table*   table;
    uint32_t row_num;
    bool     end_of_table;
};
typedef struct Cursor_t Cursor;

Cursor* table_start(Table* table);
Cursor* table_end(Table* table);


#endif /* Cursor_h */
