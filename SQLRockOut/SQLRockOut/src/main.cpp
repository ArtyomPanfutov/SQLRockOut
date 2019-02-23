//
//  main.cpp
//  SQLRockOut
//
//  Created by Artyom Panfutov on 23/02/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "InputBuffer.h"
#include "Print.h"
#include "Constant.h"
#include "MetaCommand.h"

int main(int argc, const char * argv[]) {
    InputBuffer* input_buffer = new_input_buffer();
    
    while (true)
    {
        _print_prompt();
        read_input(input_buffer);
        
        if (input_buffer->buffer[0] == '.')
        {
            switch (do_meta_command(input_buffer))
            {
                case (META_COMMAND_SUCCESS):
                    continue;
                case (META_COMMAND_UNRECOGNIZED_COMMAND):
                    printf("Command not found: '%s' .\n", input_buffer->buffer);
                    continue;
            }
        }
        
        Statement statement;
        switch (prepare_statement(input_buffer, &statement))
        {
            case (PREPARE_SUCCESS):
              break;
            case (PREPARE_UNRECOGNIZED_STATEMENT):
                printf("Unrecognized keyword at start of '%s'.\n", input_buffer->buffer);
                continue;
        }
        
        execute_statement(&statement);
        printf("Executed. \n");
    }
    return 0;
}
