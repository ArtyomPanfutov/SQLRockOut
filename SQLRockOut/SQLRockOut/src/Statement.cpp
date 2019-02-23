//
//  Statement.cpp
//  SQLRockOut
//
//  Created by Artyom Panfutov on 23/02/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include "Statement.h"

void execute_statement(Statement* statement)
{
    switch (statement->type)
    {
        case (STATEMENT_INSERT):
            printf("INSERT SHOULD BE IMPLEMENTED RIGHT HERE\n");
            break;
        case (STATEMENT_SELECT):
            printf("SELECT SHOULD BE IMPLEMENTED RIGH HERE\n");
            break;
    }
}

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement)
{
    if (strncmp(input_buffer->buffer, INSERT_STATEMENT, 6) == 0)
    {
        statement->type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }
    
    if (strncmp(input_buffer->buffer, SELECT_STATEMENT, 6) == 0)
    {
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }
    
    return PREPARE_UNRECOGNIZED_STATEMENT;
}
