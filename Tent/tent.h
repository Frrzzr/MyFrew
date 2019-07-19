#ifndef TENT_H
#define TENT_H

#include <vector>
#include <iostream>
#include <string>

namespace Name {
    template <class any> class rangeRing {
        private:
            int rSize;
            std::vector<any> rangeList;
        protected:
        public:
            rangeRing(const rangeRing&);
            rangeRing &operator=(const rangeRing&);
            any operator[](const int) const;
            rangeRing();
            rangeRing(int);
            rangeRing(int, any);
            any get(int) const;
            void add(any);
    };
}


////// constructor ///////////
template<class any> Name::rangeRing<any>::rangeRing() : rangeList(std::vector<any>(0, any()), rSize(0)) {}

template<class any> Name::rangeRing<any>::rangeRing(int rangeSize) : rSize(rangeSize), rangeList(std::vector<any>(rangeSize, any())) {}


template<class any> Name::rangeRing<any>::rangeRing(int rangeSize, any thing) : rSize(rangeSize), rangeList(std::vector<any>(rangeSize, thing)) {}

template<class any> Name::rangeRing<any>::rangeRing(const rangeRing& rangelist) {
    *this = rangelist;
}

////// constructor ///////////

template<class any> any Name::rangeRing<any>::operator[](const int index) const {
    return get(index-1);
}

template<class any> Name::rangeRing<any> &Name::rangeRing<any>::operator=(const rangeRing<any> &rangelost) {
    return *this = rangelost;
}

////// Implementation ///////////
template<class any> any Name::rangeRing<any>::get(int index) const {
    return rangeList[index];
}

template<class any> void Name::rangeRing<any>::add(any Any) {
    ////  ********   /////////////////////////////
    any anyTemp = rangeList[1];
    rangeList[1] = rangeList[0];
    rangeList[0] = Any;
    
    for (signed int index = 2; index < rSize; index++) {
        if(index == (rSize-1)) { rangeList[index] = anyTemp;
        } else {
            any temp = rangeList[index];
            rangeList[index] = anyTemp;
            anyTemp = temp;
        }
    }
}

#endif //TENT_H
