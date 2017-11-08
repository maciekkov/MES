#ifndef BVIEW_H
#define BVIEW_H

#define NUM_OF_OPTIONS 6

#include "IControl.h"
#include <memory>
#include "IView.h"
#include "BModel.h"
#include "BControl.h"
#include <windows.h>

#define SWITCH_MACRO 1
#define ENGINE_MACRO 2

class BView : public IView
{
public:
    BView(BModel* obj, BControl* control);
    virtual ~BView();
    void start()override;
    uint32_t userInteraction(uint16_t range)override;
    void menuOption(uint32_t option)override;
    void menu()override;
    void waitUntilKey();
private:
    std::string setName();
    BControl* _control;
    BModel* _model;
    bool _isOK;
    bool _isExit;

};

#endif // BVIEW_H
