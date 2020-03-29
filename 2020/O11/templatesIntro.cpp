#include "templatesIntro.h"

template<typename T>
T maximum(T t1, T t2) {
    return t1 > t2 ? t1 : t2; // This will work, assuming T has its > operator defined
}

template<typename T>
void shuffle(std::vector<T> vec) {
    int size = vec.size();
    int shuffleCount = 1000;

    while(shuffleCount > 0) {
        int id1 = rand() % size;
        int id2 = rand() % size;

        if(id1 != id2) {
            T temp = vec[id1];
            vec[id1] = vec[id2];
            vec[id2] = temp;
            shuffleCount--;
        }
    }
}
