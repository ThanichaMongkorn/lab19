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

void importDataFromFile(string f,vector<string> &name,vector<int> &score,vector<char> &grade){
    ifstream text( "name_score.txt");
    char format[] ="%[^:]: %d %d %d";

    string line;
    while(getline(text,line)){
    
        char b[100];
        int n1,n2,n3;
        sscanf(line.c_str(),format,b,&n1,&n2,&n3);
        name.push_back(b);
        int sc =n1+n2+n3;
        score.push_back(sc);
        grade.push_back(score2grade(sc));
    }

}

void getCommand(string &com,string &k){
    cout <<"Please input your command: ";
    cin >> com;
    if(toUpperStr(com)=="NAME" || toUpperStr(com)=="GRADE" ){
    cin.ignore();
    getline(cin,k);
    }
}
void searchName( vector<string> names,vector<int> scores,vector<char> grades,string key){
    int count=0;
    cout<<"---------------------------------\n";
    for(unsigned int i=0; i<names.size();i++){
        if(key==toUpperStr(names[i])){
            cout << names[i]<<"'s score = "<<scores[i]<<"\n";
            cout << names[i]<<"'s grade = "<<grades[i]<<"\n";
            count++;
        }
        else if(i==names.size()-1 and count==0){
            cout << "Cannot found.\n";
        }
    }
    cout<<"---------------------------------\n";
}

void searchGrade(vector<string> names,vector<int> scores,vector<char> grades,string key){
    int count=0;
    cout<<"---------------------------------\n";
    for(unsigned int i=0; i<names.size();i++){
        if(*key.c_str()==grades[i]){
            cout << names[i]<<" ("<<scores[i]<<")"<<"\n";
            count++;
        }
        else if(i==names.size()-1 and count==0){
            cout << "Cannot found.\n";
        }
    }
    cout<<"---------------------------------\n";
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