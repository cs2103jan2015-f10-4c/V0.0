#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <vector>
#include <string>
#include 'storage.h'

class Display{

public:
    Display(void);
    ~Display(void);
    
    void displayAll();
    void displayRequired(vector<Task>);
};
#endif
