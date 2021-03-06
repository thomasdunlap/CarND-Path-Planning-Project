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

    data_s[class_][s].push_back(data[i][s]);
    data_s[class_][d].push_back(fmod(data[i][d], 4.0));
    data_s[class_][s_dot].push_back(data[i][s_dot]);
    data_s[class_][d_dot].push_back(data[i][d_dot]);
  }

  std::vector<std::vector<double>> averages_;
  std::vector<std::vector<double>> sigs_;

  for (int i=0; i<3; i++) {
      std::vector<double> row_average;
      std::vector<double> row_sigs;

      for (int j=0; j<4; j++) {
        row_average.push_back(average(data_s[i][j]));
        row_sigs.push_back(sigs(data_s[i][j]));
      }
      averages_.push_back(row_average);
      sigs_.push_back(row_sigs);
  }

  averages_= averages_;
  sigs_ = sigs_;
}

string GaussianNB::predict(std::vector<double> sample) {
  std::vector<double> probs;

  for (int i=0; i<3; i++) {
    double prob = 1;

    for (int j=0; j<4; j++) {
      if (j == 1) {
        sample[j] = fmod(sample[j], 4.0);
      }

      prob *= gaussian(sample[j], averages_[i][j], sigs_[i][j]);
    }

    probs.push_back(prob);
  }

  int best_index = 0;
  double best_prob = probs[best_index];

  for (int i=0; i<3; i++) {
    if (probs[i] > best_prob) {
      best_index = i;
      best_prob = probs[best_index];
    }
  }

  return this->possible_labels[best_index];
}

double GaussianNB::gaussian(double x, double mu, double sig) {
  double norm = 1 / sqrt(2*M_PI * pow(sig, 2));
  return norm * exp(-pow(x - mu, 2) / (2 * pow(sig, 2)));
}

double GaussianNB::average(std::vector<double> list) {
  double sum = std::accumulate(list.begin(), list.end(), 0);
  return sum / ((float)list.size());
}
