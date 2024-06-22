serenity_component(
    NatNetMusic
    TARGETS NatNetMusic
)

stringify_gml(./Window.gml NNWindowGML.h window_gml)

set(SOURCES
    main.cpp
    Widget.cpp
)

set(GENERATED_SOURCES
    NNWindowGML.h
)

serenity_app(NatNetMusic ICON filetype-music)
target_link_libraries(NatNetMusic PRIVATE LibCore LibGfx LibGUI LibMain LibFileSystemAccessClient LibIPC)
