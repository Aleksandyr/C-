#include <iostream>
#include<fstream>
#include<string.h>
#include <sstream>

using namespace std;

string make_output_filename(size_t index) {
   ostringstream ss;
   ss << "part" << index << ".txt";
   return ss.str();
}

bool is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

int main()
{
    int buffSize;
    int fileNameNumber = 1;
    string result;

    cout << "Enter buff: ";
    cin >> buffSize;

    ifstream fileReader("input.txt");
    fileReader.seekg( 0, ios::end );
    size_t lengthOfFile = fileReader.tellg();
    char *content = new char[lengthOfFile];
    fileReader.seekg(0, ios::beg);
    fileReader.read(content, lengthOfFile);

    for(int i = 0; i < lengthOfFile; i += buffSize){
        ofstream fileWriter(make_output_filename(fileNameNumber++).c_str());

        for(int j = i; j < buffSize + i; j++){
            result += content[j];
        }

        fileWriter << result;
        fileWriter.close();
        result = "";
    }

    fileReader.close();

    return 0;
}
