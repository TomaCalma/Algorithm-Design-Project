#include "truck.h"

Truck::Truck(){}
Truck::Truck(int v, int w, int c) : maxVolume(v), maxWeight(w), cost(c) { }

int Truck::getMaxVolume() { return maxVolume; }
int Truck::getMaxWeight() { return maxWeight; }
int Truck::getCost() { return cost; }
int Truck::getVolumeCap() { return volumeCap; }
int Truck::getWeightCap() { return weightCap; }
void Truck::setMaxVolume(int v) { maxVolume = v; volumeCap = v; }
void Truck::setMaxWeight(int w) { maxWeight = w; weightCap = w; }
void Truck::setCost(int c) { cost = c; }
void Truck::addPackage(Package p) { volumeCap-=p.getVolume(); weightCap-=p.getWeight(); }


