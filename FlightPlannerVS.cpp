#include"AdjacencyList.h"
#include "Stack.h"
#include<fstream>
using namespace std;
using std::cout;
// create list

void outputPathTop3(List<City> list, const int, string, const int);
AdjacencyList createAdjacencyList(string flightData) {
    // create temp var
    int cost, time, iter;
    string city, dest, carr;
    // create list
    AdjacencyList list;
    // read in file
    ifstream read(flightData);
    // check file is open
    if (read.is_open()) {
        // get number of entries
        read >> iter;
        // for each line
        for (int i = 0; i < iter; i++) {
            // store flight data for each line
            read >> city >> dest >> cost >> time >> carr;
            // add cities to list if they don't exist
            if (!list.findCity(city)) {
                City temp(city, dest, carr, cost, time);
                list.push_back(temp);
            }
            // else add the destination
            else {

                list.resetCityIter();
                while (!list.isCityIterNull()) {
                    if (list.getCityIter() == city) {
                        City& temp = list.getCityIter();
                        temp.addDestCity(dest, carr, cost, time);

                    }
                    list.advCityIter();
                }
                list.resetCityIter();

            }
            if (!list.findCity(dest)) {
                City temp(dest, city, carr, cost, time);
                list.push_back(temp);

            }
            // else add the destination
            else {

                list.resetCityIter();
                while (!list.isCityIterNull()) {
                    if (list.getCityIter() == dest) {
                        City& temp = list.getCityIter();
                        temp.addDestCity(city, carr, cost, time);

                    }
                    list.advCityIter();
                }
                list.resetCityIter();
            }
        }
    }
   // cout << list << endl;
    return list;
}
void openFiles(string, string);
void optimizeTime(AdjacencyList, string, string);
void optimizeCost(AdjacencyList, string, string);
int outputPath(List<City>, int c);
int main() {
    openFiles("input.txt", "flights.txt");

    system("pause>0");
    return 0;
}
void openFiles(string flightData, string requiredFlights) {
    AdjacencyList list = createAdjacencyList(flightData);

    ifstream input(requiredFlights);
    // create temp var
    int flights;
    string city, dest, opt;
    if (input.is_open()) {
        input >> flights;
        for (int i = 0; i < flights; i++) {
            input >> city >> dest >> opt;
            if (opt == "T") {
                std::cout << "Flight " << i + 1 << ": " << city << ", " << dest << " (Time)" << endl;
                optimizeTime(list, city, dest);
            }
            if (opt == "C") {
                std::cout << "Flight " << i + 1 << ": " << city << ", " << dest << " (Cost)" << endl;
                optimizeCost(list, city, dest);
            }
                
        }

    }
}
void optimizeCost(AdjacencyList list, string city, string dest) {
    List<City> first;
    List<City> second;
    List<City> third;
    Stack<City> st;

    int count = 0;
    int time1 = 0;
    int time2 = 0;
    int time3 = 0;
    st.push(list.getCity(city));

    while (!st.isEmpty()) {

        // check if top is dest
        if (st.top().getCity() == dest) {
            count++;

            // store path
            Stack<City> temp = st;
            Stack<City> temp2;
            while (!temp.isEmpty()) {
                temp2.push(temp.top());
                temp.pop();
            }
            List<City> path;
            while (!temp2.isEmpty()) {
                City obj = temp2.top();
                path.push_back(obj);
                temp2.pop();
            }
            int pathTime = outputPath(path,2);

            if (count == 1) {
                time1 = pathTime;
                first = path;
            }
            else if (count == 2) {
                time2 = pathTime;
                second = path;
            }
            else if (count == 3) {
                time3 = pathTime;
                third = path;
            }
            else {
                if (pathTime < time3) {
                    if (pathTime < time2) {
                        if (pathTime < time1) {
                            time3 = time2;
                            third = second;
                            time2 = time1;
                            second = first;
                            time1 = pathTime;
                            first = path;
                            goto finished;
                        }
                        time3 = time2;
                        third = second;
                        time2 = pathTime;
                        second = path;
                        goto finished;

                    }
                    time3 = pathTime;
                    third = path;
                }

            }
        finished:

            st.pop();
            continue;
        }
        else {
            // check if destCity connection is null
            if (st.top().isDestIterNull()) {
                st.top().resetDestIter();
                st.pop();
                continue;
            }
            // check if connection is on stack
            Stack<City> temp = st;
            bool onStack = false;
            string currDest = st.top().getDest();
            temp.pop();
            while (!temp.isEmpty()) {
                if (temp.top().getCity() == currDest) {
                    st.top().advDestIter();
                    onStack = true;
                    break;
                }
                temp.pop();
            }
            if (onStack) continue;

            // not on stack so adv iter and push
            st.top().advDestIter();
            st.push(list.getCity(currDest));
        }
    }
    outputPathTop3(first, 1, dest, 2);
    outputPathTop3(second, 2, dest, 2);
    outputPathTop3(third, 3, dest, 2);
    std::cout << endl;
}
void optimizeTime(AdjacencyList list, string city, string dest) {
    
    List<City> first;
    List<City> second;
    List<City> third;
    Stack<City> st;

    int count = 0;
    int time1 = 0;
    int time2 = 0;
    int time3 = 0;
    st.push(list.getCity(city));

    while (!st.isEmpty()) {

        // check if top is dest
        if (st.top().getCity() == dest) {
            count++;

            // store path
            Stack<City> temp = st;
            Stack<City> temp2;
            while (!temp.isEmpty()) {
                temp2.push(temp.top());
                temp.pop();
            }
            List<City> path;
            while (!temp2.isEmpty()) {
                City obj = temp2.top();
                path.push_back(obj);
                temp2.pop();
            }
            int pathTime = outputPath(path,1);

            if (count == 1) {
                time1 = pathTime;
                first = path;
            }
            else if (count == 2) {
                time2 = pathTime;
                second = path;
            }
            else if (count == 3) {
                time3 = pathTime;
                third = path;
            }
            else {
                if (pathTime < time3) {
                    if (pathTime < time2) {
                        if (pathTime < time1) {
                            time3 = time2;
                            third = second;
                            time2 = time1;
                            second = first;
                            time1 = pathTime;
                            first = path;
                            goto finished;
                        }
                        time3 = time2;
                        third = second;
                        time2 = pathTime;
                        second = path;
                        goto finished;

                    }
                    time3 = pathTime;
                    third = path;
                }

            }
        finished:

            st.pop();
            continue;
        }
        else {
            // check if destCity connection is null
            if (st.top().isDestIterNull()) {
                st.top().resetDestIter();
                st.pop();
                continue;
            }
            // check if connection is on stack
            Stack<City> temp = st;
            bool onStack = false;
            string currDest = st.top().getDest();
            temp.pop();
            while (!temp.isEmpty()) {
                if (temp.top().getCity() == currDest) {
                    st.top().advDestIter();
                    onStack = true;
                    break;
                }
                temp.pop();
            }
            if (onStack) continue;

            // not on stack so adv iter and push
            st.top().advDestIter();
            st.push(list.getCity(currDest));
        }
    }
    
    outputPathTop3(first, 1, dest, 1);
    outputPathTop3(second, 2, dest, 1);
    outputPathTop3(third, 3, dest, 1);

    cout << endl;
}
int outputPath(List<City> list, int c) {
    int pathCost=0, pathTime=0;
    while (!list.isIterNull()) {
        // output city
        string city = list.getIter().getCity();
        //cout << city;
        if (list.hasPrev()) {
            DestCity& temp = list.getPrev().getDestCity(city);
            int size = temp.getSize();
          //  cout<<"(";

            
            temp.resetCarr();
            int lowestCost = temp.getCost();
            int lowestTime = temp.getTime();
            for (int i = 0; i < size; i++) {
               // cout << temp.getCarr();
                //cout << "[" << temp.getCost() << "," << temp.getTime() << "]";

                // get lowest time
                int cost = temp.getCost();
                int time = temp.getTime();
                if (cost < lowestCost)
                    lowestCost = cost;
                if (time < lowestTime)
                    lowestTime = time;




                temp.advCarr();
              //  if (size - i == 2)
                  //  cout << ",";
            }
           // cout << ")";
            pathCost += lowestCost;
            pathTime += lowestTime;
        }

        list.advIter();
        // if city has next city
     //   if (!list.isIterNull())
           // cout << " -> ";
    }
   // cout << " ["<<pathCost << ", " << pathTime <<"]"<< endl;
    if(c==1)
        return pathTime;
    if (c == 2)
        return pathCost;
   
  
  
}
void outputPathTop3(List<City> list, const int i, string dest, const int option) {
    cout << "  Itinerary "<<i<<": " << endl << "    ";
    int pathCost = 0, pathTime = 0;
    int count= 0;
    string carrier = "";
    while (!list.isIterNull()) {
        // output city
        string city = list.getIter().getCity();
        if(count==0 || city==dest)
            cout << city;
        else {
                cout << city <<carrier<< endl << "    " << city;
        }
            

        if (list.hasPrev()) {
            DestCity& temp = list.getPrev().getDestCity(city);
            int size = temp.getSize();
           // cout << "(";


            temp.resetCarr();
            int lowestCost = temp.getCost();
            int lowestTime = temp.getTime();
            int num = 0, num2 = 0;
            for (int i = 0; i < size; i++) {
                /*cout << temp.getCarr();
                cout << "[" << temp.getCost() << "," << temp.getTime() << "]";*/

                // get lowest time
                int cost = temp.getCost();
                int time = temp.getTime();
                if (cost < lowestCost) {
                    lowestCost = cost;
                    num2 = i;
                }
                if (time < lowestTime) {
                    lowestTime = time;
                    num = i;
                }
                


                temp.advCarr();
                /*if (size - i == 2)
                    cout << ",";*/
            }
         //   cout << "[" << lowestCost << "," << lowestTime << "]";
           // cout << ")";
            pathCost += lowestCost;
            pathTime += lowestTime;


            temp.resetCarr();
            if (option == 1) {
                for (int i = 0; i < num; i++) {
                    temp.advCarr();
                }
                carrier = temp.getCarr();
                cout << " (" << carrier << ")";
            }
            else if (option == 2) {
                for (int i = 0; i < num2; i++) {
                    temp.advCarr();
                }
                carrier = temp.getCarr();
                cout << " (" << carrier << ")";
            }
            

        }
        list.advIter();
        // if city has next city
        if (!list.isIterNull())
            cout << " -> ";
        count++;
    }
    cout << endl;
    cout << "    Totals for Itinerary "<<i<< ":  Time: " << pathTime << ", "<< " Cost: " << pathCost << endl;



}
