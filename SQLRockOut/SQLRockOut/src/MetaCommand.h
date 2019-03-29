//
//  MetaCommand.h
//  SQLRockOut
//
//  Created by Artyom Panfutov on 23/02/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//

#ifndef MetaCommand_h
#define MetaCommand_h

#include "InputBuffer.h"
#include "DevelopTable.h"

/**********************************************************
 *                    META COMMANDS                       *
 **********************************************************/

/* Exit command */
#define META_EXIT_COMMAND        ".exit"
#define META_PRINT_CONST_COMMAND ".constants"
#define META_COMMANT_BTREE       ".btree"

/**********************************************************/

enum MetaCommandResult_t
{
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
};
typedef enum MetaCommandResult_t MetaCommandResult;

MetaCommandResult do_meta_command(InputBuffer* input_buffer, Table* table);
void print_constants();
void indent(uint32_t level);
void print_tree(Pager* pager, uint32_t page_num, uint32_t indentation_level);
#endif /* MetaCommand_h */
