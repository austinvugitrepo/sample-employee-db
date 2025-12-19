#include <iostream> // C++
#include <string>
#include <cstring> // C

int main(){

  std::string name;
  std::cout << "Enter your name:\n";
  std::getline(std::cin, name);
  std::cout << "Your name is " << name << std::endl; //remove later
  std::string id;
  std::cout << "Enter your employee ID:\n";
  std::getline(std::cin, id);
  int tokcount = 0;
  //creating token
  char cidcopy[500];
  strncpy(cidcopy, id.c_str(), sizeof(cidcopy) - 1);
  cidcopy[sizeof(cidcopy) - 1] = '\0';
  char* token = strtok(cidcopy, " ");
  
  while (token != NULL) {
     tokcount++;
     token = strtok(NULL, " ");
  }
  
  if (tokcount == 1){
    std::cout << "Your employee ID is " << id << std::endl; //remove later
  } else {
    std::cout << "Error: Could not process ID, try again.\n";
  }
  
  
  return 0;
}
