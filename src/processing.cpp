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
    istringstream iss(line);
    string label;
      iss >> label;

      labels.push_back(label);
  }
  return labels;
}

int main() {
  std::vector<std::vector<double>> X_train; = read_state("./train_states.txt");
  std::vector<std::vector<int>> X_test; = read_state("./test_states.txt");
  std::vector<string> Y_train = read_labels("./train_labels.txt");
  std::vector<string> Y_test = read_labels("./test_labels.txt");

  std::cout << "X_train m: "<< X_train.size() << '\n';
  std::cout << "n: " << X_train[0].size() << '\n';
  std::cout << "Y_train m: "<< Y_train.size() << '\n';

  GaussianNB clf = GNB();

  clf.train(X_train, Y_train);

  std::cout << "X_test m: "<< X_test.size() << '\n';
  std::cout << "n: " << X_test[0].size() << '\n';
  std::cout << "Y_test m: "<< Y_test.size() << '\n';

  int score = 0;

  for (int i = 0; i< X_test.size(); i++) {
    std::vector<double> coordinates = X_test[i];
    string pred = clf.predict(coordinates);
    if (pred.compare(Y_test[i]) == 0) {
      score += 1;
    }
  }

  float accuracy = float(score) / Y_test.size() * 100.0;
  std::cout << "Percent correct: " << accuracy << "%\n";

  return 0;
}
