/* Doriya Spielman 313466625 */
/* Noy Tvili 308426790 */


#include "Editor.h"
#include <sstream>
#include <cstring>
#include <string.h>
#include <iostream>
using namespace std;

Editor::Editor() {
    this->document = {};
    this->userInput = "";
    loop();
}

void Editor::loop(){
    string command;
    bool flag = true;
   
    while (this->userInput != "Q"){
        
        getline(cin , command);
        this->userInput = command;
        // cin >> command;
        if (command == "Q"){ // Quits the editor without saving 
          flag = false;
          break;
        }

        else if (command == "p"){ // prints the current line (ed maintains a current line) 
            cout << this->document.getString_Line() << endl;    
        }

        else if (command == "n"){ //prints line number of current line followed by TAB followed by current line 
            cout << this->document.getCurrent_Line() << "\t" << this->document.getString_Line() << endl;
        }
        
        else if (command == "%p"){ // prints all lines
           for(int i = 0; i < this->document.getNum_Of_Line(); i++){
               cout << this->document.getDocument().at(i) << endl;
           }
        }
        
        else if (is_number(command)){//its a number - makes line #מספר the current line 
            int cur_line = stoi(command);
            this->document.setCurrent_Line(cur_line);
            cout << this->document.getString_Line()<< endl; //not sure- need to check the print
        }
    
        else if (command == "a"){ //appends new text after the current line  
        //לעשות בדיקה שהסטרינג שונה משאר הפקודות ולבדוק על הנקודה
         string input="";
         while(true){
             getline(cin, input);
             if(input == "."){
                 break;
             }
             this->document.insertNewLine_After(input);
         }
         
        }
        
        else if (command == "i"){ //inserts new text before the current line 
        string input="";
         while(true){
             getline(cin, input);
             if(input == "."){
                 break;
             }
             this->document.insertNewLine_Before(input);
         }
        }
        
        else if (command == "c"){ //changes the current line for text that follows 
            string input;
             while(true){
             getline(cin, input);
             if(input == "."){
                 break;
             }
         
            this->document.changeCurrent_Line(input);
             }
        }
        
        else if (command == "d"){ //deletes the current line 
            this->document.deleteCurrent_Line();
        }
        
        else if (isStringSwichOldNew(command)==1){ //replaces old string with new in current line (google: C++ split or token) 
            string s = command;
            string delimiter = "/";
            vector<string> words;

            size_t pos = 0;
            string token;
            while ((pos = s.find(delimiter)) != string::npos) {
                token = s.substr(0, pos);
                words.push_back(token);
                s.erase(0, pos + delimiter.length());
            }
            words.push_back(s);
            if(words.size() == 4 && (words.at(0) == "s")){
                string cur = this->document.getString_Line();
                pos = cur.find(words.at(1));
                string changedString = cur.substr(0,pos) + words.at(2) + cur.substr(pos + (strlen(words.at(1).c_str()))); // begin to pos + at(2) + begin + sizeAt(2) to end
                this->document.changeCurrent_Line(changedString);
            }
        }

        else{
            //text searches forward after current line for the specified text.
            //The search wraps to the beginning of the buffer and continues down to the current line, if necessary
            string s = command;
            string s_find = s.substr(1, s.length()); //search the word without the "/"
            bool flag = true; // if the word is found  
            int start = (this->document.getCurrent_Line());
            int end = this->document.getNum_Of_Line();
            size_t pos = 0;
            if(start==end){
                flag=true;
            }
            else{
            for (int i=start; i<end; i++ ){
                pos = this->document.lineBy_Index(i).find(s_find);
                if(pos < this->document.lineBy_Index(i).length()){
                    cout << this->document.lineBy_Index(i) << endl;
                    flag = false;
                    this->document.setCurrent_Line(i+1);
                }
            }
            }
            
            if(flag){
                start=0;
                end=this->document.getCurrent_Line();
                for(int i=start; i< end; ++i){
                    pos = this->document.lineBy_Index(i).find(s_find);
                    if(pos < this->document.lineBy_Index(i).length()){
                    cout << this->document.lineBy_Index(i) << endl;
                    this->document.setCurrent_Line(i+1);
                    }
                }
            }

        }
      
    }
}

bool Editor::is_number(const string& s){ //need to check if works
    
    string :: const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)){
        ++it;
    }
    return !s.empty() && it == s.end();
}


int Editor::isStringSwichOldNew(const string& s) {
    string delimiter = "/";
    if(s.length() >= 2){
        if (s.at(0) == 's' && s.at(1) == '/') {
            return 1;
        }
    }
    return -1;
}
