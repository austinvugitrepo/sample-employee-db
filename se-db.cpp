#include <iostream> // C++
#include <string>
#include <cstring> // C

struct Employee {
  std::string name;
  std::string id;
  std::string email;
  std::string year;
};

int main(){

  struct Employee emp;

  std::cout << "Enter your name:\n";
  std::getline(std::cin, emp.name);
  std::cout << "Your name is " << emp.name << std::endl; //remove later
  std::cout << "Enter your employee ID:\n";
  std::getline(std::cin, emp.id);
  int tokcount = 0;
  //creating token
  char cidcopy[500];
  strncpy(cidcopy, emp.id.c_str(), sizeof(cidcopy) - 1);
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
     idnumver = std::stoi(emp.id);
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
  
  std::cout << "Enter your email:\n";
  std::getline(std::cin, emp.email);
  std::cout << "Your email is " << emp.email << std::endl; //remove later
                                                       
  std::cout << "Enter your year of birth:\n";
  std::getline(std::cin, emp.year);
  //4 digit checker begins here
  if (emp.year.length() == 4){
    std::cout << "4 character response detected\n";
  } else {
     std::cerr << "Error: NOT A VALID 4 DIGIT NUMBER, try again:\n";
     return 1;
  }
  int yearnum;
  //converting id to integer
  try { //try catch combo helps with not getting core dumped
     yearnum = std::stoi(emp.year);
  } catch (const std::invalid_argument& error){
    //error is variable, .what shows exact error message
    std::cerr << "Error: NOT A VALID 4 DIGIT NUMBER, try again: " << error.what() << std::endl;
    return 1;
  }
  std::cout << "Your birth year is " << yearnum << std::endl; //remove later

  
  
  return 0;
}
