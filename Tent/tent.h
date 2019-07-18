#ifndef TENT_H
#define TENT_H

#include <vector>

template <class any> class rangeRing {
    private:
        any range;
        int pTally;
        int rSize;
        std::vector<any> rangeList;
    protected:
    public:
        rangeRing();
        rangeRing(int);
        rangeRing(int, any);
        any get(int) const;
        void add(any);
};


////// Implementation ///////////
template<class any> rangeRing<any>::rangeRing() : range(any()), rangeList(std::vector<any>(0, any()), rSize(0)), pTally(0) {}

template<class any> rangeRing<any>::rangeRing(int rangeSize) : range(any()), rangeList(std::vector<any>(rangeSize, any())), rSize(rangeSize), pTally(rangeSize) {}

template<class any> rangeRing<any>::rangeRing(int rangeSize, any thing) : range(any()), rangeList(std::vector<any>(rangeSize, thing)), rSize(rangeSize), pTally(rangeSize) {}


template<class any> any rangeRing<any>::get(int index) const {
    return rangeList[index];
}

template<class any> void rangeRing<any>::add(any Any) {
    if (pTally == rSize) {
        pTally = 1;
        rangeList[0] = Any;
    } else {
        
        rangeList[pTally++] = Any;
    }
}

#endif //TENT_H
