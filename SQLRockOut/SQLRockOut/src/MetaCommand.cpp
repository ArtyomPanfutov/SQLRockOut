//
//  MetaCommand.cpp
//  SQLRockOut
//
//  Created by Artyom Panfutov on 23/02/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "MetaCommand.h"
#include "Constant.h"
#include "BTree.h"

MetaCommandResult do_meta_command(InputBuffer* input_buffer, Table* table)
{
    if (strcmp(input_buffer->buffer, META_EXIT_COMMAND) == 0)
    {
        db_close(table);
        exit(EXIT_SUCCESS);
    }
    else if (strcmp(input_buffer->buffer, META_PRINT_CONST_COMMAND) == 0)
    {
        print_constants();
        return META_COMMAND_SUCCESS;
    }
    else
    {
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}

void print_constants()
{
    printf("ROW_SIZE: %d\n", ROW_SIZE);
    +  printf("COMMON_NODE_HEADER_SIZE: %d\n", COMMON_NODE_HEADER_SIZE);
    +  printf("LEAF_NODE_HEADER_SIZE: %d\n", LEAF_NODE_HEADER_SIZE);
    +  printf("LEAF_NODE_CELL_SIZE: %d\n", LEAF_NODE_CELL_SIZE);
    +  printf("LEAF_NODE_SPACE_FOR_CELLS: %d\n", LEAF_NODE_SPACE_FOR_CELLS);
    +  printf("LEAF_NODE_MAX_CELLS: %d\n", LEAF_NODE_MAX_CELLS);
}
