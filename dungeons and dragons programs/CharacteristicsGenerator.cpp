#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
// roll 4 dice and add the largest 3
int roll() {
  int num;
  int rolled[4];
  for(int j = 0; j < 4; j++) rolled[j] = rand() % 6 + 1;
  if(rolled[0] <= rolled[1] && rolled[0] <= rolled[2] && rolled[0] <= rolled[3]) return rolled[1] + rolled[2] + rolled[3];
  else if(rolled[1] <= rolled[0] && rolled[1] <= rolled[2] && rolled[1] <= rolled[3]) return rolled[0] + rolled[2] + rolled[3];
  else if(rolled[2] <= rolled[0] && rolled[2] <= rolled[1] && rolled[2] <= rolled[3]) return rolled[1] + rolled[0] + rolled[3];
  else return rolled[0] + rolled[1] + rolled[2];
}
// check to see if stats are balanced
bool check(int stats[], const int max) {
  int c1 = 0;
  int c2 = 0;
  bool c3 = false;
  for(int l = 0; l < max; l++) c1 = c1 + (stats[l] / 2 - 5);
  for(int h = 0; h < max; h++) c2 = c2 + stats[h];
  for(int u = 0; u < max; u++) if(stats[u] >= 14) c3 = true;
  if(c1 != 5 || c2 != 72 || c3 == false) return true;
  else return false;
}
// used to generate stats
void generateStats() {
  int stats[6];
  while(check(stats, 6)) for(int i = 0; i < 6; i++) stats[i] = roll();
  std::cout << "your stats are:";
  for(int k = 0; k < 6; k++) std::cout << " " << stats[k];
  std::cout << std::endl;
}
// generate assigned stats
void assignedStats() {
  int stats[6];
  while(check(stats, 6) || stats[2] < 12) for(int j = 0; j < 6; j++) stats[j] = roll();
  std::cout << "Your assigned stats are: " << std::endl;
  std::cout << "Str: " << stats[0] << std::endl;
  std::cout << "Dex: " << stats[1] << std::endl;
  std::cout << "Con: " << stats[2] << std::endl;
  std::cout << "Int: " << stats[3] << std::endl;
  std::cout << "Wis: " << stats[4] << std::endl;
  std::cout << "Cha: " << stats[5] << std::endl;
}
// generate race and stats with characteristics already in place;
void raceStats() {
  int race, subrace;
  int stats[6];
  std::string charc[6] {"Str: ", "Dex: ", "Con: ", "Int: ", "Wis: ", "Cha: "};
  std::string human;
  while(check(stats, 6) || stats[2] < 12) for(int j = 0; j < 6; j++) stats[j] = roll();
  race = rand() % 100 + 1;
  // Human
  if(race >= 1 && race <= 16) {
    std::cout << "You are human. Are you a varient human (Y/N): ";
    getline(std::cin, human);
    if(human == "Y" || human == "y") {
      std::cout << "You are a varient human" << std::endl;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] + stats[c] % 2 << std::endl;
      std::cout << "You also gain one skill proficiency and one feat" << std::endl;
    }
    else {
      std::cout << "You are a normal human" << std:: endl;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] + 1 << std::endl;
    }
  }
  // Dawrf
  else if(race >= 17 && race <= 30) {
    subrace = rand() % 7;
    if(subrace == 0 || subrace == 1 || subrace == 2) {
      std::cout << "You are a Hill Dwarf" << std::endl;
      stats[2] = stats[2] + 2; stats[4] = stats[4] + 1;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
    else if(subrace == 3 || subrace == 4 || subrace == 5) {
      std::cout << "You are a Mountain Dwarf" << std::endl;
      stats[2] = stats[2] + 2; stats[0] = stats[0] + 2;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
    else {
      std::cout << "You are a Duergar" << std::endl;
      stats[2] = stats[2] + 2; stats[0] = stats[0] + 1;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
  }
  // Elf
  else if(race >= 31 && race <= 46) {
    subrace = rand() % 7;
    stats[1] = stats[1] + 2;
    if(subrace == 0 || subrace == 1) {
      std::cout << "You are a High Elf" << std::endl;
      stats[3] = stats[3] + 1;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
    else if(subrace == 2 || subrace == 3) {
      std::cout << "You are a Wood Elf" << std::endl;
      stats[4] = stats[4] + 1;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
    else if(subrace == 4 || subrace == 5) {
      std::cout << "You are a Eladrin" << std::endl;
      stats[5] = stats[5] + 1;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
    else {
      std::cout << "You are a Drow (Dark Elf)" << std::endl;
      stats[5] = stats[5] + 1;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
  }
  // halfling
  else if(race >= 47 && race <= 60) {
    subrace = rand() % 2;
    stats[1] = stats[1] + 2;
    if(subrace == 0) {
      std::cout << "You are a Lightfoot Halfling" << std::endl;
      stats[5] = stats[5] + 1;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
    else {
      std::cout << "You are a Stout Halfling" << std::endl;
      stats[2] = stats[2] + 1;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
  }
  // Dragonborn
  else if(race >= 61 && race <= 67) {
    subrace = rand() % 10;
    stats[0] = stats[0] + 2; stats[5] = stats[5] + 1;
    if(subrace == 0) std::cout << "You are a Black Dragonborn" << std::endl;
    else if(subrace == 1) std::cout << "You are a Blue Dragonborn" << std::endl;
    else if(subrace == 2) std::cout << "You are a Brass Dragonborn" << std::endl;
    else if(subrace == 3) std::cout << "You are a Bronze Dragonborn" << std::endl;
    else if(subrace == 4) std::cout << "You are a Copper Dragonborn" << std::endl;
    else if(subrace == 5) std::cout << "You are a Gold Dragonborn" << std::endl;
    else if(subrace == 6) std::cout << "You are a Green Dragonborn" << std::endl;
    else if(subrace == 7) std::cout << "You are a Red Dragonborn" << std::endl;
    else if(subrace == 8) std::cout << "You are a Silver Dragonborn" << std::endl;
    else std::cout << "You are a White Dragonborn" << std::endl;
    for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
  }
  // Gnome
  else if(race >= 68 && race <= 79) {
    subrace = rand() % 7;
    stats[3] = stats[3] + 2;
    if(subrace == 0 || subrace == 1 || subrace == 2) {
      stats[1] = stats[1] + 1;
      std::cout << "You are a Forest Gnome" << std::endl;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
    else if(subrace == 3 || subrace == 4 || subrace == 5) {
      stats[2] = stats[2] + 1;
      std::cout << "You are a Rock Gnome" << std::endl;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
    else {
      stats[1] = stats[1] + 1;
      std::cout << "You are a Deep Gnome (Svirfneblin)" << std::endl;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
  }
  // half elf
  else if(race >= 80 && race <= 86) {
    std::cout << "You are a Half-Elf" << std::endl;
    stats[5] = stats[5] + 2;
    if(stats[5] % 2 == 0) for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] + stats[c]%2 << std::endl;
    else {
      for(int c = 0; c < 5; c++) std::cout << charc[c] << stats[c] + stats[c]%2 << std::endl;
      std::cout << charc[5] << stats[5] << std::endl;
      std::cout << "Add one to a stat of your choice besides: ";
      for(int y = 0; y < 5; y++) if(stats[y] % 2 == 1) std::cout << charc[y];
      std::cout << "and Cha" << std::endl;
    }
  }
  // half orc
  else if(race >= 87 && race <= 93) {
    std::cout << "You are a Half-Orc" << std::endl;
    stats[0] = stats[0] + 2;
    stats[2] = stats[2] + 1;
    for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
  }
  // tiefling
  else if(race >= 94 && race <= 100) {
    subrace = rand() % 9;
    if(subrace == 0) {
      std::cout << "You are a Tiefling of Asmodeus" << std::endl;
      stats[5] = stats[5] + 2; stats[3] = stats[3] + 1;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
    else if(subrace == 1) {
      std::cout << "You are a Tiefling of Baalzebul" << std::endl;
      stats[5] = stats[5] + 2; stats[3] = stats[3] + 1;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
    else if(subrace == 2) {
      std::cout << "You are a Tiefling of Dispater" << std::endl;
      stats[5] = stats[5] + 2; stats[1] = stats[1] + 1;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
    else if(subrace == 3) {
      std::cout << "You are a Tiefling of Fierna" << std::endl;
      stats[5] = stats[5] + 2; stats[4] = stats[4] + 1;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
    else if(subrace == 4) {
      std::cout << "You are a Tiefling of Glasya" << std::endl;
      stats[5] = stats[5] + 2; stats[1] = stats[1] + 1;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
    else if(subrace == 5) {
      std::cout << "You are a Tiefling of Levistus" << std::endl;
      stats[5] = stats[5] + 2; stats[2] = stats[2] + 1;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
    else if(subrace == 6) {
      std::cout << "You are a Tiefling of Mammon" << std::endl;
      stats[5] = stats[5] + 2; stats[3] = stats[3] + 1;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
    else if(subrace == 7) {
      std::cout << "You are a Tiefling of Mephistopheles" << std::endl;
      stats[5] = stats[5] + 2; stats[3] = stats[3] + 1;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
    else {
      std::cout << "You are a Tiefling of Zariel" << std::endl;
      stats[5] = stats[5] + 2; stats[0] = stats[0] + 1;
      for(int c = 0; c < 6; c++) std::cout << charc[c] << stats[c] << std::endl;
    }
  }
}

int main() {
  srand(time(0));
  std::string choice;
  std::cout << "A: Generate stats" << std::endl;
  std::cout << "B: Generate and assignee stats" << std::endl;
  std::cout << "C: Generate, assignee, and get race" << std::endl;
  getline(std::cin, choice);
  if(choice == "a" || choice == "A") generateStats();
  else if(choice == "b" || choice == "B") assignedStats();
  else if(choice == "c" || choice == "C") raceStats();
  else std::cout << "Not an answer so have a good day" << std::endl;
  return 0;
}
