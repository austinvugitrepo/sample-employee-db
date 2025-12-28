#include <iostream> // C++
#include <string>
#include <cstring> // C
#include <chrono> // time
#include <thread> // for sleep
struct Employee {
  std::string name;
  int id;
  std::string email;
  int year;
};

int main(){
  int empcounter = 0;
  int MAX_EMP = 999; // max number of employees
  struct Employee empdata[MAX_EMP]; //array for data collection
  std::string uid; // for emp id
  std::string uyear; // for emp year
  std::string loop = "i";

while (loop != "q") {
  std::cout << "\033[2J\033[1;1H"; //clear screen when restarting loop
  std::cout << std::endl;
  std::cout << "\033[1m" << std::string(63, '-') << "\033[0m " << std::endl;
  std::cout << "| \033[1;3;36mWelcome to Sample Employee Database!\033[0m                        |" << std::endl;
  std::cout << "| \033[35mUse this program to enter employee info into the database\033[0m   |" << std::endl;
  std::cout << "| \033[1;32mPress 'q' to quit the program, press any key to continue...\033[0m |" << std::endl;
  std::cout << "\033[1m" << std::string(63, '-') << "\033[0m " << std::endl;
  std::cout << "Employees Pre-Registered: " << empcounter << std::endl;
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
    if(empcounter == 0) {
    std::cout << "0 Employees Registered.\n";
    std::cout << "Exited Sucessfully.\n";
    } else if (empcounter > 0){
      std::cout << "Attempting to Register "<< empcounter << " Employees..." << std::endl;
      struct Employee* emp = new Employee[empcounter]; // allocating memory for finished array of all preregistered employees
      for(int i = 0; i < empcounter; i++){
        emp[i] = empdata[i];           // moving data collection array to final array
      }
      //bubble sort
      struct Employee tmp; //temporary variable
      for(int i = 0; i < empcounter; i++){   // swap comparison for the array
        for(int j = 0; j < empcounter - 1; j++){  //swap comparison for one loop; changing empcounter to instead empcounter -1 so we dont go out of bounds
             if(emp[j].id > emp[j+1].id){
                  tmp = emp[j];      //a goes to temp (empty)
                  emp[j] = emp[j+1];  // b goes to a (empty)
                  emp[j+1] = tmp;     // temp (a) goes to b(empty)
             }
        }
      }
      std::cout << "Sorted Employees:\n"; // print for-loop debug section
      for(int i = 0; i < empcounter; i++){
        std::cout << "---------------------\n";
        std::cout << emp[i].name << std::endl;
        std::cout << emp[i].id << std::endl;
        std::cout << emp[i].email << std::endl;
        std::cout << emp[i].year << std::endl;
      }
      delete[] emp; // free memory 
      std::cout << "Exited Sucessfully.\n";
    }
    break;
  } else {
     
     std::cout << "Enter your name: ";
     std::getline(std::cin, empdata[empcounter].name);
     std::cout << "\033[A\33[2K\r" << std::flush; //clear user input on previous line so user does not see their input
     std::cout << "Enter your employee ID: ";
     std::getline(std::cin, uid);
     std::cout << "\033[A\33[2K\r" << std::flush; //clear user input on previous line so user does not see their input
     //3 digit checker begins here
     if (uid.length() == 3){
    } else {
    std::cout << std::string(48, '*') << std::endl;
    std::cerr << "/ \033[31mERROR: NOT A VALID 3 DIGIT EMPLOYEE ID, try again.\033[0m/\n";
    std::cout << std::string(48, '*') << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(550)); //main thread program sleeps .550 seconds
    continue;
    }
     
    //creating token
    int tokcount = 0;
    char cidcopy[500];
    strncpy(cidcopy, uid.c_str(), sizeof(cidcopy) - 1);
    cidcopy[sizeof(cidcopy) - 1] = '\0';
    char* token = strtok(cidcopy, " ");
    // count token 
    while (token != NULL) {
     tokcount++;
     token = strtok(NULL, " ");
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
  

   //converting id to integer
    try { //try catch combo helps with not getting core dumped
   empdata[empcounter].id = std::stoi(uid);
   } catch (const std::invalid_argument& error){
    //error is variable, .what shows exact error message
    std::cout << std::string(61, '*') << std::endl;
    std::cerr << "/ \033[31mERROR: NOT A VALID NUMBER, try again:\033[0m " << error.what() << " /" << std::endl;
    std::cout << std::string(61, '*') << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(550)); //main thread program sleeps .550 seconds
    continue;
   }
 
  std::cout << "Enter your email: ";
  std::getline(std::cin, empdata[empcounter].email);
  std::cout << "\033[A\33[2K\r" << std::flush; //clear user input on previous line so user does not see their input
  std::cout << "Enter your year of birth: ";
  std::getline(std::cin, uyear);
  std::cout << "\033[A\33[2K\r" << std::flush; //clear user input on previous line so user does not see their input
  //4 digit checker begins here
  if (uyear.length() == 4){
  } else {
    std::cout << std::string(48, '*') << std::endl;
    std::cerr << "/ \033[31mERROR: NOT A VALID 4 DIGIT NUMBER, try again.\033[0m/\n";
    std::cout << std::string(48, '*') << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(550)); //main thread program sleeps .550 seconds
    continue;
  }

   //creating token
    int ytokcount = 0;
    char ycidcopy[500];
    strncpy(ycidcopy, uyear.c_str(), sizeof(ycidcopy) - 1);
    ycidcopy[sizeof(ycidcopy) - 1] = '\0';
    char* ytoken = strtok(ycidcopy, " ");
    // count token 
    while (ytoken != NULL) {
     ytokcount++;
     ytoken = strtok(NULL, " ");
    }

    //token checker for " "
   if (ytokcount == 1){
   } else {
    std::cout << std::string(43, '*') << std::endl;
    std::cout << "/ \033[31mERROR: Could not process ID, try again.\033[0m /\n";
    std::cout << std::string(43, '*') << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(550)); //main thread program sleeps .550 seconds
    continue;
   }
  
  //converting id to integer
  try { //try catch combo helps with not getting core dumped
   empdata[empcounter].year = std::stoi(uyear);
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
