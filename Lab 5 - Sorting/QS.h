#ifndef QS_H_
#define QS_H_

#include "QSInterface.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class QS : public QSInterface
{
public:
    QS();
    virtual ~QS();

    void sort(int left, int right);

    virtual void sortAll();

    virtual int medianOfThree(int left, int right);

    virtual int partition(int left, int right, int pivotIndex);

    virtual string getArray() const;

    virtual int getSize() const;

    virtual bool addToArray(int value);

    virtual bool createArray(int capacity);

    virtual void clear();
};

#endif
