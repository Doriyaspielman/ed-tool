/* Doriya Spielman 313466625 */
/* Noy Tvili 308426790 */

#include <vector>
using namespace std;

class Editor{
private:
    int num_of_line; // for this action: "7 makes line #7 the current line"
    vector <string> current_Line; //vector of lines (each line = string)

public:
    void loop();    
}
