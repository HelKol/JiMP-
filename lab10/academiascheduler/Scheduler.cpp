//
// Created by prenc on 21.05.17.
//

#include <iostream>
#include "Scheduler.h"


namespace academia{
    SchedulingItem::SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year) :
            course_id_(course_id), teacher_id_(teacher_id), room_id_(room_id), time_slot_(time_slot), year_(year){};

    SchedulingItem Schedule::operator[](int id) const {
        return list_[id];
    }

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule new_one;
        for(const auto &d : list_){
            if (d.TeacherId()== teacher_id) new_one.InsertScheduleItem(d);
        }
        return new_one;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule new_one;
        for(const auto &d : list_){
            if (d.RoomId()== room_id) new_one.InsertScheduleItem(d);
        }
        return new_one;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule new_one;
        for(const auto &d : list_){
            if (d.Year()== year) new_one.InsertScheduleItem(d);
        }
        return new_one;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> tmp;
        for(int i=0;i<n_time_slots;i++) tmp.push_back(i+1);

//        std::remove_if(tmp.begin(),tmp.end(),[](const int & a){for(auto &d: list_){if(d.TimeSlot()== a) return true;}});
        int z=0;
        for(int j=0; j<tmp.size();j++){
            for(auto &d: list_){
            if(d.TimeSlot()== tmp[j]){
                tmp.erase(tmp.begin()+z);
                z--;
                j--;
                break;
            }}
            z++;
        }
        return tmp;
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        list_.push_back(item);
    }

    size_t Schedule::Size() const {
        return list_.size();
    }

    Schedule Scheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                           const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                           const std::map<int, std::set<int>> &courses_of_year, int n_time_slots){

        

        throw NoViableSolutionFound("NoSolution");
    }

    NoViableSolutionFound::NoViableSolutionFound(std::string) {

    }
}