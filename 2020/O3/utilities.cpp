#include "headers/utilities.h"

int randomWithLimits(int upper, int lower) {
    return rand() % (upper - lower + 1) + lower;      
    // Modding with the length of the interval ensures 
    // we get a value that will be in the range of the length of the interval.
    // + lower to bring the random value up to the interval's beginning.
    // +1 to include upper in the selected interval
}