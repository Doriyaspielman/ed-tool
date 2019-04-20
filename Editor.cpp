/* Doriya Spielman 313466625 */
/* Noy Tvili 308426790 */


#include Editor.h
using namespace std;

void Editor::loop(){
    string command;

    cin >> command;


    if (command == "P"){
        prints the current line (ed maintains a current line) 
    }

    if (command == "n"){
        prints line number of current line followed by TAB followed by current line 
    }
    if (command == "%p"){
        prints all lines 
    }
    if (command == מספר){
        makes line #מספר the current line 
        צריך לחשוב איך להתייחס לכל המספרים האפשריים
    }
    if (command == "a"){
        appends new text after the current line  
    }
    if (command == "i"){
      inserts new text before the current line  
    }
    if (command == "c"){
        changes the current line for text that follows 
    }
    if (command == "d"){
        deletes the current line 
    }
    if (command == "s/old/new/"){
        replaces old string with new in current line (google: C++ split or token) 
    }
    if (command == "Q"){
        Quits the editor without saving 
    }
    else{
        /text searches forward after current line for the specified text.
        The search wraps to the beginning of the buffer and continues down to the current line, if necessary 
    }
      
}
