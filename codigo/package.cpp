#include "package.h"

Package::Package() {}
Package::Package(int v, int w, int r, int d) {}

int Package::getVolume() { return volume; }
int Package::getWeight() { return weight; }
int Package::getReward() { return reward; }
int Package::getDuration() {return duration; }
void Package::setVolume(int v) { volume = v;}
void Package::setWeight(int w) { weight = w;}
void Package::setReward(int r) { reward = r;}
void Package::setDuration(int d) { duration = d;}