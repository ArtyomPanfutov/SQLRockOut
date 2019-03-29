//
//  Statement.h
//  SQLRockOut
//
//  Created by Artyom Panfutov on 23/02/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//

#ifndef Statement_h
#define Statement_h

#include "InputBuffer.h"
#include "DevelopTable.h"
#include "Constant.h"
#include <stdlib.h>

/*************************************************************
 *                       STATEMENTS                          *
 *************************************************************/

#define INSERT_STATEMENT "insert"
#define SELECT_STATEMENT "select"

/*************************************************************/

enum PrepareResult_t
{
    PREPARE_SUCCESS,
    PREPARE_NEGATIVE_ID,
    PREPARE_STRING_TOO_LONG,
    PREPARE_UNRECOGNIZED_STATEMENT,
    PREPARE_SYNTAX_ERROR
};
typedef enum PrepareResult_t PrepareResult;

enum StatementType_t
{
    STATEMENT_INSERT,
    STATEMENT_SELECT
};
typedef enum StatementType_t StatementType;

struct Statement_t
{
    StatementType type;
    Row row_to_insert;
};
typedef struct Statement_t Statement;

enum ExecuteResult_t
{
    EXECUTE_SUCCESS,
    EXECUTE_DUPLICATE_KEY,
    EXECUTE_TABLE_FULL
};
typedef enum ExecuteResult_t ExecuteResult;

/**************************************************************
 *                         PROTOTYPES                         *
 **************************************************************/

PrepareResult prepare_insert(InputBuffer* input_buffer, Statement* statement);
PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);
ExecuteResult execute_insert(Statement* statement, Table* table);
ExecuteResult execute_select(Statement* statement, Table* table);
ExecuteResult execute_statement(Statement* statement, Table* table);

/**************************************************************/
#endif /* Statement_h */
