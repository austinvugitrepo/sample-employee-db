#include <iostream> // C++
#include <string>
#include <cstring> // C
#include <chrono> // time
#include <thread> // for sleep
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
  int empcounter = 0;

while (loop != "q") {
  std::cout << "\033[2J\033[1;1H"; //clear screen when restarting loop
  std::cout << std::endl;
  std::cout << "\033[1m" << std::string(63, '-') << "\033[0m " << std::endl;
  std::cout << "| \033[1;3;36mWelcome to Sample Employee Database!\033[0m                        |" << std::endl;
  std::cout << "| \033[35mUse this program to enter employee info into the database\033[0m   |" << std::endl;
  std::cout << "| \033[1;32mPress 'q' to quit the program, press any key to continue...\033[0m |" << std::endl;
  std::cout << "\033[1m" << std::string(63, '-') << "\033[0m " << std::endl;
  std::cout << "Employees Registered: " << empcounter << std::endl;
  std::getline(std::cin, loop);
  std::cout << "\033[A\33[2K\r" << std::flush; //clear user input on previous line so user does not see their input
  if (loop.length() == 1){
  } else {
     std::cout << std::string(27, '*') << std::endl;
     std::cerr << "/ \033[31mERROR: NOT A VALID KEY!\033[0m /\n";
     std::cout << std::string(27, '*') << std::endl;
     std::this_thread::sleep_for(std::chrono::milliseconds(550)); //main thread program sleeps .550 seconds
     continue;
  }
  if(loop == "q"){
    std::cout << "Exited Sucessfully.\n";
    break;
  } else {
     
     std::cout << "Enter your name: ";
     std::getline(std::cin, *nameptr);
     std::cout << "\033[A\33[2K\r" << std::flush; //clear user input on previous line so user does not see their input
     std::cout << "Enter your employee ID: ";
     std::getline(std::cin, *idptr);
     std::cout << "\033[A\33[2K\r" << std::flush; //clear user input on previous line so user does not see their input
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
    std::this_thread::sleep_for(std::chrono::milliseconds(550)); //main thread program sleeps .550 seconds
    continue;
   }
  //token checker for " "
  if (tokcount == 1){
  } else {
    std::cout << std::string(43, '*') << std::endl;
    std::cout << "/ \033[31mERROR: Could not process ID, try again.\033[0m /\n";
    std::cout << std::string(43, '*') << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(550)); //main thread program sleeps .550 seconds
    continue;
  }
  
  std::cout << "Enter your email: ";
  std::getline(std::cin, *emailptr);
  std::cout << "\033[A\33[2K\r" << std::flush; //clear user input on previous line so user does not see their input
  std::cout << "Enter your year of birth: ";
  std::getline(std::cin, *yearptr);
  std::cout << "\033[A\33[2K\r" << std::flush; //clear user input on previous line so user does not see their input
  //4 digit checker begins here
  if (yearptr->length() == 4){
  } else {
    std::cout << std::string(48, '*') << std::endl;
    std::cerr << "/ \033[31mERROR: NOT A VALID 4 DIGIT NUMBER, try again.\033[0m/\n";
    std::cout << std::string(48, '*') << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(550)); //main thread program sleeps .550 seconds
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
    std::this_thread::sleep_for(std::chrono::milliseconds(550)); //main thread program sleeps .550 seconds
    continue;
  }
    
    empcounter++;

   }
 }
  return 0;
}
