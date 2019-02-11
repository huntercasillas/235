#include "QS.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int* userArray;
int pointerSize = 0;
int formalSize = 0;

QS::QS() {
    userArray = NULL;
}
QS::~QS() {
    clear();
}

void swapVal(int one, int two) {
    int temp = userArray[one];
    userArray[one] = userArray[two];
    userArray[two] = temp;
}

void QS::sort(int left, int right) {
    if (right - left == 1) {
        if (userArray[right] > userArray[left]) {
            return;
        }
        else {
            swapVal(right, left);
            return;
        }
    }

    if (right == left|| left < 0 || right > pointerSize - 1 || right < left || left > right) return;
    int pivot = medianOfThree(left, right);
    int newIndex = partition(left, right, pivot);
    sort(left, newIndex - 1);
    sort(newIndex + 1, right);
}

void QS::sortAll() {
    if (pointerSize < 0) return;
    sort(0, pointerSize -1);
}

int QS::medianOfThree(int left, int right) {
    if (pointerSize <= 0) return -1;
    if (left > right || left < 0 || right < left || right > pointerSize - 1 || left == right) return -1;

    int pointerIndex = (left + right) / 2;

    if (userArray[left] > userArray[pointerIndex]) swapVal(left, pointerIndex);
    if (userArray[pointerIndex] > userArray[right]) swapVal(right, pointerIndex);
    if (userArray[left] > userArray[pointerIndex]) swapVal(left, pointerIndex);

    return pointerIndex;
}

int QS::partition(int left, int right, int pivot) {
      if (userArray == NULL) {
        return -1;
      }

      if ((pointerSize < 0) || (formalSize <= 0)) {
        return -1;
      }
      if ((left < 0) || (right < 0)) {
        return -1;
      }
      if ((right > pointerSize - 1)) {
        return -1;
      }
      if (!(left < right)) {
        return -1;
      }
      if ((!(pivot <= right)) || (!(pivot >= left)) ) {
        return -1;
      }

     swapVal(pivot, left);
     pivot = left;
     int up = left + 1;
     int down = right - 1;

     if(userArray[right] < userArray[left] && userArray[up] > userArray[right] && (right - left) > 2) {
       swapVal(right, up);
     }

     do{
       while ((up != right - 1) && !(userArray[left] < userArray[up])) {
         up++;

         if (userArray[up] > userArray[right]) {
           swapVal(up, right);
         }
       }
      while (userArray[left] < userArray[down]) {
         down--;
       }

       if (up < down) {
          swapVal(up, down);
      }
    }while (up < down);

    if(userArray[left] < userArray[right]) {
      swapVal(left, down);
      return down;
    }
    swapVal(left, right);
    return right;
}


string QS::getArray() const{
    if (pointerSize < 0 || formalSize <= 0) {
        return "";
    }
    stringstream ss;
    for (int i = 0; i != pointerSize; i++) {
        ss << userArray[i] << ",";
    }
    string final = ss.str();
    string output = final.substr(0, final.size()-1);
    return output;
}

int QS::getSize() const{
    return pointerSize;
}

bool QS::addToArray(int value) {
    if (userArray == NULL || pointerSize == formalSize) {
      return false;
    }
    userArray[pointerSize] = value;
    pointerSize++;
    return true;
}

bool QS::createArray(int capacity) {
    clear();
    if (capacity < 0) {
        return false;
    } else {
        userArray = new int[capacity];
        pointerSize = 0;
        formalSize = capacity;
        return true;
    }
}

void QS::clear() {
    if (userArray == NULL) {
        return;
    }

    delete [] userArray;
    pointerSize = 0;
    formalSize = 0;
    userArray = NULL;
}
