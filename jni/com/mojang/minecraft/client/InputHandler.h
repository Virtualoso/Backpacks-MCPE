#pragma once

#include <string>
#include <functional>
#include <memory>
class ClientInstance;
class BindingFactory;
class InputMapping;
class InputMappingFactory;
class InputRenderContext;
class InputDeviceMapper;
class ButtonEventData;
class PointerLocationEventData;
class CaretLocationData;
class DirectionEventData;
class VectorEventData;
class RawInputEventData;

enum class InputMode {
    MOUSE = 1, TOUCH = 2, GAMEPAD = 3, MOTION_CONTROLLER = 4
};
enum class DirectionId;
enum class FocusImpact;
enum class RawInputType;
enum class ButtonState;
enum class InputBindingMode;

class InputHandler {

public:

    InputHandler(BindingFactory&, InputMappingFactory&, InputMode);
    ~InputHandler();

    void render(InputRenderContext&) const;

    void _handleInputModeChange(InputMode, ClientInstance&);
    void _handleButtonEvent(ButtonEventData const&, FocusImpact, ClientInstance&);
    void _handlePointerLocationEvent(PointerLocationEventData const&, FocusImpact, ClientInstance&);
    void _handleCaretLocationEvent(CaretLocationData const&, FocusImpact, ClientInstance&);
    void _handleDirectionEvent(DirectionEventData const&, FocusImpact, ClientInstance&);
    void _handleVectorEvent(VectorEventData const&, FocusImpact, ClientInstance&);
    void _handleRawInputEvent(RawInputEventData const&, ClientInstance&);

    InputMode getCurrentInputMode() const;
    void setInputBindingMode(InputBindingMode);
    void setSuspendInput(bool);
    void setDisableInput(bool);

    void registerInputModeHandler(std::function<void (InputMode, ClientInstance&)>);
    void registerButtonDownHandler(std::string, std::function<void (FocusImpact, ClientInstance&)>, bool);
    void registerButtonUpHandler(std::string, std::function<void (FocusImpact, ClientInstance&)>, bool);
    void registerCaretLocationHandler(std::function<void (int, FocusImpact, ClientInstance&)>);
    void registerDirectionHandler(DirectionId, std::function<void (float, float, FocusImpact, ClientInstance&)>);
    void registerVectorHandler(std::function<void (short, float, float, float, FocusImpact, ClientInstance&)>);
    void registerRawInputHandler(std::function<void (int, RawInputType, ButtonState, bool, ClientInstance&)>);
    void registerTextCharHandler(std::function<void (std::string const&, bool, FocusImpact, ClientInstance&)>);
    void registerPointerLocationHandler(std::function<void (PointerLocationEventData const&, FocusImpact, ClientInstance&)>);
    void registerInputDeviceMapper(std::unique_ptr<InputDeviceMapper, std::default_delete<InputDeviceMapper>>);

    void* getInputMappingStackSize() const;
    std::string getCurrentInputMapping() const;
    void pushInputMapping(std::string const&);
    void _handleMappingChange(InputMapping*, InputMapping*);
    void popInputMapping();
    void updateInputMapping(std::string const&);
    void updateInputMappingWithFlush(std::string const&);
    void _flushDownButtons();
    void refreshInputMapping();
    void clearInputDeviceQueues();
    void* getButtonRegistry();
    void* getInputEventQueue();
    void setWindowSize(int, int);
    bool areButtonsDown();

};

