#pragma once

/**
 * Class that represents a package to be delivered by the couriers
 */
class Package {
private:
    /**
     * package's volume
     */
    int volume;
    /**
     * package's weight
     */
    int weight;
    /**
     * package's revenue
     */
    int reward;
    /**
     * average duration of the package's delivery
     */
    int duration;

public:
    /**
     * package's default constructor
     */
    Package();
    /**
     * package's constructor
     * @param v package's volume
     * @param w package's weight
     * @param r package's reward
     * @param d package's delivery duration
     */
    Package(int v, int w, int r, int d);

    /**
	 * Method that returns package's volume
	 * @return package's volume
	 */
    int getVolume();
    /**
	 * Method that returns package's weight
	 * @return package's weight
	 */
    int getWeight();
    /**
	 * Method that returns package's reward
	 * @return package's reward
	 */
    int getReward();
    /**
	 * Method that returns package's delivery duration
	 * @return package's delivery duration
	 */
    int getDuration();
    /**
     * Method that changes the package's volume
     * @param v new package volume
     */
    void setVolume(int v);
    /**
     * Method that changes the package's weight
     * @param w new package weight
     */
    void setWeight(int w);
    /**
     * Method that changes the package's reward
     * @param r new package reward
     */
    void setReward(int r);
    /**
     * Method that changes the package's delivery duration
     * @param d new package delivery duration
     */
    void setDuration(int d);
};
