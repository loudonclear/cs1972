#ifndef INPUT_H
#define INPUT_H

#include <map>
#include <QKeyEvent>

class Input
{
public:
    Input();

    static void onKeyPressed(QKeyEvent *event);
    static void onKeyReleased(QKeyEvent *event);
    static void onMousePressed(QMouseEvent *event);
    static void onMouseReleased(QMouseEvent *event);

    static bool isMouseButtonDown(int mouseButton);
    static bool isKeyDown(int key);

};

#endif // INPUT_H
