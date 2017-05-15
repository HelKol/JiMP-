    //
// Created by rencpawe on 09.05.17.
//

#include <sstream>
#include <iostream>
#include "Serialization.h"

using namespace academia;
using namespace std;

int main(void){
    stringstream out;
    JsonSerializer serializer{&out};

    Room room {117, "218", Room::Type::COMPUTER_LAB};
    room.Serialize(&serializer);
    cout<<out.str();
}
