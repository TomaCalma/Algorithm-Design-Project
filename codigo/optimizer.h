#pragma once
#include <vector>
#include <string>
#include "package.h"
#include "truck.h"

/**
 * Class that handles the implementation of the algoritms in all scenarios
 */
class Optimizer{
private:
    /**
     * Vector representing all couriers
     */
    vector<Truck> trucks;
    /**
     * Vector with the couriers' information to its' atributes from the input file
     */
    vector<string> truckInfo;
    /**
     * Vector representing all packages
     */
    vector<Package> packages;
    /**
     * Vector with the packages' information to its' atributes from the input file
     */
    vector<string> packageInfo;
public:
    /**
     * Problem optimizer's constructor
     * @param truckDataPath path to the couriers' info input file
     * @param packageDataPath path to the packages' info input file
     */
    Optimizer(string truckDataPath, string packageDataPath);
    /**
     * Method that reads a file returning a vector organized by its lines
     * @param filename path to the input file
     * @return string vector with every line from the input file
     */
    vector<string> readFile(string filename);
    /**
     * Method that associates the line read from the courier input file to a courier, initializing the respective class with the repective atributes
     * @param trucksInfo string vector with every line from the courier's input file
     * @param trucks vector containing all couriers to be initialized
     */
    void initializeTrucks(vector<string> &trucksInfo, vector<Truck> &trucks);
    /**
     * Method that associates the line read from the package input file to a package, initializing the respective class with the repective atributes
     * @param packagesInfo string vector with every line from the package's input file
     * @param packages vector containing all packages to be initialized
     */
    void initializePackages(vector<string> &packagesInfo, vector<Package> &packages);
    /**
     * Method that runs the first scenario, assigning packages to couriers
     */
    void scenario1();
    /**
     * Method that runs the second scenario, maximizing the profit of the company of every delivery
     */
    void scenario2();
    /**
     * Method that runs the third scenario, minimizing the average delivery time in a day
     */
    void scenario3();
};
