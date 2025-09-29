#include "optimizer.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

Optimizer::Optimizer(string tInfo, string pInfo) {
    truckInfo = readFile(tInfo);
    packageInfo = readFile(pInfo);
}

vector<string> Optimizer::readFile(string filename) {
    ifstream f;
    string line;
    vector<string> result;

    f.open(filename);
    if (f.is_open()) {
        while (getline(f, line)) {
            result.push_back(line);
        }
        f.close();
    }

    return result;
}
void Optimizer::initializeTrucks(vector<string> &trucksInfo, vector<Truck> &trucks){
    for(int i=1;i<trucksInfo.size();i++) {
        string word = "";
        int t[3]; int j=0;
        for(auto x: trucksInfo.at(i)) {
            if (x == ' ') {
                t[j] = stoi(word);
                word = "";
                j++;
            } else word = word + x;
        }
        t[2] = stoi(word);

        Truck truck;
        truck.setMaxVolume(t[0]);
        truck.setMaxWeight(t[1]);
        truck.setCost(t[2]);

        trucks.push_back(truck);
    }
}
void Optimizer::initializePackages(vector<string> &packagesInfo, vector<Package> &packages){
    for(int i=1; i<packagesInfo.size();i++) {
        string word = "";
        int p[4]; int j=0;
        for(auto x: packagesInfo.at(i)) {
            if (x == ' ') {
                p[j] = stoi(word);
                word = "";
                j++;
            } else word = word + x;
        }
        p[3] = stoi(word);

        Package package;
        package.setVolume(p[0]);
        package.setWeight(p[1]);
        package.setReward(p[2]);
        package.setDuration(p[3]);

        packages.push_back(package);
    }
}

// SCENARIO 1
bool comparePackages(Package p1, Package p2){
    return p1.getVolume()+p1.getWeight() > p2.getVolume()+p2.getWeight();
}
bool compareTrucks(Truck t1, Truck t2){
    return t1.getMaxVolume()+t1.getMaxWeight() > t2.getMaxVolume()+t2.getMaxWeight();
}
int firstFit(vector<Truck> &trucks, vector<Package> &packages){
    int counter = 0;
    int tNum = trucks.size();
    // Try to fit the first bin, if full jump to next
    for(int i = 0; i < packages.size(); i++) {
        int j;
        for (j = 0; j < counter; j++) {
            if (trucks.at(j).getWeightCap() >= packages.at(i).getWeight() &&
                trucks.at(j).getVolumeCap() >= packages.at(i).getVolume()) {
                trucks.at(j).addPackage(packages.at(i));
                //cout << "Carrinha " << j << ":\n  - Peso: " << trucks.at(j).getWeightCap() << "\n  - Volume: " << trucks.at(j).getVolumeCap() << endl;
                //cout << "Encomendas Restantes: " << packages.size() - i << endl;
                break;
            }
        }
        if(j == counter && tNum > 0) {
            trucks.at(counter).addPackage(packages.at(i));
            //cout << "Carrinha " << j << ":\n  - Peso: " << trucks.at(j).getWeightCap() << "\n  - Volume: " << trucks.at(j).getVolumeCap() << endl;
            tNum--;
            counter++;
        }
    }

    return counter;
}
int firstFitDecreasing(vector<Truck> &trucks, vector<Package> &packages) {
    // First Fit Decreasing Algorithm
    // Sort the input sequences placing large items first
    sort(packages.begin(), packages.end(), comparePackages);
    sort(trucks.begin(), trucks.end(), compareTrucks);

    return firstFit(trucks,packages);
}
int assignCouriers(vector<Truck> &trucks, vector<Package> &packages){
    return firstFitDecreasing(trucks,packages);
}

//SCENARIO 2
bool compareReward(Package p1, Package p2) {
    return p1.getReward() > p2.getDuration();
}
bool compareCost(Truck t1, Truck t2) {
    return t1.getCost() > t2.getCost();
}

int maximizeProfit(vector<Package> &packages,  vector<Truck> &trucks){
    sort(packages.begin(), packages.end(), compareReward);
    sort(trucks.begin(), trucks.end(), compareCost);

    int counter = 0; int profit = 0;
    int tNum = trucks.size();
    for(int i = 0; i < packages.size(); i++) {
        int j;
        for (j = 0; j < counter; j++) {
            if (trucks.at(j).getWeightCap() >= packages.at(i).getWeight() &&
                trucks.at(j).getVolumeCap() >= packages.at(i).getVolume()) {
                trucks.at(j).addPackage(packages.at(i));

                profit += packages.at(i).getReward();
                //cout << "Carrinha " << j << ":\n  - Peso: " << trucks.at(j).getWeightCap() << "\n  - Volume: " << trucks.at(j).getVolumeCap() << endl;
                //cout << "Encomendas Restantes: " << packages.size() - i << endl;
                break;
            }
        }
        if(j == counter && tNum > 0) {
            trucks.at(counter).addPackage(packages.at(i));
            profit += packages.at(i).getReward(); profit -= trucks.at(j).getCost();
            //cout << "Carrinha " << j << ":\n  - Peso: " << trucks.at(j).getWeightCap() << "\n  - Volume: " << trucks.at(j).getVolumeCap() << endl;
            tNum--;
            counter++;
        }
    }

    return profit;
}

//SCENARIO 3
bool compareDuration(Package p1, Package p2) {
    return p1.getDuration() < p2.getDuration();
}
int maximizeExpress(vector<Package> &packages){
    sort(packages.begin(), packages.end(), compareDuration);

    int timeleft = 28800;
    int counter = 0;

    for (auto p : packages) {
        timeleft -= p.getDuration();
        counter += 1;


        if (timeleft <= 0) {
            timeleft += p.getDuration();
            counter -= 1;
        }
    }

    //cout << "Encomendas: " << counter << endl;
    return (28800-timeleft)/counter;
}

void Optimizer::scenario1() {
    initializePackages(packageInfo,packages);
    initializeTrucks(truckInfo,trucks);

    cout << "CENARIO 1: " << endl;
    cout << " - Estafetas Utilizados: " << assignCouriers(trucks,packages) << endl;
}

void Optimizer::scenario2() {
    initializePackages(packageInfo,packages);
    initializeTrucks(truckInfo,trucks);

    cout << "CENARIO 2: " << endl;
    cout << " - Lucro: " << maximizeProfit(packages, trucks) << " euros" << endl;
}

void Optimizer::scenario3() {
    initializePackages(packageInfo,packages);
    initializeTrucks(truckInfo,trucks);

    cout << "CENARIO 3: " << endl;
    cout << " - Tempo Medio de Entrega Num Dia: " << maximizeExpress(packages)  << " segundos"<< endl;
}

