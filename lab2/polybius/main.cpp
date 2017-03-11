//
// Created by ubuntu on 3/11/17.
//

int main(int argc, char *argv[])
{
    ifstream input(argv[1]);
    ofstream output(arg[2]);
    int mode= atoi(argv[3]);
    string tmp;

    if(mode)
    {
        while(!input.eof())
        {
            input>>tmp;
            tmp=PolybiusCrypt(tmp);
            output<<tmp<<endl;
        }
    } else {
        while(!input.eof())
        {
            input>>tmp;
            tmp=PolybiusDecrypt(tmp);
            output<<tmp<<endl;
        }
    }
}