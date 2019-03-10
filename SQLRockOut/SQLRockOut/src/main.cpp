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
#include "Statement.h"
#include "DevelopTable.h"

int main(int argc, const char * argv[]) {
    InputBuffer* input_buffer = new_input_buffer();
    
    char* filename = DB_NAME;
    Table* table = db_open(filename);
    
    while (true)
    {
        _print_prompt();
        read_input(input_buffer);
        
        if (input_buffer->buffer[0] == '.')
        {
            switch (do_meta_command(input_buffer, table))
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
            case (PREPARE_NEGATIVE_ID):
                printf("ID < 0. \n");
                continue;
            case (PREPARE_STRING_TOO_LONG):
                printf("String is too long. \n");
                continue;
            case (PREPARE_SYNTAX_ERROR):
                printf("Syntax error. \n");
                continue;
        }
        
        switch (execute_statement(&statement, table)) {
            case (EXECUTE_SUCCESS):
                printf("Succesfuly executed.\n");
                break;
            case (EXECUTE_DUPLICATE_KEY):
                printf("Error: duplicate key. \n");
                break;
            case (EXECUTE_TABLE_FULL):
                printf("Error: table full.\n");
                break;
        }
    }
    return 0;
}
