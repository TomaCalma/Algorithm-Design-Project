#pragma once
#include "package.h"
#include <vector>

using namespace std;

/**
 * Class that represent's a courier's truck
 */
class Truck {
private:
    /**
	 * Maximum volume that a courier can carry
	 */
    int maxVolume;
    /**
     * Maximum weight that a courier can carry
     */
    int maxWeight;
    /**
     * Cost of a round trip
     */
    int cost;
    /**
     * Current volume capacity
     */
    int volumeCap;
    /**
     * Current weight capacity
     */
    int weightCap;

public:
    /**
	 * Courier default constructor
	 */
    Truck();
    /**
	 * Courier constructor.
	 * @param v Courier's maximum volume
	 * @param w Courier's maximum weight
	 * @param c Courier's cost
	 */
    Truck(int v, int w, int c);

    /**
	 * Method that returns courier's maximum volume carried
	 * @return maximum volume that a courier can carry
	 */
    int getMaxVolume();
    /**
	 * Method that returns courier's maximum weight carried
	 * @return maximum weight that a courier can carry
	 */
    int getMaxWeight();
    /**
	 * Method that returns the cost of a round trip
	 * @return cost of a round trip
	 */
    int getCost();
    /**
	 * Method that returns current courier's volume capacity
	 * @return current courier's volume capacity
	 */
    int getVolumeCap();
    /**
	 * Method that returns current courier's weight capacity
	 * @return current courier's weight capacity
	 */
    int getWeightCap();
    /**
     * Method that changes the maximum volume carried
     * @param v new maximum volume
     */
    void setMaxVolume(int v);
    /**
     * Method that changes the maximum weight carried
     * @param w new maximum weight carried
     */
    void setMaxWeight(int w);
    /**
     * Method that changes the cost of a round trip
     * @param c new cost of a round trip
     */
    void setCost(int c);
    /**
     * Method that adds a package to the courier decreasing the volume and weight capacity
     * @param p package to be added
     */
    void addPackage(Package p);
};