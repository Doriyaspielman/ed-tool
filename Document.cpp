/* Doriya Spielman 313466625 */
/* Noy Tvili 308426790 */

#include "Document.h"
#include <iostream>
#include <algorithm>
using namespace std;

Document::Document(){
    this->current_Line = 0;
}

int Document::getCurrent_Line() const{
    return this->current_Line;
}

void Document::setCurrent_Line (const int& index) {
    if(this->document_String.size() >= index)
        this->current_Line = index;
}

string Document::getString_Line() { //get the string line in the document
    if(this->document_String.size() == 0)
        return "";
    if(this->current_Line == 0){   //מארק עשה את התנאי אבל אני חושבת שמיותר
        return this->document_String.at(this->current_Line ); 
    }
    return this->document_String.at(this->current_Line -1); //the #1 line = at(0)
}

void Document::deleteCurrent_Line() {
    if(current_Line == 0) //not sure if we need this
        return;
    this->document_String.erase(this->document_String.begin() + this->current_Line -1);  //not sure about the: "this->document_String.begin()"
    if (this->current_Line > 1) //need to check the if
        this->current_Line--;
}

vector<string> Document::getDocument(){
    return this->document_String;
}

void Document::insertNewLine_Before(const string& std){
    this->document_String.insert(this->document_String.begin()+getCurrent_Line()-1,std);
}

void Document::insertNewLine_After(const string& std){
    this->document_String.insert(this->document_String.begin()+getCurrent_Line(), std);
    this->current_Line +=1;
}

int Document::getNum_Of_Line(){
    return this->document_String.size();
}

void Document::changeCurrent_Line(const string& newString){
    this->document_String[this->current_Line -1] = newString;
}

string Document::lineBy_Index(const int& index){
    return this->document_String[index];
}




