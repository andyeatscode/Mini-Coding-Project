#ifndef INVENTORY_INCLUDED_H
#define INVENTORY_INCLUDED_H

#define ITEM_AMOUNT 4
#define STATS_AMOUNT 1
#define MAX_INV_LEN 7
#define MAX_STAT_LEN 7

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