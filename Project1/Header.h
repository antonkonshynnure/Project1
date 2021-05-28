#include <iostream>
#pragma once
namespace Project1
{
    using namespace std;
    using namespace System;
    ref class Par_function abstract
    {
    protected:
        double x;
        double y;
    public:
        double get_x()
        {
            return x;
        }
        
        double get_y()
        {
            return y;
        }

        Par_function() {}
    };
    ref class func_1 : public Par_function {
    public:
        func_1() : Par_function() { x = 0; y = 0; }
        func_1(double x1, double y1) { x = x1; y = y1; }
        func_1(double t)
        {
            x = 2 * t;
            y = 5 * t;
        }
        String^ ToString() override
        {
            return "function 1: " + " x = " + Convert::ToString(x) + " y = " + Convert::ToString(y);
        }
    };
    ref class func_2 : public Par_function {
    public:
        func_2() : Par_function() { x = 0; y = 0; }
        func_2(double x1, double y1) { x = x1; y = y1; }
        func_2(double t)
        {
            x = 5 * t;
            y = 7 * t;
        }
        String^ ToString() override
        {
            return "function 2: " + " x = " + Convert::ToString(x) + " y = " + Convert::ToString(y);
        }
    };
    ref class func_3 : public Par_function {
    public:
        func_3() : Par_function() { x = 0; y = 0; }
        func_3(double x1, double y1) { x = x1; y = y1; }
        func_3(double t)
        {
            x = 3 * t;
            y = -3 * t;
        }
        String^ ToString() override
        {
            return "function 3: " + " x = " + Convert::ToString(x) + " y = " + Convert::ToString(y);
        }
    };
    ref class Abrikos {
        ref class Element
        {
        public:
            Par_function^ d;
            Element^ next;
        };
    private:
        Element^ first;
    public:
        Abrikos(){first = nullptr;}
        ~Abrikos() {};
        void Add(Par_function^ p)
        {
            Element^ temp = gcnew Element;
            temp->d = p;
            temp->next = first;
            first = temp;
        }
        String^ ToString() override
        {
            String^ str = "";
            Element^ temp = first;
            while (temp != nullptr)
            {
                str += temp->d->ToString() + "\r\n";
                temp = temp->next;
            }
            return str;
        }
        String^ sum()
        {
            double x=0, y=0;
            Element^ temp = first;
            while (temp != nullptr)
            {
                y += temp->d->get_y();
                x += temp->d->get_x();
                temp = temp->next;
            }
            return "Sum of functions: " + " x = " + Convert::ToString(x) + " y = " + Convert::ToString(y);
        }
    };
}