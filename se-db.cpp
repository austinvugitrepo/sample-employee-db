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
 // count token 
  while (token != NULL) {
     tokcount++;
     token = strtok(NULL, " ");
  }

  int idnumver;
  //converting id to integer
  try { //try catch combo helps with not getting core dumped
     idnumver = std::stoi(id);
  } catch (const std::invalid_argument& error){
    //error is variable, .what shows exact error message
    std::cerr << "Error: NOT A VALID NUMBER, try again: " << error.what() << std::endl;
    return 1;
  }
  //token checker for " "
  if (tokcount == 1){
    std::cout << "Your employee ID is " << idnumver << std::endl; //remove later
  } else {
    std::cout << "Error: Could not process ID, try again.\n";
  }
  
  std::string email;
  std::cout << "Enter your email:\n";
  std::getline(std::cin, email);
  std::cout << "Your email is " << email << std::endl; //remove later
                                                       
  std::string year;
  std::cout << "Enter your year of birth:\n";
  std::getline(std::cin, year);
  //4 digit checker begins here
  if (year.length() == 4){
    std::cout << "4 character response detected\n";
  } else {
     std::cerr << "Error: NOT A VALID 4 DIGIT NUMBER, try again:\n";
     return 1;
  }
  int yearnum;
  //converting id to integer
  try { //try catch combo helps with not getting core dumped
     yearnum = std::stoi(year);
  } catch (const std::invalid_argument& error){
    //error is variable, .what shows exact error message
    std::cerr << "Error: NOT A VALID 4 DIGIT NUMBER, try again: " << error.what() << std::endl;
    return 1;
  }
  std::cout << "Your birth year is " << yearnum << std::endl; //remove later

  
  
  return 0;
}
