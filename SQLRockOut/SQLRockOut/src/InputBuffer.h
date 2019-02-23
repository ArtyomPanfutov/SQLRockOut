//
//  InputBuffer.h
//  SQLRockOut
//
//  Created by Артем on 23/02/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//

#ifndef InputBuffer_h
#define InputBuffer_h

#include <stdio.h>

struct InputBuffer_t
{
    char*   buffer;
    size_t  buffer_length;
    ssize_t input_length;
};
typedef struct InputBuffer_t InputBuffer;

InputBuffer* new_input_buffer();

#endif /* InputBuffer_h */
