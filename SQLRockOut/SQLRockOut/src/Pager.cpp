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
                  O_CREAT,    // Create file if it does not exist
                  S_IWUSR |     // User write permission
                  S_IRUSR );
    if (fd == - 1)
    {
        printf("Can't open file.\n%d", errno);
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

void* get_page(Pager* pager, uint32_t page_num)
{
    if (page_num > TABLE_MAX_ROWS)
    {
        printf("Fetching page out of bounds. %d", TABLE_MAX_ROWS);
        exit(EXIT_FAILURE);
    }
    
    if (pager->pages[page_num] == NULL)
    {
        // Cache miss. Allocate memory and load from file.
        void* page = malloc(PAGE_SIZE);
        uint32_t num_pages = pager->file_length / PAGE_SIZE;
        
        // We might save a partial page at the end of the file
        if (pager->file_length % PAGE_SIZE)
        {
            num_pages += 1;
        }
        
        if (page_num <= num_pages)
        {
            lseek(pager->file_descriptor, page_num * PAGE_SIZE, SEEK_SET);
            ssize_t bytes_read = read(pager->file_descriptor, page, PAGE_SIZE);
            if (bytes_read == -1)
            {
                printf("Error reading file: %d\n", errno);
                exit(EXIT_FAILURE);
            }
        }
        pager->pages[page_num] = page;
    }
    return pager->pages[page_num];
}


void pager_flush(Pager* pager, uint32_t page_num, uint32_t size)
{
    if (pager->pages[page_num] == NULL)
    {
        printf("Tried to flush null page.\n");
        exit(EXIT_FAILURE);
    }
    
    off_t offset = lseek(pager->file_descriptor, page_num * PAGE_SIZE, SEEK_SET);
    
    if (offset == -1)
    {
        printf("Error seeking: %d\n", errno);
        exit(EXIT_FAILURE);
    }
    
    ssize_t bytes_written = write(pager->file_descriptor, pager->pages[page_num], size);
    
    if (bytes_written == -1)
    {
        printf("Error writing: %d\n", errno);
        exit(EXIT_FAILURE);
    }
}
