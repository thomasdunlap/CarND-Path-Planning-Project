#include "gaussiannb.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

std::vector<std::vector<double>> read_state(string path) {
  ifstream state_in(path.c_str(), ifstream::in);
  std::vector<std::vector<double>> states;
  string line;

  while (getline(state_in, line)) {
    istringstream iss(line);
    std::vector<double> x_pos;

    string token;

    while (getline(iss, token, ',')) {
      x_pos.push_back(stod(token));
    }
    states.push_back(x_pos);
  }

  return states;
}

std::vector<string> read_labels(string path){
  ifstream label_in(path.c_str(), ifstream::in);
  std::vector<string> labels;
  string line;

  while(getline(label_in, line)) {
    
  }
}
