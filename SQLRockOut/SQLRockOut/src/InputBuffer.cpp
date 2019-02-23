//
//  InputBuffer.cpp
//  SQLRockOut
//
//  Created by Artyom Panfutov on 23/02/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//

#include "InputBuffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

InputBuffer* new_input_buffer()
{
    InputBuffer* input_buffer   = (InputBuffer*)malloc(sizeof(InputBuffer));
    input_buffer->buffer        = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length  = 0;
    
    return input_buffer;
}
