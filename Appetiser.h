#pragma once
#include "Item.h"
#include <vector>

class Appetiser : public Item
{
private:
    bool shareable;
    bool twoForOne;
public:
    Appetiser( vector<string> obj );
    ~Appetiser();

    string toString();

    bool getShareable();
    bool gettwoForOne();
    void setShareable(bool S);
    void settwoForOne(bool T);
};

