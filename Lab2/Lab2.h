#include <vector>

class proc
{
    public:
        int procID;
        int PriorityNumber;
        double ArrivalTime;
        double ServiceTime;
        void Enlist(std::vector<proc*>&);
        void Delist(std::vector<proc*>&);
        void Reset_Priority();
        double Waiting_Time();
        double Time_In_System();
        proc(std::vector<proc*>&);
        ~proc();
    private:
        int QueueSize;
};