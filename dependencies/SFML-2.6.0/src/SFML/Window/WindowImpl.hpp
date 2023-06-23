////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2023 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_WINDOWIMPL_HPP
#define SFML_WINDOWIMPL_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Config.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/CursorImpl.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/JoystickImpl.hpp>
#include <SFML/Window/Sensor.hpp>
#include <SFML/Window/SensorImpl.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowHandle.hpp>
#include <SFML/Window/Window.hpp>
#include <queue>
#include <set>

namespace sf
{
class WindowListener;

namespace priv
{
////////////////////////////////////////////////////////////
/// \brief Abstract base class for OS-specific Window_ implementation
///
////////////////////////////////////////////////////////////
class WindowImpl : NonCopyable
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Create a new Window_ depending on the current OS
    ///
    /// \param mode  Video mode to use
    /// \param title Title of the Window_
    /// \param style Window style
    /// \param settings Additional settings for the underlying OpenGL context
    ///
    /// \return Pointer to the created Window_ (don't forget to delete it)
    ///
    ////////////////////////////////////////////////////////////
    static WindowImpl* create(VideoMode mode, const String& title, Uint32 style, const ContextSettings& settings);

    ////////////////////////////////////////////////////////////
    /// \brief Create a new Window_ depending on to the current OS
    ///
    /// \param handle Platform-specific handle of the control
    ///
    /// \return Pointer to the created Window_ (don't forget to delete it)
    ///
    ////////////////////////////////////////////////////////////
    static WindowImpl* create(WindowHandle handle);

public:

    ////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    ////////////////////////////////////////////////////////////
    virtual ~WindowImpl();

    ////////////////////////////////////////////////////////////
    /// \brief Change the joystick threshold, i.e. the value below which
    ///        no move event will be generated
    ///
    /// \param threshold New threshold, in range [0, 100]
    ///
    ////////////////////////////////////////////////////////////
    void setJoystickThreshold(float threshold);

    ////////////////////////////////////////////////////////////
    /// \brief Return the next Window_ event available
    ///
    /// If there's no event available, this function calls the
    /// Window_'s internal event processing function.
    /// The \a block parameter controls the behavior of the function
    /// if no event is available: if it is true then the function
    /// doesn't return until a new event is triggered; otherwise it
    /// returns false to indicate that no event is available.
    ///
    /// \param event Event to be returned
    /// \param block Use true to block the thread until an event arrives
    ///
    ////////////////////////////////////////////////////////////
    bool popEvent(Event& event, bool block);

    ////////////////////////////////////////////////////////////
    /// \brief Get the OS-specific handle of the Window_
    ///
    /// \return Handle of the Window_
    ///
    ////////////////////////////////////////////////////////////
    virtual WindowHandle getSystemHandle() const = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Get the position of the Window_
    ///
    /// \return Position of the Window_, in pixels
    ///
    ////////////////////////////////////////////////////////////
    virtual Vector2i getPosition() const = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Change the position of the Window_ on screen
    ///
    /// \param position New position of the Window_, in pixels
    ///
    ////////////////////////////////////////////////////////////
    virtual void setPosition(const Vector2i& position) = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Get the client size of the Window_
    ///
    /// \return Size of the Window_, in pixels
    ///
    ////////////////////////////////////////////////////////////
    virtual Vector2u getSize() const = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Change the size of the rendering region of the Window_
    ///
    /// \param size New size, in pixels
    ///
    ////////////////////////////////////////////////////////////
    virtual void setSize(const Vector2u& size) = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Change the title of the Window_
    ///
    /// \param title New title
    ///
    ////////////////////////////////////////////////////////////
    virtual void setTitle(const String& title) = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Change the Window_'s icon
    ///
    /// \param width  Icon's width, in pixels
    /// \param height Icon's height, in pixels
    /// \param pixels Pointer to the pixels in memory, format must be RGBA 32 bits
    ///
    ////////////////////////////////////////////////////////////
    virtual void setIcon(unsigned int width, unsigned int height, const Uint8* pixels) = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Show or hide the Window_
    ///
    /// \param visible True to show, false to hide
    ///
    ////////////////////////////////////////////////////////////
    virtual void setVisible(bool visible) = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Show or hide the mouse cursor
    ///
    /// \param visible True to show, false to hide
    ///
    ////////////////////////////////////////////////////////////
    virtual void setMouseCursorVisible(bool visible) = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Grab or release the mouse cursor and keeps it from leaving
    ///
    /// \param grabbed True to enable, false to disable
    ///
    ////////////////////////////////////////////////////////////
    virtual void setMouseCursorGrabbed(bool grabbed) = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Set the displayed cursor to a native system cursor
    ///
    /// \param cursor Native system cursor type to display
    ///
    ////////////////////////////////////////////////////////////
    virtual void setMouseCursor(const CursorImpl& cursor) = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Enable or disable automatic key-repeat
    ///
    /// \param enabled True to enable, false to disable
    ///
    ////////////////////////////////////////////////////////////
    virtual void setKeyRepeatEnabled(bool enabled) = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Request the current Window_ to be made the active
    ///        foreground Window_
    ///
    ////////////////////////////////////////////////////////////
    virtual void requestFocus() = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Check whether the Window_ has the input focus
    ///
    /// \return True if Window_ has focus, false otherwise
    ///
    ////////////////////////////////////////////////////////////
    virtual bool hasFocus() const = 0;

    ////////////////////////////////////////////////////////////
    /// \brief Create a Vulkan rendering surface
    ///
    /// \param instance  Vulkan instance
    /// \param surface   Created surface
    /// \param allocator Allocator to use
    ///
    /// \return True if surface creation was successful, false otherwise
    ///
    ////////////////////////////////////////////////////////////
    bool createVulkanSurface(const VkInstance& instance, VkSurfaceKHR& surface, const VkAllocationCallbacks* allocator);

protected:

    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    ////////////////////////////////////////////////////////////
    WindowImpl();

    ////////////////////////////////////////////////////////////
    /// \brief Push a new event into the event queue
    ///
    /// This function is to be used by derived classes, to
    /// notify the SFML Window_ that a new event was triggered
    /// by the system.
    ///
    /// \param event Event to push
    ///
    ////////////////////////////////////////////////////////////
    void pushEvent(const Event& event);

    ////////////////////////////////////////////////////////////
    /// \brief Process incoming events from the operating system
    ///
    ////////////////////////////////////////////////////////////
    virtual void processEvents() = 0;

private:

    ////////////////////////////////////////////////////////////
    /// \brief Read the joysticks state and generate the appropriate events
    ///
    ////////////////////////////////////////////////////////////
    void processJoystickEvents();

    ////////////////////////////////////////////////////////////
    /// \brief Read the sensors state and generate the appropriate events
    ///
    ////////////////////////////////////////////////////////////
    void processSensorEvents();

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    std::queue<Event> m_events;                                              //!< Queue of available events
    JoystickState     m_joystickStates[Joystick::Count];                     //!< Previous state of the joysticks
    Vector3f          m_sensorValue[Sensor::Count];                          //!< Previous value of the sensors
    float             m_joystickThreshold;                                   //!< Joystick threshold (minimum motion for "move" event to be generated)
    float             m_previousAxes[Joystick::Count][Joystick::AxisCount];  //!< Position of each axis last time a move event triggered, in range [-100, 100]
};

} // namespace priv

} // namespace sf


#endif // SFML_WINDOWIMPL_HPP
