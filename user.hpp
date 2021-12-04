#ifndef USER_H
#define USER_H

class User
{
    public:
        User();
        User(std::string  name);
        void Set_name(std::string name);
        std::string Get_name();
        void Show_name();
        void Show_record_time();
        void Show_step_count();
        void Set_record_time(int time);
        int Get_record_time();
        void Set_step_count(int count);
        int Get_step_count();
        void Print();
        void Copy(const User &cloneUser);
           

        ~User();

    private: 

        std::string name;
        int step_count = 99999;
        int record_time = 99999;

};


#endif //USER_H
