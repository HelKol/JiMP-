//
// Created by prenc on 21.05.17.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <stdexcept>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <ostream>

namespace academia{


    class SchedulingItem{
    public:
        SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year);
        int CourseId() const {return course_id_;}
        int TeacherId() const {return teacher_id_;}
        int RoomId() const {return room_id_;}
        int Year() const {return year_;}
        int TimeSlot() const {return time_slot_;}

    private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot_;
        int year_;
    };

    class Schedule{
    public:
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        void InsertScheduleItem(const SchedulingItem &item);
        size_t Size() const;
        SchedulingItem operator[](int id) const;
    private:
        std::vector<SchedulingItem> list_;
    };

    class Scheduler{
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std:: map<int, std::vector<int>>
        &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots);
    };

    class NoViableSolutionFound{
    public:
        NoViableSolutionFound(std::string);
    };

    class GreedyScheduler : public Scheduler{

    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
