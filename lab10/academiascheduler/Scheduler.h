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

        void InsertYear(int year){year_= year;};
        void InsertRoomId(int room_id){room_id_= room_id;};
        void InsertTimeSlot(int time_slot){time_slot_= time_slot;};

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
        Schedule OfCourse(int course_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        void InsertScheduleItem(const SchedulingItem &item);
        size_t Size() const;
        SchedulingItem operator[](int id) const;

        std::vector<SchedulingItem> list_;
    };

    class Scheduler{
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std:: map<int, std::vector<int>>
        &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots)=0;
    };

    class NoViableSolutionFound : public std::runtime_error{
    public:
        NoViableSolutionFound(const std::string &__arg);
    };

    class GreedyScheduler : public Scheduler{

        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std:: map<int, std::vector<int>>
        &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override;
    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
