# Flight Planner

This repository was created and maintained by Cullen Watson.

Email: cgwatson@smu.edu

# Functionality

This program determines all possible flight plans for a person wishing to travel between two different cities. It uses iterative backtracking to exhaustively search all possible itineraries between an origin/destination city

There are two input files

* Origination and Destination Data (`flights.txt`) - contains a sequence of city pairs representing 0-stop flights 

<p align="center">
  <img src="https://user-images.githubusercontent.com/78247585/181829623-99c0ed43-1764-4c27-a3b4-11b30ee51d35.png">
</p>


* Requested Flights (`input/requested.txt`) - contains a list of origin/destination city pairs the user wishes to fly from/to, with a choice of either cost or time optimization


<p align="center">
  <img src="https://user-images.githubusercontent.com/78247585/181829685-e4c742f9-bb23-4b35-882d-d2142e97b5d5.png">
</p>


# How to Use

Compile and build using CMake. There are no command-line arguments. 

Output of the top three itineraries for each origin/destination pair will be displayed to the user, sorted by cost or time optimization

<p align="center">
  <img src="https://user-images.githubusercontent.com/78247585/181829726-f269f5c5-a89e-4dac-ac81-50d219ccaa7a.png">
</p>

