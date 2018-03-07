#include "MenuWorld.h"
#include "engine/components/Button.h"

MenuWorld::MenuWorld() : elapsedTime(0), fixedTickTime(1.f/60.f) {
    m_timingSystem = std::make_shared<TimingSystem>();
    m_graphicsSystem = std::make_shared<GraphicsSystem>();
    m_inputSystem = std::make_shared<InputSystem>();

    addSystem(m_timingSystem);
    addSystem(m_graphicsSystem);
    addSystem(m_inputSystem);


    std::shared_ptr<GameObject> mainButton = std::make_shared<GameObject>("button");
    std::shared_ptr<Button> button = std::make_shared<Button>(mainButton.get(), "default", glm::ivec2(0, 0), glm::ivec2(100, 100));

    std::shared_ptr<TickComponent> tc = button;
    std::shared_ptr<UIComponent> ui = button;
    std::shared_ptr<InputComponent> in = button;

    mainButton->addComponent(tc);
    mainButton->addComponent(ui);
    mainButton->addComponent(in);

    init();
}


void MenuWorld::tick(float seconds) {
    elapsedTime += seconds;

    m_timingSystem->tick(seconds);

    while (elapsedTime >= fixedTickTime) {
        m_timingSystem->fixedTick(fixedTickTime);
        elapsedTime -= fixedTickTime;
    }

    m_timingSystem->lateTick(seconds);
}

void MenuWorld::draw(Graphics *g) {
    m_graphicsSystem->draw(g);
}

void MenuWorld::reset() {

}

void MenuWorld::onMousePressed(QMouseEvent *event) {
    m_inputSystem->onMousePressed(event);
}

void MenuWorld::onMouseReleased(QMouseEvent *event) {
    m_inputSystem->onMouseReleased(event);
}

void MenuWorld::onMouseMoved(glm::vec2 &delta) {
    m_inputSystem->onMouseMoved(delta);
}

void MenuWorld::onMouseWheelMoved(QWheelEvent *event) {
    m_inputSystem->onMouseWheelMoved(event);
}