#ifndef USER_H
#define USER_H

//max value for correct work program
constexpr int maxValue = 99999;

class User
{
    public:
        //defoult constructor
        User();
        //constructor
        User(std::string  name);
        //copy constructor
        User(const User &cloneUser);       
        void Set_name(std::string name);
        std::string Get_name();
        void Show_name();
        void Show_record_time();
        void Show_step_count();
        void Set_record_time(int time);
        int Get_record_time();
        void Set_step_count(int count);
        int Get_step_count();
        //print user information
        void Print();
       
        ~User();

    private: 
        //user name
        std::string name;
        //initialization user step count
        int step_count = maxValue;
        //initialization user record time
        int record_time = maxValue;

};


#endif //USER_H
