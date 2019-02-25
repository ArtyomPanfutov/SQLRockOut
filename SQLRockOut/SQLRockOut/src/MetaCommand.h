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

/**********************************************************
 *                    META COMMANDS                       *
 **********************************************************/

/* Exit command */
#define META_EXIT_COMMAND ".exit"


/**********************************************************/

enum MetaCommandResult_t
{
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
};
typedef enum MetaCommandResult_t MetaCommandResult;

MetaCommandResult do_meta_command(InputBuffer* input_buffer, Table* table);

#endif /* MetaCommand_h */
