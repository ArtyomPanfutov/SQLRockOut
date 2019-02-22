//
//  InputBuffer.cpp
//  SQLRockOut
//
//  Created by Artyom Panfutov on 23/02/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//

#ifndef InputBuffer_cpp
#define InputBuffer_cpp

#include <stdio.h>
#include <stdlib.h>

struct InputBuffer_t
{
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
};
typedef struct InputBuffer_t InputBuffer;

InputBuffer* new_input_buffer()
{
    InputBuffer* input_buffer   = (InputBuffer*)malloc(sizeof(InputBuffer));
    input_buffer->buffer        = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length  = 0;
    
    return input_buffer;
}
#endif /* InputBuffer_cpp */
