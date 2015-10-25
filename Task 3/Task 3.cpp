#include<iostream>
using namespace std ;
#include <map>
#include <string>
#include <fstream>
#include <streambuf>
#include <direct.h>

#include <windows.h>
#include <string>

bool dirExists(const std::string& dirName_in)
{
  DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
  if (ftyp == INVALID_FILE_ATTRIBUTES)
    return false;

  if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
    return true;

  return false;
}



void install (string curr_dep,string all_dep[][30],int row){
      int col = 1;

      cout<<"Installing "<<curr_dep<<". "<<endl;


      string req_dep[30];
      int num_req_dep =0;

      string dir = "installing_modules/"+curr_dep;
      if(dirExists(dir)){
        cout<<curr_dep<<" is already installed"<<endl;
      }
      else {
          const char *dir2 = dir.c_str();
          mkdir(dir2);
          for(int i =0 ; i < row+1 ; i ++){
            if(all_dep[i][0] == curr_dep){
                if(all_dep[i][1] != ""){
                    cout<<"In order to install "<<curr_dep<<", we need: ";

                    while(all_dep[i][col]!= ""){

                        req_dep[num_req_dep] = all_dep[i][col];
                        ++num_req_dep;
                        cout<<all_dep[i][col]<<" ";
                        ++col;
                    }
                    if(num_req_dep >0)
                        cout<<endl;
                    for(int j=0; j<num_req_dep; j++){
                        install(req_dep[j],all_dep,row);
                    }
                }

            }
            col = 1;
          }
      }
}


int main () {


    ifstream a("all_packages.json");
    ifstream d("dependencies.json");

    string all_packages((istreambuf_iterator<char>(a)),
                istreambuf_iterator<char>());

    string dependencies((istreambuf_iterator<char>(d)),
                 istreambuf_iterator<char>());

    string dep_arr[30];

    bool check = false;
    bool ready_dep = false;
    int num_dep = 0;
    string word;

    for(int i = 0; i< dependencies.length() ; i++){

        if(dependencies[i] == '"'){
            check = !check;

            if(ready_dep && word !=""){
                dep_arr[num_dep] = word;
                ++num_dep;
            }
            if(word == "dependencies"){
                ready_dep = true;
            }
            word = "";
        }
        if(dependencies[i] == '\n' && ready_dep )
           ready_dep = false;

        if(check && dependencies[i] != '"'){
            word += dependencies[i];
        }

    }

    string all_packs[30][30];
    int num_all_packs = 0;

    check = false;

    bool next_pack = true;
    int row = 0,col = 0;
    word = "";


    for(int i = 0; i< all_packages.length() ; i++){
        if(all_packages[i] == '"'){
            check = !check;

            if(word != ""){
                if(next_pack){
                    all_packs[row][col] = word;
                    ++ col;
                }
                else {
                    ++row;
                    col=0;
                    all_packs[row][col] = word;
                    ++col;
                    next_pack = true;

                }
            }
            word = "";
        }
        if(all_packages[i] == ']'){
            next_pack = false;
        }

        if(check && all_packages[i] != '"'){
            word += all_packages[i];
        }
    }

    for (int i = 0; i <num_dep;i++){
        install(dep_arr[i],  all_packs, row );
    }



}
