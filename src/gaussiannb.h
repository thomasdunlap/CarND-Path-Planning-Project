#ifndef GAUSSIANNB_H
#define GAUSSIANNB_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

class GaussianNB {
  public:
    std::vector<string> directions = {"left", "center", "right"};
    std::vector<std::vector<double>> averages_;
    std::vector<std::vector<double>> sigs_;

    int left = 0;
    int center = 1;
    int right = 2;

    int s = 0;
    int d = 1;
    int s_dot = 2;
    int d_dot = 3;

    GaussianNB();
    virtual ~GaussianNB();

    void training(std::vector<std::vector<double>> data, std::vector<string> direction;)
    std::string predict(std::vector<double> v);
    double gaussian(double x, double mu, double sig);
    double average(std::vector<double> list);
    double sig(std::vector<double> list);
};

#endif
