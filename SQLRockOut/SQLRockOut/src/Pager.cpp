//
//  Pager.cpp
//  SQLRockOut
//
//  Created by Artyom Panfutov on 25/02/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//

#include "Pager.h"
#include <stdio.h>

Pager* pager_open(const char* filename)
{
    int fd = open(filename,
                  O_RDWR  |     // Read/Write mode
                  O_CREAT |     // Create file if it does not exist
                  S_IWUSR |     // User write permission
                  S_IRUSR );
    if (fd == - 1)
    {
        printf("Can't open file.\n");
        exit(EXIT_FAILURE);
    }
    
    off_t file_length = lseek(fd, 0, SEEK_END);
    
    Pager* pager = (Pager*)malloc(sizeof(Pager));
    pager->file_descriptor = fd;
    pager->file_length     = file_length;
    
    for (uint32_t i = 0; i < TABLE_MAX_PAGES; i++)
    {
        pager->pages[i] = NULL;
    }
    
    return pager;
}
