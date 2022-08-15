#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>

int main(int argc, char* argv[]) {
  srand(time(0));
  const int n = atoi(argv[1]);
  int die = atoi(argv[2]);
  int rolls[n];
  int total = 0;
  for(int i = 0; i < n; i++) rolls[i] = rand() % die + 1;
  for(int j = 0; j < n; j++) total = total + rolls[j];
  std::cout << total << std::endl;
  return 0;
}
