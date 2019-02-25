//
//  Pager.h
//  SQLRockOut
//
//  Created by Artyom Panfutov on 25/02/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//

#ifndef Pager_h
#define Pager_h
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "Constant.h"
#include "Pager.h"

struct Pager_t
{
    int file_descriptor;
    uint32_t file_length;
    void* pages[TABLE_MAX_PAGES];
};
typedef Pager_t Pager;

/**************************************************************
 *                         PROTOTYPES                         *
 **************************************************************/

Pager* pager_open(const char* filename);
void* get_page(Pager* pager, uint32_t page_num);
void pager_flush(Pager* pager, uint32_t page_num, uint32_t size);
/**************************************************************/

#endif /* Pager_h */
