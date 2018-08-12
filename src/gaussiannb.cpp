#include "gaussiannb.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <math.h>
#include <numeric>
#include <iostream>

using namespace std;


GaussianNB::GaussianNB() {

}

GaussianNB::~GaussianNB() {}

void GaussianNB::training(std::vector<std::vector<double>> data, std::vector<string> labels) {
  std::vector<std::vector<std::vector<double>>> data_s;

  for (int i=0; i < 3; i++) {
    std::vector<std::vector<double>> class_data;
    data_s.push_back(class_data);

    for (int j=0; j<4; j++) {
      std::vector<double> observed;
      data_s[i].push_back(observed);
    }
  }

  for (int i=0; i<data.size(); i++) {
    int class_ = left;
    if (labels[i] == "right") {
      class_ = right;
    } else if (labels[i] == "center") {
      class_ = center;
    }
  }

  data_s[class_][s].push_back(data[i][s]);
  data_s[class_][d].push_back(fmod(data[i][d], 4.0));
  data_s[class_][s_dot].push_back(data[i][s_dot]);
  data_s[class_][d_dot].push_back(data[i][d_dot]);
}
