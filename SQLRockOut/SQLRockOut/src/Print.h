//
//  Print.h
//  SQLRockOut
//
//  Created by Artyom Panfutov on 23/02/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//

#ifndef Print_h
#define Print_h
#include "InputBuffer.h"
#include "DevelopTable.h"

void _print_prompt();
void print_row(Row* row);
void read_input(InputBuffer* input_buffer);

#endif /* Print_h */
