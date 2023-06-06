#include "bn_math.h"
#include "bn_random.h"

#include "cg_util.hpp"

bn::random random_obj = bn::random();

// TODO test for shuffling deck before dealing
template<int Size>
void shuffle(bn::vector<int, Size>& deck)
{
    for (int i = 0; i < Size; ++i)
    {
        int j = bn::max(0, bn::min(Size - 1, bn::abs(random_obj.get_int() % Size)));
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}
