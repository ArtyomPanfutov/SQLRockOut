//
//  Cursor.cpp
//  SQLRockOut
//
//  Created by Artyom Panftuov on 02/03/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//

#include <stdio.h>
#include "Cursor.h"

Cursor* table_start(Table* table)
{
    Cursor* cursor       = (Cursor*)malloc(sizeof(Cursor));
    cursor->table        = table;
    cursor->row_num      = 0;
    cursor->end_of_table = (table->num_rows == 0);
    
    return cursor;
}

Cursor* table_end(Table* table)
{
    Cursor* cursor       = (Cursor*)malloc(sizeof(Cursor));
    cursor->table        = table;
    cursor->row_num      = table->num_rows;
    cursor->end_of_table = true;
    
    return cursor;
}
