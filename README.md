# Flight Planner

This repository was created and maintained by Cullen Watson.

Email: cgwatson@smu.edu

# Functionality

This program determines all possible flight plans for a person wishing to travel between two different cities. It uses iterative backtracking to exhaustively search all possible itineraries between an origin/destination city

There are two input files

* Origination and Destination Data (`flights.txt`) - contains a sequence of city pairs representing 0-stop flights 

<p align="center">
  <img src="https://user-images.githubusercontent.com/78247585/181828281-62ac22c3-ec3d-460f-ae97-e278e8359075.png">
</p>


* Requested Flights (`input/requested.txt`) - contains a list of origin/destination city pairs the user wishes to fly from/to, with a choice of either cost or time optimization


<p align="center">
  <img src="https://user-images.githubusercontent.com/78247585/181828326-090096b9-b774-4b41-9de2-6b9468c9cf8f.png">
</p>


# How to Use

Compile and build using CMake. There are no command-line arguments. 

Output of the top three itineraries for each origin/destination pair will be displayed to the user, sorted by cost or time optimization

<p align="center">
  <img src="https://user-images.githubusercontent.com/78247585/181828747-4dbe4f30-7ddd-4411-b3d3-aa0075727745.png">
</p>

