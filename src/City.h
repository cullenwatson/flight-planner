#pragma once
#include"List.h"
class DestCity {
private:
    string destCity;
    List<string> carr;
    List<int> cost;
    List<int> time;
    int size;
 
public:
    // constructor to find if destCity exists (if not add to city list)
    DestCity(string d) {
        destCity = d;
        size = 0;
    }
    // used to see if destCities are equal
    bool operator==(const DestCity& d) {
        return destCity == d.destCity;
    }

    // actual constructor
    DestCity(string c, string ca, int co, int t) {
        destCity = c;
        carr.push_back(ca);
        cost.push_back(co);
        time.push_back(t);
        size = 1;
    }
    // add diff carriers
    void addCarr(const string& ca, int c, int t) {
        carr.push_back(ca);
        cost.push_back(c);
        time.push_back(t);
        size++;
    }

    // get destCity
    string getDestCity() {
        return destCity;
    }

    // get list of carriers
    string getCarr() {
        return carr.getIter();
    }
    // get list of cost
    int getCost() {

        return cost.getIter();
    }
    // get list of cost
    int getTime() {
        return time.getIter();
    }
    // adv to next carr
    void advCarr() {
        carr.advIter();
        cost.advIter();
        time.advIter();
    }
    // reset carr
    void resetCarr() {
        carr.resetIter();
        cost.resetIter();
        time.resetIter();
    }
    // check if carr is null
    bool isCarrNull() {
        return time.isIterNull();
    }
    // get num of carriers
    int getSize() {
        return size;
    }
   


};
class City {
private:
    
    string city;
    List<DestCity> destCities;

public:
    // constructor to find if city exists (if not add to adjacencylist)
    City(string c) {
        city = c;
    }
    // copy constructor
    City(const City& copy) {
        city = copy.city;
        destCities = copy.destCities;
    }
    // used to see if cities are equal
    bool operator==(const City& c) {
        return city == c.city;
    }
    // used to see if cities are equal
    bool operator==(const string& c) {
        return city == c;
    }

    // actual constructor
    City(string c, string d, string ca, int co, int t) {
        city = c;
        addDestCity(d, ca, co, t);
    }
    // add destCity
    void addDestCity(string d, string carr, int cost, int time) {
        // see if destCity exists
        if (destCities.find(DestCity(d))) {
            // loop to get iter pointing to destCity
            destCities.resetIter();
            while (!destCities.isIterNull()) {
                // once you get to destcity
                if (destCities.getIter() == d) {
                    DestCity& destCity = destCities.getIter();
                    destCity.addCarr(carr, cost, time);
                }
                // iterate through destCities
                destCities.advIter();
            }
        }
        // add destcity to list if doesn't exist
        else
            destCities.push_back(DestCity(d, carr, cost, time));
        // reset iter after done adding destCities/carriers
        destCities.resetIter();
    }
    // output
    friend ostream& operator<<(ostream& os, City city);

    // FUNCTIONS FOR DESTCITY LIST
    // check if destCities is empty
    bool isEmpty() {
        return destCities.isEmpty();
    }
    // get size of city list
    int getSize() {
        return destCities.getSize();
    }
    // get carr size
    int getCarrSize() {
        return destCities.getIter().getSize();
    }
    // go to next dest
    void advDestIter() {
        destCities.advIter();
    }
    // go to first dest
    void resetDestIter() {
        destCities.resetIter();
    }
    // check if dest iter is null
    bool isDestIterNull() {
        return destCities.isIterNull();
    }
    // get dest city from iter
    DestCity& getDestCityIter() {
        return destCities.getIter();
    }
    // save dest iter
    void saveDestIter() {
        destCities.saveIter();
    }
    // restore dest iter
    void restoreDestIter() {
        destCities.restoreIter();
    }
    // get dest
    string getDest() {
        return getDestCityIter().getDestCity();
    }

    // get city
    string getCity() {
        return city;
    }
    DestCity& getDestCity(string c) {
        // reset iter
        resetDestIter();
        // while not null
        while (!isDestIterNull()) {
            // if dest city matches, return
            if (getDestCityIter() == c)
                return getDestCityIter();
            advDestIter();
        }
        throw "dest ciyt not found";
    }
};
ostream& operator<<(ostream& os, City c)
{
    // output the city;
    os << c.getCity();

    // check if destCities is empty
    if (c.isEmpty())
        return os;
    else {
        // loop through destcities
        while (!c.isDestIterNull()) {

            cout << " -> " << c.getDestCityIter().getDestCity() << " (";
            // loopo through carries
            while (!c.getDestCityIter().isCarrNull()) {
                // output carrier -> city (Destiny [20, 40], 
                os << c.getDestCityIter().getCarr();
                os << "[" << c.getDestCityIter().getCost();
                os << "," << c.getDestCityIter().getTime() << "]";
                // adv carrier
                c.getDestCityIter().advCarr();
                if (!c.getDestCityIter().isCarrNull())
                    os << ",";
            }
            // reset carrier
            c.getDestCityIter().resetCarr();
            os << ")";
            // adv dest
            c.advDestIter();
        }
        // reset dest
        c.resetDestIter();
    }


    return os;
}