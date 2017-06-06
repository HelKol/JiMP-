//
// Created by prenc on 30.05.17.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <utility>
#include <chrono>
namespace profiling{
     template<typename Type>
         auto TimeRecorder(Type type)    {
            static std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

            auto create=(type)();


            std::chrono::duration<double, std::milli> duration = std::chrono::high_resolution_clock::now()-start;


         return std::pair<decltype(create), double>(create, duration.count());
     };


}


#endif //JIMP_EXERCISES_TIMERECORDER_H
