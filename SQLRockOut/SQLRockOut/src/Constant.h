//
//  Constant.h
//  SQLRockOut
//
//  Created by Artyom Panfutov on 23/02/2019.
//  Copyright © 2019 Artyom Panfutov. All rights reserved.
//

#ifndef Constant_h
#define Constant_h
/* DB */
#define DB_PRINT_PROMPT "SQLRockOut > "

/* Database name */
#define DB_NAME "System.RDB"

// This structures for one hard coded table
// For first developing steps...

const uint32_t COLUMN_USERNAME_SIZE = 32;
const uint32_t COLUMN_EMAIL_SIZE    = 255;

struct Row_t
{
    uint32_t id;
    char     username[COLUMN_USERNAME_SIZE + 1];
    char     email[COLUMN_EMAIL_SIZE + 1];
};
typedef struct Row_t Row;
// For compact representation of a row
#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

const uint32_t ID_SIZE         = size_of_attribute(Row, id);
const uint32_t USERNAME_SIZE   = size_of_attribute(Row, username);
const uint32_t EMAIL_SIZE      = size_of_attribute(Row, email);
const uint32_t ID_OFFSET       = 0;
const uint32_t USERNAME_OFFSET = ID_OFFSET + ID_SIZE;
const uint32_t EMAIL_OFFSET    = USERNAME_OFFSET + USERNAME_SIZE;
const uint32_t ROW_SIZE        = ID_SIZE + USERNAME_SIZE + EMAIL_SIZE;

// Table structure
const uint32_t PAGE_SIZE       = 4096;
const uint32_t TABLE_MAX_PAGES = 100;

#endif /* Constant_h */
