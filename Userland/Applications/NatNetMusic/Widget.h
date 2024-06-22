#pragma once

#include <LibGUI/Widget.h>

class GalleryWidget final : public GUI::Widget {
    C_OBJECT(GalleryWidget)
public:
    virtual ~GalleryWidget() override = default;

private:
    GalleryWidget();
};
