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

#ifndef SFML_WINDOWIMPLWIN32_HPP
#define SFML_WINDOWIMPLWIN32_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window/Event.hpp>
#include <SFML/Window/WindowImpl.hpp>
#include <SFML/System/String.hpp>
#include <windows.h>


namespace sf
{
namespace priv
{
////////////////////////////////////////////////////////////
/// \brief Windows implementation of WindowImpl
///
////////////////////////////////////////////////////////////
class WindowImplWin32 : public WindowImpl
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Construct the Window_ implementation from an existing control
    ///
    /// \param handle Platform-specific handle of the control
    ///
    ////////////////////////////////////////////////////////////
    WindowImplWin32(WindowHandle handle);

    ////////////////////////////////////////////////////////////
    /// \brief Create the Window_ implementation
    ///
    /// \param mode  Video mode to use
    /// \param title Title of the Window_
    /// \param style Window style
    /// \param settings Additional settings for the underlying OpenGL context
    ///
    ////////////////////////////////////////////////////////////
    WindowImplWin32(VideoMode mode, const String& title, Uint32 style, const ContextSettings& settings);

    ////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    ////////////////////////////////////////////////////////////
    ~WindowImplWin32();

    ////////////////////////////////////////////////////////////
    /// \brief Get the OS-specific handle of the Window_
    ///
    /// \return Handle of the Window_
    ///
    ////////////////////////////////////////////////////////////
    virtual WindowHandle getSystemHandle() const;

    ////////////////////////////////////////////////////////////
    /// \brief Get the position of the Window_
    ///
    /// \return Position of the Window_, in pixels
    ///
    ////////////////////////////////////////////////////////////
    virtual Vector2i getPosition() const;

    ////////////////////////////////////////////////////////////
    /// \brief Change the position of the Window_ on screen
    ///
    /// \param position New position of the Window_, in pixels
    ///
    ////////////////////////////////////////////////////////////
    virtual void setPosition(const Vector2i& position);

    ////////////////////////////////////////////////////////////
    /// \brief Get the client size of the Window_
    ///
    /// \return Size of the Window_, in pixels
    ///
    ////////////////////////////////////////////////////////////
    virtual Vector2u getSize() const;

    ////////////////////////////////////////////////////////////
    /// \brief Change the size of the rendering region of the Window_
    ///
    /// \param size New size, in pixels
    ///
    ////////////////////////////////////////////////////////////
    virtual void setSize(const Vector2u& size);

    ////////////////////////////////////////////////////////////
    /// \brief Change the title of the Window_
    ///
    /// \param title New title
    ///
    ////////////////////////////////////////////////////////////
    virtual void setTitle(const String& title);

    ////////////////////////////////////////////////////////////
    /// \brief Change the Window_'s icon
    ///
    /// \param width  Icon's width, in pixels
    /// \param height Icon's height, in pixels
    /// \param pixels Pointer to the pixels in memory, format must be RGBA 32 bits
    ///
    ////////////////////////////////////////////////////////////
    virtual void setIcon(unsigned int width, unsigned int height, const Uint8* pixels);

    ////////////////////////////////////////////////////////////
    /// \brief Show or hide the Window_
    ///
    /// \param visible True to show, false to hide
    ///
    ////////////////////////////////////////////////////////////
    virtual void setVisible(bool visible);

    ////////////////////////////////////////////////////////////
    /// \brief Show or hide the mouse cursor
    ///
    /// \param visible True to show, false to hide
    ///
    ////////////////////////////////////////////////////////////
    virtual void setMouseCursorVisible(bool visible);

    ////////////////////////////////////////////////////////////
    /// \brief Grab or release the mouse cursor
    ///
    /// \param grabbed True to enable, false to disable
    ///
    ////////////////////////////////////////////////////////////
    virtual void setMouseCursorGrabbed(bool grabbed);

    ////////////////////////////////////////////////////////////
    /// \brief Set the displayed cursor to a native system cursor
    ///
    /// \param cursor Native system cursor type to display
    ///
    ////////////////////////////////////////////////////////////
    virtual void setMouseCursor(const CursorImpl& cursor);

    ////////////////////////////////////////////////////////////
    /// \brief Enable or disable automatic key-repeat
    ///
    /// \param enabled True to enable, false to disable
    ///
    ////////////////////////////////////////////////////////////
    virtual void setKeyRepeatEnabled(bool enabled);

    ////////////////////////////////////////////////////////////
    /// \brief Request the current Window_ to be made the active
    ///        foreground Window_
    ///
    ////////////////////////////////////////////////////////////
    virtual void requestFocus();

    ////////////////////////////////////////////////////////////
    /// \brief Check whether the Window_ has the input focus
    ///
    /// \return True if Window_ has focus, false otherwise
    ///
    ////////////////////////////////////////////////////////////
    virtual bool hasFocus() const;

protected:

    ////////////////////////////////////////////////////////////
    /// \brief Process incoming events from the operating system
    ///
    ////////////////////////////////////////////////////////////
    virtual void processEvents();

private:

    ////////////////////////////////////////////////////////////
    /// Register the Window_ class
    ///
    ////////////////////////////////////////////////////////////
    void registerWindowClass();

    ////////////////////////////////////////////////////////////
    /// \brief Switch to fullscreen mode
    ///
    /// \param mode Video mode to switch to
    ///
    ////////////////////////////////////////////////////////////
    void switchToFullscreen(const VideoMode& mode);

    ////////////////////////////////////////////////////////////
    /// \brief Free all the graphical resources attached to the Window_
    ///
    ////////////////////////////////////////////////////////////
    void cleanup();

    ////////////////////////////////////////////////////////////
    /// \brief Process a Win32 event
    ///
    /// \param message Message to process
    /// \param wParam  First parameter of the event
    /// \param lParam  Second parameter of the event
    ///
    ////////////////////////////////////////////////////////////
    void processEvent(UINT message, WPARAM wParam, LPARAM lParam);

    ////////////////////////////////////////////////////////////
    /// \brief Enables or disables tracking for the mouse cursor leaving the Window_
    ///
    /// \param track True to enable, false to disable
    ///
    ////////////////////////////////////////////////////////////
    void setTracking(bool track);

    ////////////////////////////////////////////////////////////
    /// \brief Grab or release the mouse cursor
    ///
    /// This is not to be confused with setMouseCursorGrabbed.
    /// Here m_cursorGrabbed is not modified; it is used,
    /// for example, to release the cursor when switching to
    /// another application.
    ///
    /// \param grabbed True to enable, false to disable
    ///
    ////////////////////////////////////////////////////////////
    void grabCursor(bool grabbed);

    ////////////////////////////////////////////////////////////
    /// \brief Convert a Win32 virtual key code to a SFML key code
    ///
    /// \param key   Virtual key code to convert
    /// \param flags Additional flags
    ///
    /// \return SFML key code corresponding to the key
    ///
    ////////////////////////////////////////////////////////////
    static Keyboard::Key virtualKeyCodeToSF(WPARAM key, LPARAM flags);

    ////////////////////////////////////////////////////////////
    /// \brief Function called whenever one of our windows receives a message
    ///
    /// \param handle  Win32 handle of the Window_
    /// \param message Message received
    /// \param wParam  First parameter of the message
    /// \param lParam  Second parameter of the message
    ///
    /// \return True to discard the event after it has been processed
    ///
    ////////////////////////////////////////////////////////////
    static LRESULT CALLBACK globalOnEvent(HWND handle, UINT message, WPARAM wParam, LPARAM lParam);

    ////////////////////////////////////////////////////////////
    /// \brief Convert a Win32 scancode to an sfml scancode
    ///
    /// \param flags input flags
    ///
    /// \return SFML scancode corresponding to the key
    ///
    ////////////////////////////////////////////////////////////
    static Keyboard::Scancode toScancode(WPARAM wParam, LPARAM lParam);

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    HWND     m_handle;           //!< Win32 handle of the Window_
    LONG_PTR m_callback;         //!< Stores the original event callback function of the control
    bool     m_cursorVisible;    //!< Is the cursor visible or hidden?
    HCURSOR  m_lastCursor;       //!< Last cursor used -- this data is not owned by the Window_ and is required to be always valid
    HICON    m_icon;             //!< Custom icon assigned to the Window_
    bool     m_keyRepeatEnabled; //!< Automatic key-repeat state for keydown events
    Vector2u m_lastSize;         //!< The last handled size of the Window_
    bool     m_resizing;         //!< Is the Window_ being resized?
    Uint16   m_surrogate;        //!< First half of the surrogate pair, in case we're receiving a Unicode character in two events
    bool     m_mouseInside;      //!< Mouse is inside the Window_?
    bool     m_fullscreen;       //!< Is the Window_ fullscreen?
    bool     m_cursorGrabbed;    //!< Is the mouse cursor trapped?
};

} // namespace priv

} // namespace sf

#endif // SFML_WINDOWIMPLWIN32_HPP
