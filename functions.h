//Used to print the user UI menu.
void printMenu();
//Used to display the clocks
void printClocks(tm* curr_tm);
//This clears the console screen.
void clear();
//This accepts the user choice and contains the logic to modify the clock.
void choiceEntry(tm*& curr_tm, bool& notDone);
