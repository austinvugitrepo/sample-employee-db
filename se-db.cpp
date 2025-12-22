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
  std::string* nameptr = &emp.name;
  std::string* idptr = &emp.id;
  std::string* emailptr = &emp.email;
  std::string* yearptr = &emp.year;

  std::string loop = "i";
   
while (loop != "q") {
  std::cout << std::endl;
  std::cout << "\033[1m" << std::string(63, '-') << "\033[0m " << std::endl;
  std::cout << "| \033[1;3;36mWelcome to Sample Employee Database!\033[0m                        |" << std::endl;
  std::cout << "| \033[35mUse this program to enter employee info into the database\033[0m   |" << std::endl;
  std::cout << "| \033[1;32mPress 'q' to quit the program, press any key to continue...\033[0m |" << std::endl;
  std::cout << "\033[1m" << std::string(63, '-') << "\033[0m " << std::endl;
  std::getline(std::cin, loop);
  if (loop.length() == 1){
  } else {
     std::cout << std::string(27, '*') << std::endl;
     std::cerr << "/ \033[31mERROR: NOT A VALID KEY!\033[0m /\n";
     std::cout << std::string(27, '*') << std::endl;
     continue;
  }
  if(loop == "q"){
    break;
  } else {
     
     std::cout << "Enter your name: ";
     std::getline(std::cin, *nameptr);
     std::cout << "Enter your employee ID: ";
     std::getline(std::cin, *idptr);
    int tokcount = 0;
    //creating token
    char cidcopy[500];
    strncpy(cidcopy, idptr->c_str(), sizeof(cidcopy) - 1);
    cidcopy[sizeof(cidcopy) - 1] = '\0';
    char* token = strtok(cidcopy, " ");
    // count token 
    while (token != NULL) {
     tokcount++;
     token = strtok(NULL, " ");
    }

   //converting id to integer
    try { //try catch combo helps with not getting core dumped
    std::stoi(*idptr);
   } catch (const std::invalid_argument& error){
    //error is variable, .what shows exact error message
    std::cout << std::string(61, '*') << std::endl;
    std::cerr << "/ \033[31mERROR: NOT A VALID NUMBER, try again:\033[0m " << error.what() << " /" << std::endl;
    std::cout << std::string(61, '*') << std::endl;
    continue;
   }
  //token checker for " "
  if (tokcount == 1){
  } else {
    std::cout << std::string(43, '*') << std::endl;
    std::cout << "/ \033[31mERROR: Could not process ID, try again.\033[0m /\n";
    std::cout << std::string(43, '*') << std::endl;
    continue;
  }
  
  std::cout << "Enter your email: ";
  std::getline(std::cin, *emailptr);
  std::cout << "Your email is " << *emailptr << std::endl; //remove later
                                                       
  std::cout << "Enter your year of birth: ";
  std::getline(std::cin, *yearptr);
  //4 digit checker begins here
  if (yearptr->length() == 4){
  } else {
    std::cout << std::string(48, '*') << std::endl;
    std::cerr << "/ \033[31mERROR: NOT A VALID 4 DIGIT NUMBER, try again.\033[0m/\n";
    std::cout << std::string(48, '*') << std::endl;
     continue;
  }
  //converting id to integer
  try { //try catch combo helps with not getting core dumped
    std::stoi(*yearptr);
  } catch (const std::invalid_argument& error){
    //error is variable, .what shows exact error message
    std::cout << std::string(69, '*') << std::endl;
    std::cerr << "/ \033[31mERROR: NOT A VALID 4 DIGIT NUMBER, try again:\033[0m " << error.what() << " /" << std::endl;
    std::cout << std::string(69, '*') << std::endl;
    continue;
  }


   }
 }
  return 0;
}
