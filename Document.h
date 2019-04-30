/* Doriya Spielman 313466625 */
/* Noy Tvili 308426790 */

#include <vector>
#include <string>
using namespace std;

class Document {
    private:
        vector<string> document_String ;
        int current_Line;
        
    public:
        Document();
        int getCurrent_Line() const;
        void setCurrent_Line(const int&);
        string getString_Line();
        void deleteCurrent_Line();
        vector<string> getDocument();
        void insertNewLine_Before(const string& std);
        void insertNewLine_After(const string& std);
        int getNum_Of_Line();
        void changeCurrent_Line(const string& newString);
        string lineBy_Index(const int& index);
        /*
        void insertLineByIndex(const int&,const std::string&);
        bool setNewString(const std::string&,const std::string&);
        */
}; 
