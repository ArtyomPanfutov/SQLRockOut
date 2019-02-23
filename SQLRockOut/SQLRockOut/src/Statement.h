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

/*************************************************************
 *                       STATEMENTS                          *
 *************************************************************/

#define INSERT_STATEMENT "insert"
#define SELECT_STATEMENT "select"

/*************************************************************/
enum PrepareResult_t
{
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT
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
};
typedef struct Statement_t Statement;


/**************************
 *       Prototypes       *
 **************************/

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);
void          execute_statement(Statement* statement);

#endif /* Statement_h */
