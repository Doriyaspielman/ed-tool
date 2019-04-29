/* Doriya Spielman 313466625 */
/* Noy Tvili 308426790 */


#include "Editor.h"
#include <string>
#include <iostream>
using namespace std;

Editor::Editor() {
    cout << "Editor constructor- ckeck" << endl;  //after chech- delete
    this->document = {};
    this->userInput = "";
    loop();
}

void Editor::loop(){
    string command;
    bool flag = true;
   
    while (flag){
        cin >> command;
        if (command == "Q"){
           // Quits the editor without saving 
           flag = false;
           break;
        }

        else if (command == "P"){
            // prints the current line (ed maintains a current line) 
            cout << this->document.getString_Line() << endl;    
        }

        else if (command == "n"){
            //prints line number of current line followed by TAB followed by current line 
            cout << this->document.getCurrent_Line() << "\t" << this->document.getString_Line << endl;
        }
        else if (command == "%p"){
           // prints all lines
           for(int i = 0; i < this->document.getNum_Of_Line(); i++){
               cout << this->document.getDocument().at(i) << endl;
           }
        }
        else if (command == מספר){
            //makes line #מספר the current line 
            //צריך לחשוב איך להתייחס לכל המספרים האפשריים
        }
        else if (command == "a"){
            appends new text after the current line  
        }
        else if (command == "i"){
            inserts new text before the current line  
        }
        else if (command == "c"){
            changes the current line for text that follows 
        }
        else if (command == "d"){
            //deletes the current line 
            this->document.deleteCurrent_Line();
        }
        else if (command == "s/old/new/"){
            replaces old string with new in current line (google: C++ split or token) 
        }

        else{
            /text searches forward after current line for the specified text.
            The search wraps to the beginning of the buffer and continues down to the current line, if necessary 
        }
      
    }
}
