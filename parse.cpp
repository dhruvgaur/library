#include<bits/stdc++.h>
using namespace std;
vector< vector<string> > prog;

void print(string temp){cout<<temp<<endl;}

string keywords[]={"define","end","str","print","reverse","toupper","tolower","append_a"};
map<string,vector < vector<string> > > userdefined;

string rev(string temp){
    string ret = "";

    for(int i=temp.length()-1;i>=0;i--)
        ret.push_back(temp[i]);

    return ret;
}

string toupper(string temp){
    for(int i=0;i<temp.length();i++)
        if(isalnum(temp[i]))
            std::toupper(temp[i]);
    return temp;
}


string tolower(string temp){
    for(int i=0;i<temp.length();i++)
        if(isalnum(temp[i]))
            std::tolower(temp[i]);
    return temp;
}

string append(string temp){
    return temp+"a";
}

int main(){


    freopen("input.txt","r",stdin);
    string temp;
    int index = 0;
    while(getline(cin,temp)){
        prog.push_back(vector<string>());

        if(temp.size()==0)continue;
        istringstream iss(temp);
        do
        {
            string sub;
            iss >> sub;

            if(sub.length()!=0 )
                prog[index].push_back(sub);

        } while (iss);

        index++;
    }

    //parse the input

    for(int i=0;i<prog.size();i++){
        if(prog[i].size() ==0 )continue;
        if(prog[i][0] == "define"){

            if(prog[i].size()==1){
                cout<<"ERROR";
                return 0;
            }

            string temp = prog[i][1];

            vector< vector<string> > temp2;
            i++;
            while(prog[i][0] != "end"){

                temp2.push_back(prog[i]);
                i++;
            }
            userdefined[temp] = temp2;
        }else{
            userdefined["main"].push_back(prog[i]);
        }

    }

    //interpret the command

    for(map<string,vector < vector<string> > >::iterator it = userdefined.begin();it != userdefined.end();++it){
        vector< vector<string> > inp = it->second;
        for(int i=0;i<inp.size();i++){
            for(int j=0;j<inp[i].size();j++)
                cout<<inp[i][j]<<" ";
            cout<<endl;
        }
    }


    return 0;}
