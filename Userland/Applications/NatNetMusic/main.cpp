#include "Widget.h"
#include <LibGUI/Application.h>
#include <LibGUI/Icon.h>
#include <LibGUI/Window.h>
#include <LibGUI/Menu.h>
#include <LibMain/Main.h>

ErrorOr<int> serenity_main(Main::Arguments arguments)
{
    auto app = TRY(GUI::Application::create(arguments));
    auto app_icon = TRY(GUI::Icon::try_create_default_icon("filetype-music"sv));

    auto window = GUI::Window::construct();
    window->resize(640, 480);
    window->set_title("NatNet Music");
    window->set_icon(app_icon.bitmap_for_size(16));

    // Populate the menubar with some stubs
    String menus[] = {"&File"_string,
       "&View"_string,
       "&Navigation"_string,
       "&Resources"_string,
       "&Tools"_string,
       "Filter&s"_string,
       "&Help"_string
    };
    for (auto menu: menus) {
      (void)window->add_menu(menu);
    }

    // FIXME: Rename this widget?
    (void)window->set_main_widget<Widget>();
    window->show();

    return app->exec();
}
