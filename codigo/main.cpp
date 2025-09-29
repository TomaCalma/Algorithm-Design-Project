#include "optimizer.h"

int main() {
    Optimizer opt("../input/carrinhas.txt",  "../input/encomendas.txt");

    opt.scenario1();
    opt.scenario2();
    opt.scenario3();
}
