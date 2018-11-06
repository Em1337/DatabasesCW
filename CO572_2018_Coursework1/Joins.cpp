#include "Joins.hpp"

void NestedLoopsJoin::open(){
    left->open();
    right->open();
    for (auto rightTuple = right->next(); rightTuple; rightTuple = right->next()) {
        bufferedRightTuples.push_back(rightTuple);
        currentBufferedRightOffset = bufferedRightTuples.size();
    }
};
Tuple NestedLoopsJoin::next() {
    if(currentBufferedRightOffset == bufferedRightTuples.size()) {
        currentBufferedRightOffset = 0;
        currentLeftTuple = left->next();
    }
    if(!bool(currentLeftTuple)){
        return {};
    }
    auto currentRightTuple = bufferedRightTuples[currentBufferedRightOffset++];
    Tuple result(currentLeftTuple.size() + currentRightTuple.size());
    if(currentLeftTuple[leftAttributeID] == currentRightTuple[rightAttributeID]) {
        size_t i;
        for (i = 0; i < currentLeftTuple.size(); i++) {
            result[i] = currentLeftTuple[i];
        }
        for (size_t j = 0; j < currentRightTuple.size(); j++) {
            result[i + j] = currentRightTuple[j];
        }
        return result;
    }
};
void NestedLoopsJoin::close(){
    left->close();
    right->close();
};

void HashJoin::open(){};
Tuple HashJoin::next() { return {}; };
void HashJoin::close(){};

void SortMergeJoin::open(){};
Tuple SortMergeJoin::next() { return {}; };
void SortMergeJoin::close(){};
