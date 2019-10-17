//header guard
#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <string>
#include <iostream>

class Screen
{
    friend class Window_mgr;
    // or friend void Window_mgr::clear(ScreenIndex);
public:
    typedef std::string::size_type pos;
    //using pos = std::string::size_type; //take the same effect
    // * Constructor
    Screen() = default;
    Screen(pos ht,pos wd,char c) : height(ht),width(wd),contents(ht*wd,c) {}
    char get() const
    {
        return contents[cursor];
    }

    inline char get(pos ht,pos wd) const;
    Screen& move(pos r,pos c);
    Screen& set(char);
    Screen& set(pos,pos,char);
    Screen& display(std::ostream& os)
    {
        do_display(os);
        return *this;
    }
    const Screen& display(std::ostream& os) const
    {
        do_display(os);
        return *this;
    }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    void do_display(std::ostream& os) const
    {
        os<<contents;
    }
};

#endif