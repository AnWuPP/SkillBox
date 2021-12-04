#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <sstream>

enum flap {
    HOME = 1,
    SOCKETS = 2,
    LIGHT_HOME = 4,
    LIGHT_YARD = 8,
    HEAT_HOME = 16,
    HEAT_WATER = 32,
    AC = 64,
};

bool stob(std::string state) {
    return (state == "on" || state == "yes");
}

int main()
{
    int panel = 0;
    float tempHome, tempYard;
    std::string move, light;
    int times = 0;
    int lightk = 5000;
    std::string buf;
    std::cout << "Hello, Mr. Stark." << std::endl;

    while (times <= 48) {
        int hour = times - (times / 24) * 24;
        std::cout << "Now " << hour << ":00, light: " << lightk << "K. Input [Thome Tyard Myard Light]:" << std::endl;
        std::getline(std::cin, buf);
        std::stringstream pars(buf);
        pars >> tempHome >> tempYard >> move >> light;
        if ((move != "yes" && move != "no")
                || (light != "on" && light != "off")) {
            std::cout << "Wrong input! Please try again..";
            continue;
        }
        bool bMove = stob(move), bLight = stob(light);
        if (!(panel & HEAT_WATER) && tempYard < 0.f) {
            std::cout << "Heating water on." << std::endl;
            panel |= HEAT_WATER;
        }
        else if ((panel & HEAT_WATER) && tempYard > 5.f) {
            std::cout << "Heating water off." << std::endl;
            panel &= ~HEAT_WATER;
        }
        if (((hour > 16 && hour <= 23) || hour < 5)
            && bMove) {
            if (!(panel & LIGHT_YARD)) {
                std::cout << "Light yard on." << std::endl;
                panel |= LIGHT_YARD;
            }
        }
        else if (panel & LIGHT_YARD) {
            std::cout << "Light yard off." << std::endl;
            panel &= ~LIGHT_YARD;
        }
        if (tempHome < -22.f && !(panel & HEAT_HOME)) {
            std::cout << "Heating home on." << std::endl;
            panel |= HEAT_HOME;
        }
        else if ((panel & HEAT_HOME) && tempHome >= 25.f) {
            std::cout << "Heating home off." << std::endl;
            panel &= ~HEAT_HOME;
        }
        if (tempHome >= 30.f && !(panel & AC)) {
            std::cout << "A/C on." << std::endl;
            panel |= AC;
        }
        else if ((panel & AC) && tempHome <= 25.f) {
            std::cout << "A/C off." << std::endl;
            panel &= ~AC;
        }
        if (hour == 0 && lightk != 5000)
        {
            std::cout << "LightK reset." << std::endl;
            lightk = 5000;
        }
        else if (hour >= 16 && hour <= 20 && bLight) {
            int diff = 5000 - 2700;
            int diffHour = 21 - hour;
            lightk = 5000 - diff / diffHour;
            std::cout << "LightK changed to " << lightk << "K." << std::endl;
        }

        times++;
    }

    std::cout << "Simulation ended, MarkHome 1" << std::endl;
}
/*
Есть несколько условий по включению/отключению техники в доме и вне его.

Как только температура снаружи падает ниже 0, надо включить систему обогрева водопровода и отключить её, если температура снаружи поднялась выше 5 градусов.

Если на дворе вечер (время больше 16:00 и меньше 5:00 утра) и снаружи есть какое-то движение, то необходимо включить садовое освещение. Если движения нет или время не вечернее - света снаружи быть не должно.ы

При условии, что температура в помещении упала ниже 22 градусов, должно включится отопление. Как только температура поднимается выше или равно 25-и градусам, отопление автоматически отключается.

Если температура в помещении поднялась до 30 градусов, включается кондиционер. Как только температура становится 25 градусов - кондиционер отключается.

Всё освещение в доме также “умное” и поддерживает настройку цветовой температуры для комфортного нахождения. Каждый день начиная с 16:00 и до 20:00, температура цвета должна плавно изменяться с 5000K до 2700К. Разумеется, это изменение должно происходить в случае, если свет сейчас включен. В 0:00 температура сбрасывается до 5000К.

Все события по отключению и включению устройств должны выводится в консоль явным образом. Если устройство не изменило своего состояния (осталось включенным или выключенным) события генерироваться не должно! Если свет в доме включен, должна отображаться текущая цветовая температура.
*/