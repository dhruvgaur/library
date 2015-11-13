#include<bits/stdc++.h>
using namespace std;
vector< vector<string> > prog;

string keywords[]={"define","end","str","print","reverse","toupper","tolower","append_a"};

map<string,vector < vector<string> > > userdefined;

string rev(string temp){
    string ret = "";

    for(int i=temp.length()-1;i>=0;i--)
        ret.push_back(temp[i]);

    return ret;
}

string toupper(string temp){
    for(int i=0;i<temp.length();i++){
        if(isalnum(temp[i]))
            temp[i] = std::toupper(temp[i]);
    }

    return temp;
}


string tolower(string temp){
    for(int i=0;i<temp.length();i++)
        if(isalnum(temp[i]))
            temp[i] = std::tolower(temp[i]);

    return temp;
}

string append(string temp){
    return temp+"a";
}

void execute(string function_name,string &temp){

    if(userdefined.find(function_name)== userdefined.end()){
        cout<<"error";
        exit(0);
    }
    vector< vector<string> > fu = userdefined[function_name];
    string fu_name;
    for(int i=0;i<fu.size();i++){
        stack<string> st;

        for(int j=0;j<fu[i].size();j++){
            if(fu[i][j] == "str")
                st.push(temp);
            else
                st.push(fu[i][j]);
        }

        temp = st.top();

        if(temp[0]=='"' || temp[temp.size()]=='"')
            temp = temp.substr(1,temp.length()-2);

        st.pop();
        while(!st.empty()){
            fu_name = st.top();
            st.pop();

            if(fu_name == "print"){cout<<temp<<endl;}
            else if(fu_name =="reverse"){temp = rev(temp);}
            else if(fu_name == "toupper"){temp = toupper(temp);}
            else if(fu_name == "tolower"){temp = tolower(temp);}
            else if(fu_name == "append_a"){temp = append(temp);}
            else {
                execute(fu_name,temp);
            }
        }

    }
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
    string temp2 = "";

    execute("main",temp2);

    /*for(map<string,vector < vector<string> > >::iterator it = userdefined.begin();it != userdefined.end();++it){
        vector< vector<string> > inp = it->second;
        for(int i=0;i<inp.size();i++){
            for(int j=0;j<inp[i].size();j++)
                cout<<inp[i][j]<<" ";
            cout<<endl;
        }
    }
    */

    return 0;}
