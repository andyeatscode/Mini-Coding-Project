#ifndef INVENTORY_INCLUDED_H
#define INVENTORY_INCLUDED_H

#define ITEM_AMOUNT 4
#define STATS_AMOUNT 1
#define MAX_INV_LEN 10
#define MAX_STAT_LEN 10

#define TREE_TOP 79
#define TREE_LOG -70
#define BUSH -99
#define STONE -2

typedef struct _item{
    int amount;
    char name[MAX_INV_LEN];
}item;

typedef struct _stats{
    int amount;
    char name[MAX_STAT_LEN];
    int max_amount;
}stats;

#endif