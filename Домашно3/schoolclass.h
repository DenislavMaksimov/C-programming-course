#ifndef SCHOOLCLASS_H
#define SCHOOLCLASS_H

#include "person.h"

struct SchoolClass {
    struct Person students[26];
    char classSection;
    int classNumber;
    struct Person classTeacher;
};

#endif
