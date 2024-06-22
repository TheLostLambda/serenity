#include "Widget.h"
#include <Applications/NatNetMusic/NNWindowGML.h>

GalleryWidget::GalleryWidget()
{
    load_from_gml(window_gml).release_value_but_fixme_should_propagate_errors();
}
