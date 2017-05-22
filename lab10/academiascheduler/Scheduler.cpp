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


    Schedule Schedule::OfCourse(int course_id) const {
        Schedule new_one;
        for(const auto &d : list_){
            if (d.CourseId()== course_id) new_one.InsertScheduleItem(d);
        }
        return new_one;
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
        for(int d=0;d<n_time_slots;d++) tmp.push_back(d+1);

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

    void Schedule::InsertScheduleItem(const SchedulingItem &schedulingItem) {
        list_.push_back(schedulingItem);
    }

    size_t Schedule::Size() const {
        return list_.size();
    }

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                           const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                           const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots){
        Schedule output;
        bool is_error;
        bool Unavailable[rooms.size()][n_time_slots]{};
        std::vector<int> free_places;

        for(auto teacher : teacher_courses_assignment) {
            std::vector<int> tmp = teacher.second;
            for(const auto &course : tmp) {
                output.InsertScheduleItem(SchedulingItem(course,teacher.first,0,0,0));
            }
        }

        for(auto &schedulingItem : output.list_) {
            for (auto year : courses_of_year) {
                for (auto course : year.second) {
                    if (schedulingItem.CourseId()== course) schedulingItem.InsertYear(year.first);
                }
            }
        }


        for(auto &d : output.list_){
            free_places.clear();
            std::vector<int> availableCourses = output.OfCourse(d.CourseId()).AvailableTimeSlots(n_time_slots);
            std::vector<int> availableTeachers = output.OfTeacher(d.TeacherId()).AvailableTimeSlots(n_time_slots);
            set_intersection(availableTeachers.begin(), availableTeachers.end(),
                             availableCourses.begin(), availableCourses.end(), back_inserter(free_places));
            is_error=false;
            for(int i= 0;i<rooms.size();++i){
                for(auto time : free_places){
                    if (!Unavailable[i][time] && !is_error){
                        is_error= true;
                        Unavailable[i][time]= true;
                        d.InsertRoomId(rooms[i]);
                        d.InsertTimeSlot(time);
                    }
                }
            }
            if (!is_error)
                throw NoViableSolutionFound{"error"};
        }
        return output;
    }

    NoViableSolutionFound::NoViableSolutionFound(const std::string &__arg) : runtime_error(__arg) {

    }
}