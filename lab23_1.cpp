#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &name,vector<int> &score,vector<char> &grade){
    ifstream source;
    source.open(filename);
    string textline;
    char format[] = "%[^:]: %d %d %d";
    int a,b,c;
    char names[100];
    while(getline(source,textline)){
        sscanf(textline.c_str(),format,names,&a,&b,&c);
        name.push_back(names);
        int sum = a+b+c;
        score.push_back(sum);
        grade.push_back(score2grade(sum));
    }
}

void getCommand(string &command,string &key){
    cout<<"Please input your command: ";
    string text;
    char comm[100],keys[100];
    getline(cin,text);
    if(toUpperStr(text)=="EXIT"){
        command = text;
    }else{
        text.insert(text.size(),",");
        char format_text[] = "%[^ ,] %[^,],";
        sscanf(text.c_str(),format_text,comm,keys);
        command = comm;
        key = keys;
    }
}

void searchName(){

}

void searchGrade(){

}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
