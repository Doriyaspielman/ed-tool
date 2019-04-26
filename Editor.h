/* Doriya Spielman 313466625 */
/* Noy Tvili 308426790 */

#include "Document.h"
#include <iostream>
using namespace std;

class Editor{
private:
    Document document;
    string userInput;
    int num_of_line; // for this action: "7 makes line #7 the current line"

public:
    Editor();
    void loop();    
}
