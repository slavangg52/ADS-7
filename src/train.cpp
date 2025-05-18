// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCar(bool light) {
    if (!first) {
        first = new Car{light, nullptr, nullptr};
        first->next = first;
        first->prev = first;
    } else {
        Car* lastCar = first->prev;
        Car* newCar = new Car{light, first, lastCar};
        lastCar->next = newCar;
        first->prev = newCar;
    }
}

int Train::getLength() {
    countOp = 0;
    int steps = 1;
    Car* current = first;
    current->light = true;

    while (true) {
        current = current->next;
        countOp++;

        if (current->light) {
            current->light = false;
            int backSteps = steps;

            while (backSteps--) {
                current = current->prev;
                countOp++;
            }

            if (!current->light) {
                return steps;
            }

            steps = 1;
            current->light = true;
        } else {
            steps++;
        }
    }
}

int Train::getOpCount() {
    return countOp;
}
