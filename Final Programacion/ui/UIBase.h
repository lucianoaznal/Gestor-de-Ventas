#pragma once
#include<iostream>
#include"../include/rlutil.h"



class UIBase{
    public:
        UIBase();
        ~UIBase();
    protected:
        void clearW();
        void pause();
        bool confirm(std::string);
        void message(std::string,int);


};
