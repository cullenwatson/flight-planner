#pragma once

#include"City.h"
class AdjacencyList {
private:
    List<City> listOfCities;
public:
    // list of cities
    AdjacencyList(List<City> l) : listOfCities(l) {}
    // copy constructor
    AdjacencyList(const AdjacencyList& d) {
        listOfCities = d.listOfCities;
    }
    // default constructor
    AdjacencyList() = default;
    // friend function
    friend ostream& operator<<(ostream& os, AdjacencyList a);

    // push back
    void push_back(City& c) {
        listOfCities.push_back(c);
    }
    // get city
    City& getCityIter() {
        return listOfCities.getIter();
    }
    // adv city
    void advCityIter() {
        listOfCities.advIter();
    }
    // reset city
    void resetCityIter() {
        listOfCities.resetIter();
    }
    // check if city iter is null
    bool isCityIterNull() {
        return listOfCities.isIterNull();
    }
    // see if city exists
    bool findCity(string c) {
        City temp(c);
        return listOfCities.find(c);
    }
    City& getCity(string c) {
        return listOfCities.get(City(c));
    }
    List<City>& returnCities(){
        return listOfCities;
    }

};
// output adjacency list
ostream& operator<<(ostream& os, AdjacencyList a) {
    os << "----ADJACENCY LIST----" << endl;
    a.resetCityIter();
    while (!a.isCityIterNull()) {
        os <<a.getCityIter() << endl;
        a.advCityIter();
    }
    a.resetCityIter();

    return os;
}