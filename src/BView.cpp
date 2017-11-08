#include "BView.h"

BView::BView( BModel* obj, BControl* control)
    :_model(obj), _control(control)
{
    _isExit = false;
}

BView::~BView()
{

}

void BView::start()
{
    while(!_isExit)
    {
        menu();
        menuOption(userInteraction(NUM_OF_OPTIONS));
    }
    std::cout << "GoodBye";
}

uint32_t BView::userInteraction(uint16_t range)
{
    std::cout << "Option : ";
    uint32_t choice = 0;
    _isOK = false;
    bool outOfRange;
    do
    {
        outOfRange = false;
        std::cin >> choice;
        if(choice < 0 || choice > range)
        {
            std::cout << "out of range, type correct input: " << std::endl;
            std::cin.ignore();
            std::cin.clear();
            outOfRange = true;
        }
        if(std::cin.fail())
        {
            std::cout << "wrong data. Try one more time" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(!outOfRange) // If input is correct
            _isOK = true;
    }
    while(!_isOK);
    return choice;
}

void BView::menuOption(uint32_t option)
{
    std::string name;
    switch(option)
    {
    case 1:
        name = setName();
        _model->queueAddDevice(SWITCH_MACRO, name);
        break;
    case 2:
        name = setName();
        _model->queueAddDevice(ENGINE_MACRO, name);
        break;
    case 3:
        if(_model->getVectorSize() > 0)
        {
            _model->printDeviceName();
            uint16_t num = userInteraction(_model->getVectorSize()-1);
            _model->printDeviceStatistics(num);
            waitUntilKey();
        }
        else
            std::cout << "There are no connected device into a system" << std::endl;
        break;
    case 4:
        _model->saveConfiguration();
        break;
    case 5:
        _model->loadConfiguration();
        break;
    case 6:
        _isExit = true;
        break;
    default:
        std::cout << "Wrong options in BView::menuOption()" << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
    system("cls"); //MK zmieniæ na "clear" pod LINUXEM
}

void BView::menu()
{
    std::cout << "*********************************" << std::endl;
    std::cout << "       1.ADD SWICH  DEVICE" << std::endl;
    std::cout << "       2.ADD ENGINE DEVICE" << std::endl;
    std::cout << "       3.SHOW STATISTICS" << std::endl;
    std::cout << "       4.SAVE CONFIGURATION" << std::endl;
    std::cout << "       5.LOAD CONFIGURATION" << std::endl;
    std::cout << "       6.EXIT" << std::endl;
    std::cout << "*********************************" << std::endl;
}

std::string BView::setName()
{
    _isOK = false;
    std::string bufor;
    std::cout << "Type device name (max 10 characters):";
    while(!_isOK)
    {
        std::cin.ignore();
        std::cin.clear();
        getline(std::cin, bufor);
        if(bufor.size() <= 10)
            _isOK = true;
        else
            std::cout << std::endl << "Name is to long. Try one more time :";
    }
    return bufor;
}

void BView::waitUntilKey()
{
    _isOK = false;
    while(!_isOK)
    {
        std::cout << "Press any sign and confirm enter to exit.." << std::endl;
        char sign;
        std::cin.ignore();
        std::cin.clear();
        sign = getchar();
        if(sign != EOF)
            _isOK = true;
    }
}
