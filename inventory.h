#ifndef INVENTORY_INCLUDED_H
#define INVENTORY_INCLUDED_H

typedef struct _inventory{
    item stick;
    item wood;
    item stone;
    item berry;
}inventory;

typedef struct _item{
    int amount;
    char name[7];
}item;

#endif