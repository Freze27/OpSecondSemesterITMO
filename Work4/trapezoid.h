#ifndef LAB4_Trapezoid_H
#define LAB4_Trapezoid_H
#include "interface.h"

class Trapezoid: public Object, public IGeoFig, public CVector2D, public IPhysObject, public IPrintable, public IDialogInitiable, public BaseCObject{
public:
    Trapezoid();
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
    double basis_large;
    double basis_small;
    double side;
    double m;
    CVector2D center;
    char* name = "Trapezoid";
};

#endif
