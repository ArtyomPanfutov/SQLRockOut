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

#include "Constant.h"
#include "InputBuffer.cpp"

int main(int argc, const char * argv[]) {
    InputBuffer* input_buffer = new_input_buffer();
    
    while (true)
    {
        print_prompt();
        read_input(input_buffer);
        
        if (strcmp(input_buffer->buffer, EXIT_COMMAND) == 0)
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            printf("Command not found: '%s' .\n", input_buffer->buffer);
        }
    }
    return 0;
}
