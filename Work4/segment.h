#ifndef LAB4_SEGMENT_H
#define LAB4_SEGMENT_H
#include "interface.h"
#include <iostream>

class Segment : public Object, public IGeoFig, public CVector2D, public IPhysObject, public IPrintable, public IDialogInitiable, public BaseCObject{
public:
    Segment();
    double square() override;
    double perimeter() override;
    double mass() const override;
    CVector2D position() override;
    bool operator==(const IPhysObject& obj) const override;
    bool operator<(const IPhysObject& obj) const override;
    void draw() override;
    void initFromDialog() override;
    const char* classname() override;
    unsigned int size() override;
private:
    CVector2D start, end;
    double len;
    double m;
    char* name = "Segment";

};

#endif
