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

#ifndef SFML_RENDERWINDOW_HPP
#define SFML_RENDERWINDOW_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Window/Window.hpp>
#include <string>


namespace sf
{
////////////////////////////////////////////////////////////
/// \brief Window that can serve as a target for 2D drawing
///
////////////////////////////////////////////////////////////
class SFML_GRAPHICS_API RenderWindow : public Window, public RenderTarget
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    /// This constructor doesn't actually create the Window_,
    /// use the other constructors or call create() to do so.
    ///
    ////////////////////////////////////////////////////////////
    RenderWindow();

    ////////////////////////////////////////////////////////////
    /// \brief Construct a new Window_
    ///
    /// This constructor creates the Window_ with the size and pixel
    /// depth defined in \a mode. An optional style can be passed to
    /// customize the look and behavior of the Window_ (borders,
    /// title bar, resizable, closable, ...).
    ///
    /// The fourth parameter is an optional structure specifying
    /// advanced OpenGL context settings such as antialiasing,
    /// depth-buffer bits, etc. You shouldn't care about these
    /// parameters for a regular usage of the graphics module.
    ///
    /// \param mode     Video mode to use (defines the width, height and depth of the rendering area of the Window_)
    /// \param title    Title of the Window_
    /// \param style    %Window style, a bitwise OR combination of sf::Style enumerators
    /// \param settings Additional settings for the underlying OpenGL context
    ///
    ////////////////////////////////////////////////////////////
    RenderWindow(VideoMode mode, const String& title, Uint32 style = Style::Default, const ContextSettings& settings = ContextSettings());

    ////////////////////////////////////////////////////////////
    /// \brief Construct the Window_ from an existing control
    ///
    /// Use this constructor if you want to create an SFML
    /// rendering area into an already existing control.
    ///
    /// The second parameter is an optional structure specifying
    /// advanced OpenGL context settings such as antialiasing,
    /// depth-buffer bits, etc. You shouldn't care about these
    /// parameters for a regular usage of the graphics module.
    ///
    /// \param handle   Platform-specific handle of the control (\a HWND on
    ///                 Windows, \a %Window on Linux/FreeBSD, \a NSWindow on OS X)
    /// \param settings Additional settings for the underlying OpenGL context
    ///
    ////////////////////////////////////////////////////////////
    explicit RenderWindow(WindowHandle handle, const ContextSettings& settings = ContextSettings());

    ////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    /// Closes the Window_ and frees all the resources attached to it.
    ///
    ////////////////////////////////////////////////////////////
    virtual ~RenderWindow();

    ////////////////////////////////////////////////////////////
    /// \brief Get the size of the rendering region of the Window_
    ///
    /// The size doesn't include the titlebar and borders
    /// of the Window_.
    ///
    /// \return Size in pixels
    ///
    ////////////////////////////////////////////////////////////
    virtual Vector2u getSize() const;


    ////////////////////////////////////////////////////////////
    /// \brief Tell if the Window_ will use sRGB encoding when drawing on it
    ///
    /// You can request sRGB encoding for a Window_ by having the sRgbCapable flag set in the ContextSettings
    ///
    /// \return True if the Window_ use sRGB encoding, false otherwise
    ///
    ////////////////////////////////////////////////////////////
    virtual bool isSrgb() const;

    ////////////////////////////////////////////////////////////
    /// \brief Activate or deactivate the Window_ as the current target
    ///        for OpenGL rendering
    ///
    /// A Window_ is active only on the current thread, if you want to
    /// make it active on another thread you have to deactivate it
    /// on the previous thread first if it was active.
    /// Only one Window_ can be active on a thread at a time, thus
    /// the Window_ previously active (if any) automatically gets deactivated.
    /// This is not to be confused with requestFocus().
    ///
    /// \param active True to activate, false to deactivate
    ///
    /// \return True if operation was successful, false otherwise
    ///
    ////////////////////////////////////////////////////////////
    bool setActive(bool active = true);

    ////////////////////////////////////////////////////////////
    /// \brief Copy the current contents of the Window_ to an image
    ///
    /// \deprecated
    /// Use a sf::Texture and its sf::Texture::update(const Window&)
    /// function and copy its contents into an sf::Image instead.
    /// \code
    /// sf::Vector2u windowSize = Window_.getSize();
    /// sf::Texture texture;
    /// texture.create(windowSize.x, windowSize.y);
    /// texture.update(Window_);
    /// sf::Image screenshot = texture.copyToImage();
    /// \endcode
    ///
    /// This is a slow operation, whose main purpose is to make
    /// screenshots of the application. If you want to update an
    /// image with the contents of the Window_ and then use it for
    /// drawing, you should rather use a sf::Texture and its
    /// update(Window&) function.
    /// You can also draw things directly to a texture with the
    /// sf::RenderTexture class.
    ///
    /// \return Image containing the captured contents
    ///
    ////////////////////////////////////////////////////////////
    SFML_DEPRECATED Image capture() const;

protected:

    ////////////////////////////////////////////////////////////
    /// \brief Function called after the Window_ has been created
    ///
    /// This function is called so that derived classes can
    /// perform their own specific initialization as soon as
    /// the Window_ is created.
    ///
    ////////////////////////////////////////////////////////////
    virtual void onCreate();

    ////////////////////////////////////////////////////////////
    /// \brief Function called after the Window_ has been resized
    ///
    /// This function is called so that derived classes can
    /// perform custom actions when the size of the Window_ changes.
    ///
    ////////////////////////////////////////////////////////////
    virtual void onResize();

private:

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    unsigned int m_defaultFrameBuffer; //!< Framebuffer to bind when targeting this Window_
};

} // namespace sf


#endif // SFML_RENDERWINDOW_HPP


////////////////////////////////////////////////////////////
/// \class sf::RenderWindow
/// \ingroup graphics
///
/// sf::RenderWindow is the main class of the Graphics module.
/// It defines an OS Window_ that can be painted using the other
/// classes of the graphics module.
///
/// sf::RenderWindow is derived from sf::Window, thus it inherits
/// all its features: events, Window_ management, OpenGL rendering,
/// etc. See the documentation of sf::Window for a more complete
/// description of all these features, as well as code examples.
///
/// On top of that, sf::RenderWindow adds more features related to
/// 2D drawing with the graphics module (see its base class
/// sf::RenderTarget for more details).
/// Here is a typical rendering and event loop with a sf::RenderWindow:
///
/// \code
/// // Declare and create a new render-Window_
/// sf::RenderWindow Window_(sf::VideoMode(800, 600), "SFML Window_");
///
/// // Limit the framerate to 60 frames per second (this step is optional)
/// Window_.setFramerateLimit(60);
///
/// // The main loop - ends as soon as the Window_ is closed
/// while (Window_.isOpen())
/// {
///    // Event processing
///    sf::Event event;
///    while (Window_.pollEvent(event))
///    {
///        // Request for closing the Window_
///        if (event.type == sf::Event::Closed)
///            Window_.close();
///    }
///
///    // Clear the whole Window_ before rendering a new frame
///    Window_.clear();
///
///    // Draw some graphical entities
///    Window_.draw(sprite);
///    Window_.draw(circle);
///    Window_.draw(text);
///
///    // End the current frame and display its contents on screen
///    Window_.display();
/// }
/// \endcode
///
/// Like sf::Window, sf::RenderWindow is still able to render direct
/// OpenGL stuff. It is even possible to mix together OpenGL calls
/// and regular SFML drawing commands.
///
/// \code
/// // Create the render Window_
/// sf::RenderWindow Window_(sf::VideoMode(800, 600), "SFML OpenGL");
///
/// // Create a sprite and a text to display
/// sf::Sprite sprite;
/// sf::Text text;
/// ...
///
/// // Perform OpenGL initializations
/// glMatrixMode(GL_PROJECTION);
/// ...
///
/// // Start the rendering loop
/// while (Window_.isOpen())
/// {
///     // Process events
///     ...
///
///     // Draw a background sprite
///     Window_.pushGLStates();
///     Window_.draw(sprite);
///     Window_.popGLStates();
///
///     // Draw a 3D object using OpenGL
///     glBegin(GL_QUADS);
///         glVertex3f(...);
///         ...
///     glEnd();
///
///     // Draw text on top of the 3D object
///     Window_.pushGLStates();
///     Window_.draw(text);
///     Window_.popGLStates();
///
///     // Finally, display the rendered frame on screen
///     Window_.display();
/// }
/// \endcode
///
/// \see sf::Window, sf::RenderTarget, sf::RenderTexture, sf::View
///
////////////////////////////////////////////////////////////
