// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : head(nullptr), operationsCount(0) {}

void Train::addCar(bool isLightOn) {
    if (!head) {
        head = new Car{isLightOn, nullptr, nullptr};
        head->next = head;
        head->prev = head;
    } else {
        Car* lastCar = head->prev;
        Car* newCar = new Car{isLightOn, head, lastCar};
        lastCar->next = newCar;
        head->prev = newCar;
    }
}

int Train::getLength() {
    operationsCount = 0;
    int currentSteps = 1;
    Car* currentCar = head;
    currentCar->light = true;

    while (true) {
        currentCar = currentCar->next;
        operationsCount++;

        if (currentCar->light) {
            currentCar->light = false;
            int stepsBack = currentSteps;

            while (stepsBack--) {
                currentCar = currentCar->prev;
                operationsCount++;
            }

            if (!currentCar->light) {
                return currentSteps;
            }

            currentSteps = 1;
            currentCar->light = true;
        } else {
            currentSteps++;
        }
    }
}

int Train::getOpCount() {
    return operationsCount;
}
